// https://leetcode.com/problems/subtree-of-another-tree/
// O(n * m) time complexity where n is the size of root tree and m is the size of the subtree. For each node in the tree, we're checking the created subtree with the given subtree. 
// O(max(n, m)) space complexity. It'd be O(n+m) for 2 highly skewed trees, but the calls are not simultaneous and the isSubtree recursion resumes only after isSameTree completes, the actual maximum call stack at any point is O(max(n, m)).   
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        if (isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool isSameTree(TreeNode* pNode, TreeNode* qNode) {
        if (pNode == nullptr && qNode == nullptr) return true;
        if (pNode == nullptr || qNode == nullptr) return false;

        return (pNode->val == qNode->val) && isSameTree(pNode->left, qNode->left) && isSameTree(pNode->right, qNode->right);
    }
};
