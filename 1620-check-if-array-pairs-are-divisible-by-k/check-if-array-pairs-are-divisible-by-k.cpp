class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        int present = 0;
        for(int element : arr){
            int rem = element%k;
            int needed = (k - rem)%k;
            needed += k;
            needed %= k;
            rem += k;
            rem %= k;
            if(m[needed] > 0){
                m[needed]--;
                present--;
            }else{
                m[rem]++;
                present++;
            }
        }

        if(present != 0) return false;
        return true;
    }
};