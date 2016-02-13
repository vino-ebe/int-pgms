#include<iostream>
using namespace std;

void swap(int *q, int curIndex, int parentIndex);

class heaptree
{
    private:
        int pqueue[50];
        int curIndex;
        void bubbleUp(int index);
        int getParent(int child);
        int getLeftChild(int parent);
        int getRightChild(int parent);

    public:
        heaptree()
        {
            curIndex = 0;
        }
        static const int MAX_TREE = 100;
        void insertHeapTree(int tree);
        int extractMin();
        void bubbleDown();
        void deleteEntry();
        void printheap();
};

void heaptree::insertHeapTree(int data)
{
    int childIndex = curIndex;
    pqueue[childIndex] = data;
    curIndex++;

    if(data < pqueue[getParent(childIndex)])
    {
        bubbleUp(childIndex);
    }
}

void heaptree::bubbleUp( int curIndex)
{

    while (pqueue[curIndex] < pqueue[getParent(curIndex)])
    {
        swap(pqueue, curIndex, getParent(curIndex));
        curIndex = getParent(curIndex);
    }
}

int heaptree::getParent(int childIndex)
{
    if (childIndex < 1)
    {
        return -1;
    }
    return (childIndex -1)/2; 
}

int heaptree::getLeftChild (int parentIndex)
{
    return (parentIndex * 2) + 1;
}

int heaptree::getRightChild (int parentIndex)
{
    return (parentIndex * 2) + 2;
}

void heaptree::printheap()
{
    cout<<"The tree list is:";
    for (int i = 0;i < curIndex;i++)
    {
        cout<<pqueue[i]<<" ";
    }
    cout<<endl;
}

int heaptree::extractMin()
{
    int min = pqueue[0];

    pqueue[0] = pqueue[curIndex - 1];

    curIndex--;

    bubbleDown();

    return min;
}

void heaptree::bubbleDown()
{
    int rootIndex = 0;
    int lchild = 0, rchild = 0, smallChild = 0;

    while(((rootIndex * 2) + 2) < curIndex)
    {
        lchild = (rootIndex * 2) + 1;
        rchild = (rootIndex * 2) + 2;
        smallChild = pqueue[lchild] < pqueue[rchild] ? lchild : rchild;

        if (pqueue[rootIndex] > pqueue[smallChild])
        {
            swap(pqueue, rootIndex, smallChild);
            rootIndex = smallChild;
        }
        else
        {
            break;
        }
    }
}

void swap(int *q, int curIndex, int parentIndex)
{
    int temp = (q)[curIndex];
    (q)[curIndex] = (q)[parentIndex];
    (q)[parentIndex] = temp;
}

int main()
{
    heaptree heap;
    heap.insertHeapTree(5);
    heap.insertHeapTree(15);
    heap.insertHeapTree(3);
    heap.insertHeapTree(13);
    heap.insertHeapTree(7);
    heap.insertHeapTree(1);
    heap.printheap();
    cout<<"Minimum"<<heap.extractMin()<<endl;
    heap.printheap();
}

