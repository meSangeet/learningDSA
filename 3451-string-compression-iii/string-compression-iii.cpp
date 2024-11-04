class Solution {
public:
    string compressedString(string word) {
        string s = word;
        int cur = 0;
        char prev = '*';
        string ans = "";
        for(int i = 0; i<s.length(); i++){
            char x = s[i];
            // cout<<"processing - "<<x<<endl;
            // cout<<prev<<" "<<cur<<endl;

            if(x == prev){
                cur++;
                if(cur == 9){
                    ans.push_back('9');
                    ans.push_back(x);
                    cur = 0;
                    prev = '*';
                    if(i == s.length()-1) break;
                }
                if(i == s.length()-1){
                    ans.push_back('0'+cur);
                    ans.push_back(prev);
                }
            }else{
                if(prev != '*'){
                    // cout<<"Inside *"<<endl;
                    ans.push_back('0' + cur);
                    ans.push_back(prev);
                    prev = x;
                    cur = 1;
                    if(i == s.length()-1){
                        ans.push_back('1');
                        ans.push_back(x);
                    }
                }else{
                    cur = 1;
                    prev = x;
                    if(i == s.length()-1){
                        ans.push_back('0'+cur);
                        ans.push_back(prev);
                    }           
                }
            }
            // cout<<prev<<" "<<cur<<endl;
        }

        return ans;        
    }
};