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

         count++;
        head=head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
           int size=len(head);
        
        if(head->next==NULL&&n==1){
            return NULL;
        }
        
        int count=size-n;
        if(count<0){
            return head;
        }
        else if(count==0){
            return head->next;
        }
        ListNode*temp=head;
        int i=0;
        while(i<count-1){
           
            temp=temp->next;
            i++;
        }
        temp->next=temp->next->next;
        return head;
        
    }
};