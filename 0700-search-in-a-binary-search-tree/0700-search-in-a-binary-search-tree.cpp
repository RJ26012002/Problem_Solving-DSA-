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
    void solve(TreeNode* root, int val, TreeNode* &temp){
       
        // if(root== NULL && root->left ==NULL && root->right==NULL){
        //     return;
        // }
        if(root==NULL){
            return;
        }
        if(root->val==val){
            temp = root;
            return;
        }
        
       
        if(root->val > val){
            solve(root->left,val,temp);
        }
        else{
            solve(root->right,val,temp);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = NULL;
        solve(root,val,temp);
        
        return temp;
    }
};