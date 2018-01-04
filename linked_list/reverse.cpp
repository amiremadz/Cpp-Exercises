/*
Reverse a singly linked list.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current  = head;
        ListNode* previous = nullptr;
        ListNode* next     = nullptr;
        
        while(current){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;    
        return newhead;
    }
};