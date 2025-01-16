// https://leetcode.com/problems/merge-two-sorted-lists/

// O(n+m) time complexity with a constant space complexity. Iterative solution.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(INT_MIN);
        ListNode* tail = dummyNode;

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        while (ptr1 && ptr2) {
            if (ptr1->val < ptr2->val) {
                tail->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                tail->next = ptr2;
                ptr2 = ptr2->next;
            }

            tail = tail->next;
        }

        tail->next = ptr1 ? ptr1 : ptr2;

        return dummyNode->next;
    }
};
