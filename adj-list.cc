#include<iostream>
using namespace std;

struct vertex
{
    int node;
    bool visited;
    struct vertex *link;
};

vertex *headList = NULL;
int numVertex = 8;

bool addEdge(int fromNode, int toNode);
vertex* newVertex(int node);
void initheadList();
void printGraph();

vertex* newVertex(int node)
{
    vertex *v = new vertex();
    v->node = node;
    v->link = NULL;
    return v;
}

bool addEdge(int fromNode, int toNode)
{
    if(!(fromNode < numVertex && toNode < numVertex)) 
    {
        cout<<"Invalid edge"<<endl;
        return false;
    }

    vertex *v = newVertex(toNode);
    v->link = headList[fromNode].link;
    headList[fromNode].link = v;

    vertex *v1 = newVertex(fromNode);
    v1->link = headList[toNode].link;
    headList[toNode].link = v1;

    return true;
}

void initheadList()
{
    for(int i = 0; i < numVertex; i++)
    {
        headList[i].node = i;
        headList[i].visited = false;
        headList[i].link = NULL;
    }
}

void dfs()
{
    stack<vertex> s;
    s.push(headList[0]); /* Lets push the start node in to the stack */
    vertex v;
    bool visited[8] = {};
    int minNode;

    s.push(headList[0]);
    visited[0] = true;

    while(s.empty() != true)
    {
        v = s.top;
        while(v.link != NULL)
        {
            if(visited[v.node] != true) 
            {
                visited[v.node] = true;
                s.push(v);
            }
        }
    }
}

void printGraph()
{
    for(int i = 0; i < numVertex; i++)
    {
        vertex *v = &headList[i];
        cout<<"Adjacency list of Vertex "<<i<<endl;
        while(v != NULL)
        {
            cout<<"-> "<<v->node;
            v = v->link;
        }
        cout<<endl;
    }
}

int main()
{
    headList = new vertex[8];
    initheadList();
    addEdge(0,1);
    addEdge(0,4);
    addEdge(1,2);
    addEdge(1,3);
    addEdge(1,4);
    addEdge(2,3);
    addEdge(3,4);
    printGraph();
    return 0;
}
