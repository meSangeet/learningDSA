class Solution {
public:

    const int MOD = 1e9+7;
    long long mod_pow(long long a, long long b, long long mod) {
        long long result = 1;
        a %= mod;  // Handle cases where a >= mod

        while (b > 0) {
            if (b & 1) {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }

        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int maxInd = nums.size()+10;
        vector<long long> precomp(maxInd,0);
        long long prev = 0;
        long long tempAns = 0;
        for(int i = 0; i<maxInd; i++){
            long long cur = mod_pow(2, i, MOD);
            precomp[i] = cur + prev;
            precomp[i] %= MOD;
            prev = precomp[i];
        }
        //we will solve for every element
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int curE = temp[i];
            //sum should be less than or equals to the target
            if(curE > target){
                continue;
            }

            int bar = target - temp[i];

            //now we need to search for the greatest element less than or equals to bar
            //this is achieved using upperbound - 1;

            auto it = upper_bound(temp.begin() + i, temp.end(), bar);
            int ind = it -  temp.begin();
            ind--;

            //ind will give us the required index
            //now this should not be less than i
            if(ind < i) continue;

            //now we can select (i,i), (i,i+1), (i,i+2) ... (i, ind)
            //(i,i) -> one selectionm
            //(i,i+1) -> one selection
            //(i, i+2) -> 2 selections. (pow  = b-a-1)
            //max pow = ind - i - 1 (basically from 2^0 to 2^max_pow)
            //is we will try to calculate this again and again this will give us TLE why not 
            //let's precompute
            //done with precomputing
            int max_pow = ind - i - 1;
            if(max_pow >= 0)
            tempAns += precomp[max_pow];
            tempAns++;
            tempAns %= MOD;
        }

        int ans = tempAns;
        return ans;
    }
};