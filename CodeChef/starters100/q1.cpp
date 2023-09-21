#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n; string s; cin>>s;
	    int ind = 0;
	    for(int i = 0; i<n; i++)
	    {
	        if(s[i] == '1')
	        {
	            ind = i;
	            break;
	        }
	    }
	    
	    if(ind < (n-2))
	    {
	        for(int i = ind+1; i<n; i++)
	        {
	            s[i] = '0';
	        }
	    }
	    
	    cout<<s<<endl;
	}
	return 0;
}
