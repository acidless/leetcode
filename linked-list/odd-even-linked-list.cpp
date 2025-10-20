// Problem: Odd Even Linked List
// Link: https://leetcode.com/problems/odd-even-linked-list
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) {
            return nullptr;
        }

        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* oddHead = nullptr;

        int size = 1;
        while(current && current->next) {
            prev = current;
            auto next = current->next;
            current->next = current->next->next;
            current = next;
            if(!oddHead) {
                oddHead = current;
            }

            size++;
        }

        if(size & 1) {
            current->next = oddHead;
        } else {
            prev->next = oddHead;
        }

        return head;
    }
};
