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
    int maxDepth(TreeNode* root) {
        //bfs solution'
        // not iterative (uses stack)
        // we keep repalcing the children with the level of depth
        if (!root) return 0;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size(); // q.size() in for loop is bad because were popping q so it changes size
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) {q.push(node->left);}
                if (node->right != nullptr) {q.push(node->right);}
                
            }
            level++;
        }
        return level;
    }
};

// o n time complexity

// recursively

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(max->right));
    }
};