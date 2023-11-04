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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        vector<int> currLevel; // this will contain the nodes of the current level
        int maxLevel = 0; //this will contain the last level traversed till now

        queue<pair<TreeNode*, int>> q;

        q.push({root,1});

        while(!q.empty())
        {
            pair<TreeNode*,int> temp = q.front();
            int data = temp.first->val;
            int lev = temp.second;
            q.pop();
            if(maxLevel == 0)
            {
                ans.push_back({data});
                maxLevel = 2;
            }else{
                if(lev > maxLevel)
                {
                    ans.push_back(currLevel);
                    maxLevel = lev;
                    currLevel.clear();
                    currLevel.push_back(data);
                }else{
                    currLevel.push_back(data);
                }
            }

            if(temp.first->left)
            {
                q.push({temp.first->left, lev+1});
            }
            if(temp.first->right)
            {
                q.push({temp.first->right, lev+1});
            }
        }
        if(currLevel.size())
        ans.push_back(currLevel);
        return ans;
    }
};

//main function
int main()
{

    return 0;
}