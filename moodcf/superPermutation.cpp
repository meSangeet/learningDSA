#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898
int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        ll pro = (n*(n+1))/2;
        if(pro%n == 0){
            cout<<-1<<endl; 
        }
    }   
    return 0;
}