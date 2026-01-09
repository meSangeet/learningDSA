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
    TreeNode* ans;
    int maxD;
    int f(TreeNode* node,int depth){
     if(!node){
        return depth;
     }
     int leftdis=f(node->left,depth+1);
     int rightdis=f(node->right,depth+1);
     if(leftdis==rightdis && leftdis==maxD){
        ans=node;
     }
     return max(leftdis,rightdis);
    }
    int maxDepth(TreeNode* node){
        if(!node){
            return 0;
        }
        int left=maxDepth(node->left)+1;
        int right=maxDepth(node->right)+1;
        return max(left,right);

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
       maxD=maxDepth(root);
       int k=f(root,0);
        // cout<<maxD<<endl;
        return ans;
    }
};