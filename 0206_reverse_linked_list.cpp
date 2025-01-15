// https://leetcode.com/problems/reverse-linked-list


// O(n) | O(1) solution using an iterative method.
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
    ListNode* reverseList(ListNode* head) {
        ListNode* previousNode = nullptr;
        ListNode* currentNode = head;

        while (currentNode != nullptr) {
            ListNode* nextNode = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }

        return previousNode;
    }
};

// O(n) time and space complexity recursive solution
class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* previous = nullptr) {
        if (head == nullptr) {
            return previous;
        }

        ListNode* nextHead = head->next;
        head->next = previous;
        return reverseList(nextHead, head);
    }
};
