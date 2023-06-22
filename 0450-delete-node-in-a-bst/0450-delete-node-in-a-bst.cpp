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
    TreeNode* maxVal(TreeNode* root){
    TreeNode* temp = root;
    while(temp->right != NULL){
        temp=temp->right;
    }
    return temp;
}
    TreeNode* deletNode(TreeNode* root, int target){
    if(root==NULL){
        return NULL;
    }
    if(root->val ==  target){
        
        // no child
        if(root->left==NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child
        if(root->left == NULL && root->right != NULL){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right == NULL){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL){
            // get inorder pred 
            int pred = maxVal(root->left)->val;
            // copy value
            root->val = pred;
            // baki bacha hua kaam
            root->left = deletNode(root->left,pred);
            return root;
        }


    }
    else if(target > root->val){
        root->right=deletNode(root->right,target);

    }
    else{
        root->left = deletNode(root->left,target);
    }
    return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp = deletNode(root,key);
        return temp;
    }
};