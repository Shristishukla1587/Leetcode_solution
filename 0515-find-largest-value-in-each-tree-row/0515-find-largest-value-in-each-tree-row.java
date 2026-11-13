/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public List<Integer> largestValues(TreeNode root) {

        // Store the maximum value of each level
        List<Integer> result = new ArrayList<>();

        // Handle empty tree
        if (root == null) {
            return result;
        }

        // Create a queue for BFS
        Queue<TreeNode> q = new LinkedList<>();

        // Insert root node
        q.offer(root);

        // Traverse level by level
        while (!q.isEmpty()) {

            // Number of nodes at current level
            int size = q.size();

            // Initialize maximum
            int max = Integer.MIN_VALUE;

            // Process all nodes of current level
            for (int i = 0; i < size; i++) {

                TreeNode curr = q.poll();

                // Update maximum
                max = Math.max(max, curr.val);

                // Add left child
                if (curr.left != null) {
                    q.offer(curr.left);
                }

                // Add right child
                if (curr.right != null) {
                    q.offer(curr.right);
                }
            }

            // Store maximum of current level
            result.add(max);
        }

        return result;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna