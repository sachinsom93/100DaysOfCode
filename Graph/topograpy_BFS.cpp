#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph
{
    private: 
        int v;
        vector <int> *adj;
    public:
        Graph(int vertices)
        {
            this->v = vertices;
            this->adj = new vector<int>[this->v];
        }
        void addEdge(int x, int y)
        {
            this->adj[x].push_back(y);
        }
        void printAdj()
        {
            for(int i = 0; i< this->v; i++)
            {
                cout << i << "->";
                for(auto u: this->adj[i])
                {
                    cout << u << " ";
                }
                cout << endl;
            }
        }
        void topograpySort()
        {
            // store all indegrees
            vector<int>indegree;
            for(int i = 0; i < this->v; i++)
            {
                for(int u: adj[i])
                {
                    indegree[u]++;
                }
            }
            for(int i = 0; i< indegree.size(); i++)
            {
                cout << indegree[i] << " ";
            }
            cout << endl;
        }
};
int main(int argc, char *argv[])
{
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.printAdj();
    g.topograpySort();
    return 0;
}