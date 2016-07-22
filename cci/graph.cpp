#include<iostream>

using namespace std;

struct graphNode {
    int vertex;
    struct graphNode* next;
};

class graph {
    private:
        static const int NUM_VERTEX = 10;
        graphNode* V[NUM_VERTEX];
        int numEdges[NUM_VERTEX];
        bool visited[NUM_VERTEX];

        graphNode* createNode(int vertex) {
            graphNode *temp = new graphNode();
            temp->vertex = vertex;
            temp->next = NULL;
            return temp;
        }

    public:
        graph() {
            for (int i = 0; i < NUM_VERTEX; i++) {
                V[i] = NULL;
                numEdges[i] = 0;
                visited = false;
            }
        }

        void addEdge(int fromVertex, int toVertex) {
            if (!V[fromVertex]) {
                V[fromVertex] = createNode(fromVertex);
            }

            graphNode* temp = createNode(toVertex);
            temp->next = V[fromVertex]->next;
            V[fromVertex]->next = temp;
        }

        void printGraph() {
            graphNode *temp = NULL;
            for (int i = 0; i < NUM_VERTEX; i++) {
                temp = V[i]; 
                if (temp) {
                    cout<<"Vertex ["<<i<<"] --->";
                    while (temp) {
                        cout<<temp->vertex;
                        temp = temp->next;
                        cout<<"--->";
                    }
                }
                cout<<endl;
            }
        }

        bool routeExist(int vertex1, int vertex2) {
            graphNode* temp = V[vertex1];

            while (temp) {
                if (temp->vertex == vertex2) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
};


int main()
{
    graph g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(4,3);

    g.printGraph();
    if (g.routeExist(3,5)) {
        cout<<"Route Exist"<<endl;
    } else {
        cout<<"Route does not exist"<<endl;
    }
}

