// https://leetcode.com/problems/diameter-of-binary-tree/
// O(n) space and time complexity solution using a DFS search algorithm
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
    int diameterOfBinaryTree(TreeNode* root) {
        dfsTravel(root);

        return currentMaxDiameter;
    }
private: 
    int currentMaxDiameter = 0;

    // @returns: The height of the tree
    int dfsTravel(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftHeight = dfsTravel(node->left);
        int rightHeight = dfsTravel(node->right);

        int diameterOfTree = leftHeight + rightHeight; // Diameter of a tree = height of the left and right subtrees

        if (diameterOfTree > currentMaxDiameter) {
            currentMaxDiameter = diameterOfTree;
        }

        return (1 + max(leftHeight, rightHeight));
    }
};
