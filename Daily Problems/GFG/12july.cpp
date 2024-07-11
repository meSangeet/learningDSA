class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        // Your code here
        if(target == root->data && !root->right && !root->left)
        {
            return true;
        }
        bool a = false, b = false;
        if(target > root->data && root->left)
            a = hasPathSum(root->left, target - root->data);
            
        if(target > root->data && root->right)
            b = hasPathSum(root->right, target - root->data);
        
        if(a == false && b == false) return false;
        return true;
    }
};