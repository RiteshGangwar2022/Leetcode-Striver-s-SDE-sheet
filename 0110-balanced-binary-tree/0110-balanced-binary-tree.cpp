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
    
    /*int height(TreeNode*root){
        
        if(root==NULL){
            return 0;
        }
        
        return max(height(root->left),height(root->right))+1;
        
    }*/
    
    pair<bool,int> helper(TreeNode*root){
        
        if(root==NULL){
            
            pair<bool,int>res;
            res={true,0};
            return res;
        }
        
        pair<bool,int>left=helper(root->left);
        pair<bool,int>right=helper(root->right);
         
        int lh=left.second;
        int rh=right.second;
           bool leftbal=left.first;
           bool rightbal=right.first;
            int height=max(lh,rh)+1;
            
            pair<bool,int>res;
             res.second=height;
            if((abs(lh-rh)<=1)&&rightbal&&leftbal){
                res.first=true;
            }
             else{
                 res.first=false;
             }
            return res;
                                   
    }
    bool isBalanced(TreeNode* root) {
        
        
        //TC =>O(n^2) and SC=>O(H)
       /* if(root==NULL){
            return true;
        }
        
     
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        int lh=height(root->left);
        int rh=height(root->right);
        if((abs(lh-rh)<=1)&&left&&right){
             return true;
        }
        else{
            return false;
        }*/
        pair<bool,int>ans=helper(root);    //pair<isbst,height>
        return ans.first;
        
        
    }
};