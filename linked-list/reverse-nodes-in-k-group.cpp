// Problem: Reverse Nodes in k-Group
// Link: https://leetcode.com/problems/reverse-nodes-in-k-group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* firstInGroup = head;
        ListNode* lastInPrevGroup = nullptr;
        ListNode* current = head;
        ListNode* newHead = nullptr;

        int currentK = 0;

        while(current) {
            currentK++;
            current = current->next;

            if(currentK == k) {
                auto sublistHead = reverseSublist(firstInGroup, current, k);

                if(lastInPrevGroup) {
                    lastInPrevGroup->next = sublistHead;
                }

                if(!newHead) {
                    newHead = sublistHead;
                }

                currentK = 0;
                lastInPrevGroup = firstInGroup; 
                firstInGroup = current;
            }
        }

        return newHead;
    }
private:
    ListNode* reverseSublist(ListNode* head, ListNode* afterNode, int k) {
        ListNode* prev = afterNode;
        ListNode* next = nullptr;
        ListNode* current = head;

        int idx = 0;
        while(idx < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;

            idx++;
        }

        return prev;
    }
};
