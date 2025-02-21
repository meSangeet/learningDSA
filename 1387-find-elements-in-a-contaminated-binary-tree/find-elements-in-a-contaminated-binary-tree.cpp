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
class FindElements {
    TreeNode* root;
public:
    FindElements(TreeNode* root) {
        this->root = root;
    }
    
    bool func(TreeNode* curr, int target, int value){
        if(value == target) return true;
        bool leftAns = false, rightAns = false;
        if(curr->left){
            leftAns = func(curr->left, target, 2*value + 1);
        }
        if(curr->right){
            rightAns = func(curr->right, target, 2*value + 2);
        }

        return leftAns or rightAns;
    }

    bool find(int target) {
        return func(root, target, 0);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */