//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insertele(stack<int>&s,int ele){
    
    if(s.size()==0 || s.top()<=ele){
        
        s.push(ele);
        return;
    }
    
    int top=s.top();
    s.pop();
    insertele(s,ele);
    s.push(top);
      
}
void SortedStack :: sort()
{
   //Your code here
   /*one app=>use min-prioriyt queue, push all the elements , and than , push back into stack again*/
   
   //but here we need to sort recusrively
    
    if(s.size()==1){
        
        return;
    }
   
    int top=s.top();
    s.pop();
    sort();
    insertele(s,top);
    
   
}