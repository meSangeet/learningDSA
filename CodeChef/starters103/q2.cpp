#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--)
	{
	    vector<int> a(3), b(3);
	    for(int i = 0; i<3; i++)
	    {
	        cin>>a[i];
	    }
	    for(int i = 0; i<3; i++)
	    {
	        cin>>b[i];
	    }
	    
	    sort(a.begin(), a.end(), greater<int>());
	    sort(b.begin(), b.end(), greater<int>());
	    
	    int A = 0, B = 0;
	    A = 100*a[0] + 10*a[1] + a[2];
	    B = 100*b[0] + 10*b[1] + b[2];
	    
	    if(A == B)
	    {
	        cout<<"Tie"<<endl;
	    }else{
	        if(A > B)
	        {
	            cout<<"Alice"<<endl;
	        }else{
	            cout<<"Bob"<<endl;
	        }
	    }
	}
	return 0;
}