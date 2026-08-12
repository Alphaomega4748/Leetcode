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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> values;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                values.push_back(node->val);

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }

            if (level % 2 == 0) {
                for (int i = 0; i < values.size(); i++) {
                    if (values[i] % 2 == 0)
                        return false;

                    if (i > 0 && values[i] <= values[i - 1])
                        return false;
                }
            }
            else {
                for (int i = 0; i < values.size(); i++) {
                    if (values[i] % 2 != 0)
                        return false;

                    if (i > 0 && values[i] >= values[i - 1])
                        return false;
                }
            }

            level++;
        }

        return true;
    }
};