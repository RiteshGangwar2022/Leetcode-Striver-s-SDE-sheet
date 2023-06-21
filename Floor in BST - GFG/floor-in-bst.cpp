//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

int floor(Node *root, int x);

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << floor(root, s) << "\n";
    }
}

// } Driver Code Ends


// Function to search a node in BST.


void helper(Node*root,vector<int>&ans){
    
    if(root==NULL){
        return;
    }
    
    helper(root->left,ans);
    ans.push_back(root->data);
    helper(root->right,ans);
}
int floor(Node* root, int x) {
    // Code here
   
    vector<int>ans;
    helper(root,ans);
    int size=ans.size();
     if(ans[0]>x){
        return -1;
    }
    
    //lower_bound gives the index of the element which is equal to or greater than x
    int index=lower_bound(ans.begin(),ans.end(),x)-ans.begin();
    
     if(index>=ans.size()){
         
         return ans[size-1];
     }
     else if(ans[index]==x){
        return ans[index];
     }
     else{
         return ans[index-1];
     }
    
}
