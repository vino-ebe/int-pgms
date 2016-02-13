#include<iostream>

using namespace std;

struct list
{
    int data;
    struct list *next;
};

class linkedList
{
    private:
        list *head;

    public:
        linkedList()
        {
            head = NULL;
        }

        void addNode(int data)
        {
            list *temp = new list();
            
            temp->data = data;
            temp->next = head;
            head = temp;

        }

        void printList()
        {
            list *temp = head;

            while(temp)
            {
                 cout<<temp->data<<endl;
                 temp = temp->next;
            }
        }

        void reverseList()
        {
            list *a = head,*c = NULL;
            list *b; 

            while(a != NULL)
            {
                b = a->next;
                a->next = c;
                c = a;
                a = b;
            }
            head = c;
        }

        void reversePair()
        {
            list *f,*s; 
            list *temp;
            list *pairHead = head;
            list *t = NULL;

            while(pairHead->next != NULL)
            {
                f = pairHead;
                s = f->next;

                temp = s->next;
                s->next = f;
                f->next = temp;

                if(f == head)
                {
                    head = s;
                }

                if(t == NULL)
                {
                    t = f;
                }
                else
                {
                    t->next = s;
                    t = f;
                }

                if(f->next != NULL)
                {
                    pairHead = f->next;
                }
                else
                {
                    break;
                }
            }
        }
};

int main()
{
    linkedList l;
    l.addNode(10);
    l.addNode(20);
    l.addNode(30);
    l.addNode(40);
    l.addNode(50);
    l.addNode(60);

    l.printList();

    cout<<"Reverse List"<<endl;

    //l.reverseList();

    l.reversePair();

    l.printList();

    return 0;
}
