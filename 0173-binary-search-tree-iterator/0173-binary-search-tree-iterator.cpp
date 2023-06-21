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
class BSTIterator {
public:
    
    stack<TreeNode*>st;
    void pushall(TreeNode*root){
       TreeNode*curr=root;
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;//as we want smallest element on top of the stack
        }
    }
    BSTIterator(TreeNode* root) {
        pushall(root);  //push all the elemnets in stack
         
        
    }
    
    int next() {
        
        TreeNode*ans=st.top();
        st.pop();
        pushall(ans->right);
         return ans->val;
    }
    
    bool hasNext() {
        if(st.size()){
             return true;
        
        }
        else{
           return false;
        }
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */