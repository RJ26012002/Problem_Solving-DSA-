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
    // finding and saving the inorder or tree in vector
    void inorderr(TreeNode* &root,vector<int> & nums){
        if(root==NULL){
            return;
        }
        // L
        inorderr(root->left,nums);
        // N
        nums.push_back(root->val);
        // R
        inorderr(root->right,nums);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        inorderr(root,inorder);
        
        // checking that vector elements are in increasing order or not
        for(int i =0;i<inorder.size()-1;i++){
            if(inorder[i]>=inorder[i+1]){
                return false;
            }
        } 
    return true;

    }
};