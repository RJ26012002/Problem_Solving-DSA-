//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int fmid(int in[] , int target , int s , int e){
    for(int i=s;i<=e;i++){
        if(in[i]==target){
            return i;
        }
    }
    return s;
}
Node* solve(int in[],int post[],int &postIndex , int s ,int e,int n){
    if(postIndex>=n || s>e){
        return NULL;
    }
    int element  = post[postIndex--];
    Node* root =  new Node(element);
    int mid = fmid(in , element , s ,e);
    root->right  = solve(in , post ,postIndex, mid+1,e,n);
    root->left = solve(in , post , postIndex,s,mid-1,n);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int bh=n-1;
    return solve(in, post ,bh ,0,n-1,n);
}
