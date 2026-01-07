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
    long long ans=0;
    const long long mod=1e9+7;
    long long totalSum=0;

    long long dfs(TreeNode* node){
        if(!node) return 0;

        long long left=dfs(node->left);
        long long right=dfs(node->right);

        long long subTreeSum=node->val+left+right;
        ans=max(ans,(totalSum-subTreeSum)*subTreeSum);

        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        totalSum=dfs(root);
        dfs(root);
        return ans%mod;    
    }
};