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
    
    class info{
        
        public:
        
        int mini;
        int maxi;
        int sum;
        bool isbst;
       
    };
    
    info helper(TreeNode*root,int&sum){
        
        if(root==NULL){
            
            return {INT_MAX,INT_MIN,0,true};
        }
        
        info lefts=helper(root->left,sum);
        info rights=helper(root->right,sum);
        
        info curr;
        curr.mini=min(root->val,lefts.mini);
        curr.maxi=max(root->val,rights.maxi);
        curr.sum=root->val+lefts.sum+rights.sum;
        
        if((lefts.isbst)&&(rights.isbst)&&(root->val>lefts.maxi&&root->val<rights.mini)){
            
            curr.isbst=true;
        
        }
        else{
            curr.isbst=false;
        }
        
        if(curr.isbst){
               sum=max(sum,curr.sum);
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        
        int sum=0;
        info ans=helper(root,sum);
        return sum;
    }
};