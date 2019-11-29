// ******** START SEGMENT_TREE ********

struct Node {
    int totalSum; 

    int maxPrefixSum; 
    int maxSuffixSum; 
    int maxSubarraySum;

    int minPrefixSum; 
    int minSuffixSum; 
    int minSubarraySum;

    Node (int value = 0) {
        minPrefixSum =minSuffixSum =  minSubarraySum = maxPrefixSum = maxSuffixSum = maxSubarraySum = totalSum = value; 
    }

    static Node merge(Node leftChild, Node rightChild) { 
    
        Node parentNode; 

        parentNode.totalSum = leftChild.totalSum + 
                            rightChild.totalSum; 


        parentNode.maxPrefixSum = max(leftChild.maxPrefixSum, 
                                    leftChild.totalSum +  
                                    rightChild.maxPrefixSum); 
    
        parentNode.maxSuffixSum = max(rightChild.maxSuffixSum, 
                                    rightChild.totalSum + 
                                    leftChild.maxSuffixSum); 
    
        parentNode.maxSubarraySum = max({leftChild.maxSubarraySum, 
                                        rightChild.maxSubarraySum, 
                                        leftChild.maxSuffixSum +  
                                        rightChild.maxPrefixSum}); 


        parentNode.minPrefixSum = min(leftChild.minPrefixSum, 
                                    leftChild.totalSum +  
                                    rightChild.minPrefixSum); 
    
        parentNode.minSuffixSum = min(rightChild.minSuffixSum, 
                                    rightChild.totalSum + 
                                    leftChild.minSuffixSum); 

        // parentNode.minSubarraySum = min({leftChild.minSubarraySum, 
        //                                 rightChild.minSubarraySum, 
        //                                 leftChild.minSuffixSum +  
        //                                 rightChild.minPrefixSum});

        parentNode.minSubarraySum = min({leftChild.minSubarraySum, 
                                     leftChild.totalSum + rightChild.minPrefixSum});
    
        return parentNode; 
    } 
};

#define N ((int)1e6+5)
Node t[N * 2];
int n;

void build() { 
//   for (int i = n - 1; i > 0; --i) t[i] = Node::merge(t[i<<1], t[i<<1|1]);
    for (int i  = 1; i <= 2 * n + 5; i++)
        t[i] = Node();
}

void update(int p, Node obj) {  // set value at position p
  for (t[p += n] = obj; p >>= 1; ) 
            t[p] = Node::merge(t[p<<1], t[p<<1|1]);
}

Node query(int l, int r) {  // result on interval [l, r)
    Node retL, retR = Node();
    for(l += n, r += n; l < r; l>>=1, r>>=1){
        if(l&1) retL = Node::merge(retL, t[l++]);
        if(r&1) retR = Node::merge(t[--r], retR);
    } 
    return Node::merge(retL, retR);
}

// make cin to n
// change Node atributes and merge function 

// if using initial array, assign values to n ... 2n-1

// ******** END SEGMENT_TREE ********