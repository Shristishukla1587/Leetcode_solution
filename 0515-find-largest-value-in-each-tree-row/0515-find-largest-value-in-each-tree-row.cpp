/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {

        // Store maximum value of each level
        vector<int> result;

        // Handle empty tree
        if (root == nullptr) {
            return result;
        }

        // Create queue for BFS
        queue<TreeNode*> q;

        // Insert root
        q.push(root);

        // Traverse level by level
        while (!q.empty()) {

            // Number of nodes at current level
            int size = q.size();

            // Initialize maximum
            int maxi = INT_MIN;

            // Process current level
            for (int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                // Update maximum
                maxi = max(maxi, curr->val);

                // Add left child
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }

                // Add right child
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }

            // Store maximum of current level
            result.push_back(maxi);
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna