#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void addEdge(int v1, int v2);
void printGraph();
void bfs(int startNode);
void dfsUtil(int parentSet[],int v);
void dfs(int startNode);

vector<int> g_adjList[10];

int main()
{
    addEdge(0,1);
    addEdge(0,6);
    addEdge(0,8);
    addEdge(1,0);
    addEdge(1,4);
    addEdge(1,6);
    addEdge(1,9);
    addEdge(2,4);
    addEdge(2,6);
    addEdge(3,4);
    addEdge(3,5);
    addEdge(3,8);
    addEdge(4,1);
    addEdge(4,2);
    addEdge(4,3);
    addEdge(4,5);
    addEdge(4,9);
    addEdge(5,3);
    addEdge(5,4);
    addEdge(6,0);
    addEdge(6,1);
    addEdge(6,2);
    addEdge(7,8);
    addEdge(7,9);
    addEdge(8,0);
    addEdge(8,3);
    addEdge(8,7);
    addEdge(9,1);
    addEdge(9,4);
    addEdge(9,7);

    printGraph();
    bfs(0);
    dfs(0);
}

void printGraph()
{
    vector<int>::iterator it;
    vector<int> temp;

    for(int i = 0; i < 10;i++)
    {
        int s = g_adjList[i].size();
        temp = g_adjList[i];
        //for(int j = 0;j < g_adjList[i].size(); j++)
        for(it = g_adjList[i].begin();it !=  g_adjList[i].end(); it++)
        {
            //if(j == 0)
            if(it == g_adjList[i].begin())
            cout<<"Node["<<i<<"]------->";
            //cout<<temp[j]<<"|";
            cout<<*it<<"|";
        }
        cout<<endl;
    }
}

void addEdge(int v1, int v2)
{
    g_adjList[v1].push_back(v2);
}
/* BFS
 * Visit the start node.
 * Now visit all the neighbours of start node.
 * Now visit the next node.
 */

void bfs(int startNode)
{
    int visited[10] = {};
    int v;
    queue<int> q;

    v = startNode;
    visited[v] = 1;
    cout<<"Visited:"<<v<<endl;
    q.push(v);

    while(!q.empty())
    {
        v= q.front();
        q.pop();

        vector<int>::iterator it = g_adjList[v].begin();
        while(it != g_adjList[v].end())
        {
            if(!visited[*it])
            {
                cout<<"Visited:"<<*it<<endl;
                visited[*it] = 1;
                q.push(*it);
            }
            it++;
        }
    }   
}

/* DFS
 * mark the start node as visited.
 * Now pick the first neighbour of startnode and recursively visit its neighbor.
 * Now come back to the next neighbor of the start node.
 * After visiting a node mark it as visited and dont visit again
 */

void dfs(int startNode)
{
    int parentSet[10];
    cout<<"DFS"<<endl;

    for(int i = 0; i < 10; i++)
    {
        parentSet[i] = -1;

    /* Now start from startNode */

    }
    dfsUtil(parentSet,startNode);
}

void dfsUtil(int parentSet[],int v)
{
    parentSet[v] = 1;
    cout<<"Visited:"<<v<<endl;
    vector<int>::iterator it = g_adjList[v].begin();

    while(it != g_adjList[v].end())
    {
        if(parentSet[*it] != 1)
        {
            dfsUtil(parentSet,*it);
        }
        it++;
    }
}
