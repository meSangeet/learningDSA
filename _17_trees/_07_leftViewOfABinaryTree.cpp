#include <bits/stdc++.h>
using namespace std;
#define ll long long

void function1(vector<int> &ans, Node* temp, int level, int &lev)
{
    if(level > lev)
    {
        ans.push_back(temp->data);
        lev = level;
    }
    if(temp->left)
    {
        function1(ans, temp->left, level+1, lev);
    }
    if(temp->right)
    {
        function1(ans, temp->right, level+1, lev);
    }
    return;
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   int lev = 0;
   if(!root) return {};
   vector<int> ans;
   function1(ans, root, 1, lev);
   return ans;
}

//main function
int main()
{

    return 0;
}