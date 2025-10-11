// Problem: Reverse Linked List
// Link: https://leetcode.com/problems/reverse-linked-list
// Approach: Swap pointers, O(n)

var reverseList = function(head) {
    let current = head, next = null, prev = null;

    while(current){
        next = current.next;
        current.next = prev;
        prev = current;
        current = next;
    }

    return prev;
};
