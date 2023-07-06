//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int fmid(int in[], int target,int s ,int e){
        for(int i=s;i<=e;i++){
            if(in[i]==target){
                return i;
            }
        }
        return 0;
    }
    Node* solve(int in[],int pre[],int& preIndex , int s, int e,int n){
        if(preIndex>= n|| s>e)
            return NULL;
            
        int element  = pre[preIndex++];
        Node* root = new Node(element);
        int mid = fmid(in,element,s,e);
        root->left =  solve(in ,pre, preIndex ,s,mid-1 ,n);
        root->right = solve(in,pre,preIndex,mid+1,e,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int bhaiyrrrr  = 0;
        return solve(in,pre,bhaiyrrrr,0,n,n);   
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends