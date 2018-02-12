/*
160. Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_A = 0;
        int len_B = 0;
        
        len_A = length(headA);
        len_B = length(headB);
        
        if(len_B > len_A){
            ListNode* temp = headA;
            int tmp;
            
            temp = headA;
            headA = headB;
            headB = temp;
            
            tmp = len_A;
            len_A = len_B;
            len_B = tmp;
        }
        
        int diff = len_A - len_B;
        
        while(diff){
            headA = headA->next;
            --diff;
        }
        
        while(headA){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
    
private:
    int length(ListNode* head){
        int len = 0;
        if(head == nullptr){
            return len;
        }

        while(head){
            ++len;
            head = head->next;
        }
        return len;
    }
    
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        
        if(!ptr1 || !ptr2){
            return nullptr;
        }
        
        while(ptr1 && ptr2 && ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
            // Any time they collide or reach end together without colliding 
        	// then return any one of the pointers.
            if(ptr1 == ptr2){
                return ptr1;
            }

            // If one of them reaches the end earlier then reuse it 
        	// by moving it to the beginning of other list.
        	// Once both of them go through reassigning, 
        	// they will be equidistant from the collision point.            
            if(ptr1 == nullptr){
                ptr1 = headB;
            }
            
            if(ptr2 == nullptr){
                ptr2 = headA;
            }            
        }
        return ptr1;
    }
};