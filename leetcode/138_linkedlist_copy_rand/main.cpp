/*
138. Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr){
            return nullptr;
        }
        
        RandomListNode *clone = nullptr;
        RandomListNode *orig  = head;
        unordered_map<RandomListNode *, RandomListNode *> hash;        
        
        while(orig){
            hash[orig] = new RandomListNode(orig->label);
            orig = orig->next;
        }
        
        orig = head;
        while(orig){
            clone = hash[orig];
            clone->next   = hash[orig->next];
            clone->random = hash[orig->random];
            orig = orig->next;
        }
        
        return hash[head];        
    }