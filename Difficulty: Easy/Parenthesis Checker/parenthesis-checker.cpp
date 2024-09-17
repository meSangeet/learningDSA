//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool isStart(char x){
        return x == '{' || x == '[' || x == '(';
    }
    
    bool check(char cur, char last){
        return (cur == ']' and last == '[') or
        (cur == '}' and last == '{') or
        (cur == ')' and last == '(');
    }
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        for(auto a:x){
            if(isStart(a)){
                s.push(a);
            }else{
                if(s.empty()) return false;
                if(check(a,s.top())) s.pop();
                else return false;
            }
        }
    return s.empty();
    }
    

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends