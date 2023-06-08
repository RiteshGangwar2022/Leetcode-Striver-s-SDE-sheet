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
    ListNode* reverseList(ListNode* head) {
         
        
        //both solutions works in O(n)
        
        //if there is no or one element in linked list
       /* if(head==NULL || head->next==NULL){
            return head;
        }
        
        
        //else reverse whole linked list except head
        ListNode*ans=reverseList(head->next);
        ListNode*tail=head->next; //getting last node of reverse linked list
        tail->next=head; //adding head to last node of reverse list
        head->next=NULL;
        return ans;*/
        
        //iterative way to reverse linked list
        
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*nexti=NULL;
        while(curr!=NULL){
            nexti=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nexti;
        }
        return prev;
    } 
};