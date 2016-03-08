/*You have two numbers represented by a linked list, where each node contains a
 * single digit. The digits are stored in reverse order, such that the Ts digit is at the
 * head of the list. Write a function that adds the two numbers and returns the sum
 * as a linked list.
 * EXAMPLE
 * Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is, 617 + 295.
 * Output: 2 -> 1 -> 9.That is, 912.
 */

#include<iostream>
#include "linkedlist.h"
using namespace std;

void listAdd(llist *num1, llist *num2,int *sum1, int *sum2);
int main()
{
    llist *num1 = new llist();
    llist *num2 = new llist();

    num1->insert(6);
    num1->insert(1);
    num1->insert(7);

    num1->insert(2);
    num1->insert(9);
    num1->insert(5);

    int sum1 = 0, sum2 = 0;
    listAdd(num1, num2, &sum1, &sum2);
    cout<<"Sum 1 is:"<<sum1<<"Sum2 is:"<<sum2<<endl;
}

void listAdd(llist *num1, llist *num2,int *sum1, int *sum2)
{
    if (num1 == NULL || num2 == NULL) {
        return;
    }

    listAdd(num1.next, num2->next, &sum1, &sum2);
    sum1 = sum1 * 10 + num1->data;
    sum2 = sum2 * 10 + num2->data;
}
