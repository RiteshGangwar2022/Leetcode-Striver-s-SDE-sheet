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
    
   /* int getpos(vector<int>&inorder,int x){
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==x){
            return i;
        }
    }
    return -1;
}*/
    
    //we can also create mapping of node-val to index of inorder
    void mapping(map<int,int>&mp,vector<int>&inorder){

                for(int i=0;i<inorder.size();i++){
                    
                    mp[inorder[i]]=i;
                }
    }
    
TreeNode*helper(int &index,vector<int>&preorder,vector<int>&inorder,int start,int end,map<int,int>&mp){
       
       if(start>end || index>preorder.size()){
           return NULL;
       }
        int ele=preorder[index++];
       TreeNode*root=new TreeNode(ele);
    
      // int pos=getpos(inorder,ele);
    int pos=mp[ele];
       root->left=helper(index,preorder,inorder,start,pos-1,mp);
       root->right=helper(index,preorder,inorder,pos+1,end,mp);
       return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        mapping(mp,inorder);
          int index=0;
          TreeNode*ans=helper(index,preorder,inorder,0,inorder.size()-1,mp);
          return ans;

    }
};