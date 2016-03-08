#include<iostream>
#include"linkedlist.h"

using namespace std;

int main()
{
    llist list;
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    //list.print();
    list.deleteNode(20);
    //list.print();

    llist *num1 = new llist();
    llist *num2 = new llist();

    num1->insert(6);
    num1->insert(1);
    num1->insert(7);

    num2->insert(2);
    num2->insert(9);
    num2->insert(5);
    llist num3, num4;
    num4 = num3.listAdd_rec(num1, num2);
    //num4.print();

    llist num5;
    num5.insert(0);
    num5.insert(1);
    num5.insert(2);
    num5.insert(1);
    num5.insert(0);
    if (num5.palindrome(&num5) ) {
        cout<<"It is a palindrom"<<endl;
    } else {
        cout<<"It is NOT a palindrom"<<endl;
    }
}
