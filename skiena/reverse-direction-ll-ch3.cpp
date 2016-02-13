//Write a program to reverse the direction of a given singly-linked list. In other
//words, after the reversal all pointers should now point backwards. Your algorithm
//should take linear time.

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}Node;

class mylist
{
    private:
        Node *head;

    public:
        mylist()
        {
            head = NULL;
        }

        void insert( int data)
        {
                Node *newNode = new Node();
                newNode->data = data;
            if (head == NULL)
            {
                newNode->next = NULL;
                head = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }

        void print()
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout<<temp->data<<"-->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }

        void reverselinks()
        {
            Node *a = head, *b = head;
            Node *c = NULL;

            while( b != NULL)
            {
                b = a->next;
                a->next = c;
                c = a;
                a = b;
            }

            head = c;
        }

        void reverse_rec()
        {
            Node *current = head;
            Node *future = current->next;

            r_reverse(current, future, &head);
        }

        void r_reverse( Node* current, Node* future, Node** head)
        {
            if (future == NULL)
            {
                *head = current;
                return;
            }

            r_reverse(current->next, future->next, head);

            future->next = current;
            current->next = NULL;
        }
};

int main()
{
    mylist list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    cout<<"Before reverse"<<endl;
    list.print();
    list.reverse_rec();
//    list.reverselinks();
    cout<<"After reverse"<<endl;
    list.print();
}

