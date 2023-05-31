#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int sum = 0;
	    int n, k, l;
	    cin>>n>>k>>l;
	    vector<pair<int,int>> dotify;
	    for(int i = 0; i<n; i++)
	    {
	        int p,q; cin>>p>>q;
	        if(l == q) dotify.push_back({p,q});
	    }
	    if(dotify.size() < k){
	        cout<<"-1"<<endl;
	    }else{
            int j = k;
	    sort(dotify.begin(), dotify.end());
	    for(int i = dotify.size()-1; j>0; i--)
	    {
	     sum += dotify[i].first;   
         j--;
	    }
	    cout<<sum<<endl;
	    }
	}
	return 0;
}
