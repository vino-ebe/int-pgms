#include<iostream>

using namespace std;

struct linkedlist {
    int data;
    struct linkedlist *next;
};

class llist {
    private:
        linkedlist *head;

        linkedlist* newNode(int data) {
            linkedlist *node = new linkedlist();
            node->data = data;
            node->next = NULL;
            return node;
        }

    public:
        llist() {
            head = NULL;
        }

        void insert(int data) {
            linkedlist *node = newNode(data);
            node->next = head;
            head = node;
        }

        void print() {
            linkedlist *temp = head;
            while (temp != NULL) {
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }

        bool deleteNode(int data) {
            linkedlist *temp = head;

            if (head->data == data) {
                head = head->next;
                free(temp);
            } else {
                while (temp->next) {
                    if (temp->next->data == data) {
                        linkedlist *todelete = temp->next;
                        temp->next = todelete->next;
                        free(todelete);
                        return true;
                    }
                    temp = temp->next;
                }
            }
            cout<<"Could not find the node to delete"<<endl;
            return false;
        }

        llist listAdd_rec(llist *num1, llist *num2) {
            int sum1 = 0, sum2 = 0;
            linkedlist *temp1 = num1->head;
            linkedlist *temp2 = num2->head;
            listAdd(temp1, temp2, &sum1, &sum2);
            cout<<"Sum 1 is:"<<sum1<<"Sum2 is:"<<sum2<<endl;
            int sum3 = sum1 + sum2;
            llist res;

            while(sum3) {
                res.insert(sum3 % 10);
                sum3 = sum3 / 10;
            }

            return res;
        }

        void listAdd(linkedlist *num1, linkedlist *num2, int *sum1, int *sum2)
        {
            if (num1 == NULL || num2 == NULL) {
                return;
            }

            listAdd(num1->next, num2->next, sum1, sum2);
            *sum1 = ((*sum1) * 10) + num1->data;
            *sum2 = ((*sum2) * 10) + num2->data;
        }

        bool palindrome(llist *list1)
        {
            return palindrome_rec(list1->head, &(list1->head));
        }

        bool palindrome_rec(linkedlist *list1, linkedlist **list2)
        {
            if (list1 == NULL) {
                return true;
            }

            bool ret1 = palindrome_rec(list1->next, list2); 
            if (ret1 == false)
                return false;

            
            if (list1->data != (*list2)->data) {
                return false;
            }
            (*list2) = (*list2)->next;
            return true;
        }
};
