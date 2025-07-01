class Solution {
public:
    int possibleStringCount(string word) {
        int count = 0;
        char prev = word[0];
        int ans = 0;
        for(int i = 1; i < word.length(); i++){
            if(word[i] != prev){
                //mistyping is over
                ans += count;
                prev = word[i];
                count = 0;
            }else{
                count++;
            }
            // cout<<count<<" "<<ans<<endl;
        }
        ans += count;
        
        return ans+1;
    }
};