#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t; cin>>t;
    unordered_map<ll,ll> m;
    m[0] = 1;
    m[-1] = 1;
    m[2] = 1;
    unordered_map<ll,ll> count;
    count[0] = 1;
    count[1] = 3;
    int max = 1;
    while(t--)
    {
        ll y; cin>>y;
        
        if(y < 2)
        {
            cout<<count[y]<<endl;
        }else{
            count[y] = count[y-1];
        for(auto x:m)
        {
            int fir = x.first + 2;
            int sec = x.first - 1;
            
            if(m[fir] != 1)
            {
                m[fir] = 1;
                count[y] += 1;
            }
            if(m[sec] != 1)
            {
                m[sec] = 1;
                count[y] += 1;
            }
        }

            cout<<count[y]<<endl;
        }

    }
    
    
    return 0;
}