//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
          //one app->use two loops  TC =>O(n^2)
          // another using stack , TC =>O(n) and SC =>O(n)
          
          //stack will keep track of largest element than arr[i]
          
          stack<long long>s;
          s.push(-1);
          int k=n-1;
          vector<long long>ans(n);
          
          for(int i=n-1;i>=0;i--){
              
                while(s.size()!=0 && s.top()<=arr[i]){
                    s.pop();
                }
                
                if(s.size()==0){
                    ans[k--]=-1;
                }
                else{
                    ans[k--]=s.top();
                }
                
                s.push(arr[i]);
          }
          return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends