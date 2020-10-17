#include<iostream>
#include<vector>
using namespace std;

class GraphDirected
{
    private: 
        int v;
        vector <int> *adj;
    public: 
        GraphDirected(int vertices)
        {
            this->v = vertices;
            this->adj = new vector<int>[this->v];
        }
        void addEdge(int x, int y)
        {
            if( x < this->v && y < this->v)
            {
                this->adj[x].push_back(y);
            }
            else
            {
                cout << "error due to wrong arguments" << endl;
            }
            
        }
        void printGraph()
        {
            for(int i = 0; i < this->v; i++)
            {
                cout << i << "->";
                for(int x : this->adj[i])
                {
                    cout << x << " ";
                }
                cout << endl;
            }
        }
        bool DFSRec(int s, bool visited[], bool recStack[])
        {
            visited[s] = true;
            recStack[s] = true;
            for(int u: this->adj[s])
            {
                if(visited[u] == false && DFSRec(u, visited, recStack) == true)
                {
                    return true;
                }
                else if(recStack[u] == true)
                {
                    return true;
                }
            }
            recStack[s] = false;
            return false;
        }
        bool DFS(int s)
        {
            bool visited[this->v];
            bool recStack[this->v];
            for(int i = 0; i < this->v; i++)
            {
                visited[i] = false; // visited array
                recStack[i] = false; // recursion stack
            }
            for(int i = 0; i < this->v; i++)
            {
                if(visited[i] == false)
                {
                    if(DFSRec(i, visited, recStack) == true)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
};

int main(int argc, char *argv[])
{
    GraphDirected gd(5);
    gd.addEdge(0, 3);
    gd.addEdge(3, 4);
    gd.addEdge(4, 2);
    gd.addEdge(2, 1);
    gd.addEdge(1, 3);
    gd.printGraph();
    gd.DFS(0) ? cout << "yes" << endl : cout << "No" << endl;
    return 0;
}



// 0 -> 3 -> 4 -> 2 -> 1