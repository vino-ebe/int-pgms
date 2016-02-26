#include<iostream>
#include<queue>

using namespace std;

typedef struct edgeNode {
    int v;
    struct edgeNode *next;
}edgeNode_t;

#define MAXV    100

typedef struct graphs {
    edgeNode_t *node[MAXV];
    int nVertex;
    int degree[MAXV];
    int nEdges;
    bool directed;
}graph_t;

class graph {
    private:
        graph_t G;
        int state[4];
        int parent[4];

        enum stateVar {
            kUnDiscovered,
            kDiscovered,
            kProcessed
        }stateEnum;

    public:
        graph() {
            for (int i = 0; i < MAXV; i++) {
                G.node[i] = NULL;
                G.degree[i] = 0;
            }
            for (int i = 0; i < 4; i++) {
                state[i] = kUnDiscovered;
            }
            G.directed = true;
            G.nVertex = 0;
        }

        void addEdge(int fromVertex, int toVertex) {

            edgeNode_t *edge = new edgeNode_t;
            edge->v = toVertex;
            edge->next = G.node[fromVertex];
            G.node[fromVertex] = edge;
            G.degree[fromVertex]++;
            G.nEdges++;
        }

        void printGraph() {

            for (int i = 0; i < MAXV; i++) {
                if (G.node[i]) {
               cout<<"Edges for Vertex ["<<i<<"]";
                    edgeNode_t *edge = G.node[i];

                    while(edge) {
                        cout<<"-->"<<edge->v;
                        edge = edge->next;
                    }
                    cout<<endl;
                }
            }
        }

        void bfs(int startVertex) {
            queue<int> edgeQueue;


            for (int i = 0; i < 4; i++) {
                state[i] = kUnDiscovered;
                parent[i] = -1;
            }

            state[startVertex] = kDiscovered;
            parent[startVertex] = -1;

            edgeQueue.push(startVertex);

            while (!edgeQueue.empty()) {
                int v = edgeQueue.front();
                edgeQueue.pop();
                state[v] = kProcessed;
                cout<<v<<endl;
                edgeNode_t *curEdge = G.node[v];
                // Add all its neighbours to the queue
                while (curEdge != NULL) {
                    if (state[curEdge->v] != kDiscovered && state[curEdge->v] != kProcessed) { 
                        state[curEdge->v] = kDiscovered;
                        edgeQueue.push(curEdge->v);
                    }
                    curEdge = curEdge->next;
                }
            }
        }
        
        void dfs(int startVertex) {

            state[startVertex] = kDiscovered;
            cout<<startVertex<<endl;
            edgeNode_t *curEdge = G.node[startVertex];

            while (curEdge != NULL) {
                if (state[curEdge->v] != kDiscovered && state[curEdge->v] != kProcessed) {
                    state[curEdge->v] = kDiscovered;
                    parent[curEdge->v] = startVertex;
                    dfs(curEdge->v);
                }
                curEdge = curEdge->next;
            }
            cout<<"Setting vertex "<<startVertex<<"Processed"<<endl;
            state[startVertex] = kProcessed;
        }
};

int main()
{
    graph *gr = new graph();
    gr->addEdge(0,3);
    gr->addEdge(1,0);
    gr->addEdge(1,2);
    gr->addEdge(2,3);
    gr->addEdge(3,0);
    gr->addEdge(3,1);

    //gr->bfs(0);
    cout<<"DFS"<<endl;
    gr->dfs(0);
    gr->printGraph();
    return 0;
}
