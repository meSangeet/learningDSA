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
    int mx;
public:
    void func(int level, TreeNode* node, map<int,int> &m){
        if(!node) return;
        m[level] += node->val;
        func(level+1, node->left, m);
        func(level+1, node->right, m);
    }
    int maxLevelSum(TreeNode* root) {
        map<int,int> m;
        mx = 0;
        TreeNode* node = root;
        func(1, node, m);
        mx = INT_MIN;
        vector<int> temp;
        for(auto x : m){
            temp.push_back(x.second);
            mx = max(x.second, mx);
        }
        for(int i = 0; i<temp.size(); i++){
            if(temp[i] == mx) return i+1;

        }

        return 0;
    }
};