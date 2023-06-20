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
    
   /* TreeNode*helper(vector<int>&preorder,int s,int e){
        
        
        if(s>e){
            return NULL;
        }
        
        int mid=(s+e)/2;
        
        TreeNode*root=new TreeNode(preorder[mid]);
        root->left=helper(preorder,s,mid-1);
        root->right=helper(preorder,mid+1,e);
        return root;

    }*/
    
    TreeNode*helper(vector<int>&preorder,int mini,int maxi,int &i){
        
        
        if(i>=preorder.size()){
                return NULL;
        }
        
        //cheking bst validity by left-right range
        if(preorder[i]<mini || preorder[i]>maxi){
            
              return NULL;
        }
        
        TreeNode*root=new TreeNode(preorder[i++]);
        root->left=helper(preorder,mini,root->val,i);
        root->right=helper(preorder,root->val,maxi,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        
        //first app=> sort the preorder and, makes in order, solv it as BST from sorted array
       /* sort(preorder.begin(),preorder.end());
        
        TreeNode*ans=helper(preorder,0,preorder.size()-1);
        return ans;*/
        
        //another app=>use left-right range
        int i=0;
        TreeNode*ans=helper(preorder,INT_MIN,INT_MAX,i);
        return ans;
        
    }
};