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
public:
    
    void preorder(TreeNode*root,vector<int>&ans){
        
        
        //TC =>o(N)
       /* if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);*/
        
        //iterative version
        
        stack<TreeNode*>st;
        TreeNode*curr=root;
        while(true){
                
            if(curr!=NULL){
               ans.push_back(curr->val);
                st.push(curr);
                curr=curr->left;
            }
            else{ 
                if(st.size()==0){
                    
                    break;
                }
                curr=st.top();
                st.pop();
                curr=curr->right;
            }
        
        }
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
                 return ans;
        }
        
        preorder(root,ans);
        return ans;
    }
};