// Problem: Add Two Numbers
// Link: https://leetcode.com/problems/add-two-numbers
// Approach: O(n + m)


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addRecursive(l1, l2, 0);
    }

private:
    ListNode* addRecursive(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && carry == 0) {
            return nullptr;
        }

        int sum = carry;
        if (l1) {
            sum += l1->val;
        }
        if (l2) {
            sum += l2->val;
        }

        ListNode* node = new ListNode(sum % 10);
        node->next = addRecursive(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, sum / 10);

        return node;
    }
};
