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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        //TC =>O(n) and SC=>O(n)
       /* ListNode*ans=new ListNode(-1);
        ListNode*newnode=ans;
        
        while(list1!=NULL&&list2!=NULL){
            
              
            if(list1->val>=list2->val){
                  
                ListNode*temp=new ListNode(list2->val);
                newnode->next=temp;
                newnode=newnode->next;
                list2=list2->next;
            }
            else{
                ListNode*temp=new ListNode(list1->val);
                newnode->next=temp;
                newnode=newnode->next;
                list1=list1->next;
            }
        }
        if(list1!=NULL){
            newnode->next=list1;
            newnode=newnode->next;
        }
        if(list2!=NULL){
            newnode->next=list2;
            newnode=newnode->next;  
        }
        return ans->next;*/
        
        
        //use two pointers ,l1 and l2=>point l1 to smallest number and l2 to greater one.
        //move l1 till ,l1 is smaller than l2
        //TC =>O(n+m) and SC=>O(1)
        if(list1==NULL){
              return list2;
        }
        if(list2==NULL){
              return list1;
        }
       
        
        if(list1->val>list2->val){
              swap(list1,list2);
        }
       
        ListNode*res=list1;
        while(list1!=NULL&&list2!=NULL){
            
            ListNode*temp=NULL;
            
               while(list1!=NULL&&list1->val<=list2->val){
                   temp=list1;
                   list1=list1->next;
               }
            
            temp->next=list2;
            swap(list1,list2);
        }
        return res;
        
        
    }
};