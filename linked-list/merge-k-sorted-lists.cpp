// Problem: Merge k Sorted Lists
// Link: https://leetcode.com/problems/merge-k-sorted-lists
// Approach: Merging lists one by one, O(n * k)


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* currentList = nullptr;

        for(auto& list : lists) {
            currentList = mergeTwoLists(currentList, list);
        }

        return currentList;
    }
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* node = &dummy;

        while(list1 || list2) {
            if(list1 && !list2) {
                node->next = list1;
                list1 = list1->next;
            } else if(list2 && !list1) {
                node->next = list2;
                list2 = list2->next;
            } else {
                if(list1->val > list2->val) {
                    node->next = list2;
                    list2 = list2->next;
                } else {
                    node->next = list1;
                    list1 = list1->next;
                }
            }

            node = node->next;
        }

        return dummy.next;
    }
};
