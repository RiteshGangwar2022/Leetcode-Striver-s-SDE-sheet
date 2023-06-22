//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    
    class info{
        public:
        int mini;
        int maxi;
        int size;
        bool isbst;
    };
    
    /*class LBST{
         public:
         int leftmax,rightmin,size;
         LBST(int leftdata,int rightdata, int size){
             
             this->leftmax=leftdata;
             this->rightmin=rightdata;
             this->size=size;
         }
    };
    
    
    
    //without using extra variable
    LBST helper(Node*root){
        
        if(root==NULL){
            
            return {INT_MAX,INT_MIN,0};
        }
        
        LBST left=helper(root->left);
        LBST right=helper(root->right);
        
        int leftmaxi=max(root->data,max(left.leftmax,right.leftmax));
        int rightmini=min(root->data,min(left.rightmin,right.rightmin));
        int size=left.size+right.size+1;
        
        if(root->data<leftmaxi || root->data>rightmini){
              
               return LBST(INT_MAX,INT_MIN,max(left.size,right.size));
               
        }
        
        return LBST(leftmaxi,rightmini,size);
        
    }*/
    info helper(Node*root,int &maxsize){
        
        if(root==NULL){
            return {INT_MAX,INT_MIN,0,true};
        }
        
        info left=helper(root->left,maxsize);
        info right=helper(root->right,maxsize);
        
        info currnode;
        currnode.size=left.size+right.size+1;
        currnode.mini=min(root->data,left.mini);
        currnode.maxi=max(root->data,right.maxi);
        
        if( left.isbst && right.isbst && (root->data<right.mini && root->data>left.maxi)){
            currnode.isbst=true;
        }
        else{
            currnode.isbst=false;
        }
        
        if(currnode.isbst){
            maxsize=max(maxsize,currnode.size);
        }
          return currnode;
        
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	//app->check BST for every node ,take max size of bSt in ans
    	
    	//another app->is to use class to get min and max,size and is bst at same time to get time complexity O(N) and sc(H)
    	
    	int maxsize=0;
    	info temp=helper(root,maxsize);
        return maxsize;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends