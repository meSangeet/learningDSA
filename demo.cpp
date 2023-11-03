#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> getServerIndex(int n, vector<int> arrival, vector<int> burstTime)
{
    vector<vector<int>> pp;

    for(int i = 0; i<arrival.size(); i++)
    {   vector<int> temp;
        temp.push_back(arrival[i]);
        temp.push_back(i);
        temp.push_back(burstTime[i]);
        pp.push_back(temp);
    }
    cout<<"hi"<<endl;
    sort(pp.begin(), pp.end());
    vector<int> ans;
    vector<int> servers(n+1, 0);
    for(int i = 0; i<pp.size(); i++)
    {
        bool flag = true;
        for(int j = 1; j<=n; j++)
        {
            if(servers[j] <= pp[i][0])
            {
                servers[j] = pp[i][0] + pp[i][2];
                pp[i].push_back(j);
                flag = false;
                break;
            }
        }
        if(flag)
        pp[i].push_back(-1);
        swap(pp[i][0],pp[i][1]);
    }

    sort(pp.begin(), pp.end());

    for(int i = 0; i<pp.size(); i++)
    {
        ans.push_back(pp[i][3]);
    }
    /*
    4 5
3 5 1 6 8 
9 2 10 4 5
    */
    return ans;
}

//main function
int main()
{
    int n; cin>>n;
    int a; cin>>a;
    vector<int> arrival(a);
    for(int i = 0; i<a; i++)
    {
        cin>>arrival[i];
    }
    vector<int> burstTime(n);
    for(int i = 0; i<a; i++)
    {
        cin>>burstTime[i];
    }
    cout<<"here";
    vector<int> ans = getServerIndex(n, arrival, burstTime);
    cout<<endl<<"ans - "<<endl;
    for(int i = 0; i<ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}