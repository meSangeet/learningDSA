#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898
int main()
{
    int arr[] = {15, 20};
    int poop = 0, penalty = 0;
    for(int i = 0; i<2; i++)
    {
        penalty += arr[i];
        poop += penalty;
    }   
    cout<<endl<<penalty<<" "<<poop;
    return 0;
}