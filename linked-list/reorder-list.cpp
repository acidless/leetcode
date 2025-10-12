// Problem: Reorder List
// Link: https://leetcode.com/problems/reorder-list/
// Approach: O(n)


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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while (second) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        ListNode* firstPart = head;
        ListNode* secondPart = prev;

        ListNode* start = head;
        int i = 0;
        while (secondPart) {
            ListNode* tmp1 = firstPart->next;
            ListNode* tmp2 = secondPart->next;

            firstPart->next = secondPart;
            secondPart->next = tmp1;

            firstPart = tmp1;
            secondPart = tmp2;
        }
    }
};
