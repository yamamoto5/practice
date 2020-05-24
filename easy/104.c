/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root){
    int max_left = 0;
    int max_right = 0;
    if(!root)
    {
        return 0;
    }
    else if(!root->left && !root->right)
    {
        return 1;
    }
    else
    {
        max_left = maxDepth(root->left);
        max_right = maxDepth(root->right);
    }

    return (max_left > max_right) ? max_left+1 : max_right+1;
}
