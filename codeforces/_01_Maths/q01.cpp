#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898
int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll p=b,q=c,r=c;
        while(p >= a)
        {
            ll sum = q+r;
            if(sum > a){
                cout<<p<<" "<<q<<" "<<r;
                goto x;
            }
            p--;
        }
        p = b;
        while(q >= b)
        {
            ll sum = p+r;
            if(sum > q){
                cout<<p<<" "<<q<<" "<<r;
                goto x;
            }
            q--;
        }
        q = c;
        while(r <= d)
        {
            ll sum = p+q;
            if(sum > r){
                cout<<p<<" "<<q<<" "<<r;
                goto x;
            }
            r++;
        }
        x:
        bool flag = true;
        cout<<endl;
    }

    return 0;
}