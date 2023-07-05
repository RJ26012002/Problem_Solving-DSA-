//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{   // building tree from levelorder
    int curr=0;
    Node* root = new Node(levelOrder[curr++]);
    queue<Node*> q;
    q.push(root);
    while(curr!=n){
        Node* temp = q.front();
        q.pop();
        
        temp->left = new Node(levelOrder[curr++]);
        q.push(temp->left);
        
        if(curr!=n){
            temp->right  = new Node(levelOrder[curr++]);
            q.push(temp->right);
        }
    }
    return root;
    
}