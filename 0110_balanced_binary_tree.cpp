// https://leetcode.com/problems/balanced-binary-tree/
// O(n) solution USING THE FAMOUS, EXCEPTION-DRIVEN DEVELOPMENT! It's the new hot shit after test-driven development. Jokes aside, this idea is disgusting, but I literally solved the problem in 3 minutes with it so I guess I cannot complain. I'm a horrible person.
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
    bool isBalanced(TreeNode* root) {
        try {
            dfsTravel(root);
        } catch (exception exception) {
            // lmao, exception-driven development
            return false;
        }

        return true;
    }

private: 
    // @returns the height of the tree
    int dfsTravel(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftHeight = dfsTravel(node->left);
        int rightHeight = dfsTravel(node->right);

        if (abs(rightHeight - leftHeight) > 1) {
            throw std::invalid_argument("Height issue");
        }

        return 1 + max(leftHeight, rightHeight);
    }
};
