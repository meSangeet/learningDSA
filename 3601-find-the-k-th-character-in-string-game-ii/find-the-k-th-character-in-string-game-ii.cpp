#define ll long long
class Solution {
public:
    char helper(ll rem, ll count, vector<int>& operations){
        if(rem == 1){
            return (char)('a' + count%26);
        }

        ll ex = log2(rem);
        ll no = powl(2, ex);
        ll rem2 = rem - no;
        if(rem2 == 0){
            rem2 = no/2;
            ex--;
        }

        //current operation will be ex+1 th operation

        int ind = ex;
        if(operations[ind] == 0)
        return helper(rem2, count, operations);
        else return helper(rem2, count+1, operations);
    }

    char kthCharacter(long long k, vector<int>& operations) {
        return helper(k, 0ll, operations);
    }
};