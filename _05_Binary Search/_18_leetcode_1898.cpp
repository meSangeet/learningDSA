#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898


class Solution{
    public:
    bool isSub(string s, string p, vector<int> &removable, int k)
{
    for (int i = k; i >= 0; i--)
    {
        s[removable[i]] = '.';
    }
    cout<<endl<<s;
    int i = 0, j = 0;
    while (j <= p.size() - 1 && i < s.size())
    {
        if (s[i] == '.')
        {
            i++;
            continue;
        }
        else if (i >= s.size()){
            cout<<"false"<<endl;
            return false;
        }else
        {
            if (s[i] == p[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
    }
    if(j >= p.size()){
        cout<<"true"<<endl;
        return true;
    }
        cout<<"false"<<endl; return false;
}


int maximumRemovals(string s, string p, vector<int> &removable)
{
    int st = 0, e = removable.size() - 1;
    int ans = 0;
    int mid = st + (e - st) / 2;
    bool f = false;
    while (st <= e)
    {
        if (isSub(s, p, removable, mid))
        {
            f = true;
            ans = mid;
            st = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = st + (e - st) / 2;
    }
    if(f)
    return ans+1;

    return ans;
}


};
int main()
{
    string s, p;
    cin >> s >> p;
    int n;
    cin >> n;
    vector<int> removable;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        removable.push_back(p);
    }
    cout << endl;
    return 0;
}