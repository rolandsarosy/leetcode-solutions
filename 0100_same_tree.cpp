// https://leetcode.com/problems/same-tree/description/
// O(n) space and time complexity with a BFS iterative approach. O(n) space complexity only, as we're only storing partial trees, and never two complete trees.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        deque<TreeNode*> pQueue;
        deque<TreeNode*> qQueue;

        pQueue.push_back(p);
        qQueue.push_back(q);

        while (pQueue.size() > 0 && qQueue.size() > 0) {
            TreeNode* pNode = pQueue.front();
            pQueue.pop_front();

            TreeNode* qNode = qQueue.front();
            qQueue.pop_front();

            if (pNode->val != qNode->val) return false;

            if ((pNode->left == nullptr) != (qNode->left == nullptr)) return false;  // One exists, the other doesn't
            if ((pNode->right == nullptr) != (qNode->right == nullptr)) return false;

            if (pNode->left && qNode->left) {
                pQueue.push_back(pNode->left);
                qQueue.push_back(qNode->left);
            }

            if (pNode->right && qNode->right) {
                pQueue.push_back(pNode->right);
                qQueue.push_back(qNode->right);
            }
        }

        return true;
    }
};
