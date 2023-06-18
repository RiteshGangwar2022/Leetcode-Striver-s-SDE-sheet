/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
      TreeNode* prev=NULL;
public:
    void flatten(TreeNode* root) {
        
        //one approach is to save preorder traversal in a vector and create a link list from it
        //but we cannot create new linked list
        
         //using recursion
        //TC =>o(n) and Sc=>O(n)
      /*  if(root==NULL){

            return;
        }
        
        
        flatten(root->right);
        flatten(root->left);
        //make connection to right node
        root->right=prev;
        //break connection from left node
        root->left=NULL;
        prev=root;//update prev to root*/
        
        //iterative solution
        
        //take a stack ,push root into it, push roots left and right part , point curr->right to st.top(), 
        
        //TC =>O(n) and SC=>O(n)
        
       /* stack<TreeNode*>s;
        s.push(root);
        TreeNode*curr=root;
        while(curr!=NULL){
            
            curr=st.top();
            st.pop();
            if(curr->right){
                s.push(curr->right);
            }
            if(curr->left){
                s.push(curr->left);
            }
            
            if(s.size()){
                  curr->right=st.top();
            }
            curr->left=NULL;
        }*/
        
        //morris traversal =>   TC =>O(n) and Sc(1)
        
        TreeNode*curr=root;
        while(curr!=NULL){
            
            if(curr->left){
                  
                TreeNode*prev=curr->left;
                while(prev->right!=NULL){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
            }
            curr->left=NULL;
            curr=curr->right;
        }
           
    }
};
