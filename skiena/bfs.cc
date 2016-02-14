#include<iostream>
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

    public:
        graph() {
            for (int i = 0; i < MAXV; i++) {
                G.node[i] = NULL;
                G.degree[i] = 0;
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
};

int main()
{
    graph gr;
    gr.addEdge(0,1);
    gr.addEdge(0,3);
    gr.addEdge(1,3);
    gr.addEdge(2,3);
    gr.addEdge(2,1);

    gr.printGraph();
    return 0;
}
