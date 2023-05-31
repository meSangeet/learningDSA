//given any number you need to find the ith bit of that number 

#include <bits/stdc++.h>
using namespace std;

char ith(int n, int i)
{
    int mask = 1;
    mask = mask << i;
    if((mask & n) == 0) return '0';
    else return '1';
}


int main()
{
    int n; cin>>n;
    cout<<"\n"<<"enter the value of i - "; int i; cin>>i;
    cout<<"\n ith bit of the number "<<n<<" is "<<ith(n,i);
    
    
    return 0;
}
// 11 -> 1011