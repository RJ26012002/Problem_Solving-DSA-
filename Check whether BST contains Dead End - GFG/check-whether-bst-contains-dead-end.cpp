//{ Driver Code Starts
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


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
// void inorder(Node* root,vector<int> &nums){
//     if(root == NULL)
//         return ;
//     inorder(root->left,nums);
//     nums.push_back(root->data);
//     inorder(root->right,nums);
// }

bool solve(Node* root,int min , int max){
    if(root==NULL){
        return false;
    }
    if(min==max){
        return true;
    }
    return solve(root->left,min,root->data-1) || solve(root->right , root->data+1,max);
}
bool isDeadEnd(Node *root)
{
    // vector<int> nums;
    // inorder(root,nums);
    // if(nums[0]==1){
    //     return true;
    // }
    
    // int prev =nums[0];
    // int next = 0;
    // for(int i =1;i<nums.size()-1;i++){
    //     next = nums[i+1];
    //     int curr = nums[i];
    //     if(curr-prev ==1 && next-curr==1){
    //         return true;
    //     }
    //     prev=nums[i];
    // }
    // return false;
    return solve(root,1,INT_MAX); // root ,lower bound , upper bound
}