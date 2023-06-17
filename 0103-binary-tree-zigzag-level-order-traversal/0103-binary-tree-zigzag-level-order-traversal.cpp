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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
              if(root==NULL){
                  return ans;
              }
              bool lefttoright=true;
              queue<TreeNode*>q;
              q.push(root);
              while(q.size()){
                      
                      int size=q.size();
                      vector<int>temp(size);
                      for(int i=0;i<size;i++){
                           auto it=q.front();
                           q.pop();
                            
                            int index=lefttoright?i:size-1-i;
                            temp[index]=it->val;
                            if(it->left){
                                q.push(it->left);
                            }
                            if(it->right){
                                q.push(it->right);
                            }
                      }
                      lefttoright=!lefttoright;
                      ans.push_back(temp);
              }
              return ans;
    }
};