#include <iostream>
#include <vector>

using namespace std;

class Graph {
    vector<bool> nodes;
    vector<vector<int>> edges;
    public:
        Graph (int n);
        void addEdge(int n1, int n2);
        bool DFS(int b, int c);
        bool checkTree();
};

Graph::Graph(int n){
    nodes.resize(n + 1, false);
    edges.resize(n + 1);
}

void Graph::addEdge(int n1, int n2){
    edges.at(n1).push_back(n2);
    edges.at(n2).push_back(n1);
}

bool Graph::DFS(int b, int c){
    if (nodes.at(c))
        return false;
    nodes.at(c) = true;
    for (int i: edges.at(c)){
        if(i != b){
            if (!DFS(c , i))
                return false;
        }
    }
    return true;
}

bool Graph::checkTree(){
    for (int i = 1; i < nodes.size() ; i++){
        if (!nodes.at(i))
            return false;
    }
    return true;
}

int main(){
    int n , e;
    cin >> n >> e;
    Graph graph (n);
    for (int i = 0 ; i < e ; i++){
        int n1, n2;
        cin >> n1 >> n2;
        graph.addEdge(n1, n2);
    }

    if (graph.DFS(0, 1) && graph.checkTree()){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
