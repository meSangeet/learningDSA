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
    void PT(vector<int> &ans, TreeNode* temp)
    {
        if(temp)
        {
            ans.push_back(temp->val);
            if(temp->left) PT(ans, temp->left);
            if(temp->right) PT(ans, temp->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        PT(ans, root);
        return ans;
    }
};

//main function
int main()
{

    return 0;
}