// 1. kahn's algorithm basically worked for DAG(directed acyclic graph)
// 2. A graph should contain atleast one vertieces that have in degree zero
// 3. kahn algo recursivly traverse to each of the vertices that have indegree equal to zero and remove 
//      decrease indegree of all the adjancy vertices of that vertices
// let's jump in 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class DAG
{
    private:
        int v;
        vector<int> *adj;
    public:
        DAG(int vertices)
        {
            this->v = vertices;
            this->adj = new vector<int>[this->v];
        }
        void addEdge(int x, int y)
        {
            this->adj[x].push_back(y);
        }
        void printDAG()
        {
            for(int i = 0; i < this->v; i++)
            {
                cout << i << "->";
                for( auto v: this->adj[i])
                {
                    cout << v << " ";
                }
                cout << endl;
            }
        }
        int getInDegree(int vertix)
        {
            int count = 0;
            for(int i = 0; i< this->v; i++)
            {
                for(auto v: adj[i])
                {
                    if(v == vertix)
                    {
                        count++;
                    }
                }
            }
            return count;
        }
        void BFS()
        {
            // Step 1: store every vertices's indegree
            vector<int> inDegree;
            for(int i = 0; i < this->v; i++)
            {
                inDegree.push_back(i);
            }
            // step2: Create a queue
            queue<int> q;
            // step3: Add all 0 indegree vertices into the queue
            for(auto i : inDegree)
            {
                if(inDegree[i] == 0)
                {
                    q.push(i);
                }
            }
            // Step 4:
            while(q.empty() == false)
            {
                int u = q.front();
                q.pop();
                cout << u << " ";
                for(auto x: this->adj[u])
                {
                    inDegree[x] -= 1;
                    if(inDegree[x] == 0)
                    {
                        q.push(x);
                    }
                }
            }

        }
};

int main(int argc, char *argv[])
{
    DAG d(5);
    d.addEdge(0, 1);
    d.addEdge(1, 2);
    d.addEdge(2, 3);
    d.addEdge(4, 1);
    d.printDAG();
    cout << d.getInDegree(1) << endl;
    d.BFS();
    return 0;
}