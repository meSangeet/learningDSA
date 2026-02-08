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
    int height(TreeNode* temp)
    {
        if(!temp) return 0;

        int left = height(temp->left);
        int right = height(temp->right);

        if(left == -1 || right == -1)
        {
            return -1;
        }

        int ans = abs(left-right);
        if(ans > 1)
        {
            return -1;
        }

        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(height(root) == -1)
        {
            return false;
        }

        return true;
    }
};