/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int InLocateNode(vector<int> & in,int val ,int s,int e){
        for(int i =s;i<=e;i++){
            if(val == in[i]){
                return i;
            }
        
        }
        return -1;
    }
    TreeNode* solve(vector<int>& pre, vector<int>& in,int &preorderIndex , int start , int end){
        // base case
        if(preorderIndex>=pre.size() || start >end){
            return NULL;
        }

        // taking node element from preorder and making it node 
        int element = pre[preorderIndex++];
        TreeNode* root= new TreeNode(element);

        // now finding the position of this node in inorder
        int pos = InLocateNode(in,element,start,end);

        // now forming left and right trees with the help of inorder
        root->left = solve(pre,in,preorderIndex,start,pos-1);
        root->right = solve(pre,in,preorderIndex,pos+1,end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index =0;
        return solve(preorder,inorder,index,0,inorder.size()-1);
    }
};