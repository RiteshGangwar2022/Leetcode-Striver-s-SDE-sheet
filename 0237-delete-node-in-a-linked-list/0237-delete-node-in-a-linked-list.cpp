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
    void deleteNode(ListNode* node) {
        
        //simple, just remove next node by copying value to node to be remove
        
        //2 step process
        
        //1)copy data of next node to this node
        //2)point this node next to next->next (to skip the 1 element)
        
        node->val=node->next->val;
        node->next=node->next->next;
        
        
    }
};