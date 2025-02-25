#define ll long long
class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        ll o = 0, e = 0;
        //o is the number of odd sub arrays ending at i-1 
        //e is the number of even subarray ending at i-1
        ll ans = 0;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]%2){
                //if current element is odd then all the previous even sub arrays can be 
                //extended to this subarray and they will become odd and this element
                //standalone will also be an odd subarray
                ll temp = o;
                o = e + 1;
                //what about even subarrays
                //all the previous odd sub arrays will now be even
                e = temp;
                ans += o;
                o %= M;
                e %= M;
                ans %= M;
            }else{
                //if current element is even previously odd subarrays will still be odd
                o = o;
                ans += o;
                e++;
                o %= M;
                e %= M;
                ans %= M;
            }
        }
        return ans;

        return ans;
        
    }
};