// ******** BEGIN UNION FIND ********

int parent[100007];

int getParent(int n){
    if (parent[n] == n)
        return n;
    return parent[n] = getParent(parent[n]);
}

void join(int n1, int n2){
    parent[getParent(n2)] = getParent(n1); 
}

// ******** END UNION FIND ********