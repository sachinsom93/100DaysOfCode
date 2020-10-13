#include<iostream> 
using namespace std;
#include<vector>
class Graph
{
    private: 
        int v;
        vector <int> *adj;
    public: 
        Graph(int nodes)
        {
            this->v = nodes;
            this->adj = new vector<int>[v];
        }
        void addEdge(int u, int v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void printGraph()
        {
            int i = 0;
            for(i = 0; i < this->v; i++)
            {
                cout << i << "->";
                for(int j: adj[i])
                {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
};

int main(int argc, char *argv[])
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.printGraph();
    return 0;
}