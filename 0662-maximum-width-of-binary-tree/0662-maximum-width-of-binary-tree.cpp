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
    int widthOfBinaryTree(TreeNode* root) {
        
        
        
        int ans=INT_MIN;
        
        queue<pair<TreeNode*,int>>q;//<root,index>
        q.push({root,0});
        while(q.size()){
            
            int minindex=q.front().second;//getting first node of  of a level as minindex
            int first,last;
            int size=q.size();
            for(int i=0;i<size;i++){
                
                int index=q.front().second-minindex; //getting mindex
                TreeNode*curr=q.front().first;
                q.pop();
                
                //to get first andd last node index of level
                if(i==0) {
                    first=index;
                }
                if(i==size-1){
                     last=index;
                }
                
                if(curr->left){

                     q.push({curr->left,(long long)2*index+1});
                }
                if(curr->right){
                           q.push({curr->right,2*index+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};