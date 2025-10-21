// Problem: Maximum Twin Sum of a Linked List
// Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list
// Approach: Reversing half of a list, O(n)


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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* prev = nullptr;
        ListNode* fast = head;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* left = prev;
        int m = numeric_limits<int>::min();
        while(left && slow) {
            m = max(m, left->val + slow->val);
            left = left->next;
            slow = slow->next;
        }

        return m;
    }
};
