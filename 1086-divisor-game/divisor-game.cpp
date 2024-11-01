class Solution {
public:
    bool divisorGame(int n) {
        //dry running the cases
        /*
        1 - false
        2 - true
        3 - false
        4 - true
        5 - 1 + 4 -> opposite of 4 - false
        6 - true
        7 - false
        8 - true
        9 - false
        10 - true
        11 - false
        12 - true
        13 - false
        14 - true
        15 - 
        */

        if(n%2) return 0;
        return 1;
    }
};