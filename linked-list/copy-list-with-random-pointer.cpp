// Problem: Copy List with Random Pointer
// Link: https://leetcode.com/problems/copy-list-with-random-pointer
// Approach: Duplicating nodes of the list, O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return nullptr;
        }

        Node* curr = head;
        while(curr) {
            Node* node = new Node(curr->val);
            node->next = curr->next;
            curr->next = node;
            curr = curr->next->next;
        }

        curr = head;
        while(curr) {
            if(curr->random) {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        curr = head;
        Node* copyHead = head->next;
        Node* copyCurr = copyHead;

        while (curr) {
            curr->next = curr->next->next;
            if (copyCurr->next) {
                copyCurr->next = copyCurr->next->next;
            }

            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return copyHead;
    }
};
