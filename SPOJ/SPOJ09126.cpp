#include <iostream>
#include <vector>

using namespace std;

vector<int> edges[100001];
bool passed[100001];

void addEdge(vector<int> vec[], int v, int u){
	vec[v].push_back(u);
	vec[u].push_back(v);
}

void DFS(int curNode, int curCount, int *maxV, int *maxN){
	passed[curNode] = true;
	for (int i = 0; i < edges[curNode].size(); i++){
		if (!passed[edges[curNode].at(i)]){
			if (curCount + 1 > *maxV){
				*maxV = curCount + 1;
				*maxN = edges[curNode].at(i);
			}
			DFS(edges[curNode].at(i), curCount + 1 , maxV, maxN);		
		}
	}
}

int main(){
	int cases;
	cin >> cases;
	while (cases-- > 0){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			edges[i].clear();
			passed[i] = false;
		}

		int n1, n2, cur = n;
		while (cur-- > 1){
			cin >> n1 >> n2;
			addEdge(edges, n1, n2);
		}

		int maxValor = 0, maxNode = 0;

		DFS(0, 0, &maxValor, &maxNode);

		maxValor = 0;

		for (int i = 0; i < n; i++){
			passed[i] = false;
		}

		DFS(maxNode, 0, &maxValor, &maxNode);

		cout << (maxValor+1)/2 << endl;


	}
}