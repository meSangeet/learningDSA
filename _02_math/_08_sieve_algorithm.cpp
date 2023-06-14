#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898
int main()
{
    vector<bool> sieve(10000007, true); // initially considering that all the numbers are prime
    sieve[0] = sieve[1] = false;
    for(int i = 0; i<10000007; i++)
    {
        // we will start the internal loop from the next prime number and count j from 2*i as ith number will be prime
        if(sieve[i] == true){
            for(int j = 2*i; j<10000007; j+=i)
            {
                sieve[j] = false;
            }
        }
    }

    cout<<"enter number of queries - "; int t; cin>>t;
    while(t--)
    {
        int p; cin>>p;
        if(sieve[p]) cout<<"Prime"<<endl;
        else cout<<"Not Prime"<<endl;
    }
    return 0;
}