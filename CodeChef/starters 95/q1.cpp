#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    vector<string> arr;
	    int ca = 0, cb = 0, co = 0, cab = 0;
	    for(int i = 0; i<n; i++)
	    {
	        string p; cin>>p;
	        arr.push_back(p);
	        if(p == "A") ca++;
	        else if(p == "B") cb++;
	        else if(p == "O") co++;
	        else cab++;
	    }
	    long long int ans = 0;
	    if(ca > cb){
	      ans = co + ca + cab;  
	    }else{
	        ans = co + cb + cab;
	    }
	    cout<<ans<<endl;
	    
	}
	return 0;
}
