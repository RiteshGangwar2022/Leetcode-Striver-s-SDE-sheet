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
    ListNode *detectCycle(ListNode *head) {
        
        //using map TC=>O(n) and SC=>O(n)
       /* unordered_set<ListNode*>st;//element,index
        ListNode*temp=head;
        while(temp){
            
            if(st.find(temp)!=st.end()){
                    return temp;
            }else{
                st.insert(temp);
                temp=temp->next;
            }
            
        }
        return NULL;*/
        
          if(head==NULL || head->next==NULL){
          return NULL;
      }
       ListNode*slow=head;
       ListNode*fast=head;
       while(fast!=NULL && fast->next!=NULL){
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast){
               break;
           }
       }
       if(slow!=fast){
           return NULL;
       }
       slow=head; 
          while(slow!=fast){
              slow=slow->next;
              fast=fast->next;
          }

          return slow;
    }
};