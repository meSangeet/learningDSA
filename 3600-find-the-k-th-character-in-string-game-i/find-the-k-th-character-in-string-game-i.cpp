class Solution {
public:
    char helper(int rem, int count){
        if(rem == 1){
            return (char)('a' + count%26);
        }

        int ex = log2(rem);
        int no = pow(2, ex);
        int rem2 = rem - no;
        if(rem2 == 0){
            rem2 = no/2;
        }

        return helper(rem2, count+1);
    }
    char kthCharacter(int k) {
        //a ab abbc abbcbccd
        //len 1,2,4,8
        //let's do it the tough way

        //let's go back to the first character recursively

        return helper(k, 0);
    }
};