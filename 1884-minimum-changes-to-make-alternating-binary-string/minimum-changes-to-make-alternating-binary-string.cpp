class Solution {
public:
    int minOperations(string s) {
        int count0 = 0;
        int count1 = 0;

        for(int i = 0 ; i < s.size() ; i++){
            // assuming the s starts with '0'
            // then for all even index s[i] must be '0' and odd index have '1'
            if(i % 2 == 0){
                if(s[i] != '0'){
                    count0++;
                }
            }
            else{
                if(s[i] != '1'){
                    count0++;
                }
            }

            // assuming the s start with '1'
            // then for all even index s[i] must be '1' and odd index have '0'
            if(i % 2 == 0){
                if(s[i] != '1'){
                    count1++;
                }
            }
            else{
                if(s[i] != '0'){
                    count1++;
                }
            }
        }
        // now returning the minimum value of count0 and count1
        return min(count0 , count1);
    }
};