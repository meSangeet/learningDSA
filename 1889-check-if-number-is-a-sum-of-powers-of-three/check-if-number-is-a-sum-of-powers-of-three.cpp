class Solution {
public:
    bool checkPowersOfThree(int n) {
        //how is this a medium question
        while(n){
            int rem = n%3;
            if(rem > 1) return false;
            n /= 3;
        }
        return true;
    }
};