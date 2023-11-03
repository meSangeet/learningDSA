#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

    void function(TreeNode* root, vector<int> &ans)
    {
        if(root){
        if(root->left)
        {
            function(root->left, ans);
        }
        ans.push_back(root->val);
        if(root->right)
        {
            function(root->right, ans);
        }
        }
        
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        function(root, ans);
        return ans;
    }
};

//main function
int main()
{

    return 0;
}