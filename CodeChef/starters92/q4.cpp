#include <bits/stdc++.h>
using namespace std;

int factmod(int n) {
    int ans = 1;
    for(int i = n; i>=1; i--)
    {
        ans = ans*i;
    }
    
    return ans;
}

int main() {
	int t; cin>>t;
	while(t--)
	{
	  int n, k;
	  cin>>n>>k;
	  cout<<factmod(k)<<endl;
	}
	return 0;
}
