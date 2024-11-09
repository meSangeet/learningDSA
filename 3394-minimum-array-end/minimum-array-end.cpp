#define ll long long
class Solution {
public:
    long long minEnd(int n, int x) {
        ll start = x;
        int nums = 1;
        while(nums != n){
            ll cur = start+1;
            // while((cur&x) != x){
            //     cur++;
            // }
            cur |= x;
            start = cur;
            // cout<<start<<endl;
            nums++;
        }
        return start;
    }
};