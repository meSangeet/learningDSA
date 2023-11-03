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
    void PostT(vector<int>&ans, TreeNode* temp)
    {
        if(temp)
        {
            if(temp->left)
            {
                PostT(ans, temp->left);
            }
            if(temp->right)
            {
                PostT(ans, temp->right);
            }
            ans.push_back(temp->val);
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        PostT(ans, root);
        return ans;   
         }
};

//main function
int main()
{

    return 0;
}