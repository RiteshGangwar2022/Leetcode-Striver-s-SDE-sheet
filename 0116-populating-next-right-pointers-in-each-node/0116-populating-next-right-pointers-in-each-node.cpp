/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
          if(root==NULL){
              return NULL;
          }
        // TC=>O(n) and SC=>O(n) => do dry run for this algo ,it is simple we are just taking the currnext=NULL and , update currnext with curr
       /* queue<Node*>q;
        q.push(root);
        while(q.size()){
            
             int size=q.size();
              Node*nextcurr=NULL;
              for(int i=0;i<size;i++){
                   
                  Node*curr=q.front();
                  q.pop();
                  curr->next=nextcurr;
                  nextcurr=curr;
                  if(curr->right){
                      q.push(curr->right);
                  }
                  if(curr->left){
                      q.push(curr->left);
                  }
              }
        }
        return root;
        */
        
        //iterative version TC=>O(n) , and SC=>O(1)
        
        Node*curr=root;
        while(curr->left){
            
              Node*temp=curr;
            while(curr!=NULL){
                 
                  curr->left->next=curr->right;
                if(curr->next){
                    curr->right->next=curr->next->left;
                }
                curr=curr->next;
            }
            curr=temp->left;
        }
          return root;
    }
};