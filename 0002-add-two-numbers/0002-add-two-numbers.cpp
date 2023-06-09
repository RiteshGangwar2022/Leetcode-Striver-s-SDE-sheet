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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
             //tc=>O(max(n,m)) and sc=>O(max(n,m))
        ListNode*ans=new ListNode(-1);
        ListNode*newnode=ans;
        
        int carry=0;
        while(l1!=NULL&&l2!=NULL){
            
            int num=l1->val+l2->val+carry;
            carry=num/10;
            int newval=num%10;
            ListNode*temp=new ListNode(newval);
            newnode->next=temp;
            newnode=newnode->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            
            int num=l1->val+carry;
            carry=num/10;
            int newval=num%10;
            ListNode*temp=new ListNode(newval);
            newnode->next=temp;
            newnode=newnode->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            
            int num=l2->val+carry;
            carry=num/10;
            int newval=num%10;
            ListNode*temp=new ListNode(newval);
            newnode->next=temp;
            newnode=newnode->next;
            l2=l2->next;
        }
        if(carry){
            ListNode*temp=new ListNode(carry);
            newnode->next=temp;
            newnode=newnode->next;
        }
        return ans->next;
        
    }
};