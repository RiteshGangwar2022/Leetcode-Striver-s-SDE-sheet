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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL ||head->next==NULL || k==0){
            return head;
        }
        
        //move last node to first for k times
        //TC =>O(n*k), where n is the number of nodes in linked list
       /* for(int i=0;i<k;i++){
              ListNode*temp=head;
            
              while(temp->next->next!=NULL){
                  temp=temp->next;
              }
               ListNode*last=temp->next;
               temp->next=NULL;
               last->next=head;
                head=last;
        }
        return head;*/
        
        //we can see for k>length of linked list, we need to rotate it by k%len
        
        int size=len(head);
        
        k=k%size; //for k>size
        int end=size-k;
        ListNode*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;//to make it circular linked list
        
        int i=0;
        while(i<end){
             temp=temp->next;
              i++;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
           
    }
};