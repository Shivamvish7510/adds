#include<iostream>
using namespace std;

class BTreeNode{
    public:
    int *keys; // array of keys
    int t;  // min degree
    BTreeNode **C; // chid pointer
    int n; // current number of keys
    bool leaf; // true if leaf node

    BTreeNode(int t1, bool leaf1);

    void insertNonfull(int k );
    void splitChild(int i, BTreeNode *y);
    void traverse();
    BTreeNode *search(int k);
    friend class BTree;
};

class Btree{
    public:
    BTreeNode *root;
    int t;

    Btree(int t1){
        root = NULL;
        t= t1;
    }

    void traverse(){
        if (root != NULL)
        root->traverse();
    }
    
    BTreeNode *search(int k){
        return (root == NULL)? NULL : root -> search(k);
    }

    void insert(int k);

};


// Constructor for BTreeNode

BTreeNode::BTreeNode(int t1, bool leaf1){
    t =t1;
    leaf = leaf1;
    keys = new  int[2*t-1];
    C = new BTreeNode *[2*t];
    n = 0;
}

// Traverse the B-Tree
void BTreeNode::traverse(){
    int i;
    for(i=0; i<n; i++){
        if (leaf == false)
            C[i]-> traverse();
        cout<< keys[i] << " ";
        
    }

    if (leaf == false)
        C[i]->traverse();
}


// search in B-Tree
BTreeNode *BTreeNode :: search(int k){
    int i=0;
    while(i<n && k >keys[i]){
        i++;
        if (keys[i] == k){
            return this;
        }
        if (leaf == true){
            return NULL;
        }
        return C[i]->search(k);
    }
}


// Insert a new key in the B-Tree
void Btree:: insert(int k){

int main(){

}
