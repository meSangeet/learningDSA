class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int wlen = word.length();
        int slen = sequence.length();
        if(wlen > slen) return 0;
        if(wlen == slen) return sequence == word;

        int ans = 0;
        int count = 0;
        bool prev = false;
        int ind = 0;
        for(int i = 0; i<slen; i++){
            cout<<i<<" "<<count<<endl;
            string cur = sequence.substr(i, wlen);
            if(cur == word){
                count++;
                ans = max(ans, count);
                ind = i;
                i += wlen-1;
                prev = true;
            }else{
                count = 0;
                if(prev)
                i = ind;
                prev = false;
            }
        }

        return ans;
    }
};