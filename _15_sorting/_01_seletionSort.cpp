#include <bits/stdc++.h>
using namespace std;
#define ll long long

void selsort(vector<int> &arr)
{
    for(int i = 0; i<arr.size(); i++)
    {
        int ind = i;
        for(int j = i+1; j<arr.size(); j++)
        {
            if(arr[j] < arr[ind])
            {
                ind = j;
            }
        }
        swap(arr[i], arr[ind]);
    }
}

//main function
int main()
{
    int n; cin>>n;
    vector<int> arr;
    for(int i = 0; i<n; i++)
    {
        int p; cin>>p;
        arr.push_back(p);
    }

    selsort(arr);
    cout<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}