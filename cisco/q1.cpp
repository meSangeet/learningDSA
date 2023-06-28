#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

long getNumbberOfDroppedPackets(vector<vector<int>> requests, int max_packets, int rate)
{
    long long n = requests.size();
    sort(requests.begin(), requests.end());
    int curr = 0, drop = 0;
    long long t = 0;
    for (int i = 0; i < n; i++)
    {
        while (t != requests[i][0])
        {
            if (curr >= rate)
            {
                curr -= rate;
            }
            else
            {
                curr = 0;
            }
            t++;
        }
        curr += requests[i][1];
        if (curr > max_packets)
        {
            drop += (curr - max_packets);
            curr = max_packets;
        }
        
        if (curr >= rate)
        {
            curr -= rate;
        }else
        {
            curr = 0;
        }
        t++;
    }
    return drop;
}
int main()
{
    int n; cin>>n;
    vector<vector<int>>arr;
    for(int i = 0; i<n; i++)
    {
        int a, b; cin>>a>>b;
        vector<int> temp = {a,b};
        arr.push_back(temp);
    }
    cout<<"enter max p - ";
    int mp; cin>>mp;
    cout<<"enter rate - "; int rate; cin>>rate;
    cout<<endl<<getNumbberOfDroppedPackets(arr,mp,rate);
    return 0;
}