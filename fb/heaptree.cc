#include<iostream>

#define PARENT(i)  (i - 1)/2

using namespace std;


class heap
{
    private:
        int htree[100];
        int index;

    public:
        heap()
        {
            index = 0;
        }

        addNode(int data)
        {
            int i = index;

            htree[index] = data;

            while( i > 0; htree[PAREENT(i)] < htree[i])
            {
                /* We need to swap the parent and child */

                int temp = htree[PARENT(i)];
                htree[PARENT(i)] = htree[i];
                htree[i] = temp;

                i = PARENT(i);
            }

            index++;
        }

};

int main()
{
    heap tree;
    tree.addNode(5);
    tree.addNode(6);
    tree.addNode(7);
    tree.addNode(8);
    tree.addNode(9);
    tree.addNode(10);
}
