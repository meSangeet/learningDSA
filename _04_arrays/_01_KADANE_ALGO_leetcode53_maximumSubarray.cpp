#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> arr)
{
    int size = arr.size();
    int max_till_now = INT_MIN;
    int sum_till_now = 0;
    int max = INT_MIN;
    bool flag = false;
    for(int i = 0; i<size; i++)
    {
        if(arr[i] > max) max = arr[i];
        if(max > 0) flag = true;
        sum_till_now += arr[i];
        if(sum_till_now < 0) sum_till_now = 0;
        else{
            if(sum_till_now > max_till_now)
            {
                max_till_now = sum_till_now;
            }
        }
    }
    if(flag == false) return max;
    return max_till_now;
}



int main()
{
    int n; cout<<"enter number of elements in your array - "; cin>>n;
    vector<int> arr;
    while(n--)
    {
        int p; cin>>p;
        arr.push_back(p);
    }    
    cout<<endl<<"Maximum sum of subarray is - "<<kadane(arr);
    return 0;
}