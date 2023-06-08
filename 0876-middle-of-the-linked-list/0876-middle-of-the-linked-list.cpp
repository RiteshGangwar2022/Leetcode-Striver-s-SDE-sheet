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
       int len(ListNode*head){
        int count=0;
        while(head!=NULL){
             head=head->next;
            count++;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        
        //finding middle by length TC=>O(n)
        if(head->next==NULL){
                return head;
        }
        
        int count=len(head);
        
        /*int t=count/2;
        int i=0;
        ListNode*temp=head;
        
        while(i<t){
             temp=temp->next;
            i++;
        }
        return temp;
        */
        
        //two pointer algorithm
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(count%2!=0){
            return slow;
        }
        else{
            return slow->next;//as we need second of the two middle in case of even len
        }
        
        
    }
};