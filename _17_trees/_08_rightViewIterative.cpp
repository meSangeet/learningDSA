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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
        {
            return ans;
        }

        int lev = 0;

        stack<pair<TreeNode*,int>> st;
        st.push({root, 1});
        while(!st.empty())
        {
            pair<TreeNode*, int> p = st.top();
            st.pop();
            int level = p.second;
            TreeNode* temp = p.first;
            if(level > lev)
            {
                ans.push_back(temp->val);
                lev = level;
            }

            if(temp->left)
            {
                st.push({temp->left, level+1});
            }
            if(temp->right)
            {
                st.push({temp->right, level+1});
            }
        }
        return ans;
    }
};

//main function
int main()
{

    return 0;
}