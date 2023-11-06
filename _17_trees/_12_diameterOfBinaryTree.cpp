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
    int height(TreeNode* temp)
    {
        if(temp == NULL)
        {
            return 0;
        }

        return max(height(temp->left), height(temp->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        return max({ld,rd,lh+rh});
    }
};

//main function
int main()
{

    return 0;
}