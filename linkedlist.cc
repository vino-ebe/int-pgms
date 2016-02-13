#include<iostream>
using namespace std;

struct list
{
    int data;
    struct list *next;
};

class linkedlist
{
    private:
        list *head;

    public:
       linkedlist();
       void  addNode(int data);
       void  printList();
};

linkedlist::linkedlist()
{
    head = NULL;
}

void linkedlist::addNode(int data)
{
    list *temp = new list;
    temp->data = data;
    temp->next = head;
    head = temp;
}

void linkedlist::printList()
{
    list *temp = head;
    cout<<"The list contains"<<endl;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

int main()
{
    linkedlist l;
    l.addNode(20);
    l.addNode(30);
    l.printList();
}
