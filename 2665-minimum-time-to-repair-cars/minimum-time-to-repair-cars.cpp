#define ll long long
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        //I think this is binary search
        int n = ranks.size();
        ll l = 0, r = LLONG_MAX;
        ll ans = LLONG_MAX;
        while(l <= r){
            ll mid = l + (r-l)/2;
            // cout<<mid<<endl;
            ll temp = cars;
            for(int i = 0; i<n; i++){
                ll cm = mid/ranks[i];
                ll cc = sqrtl(cm);
                temp -= cc;
                if(temp <= 0){
                    break;
                }
            }
            if(temp <= 0){
                //possible
                ans = mid;
                r = mid-1;
            }else{
                // cout<<"not possible for "<<mid<<" temp = "<<temp<<endl;
                l = mid+1;
            }
        }

        return ans;
    }
};