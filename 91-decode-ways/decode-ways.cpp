class Solution {
public:
    int numDecodings(string s) {
        //we can take a maximum of 2 characters at a time as max number is 26
        //dp[i] -> numbers of strings till the index i
        int n = s.length();
        vector<int> dp(n+1, 1);
        //first number cannot be 0, and if there are any 0s in the string that cannot be clubbed with
        //the previous number then the answer will be 0
        if(s[0] == '0') return 0;
        for(int i = 2; i <= n; i++){
            int ind = i-1;
            //either we will just take this number or we will club it with the previous number
            int total = 0;
            //case1 : just the current number
            if(s[ind] != '0'){
                //current number will be taken and will be added with the previous
                total += dp[i-1];
            }

            //case2 : clubbing with the previous number
            if(s[ind-1] != '0'){
                string num = "";
                num.push_back(s[ind-1]);
                num.push_back(s[ind]);
                int no = stoi(num);
                if(no <= 26){
                    total += dp[i-2];
                }
            }

            dp[i] = total;
            cout<<dp[i]<<" ";
        }

        return dp[n];
    }
};