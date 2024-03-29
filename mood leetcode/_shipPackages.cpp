#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

class Solution {
public:
    bool isvalid(vector<int>& weights, int days,int mid){
        int tempdays= 1;
        int count =0;
        for(int i=0;i<weights.size();i++){
            count = count+weights[i];
            
            if(weights[i] > mid) return false; 
            if(count > mid){
                tempdays++;
                count = weights[i];
            }
            if(tempdays > days) return false;

        }
        if(tempdays > days ) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int left=weights[0],right=weights[0];
        //finding left , right for BS
        for(int i=1;i<weights.size();i++){
            left = max(left,weights[1]);
            right+= weights[i];
        }

        while(left<right){
            int mid = left+(right-left)/2;
            // if its valid then continue on left side of mid
            if(isvalid(weights,days,mid) == true){ 
                right = mid;
            }
            else left = mid+1;
        }

        return right;
        
    }
};


int main()
{
    
    return 0;
}