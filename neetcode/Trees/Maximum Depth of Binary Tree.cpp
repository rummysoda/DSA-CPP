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
        //bfs solution
        // we keep repalcing the children with the level of depth
        if (!root) return 0;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size(); // i dont undestand why s.sizehere isnt same if i put q.size( ) in the for loop
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