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
    TreeNode* invertTree(TreeNode* root) {
        //depth first search recursively
        if (root == 0) {return {};}
        auto tmp = left;

        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// iterative o(n)

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //queue solution iteratively
        if (root == nullptr) {return nullptr;}
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            swap(node->left,node->right);
            if(node->left != nullptr) {q.push(node->left);}
            if(node->right != nullptr) {q.push(node->right);}
        }
        return root;
    }
};