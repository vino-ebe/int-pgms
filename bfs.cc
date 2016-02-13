#include<iostream>
using namespace std;


struct adjlistNode
{
    int dest;
    struct adjlistNode *next;
};

struct adjList
{
    struct adjlistNode *head;
};

class Graph
{
    private:
        int numVertex;
        adjList *list;
        adjlistNode* newAdjListNode(int dest);

    public:
        Graph(int numVertex):numVertex(numVertex) 
        {
            list = new adjList[numVertex];

            for(int i = 0; i < numVertex; i++)
            {
                list[i].head = NULL;
            }
        }
        
         void addEdge(int srcv,int dstv);
         void printGraph();
};

adjlistNode* Graph::newAdjListNode(int dest)
{
    struct adjlistNode *node = new adjlistNode;
    node->dest = dest;
    node->next = NULL;
    return node;
}

void Graph::addEdge(int srcv,int destv)
{

    struct adjlistNode *node = newAdjListNode(destv);
    node->next = list[srcv].head;
    list[srcv].head = node;

    node = newAdjListNode(srcv);
    node->next = list[destv].head;
    list[destv].head = node;
    
}

void Graph::printGraph()
{
    for(int i = 0; i < numVertex;i++)
    {
        adjlistNode *temp = list[i].head;
        while(temp != NULL)
        {
            cout<<"---->"<<temp->dest;
            temp = temp->next;
        }
        cout<<endl;
    }
}

struct bfsNode
{
    int vertexNum;
    int distance;
    int pred;
};

struct bfsNodeList
{
    bfsNode *head;
};

class BFS
{
    private:
        bfsNodeList *bfslist;
        Graph *gh;

    public:
        BFS(Graph g):gh(g)
        {
            bfslist = new bfsNodeList[gh->numVertex];
            for(int i = 0; i < gh->numVertex; i++)
            {
                bfslist[i].head = NULL; 
            }
        }
};

bfsNode* BFS::newBfsNode(int vertex)
{
    bfsNode bnode* = new bfsNode;
    bnode.vertexNum = vertex;
    bnode.distance = 0;
    bnode.pred = 0;
    bnode.next = NULL;
}

void BFS:initBFSTree()
{
    for(int i = 0; i < gh->numVertex;i++)
    {
        bfslist[i].head = newBfsNode(i);
    }
}

void BFS::buildBFSTree(int source)
{
            bfslist[source].head.distance = 0;
    for(int i = 0; i < gh->numVertex;i++)
    {
        adjlistNode *temp = gh->list[i].head;
        while(temp->next != NULL)
        {
            bfslist[temp->dest].head.distance = i +1;
            bfslist[temp->dest].head.pred = i +1;
        }
    }
}
int main()
{
    Graph gh(5);
    gh.addEdge(0,1);
    gh.addEdge(0,4);
    gh.addEdge(1,2);
    gh.addEdge(1,3);
    gh.addEdge(1,4);
    gh.addEdge(2,3);
    gh.addEdge(3,4);

    gh.printGraph();

    return 0;
}
