#include<iostream>
#include<list>
#include<queue>
#include<stack>
using namespace std;

void printVector(vector<int> vec){
    for (int i = 0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout<<endl;
}

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList(){
        for (int i = 0; i < V; i++){
            cout << i << " : ";
            for (int neighbor : l[i]){
                cout << neighbor << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void bfs(int src){
        queue<int> q;
        vector<bool> visited(V, false);

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int v : l[u]){
                if (!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        cout << endl;
        return;
    }

    void dfsRec(int u, vector<bool>& visited){
        
        cout << u << " ";
        visited[u] = true;

        for (int v : l[u]){
            if (!visited[v]){
                dfsRec(v, visited);
            }
        }

    }

    void dfs_r(int src){
        vector<bool> visited(V, false);
        dfsRec(src, visited);
        cout << endl;
    }

    void dfs(int src){
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(src);
        visited[src] = true;

        while(!s.empty()){
            int u = s.top();
            s.pop();

            cout << u << " ";

            for (auto it = l[u].rbegin(); it != l[u].rend(); ++it){
                if (!visited[*it]){
                    s.push(*it);
                    visited[*it] = true;
                }
            }
        }
        cout << endl;

    }

    bool isCycleDFS(int src, vector<bool>& visited, int parent){  
        visited[src] = true;

        for (int v : l[src]){
            if (!visited[v]){
                if (isCycleDFS(v, visited, src)){
                    return true;
                }
            } else if (v != parent){
                return true;
            }
        }
        return false;
    }

    bool isCycle(){
        vector<bool> visited(V, false);

        for (int i = 0; i< V; i++){
            if (!visited[i]) {
                if (isCycleDFS(i, visited, -1)){
                    return true;
                }
            }
        }

        return false;
    }
    
};


int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    // g.addEdge(2,3);
    g.addEdge(2,4);
    
    g.bfs(0);
    g.dfs_r(0);

    return 0;
}