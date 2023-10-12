#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int t; cin>>t;
	while(t--)
	{
	    ll n,k; cin>>n>>k;
	    string s; cin>>s;

	int c1 = 0, c0 = 0;
	for(int i = 0; i<n; i++)
	{
	    if(s[i] == '0') c0++;
	    else c1++;
	}
    ll ans1 = 0, ans0 = 0;
	for(int i = 0; i<k; i++)
	{
	    int j = 0;
	    vector<char> temp;
	    ll no1 = 0, no0 = 0;
	    while((i + j*k) < n)
	    {
	        temp.push_back(s[i + k*j]);
	        
	        j++;
	        
	        if(temp.back() == '0') no0++;
	        else no1++;
	        
	    }
	    
	    if(no1 == 0)
	    {
	        ans1 = INT_MAX;
	    }
	    
	    if(no1%2 == 1)
	    {
	        ans0 += (no1/2) + 2;
	    }else{
	        ans0 += (no1/2);
	    }
	    
	    ans1 += no0;
	    
	    
	}
	
	cout<<min(ans1,ans0)<<endl;
	}
	return 0;
}