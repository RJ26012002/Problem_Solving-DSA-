//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Info{
    public:
    int size;
    int mini;
    int maxi;
    bool isBST;
    
    Info(){
        
    }
    
    Info(int a , int b , int c, bool d){
        mini = a;
        maxi = b;
        size = c;
        isBST = d;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Info solve(Node* root, int &ans){
        if(root==NULL){
            return Info{INT_MAX,INT_MIN,0,true}; 
        }
        
        // calling for left subtree 
        Info leftAns = solve(root->left,ans);
        // calling for right subtree
        Info rightAns = solve(root->right ,ans);
        
        // create ans for current node 
        Info curr;
        curr.size = leftAns.size + rightAns.size + 1;
        curr.mini = min(leftAns.mini , root->data);
        curr.maxi = max(rightAns.maxi,root->data);
        
        // checking that curr node is a bst or not  
        if(leftAns.isBST && rightAns.isBST && (root->data > leftAns.maxi && root->data < rightAns.mini)){
            curr.isBST = true;
        }
        else{
            curr.isBST = false;
        }
        
        // updating the answer if the curr subtree/ tree is a BST
        if(curr.isBST){
            ans = max(ans,curr.size);
        }
        
        return curr;
    }
    int largestBst(Node *root)
    {
        int ans =0;
        solve(root,ans);
        return ans;
    	//Your code here
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends