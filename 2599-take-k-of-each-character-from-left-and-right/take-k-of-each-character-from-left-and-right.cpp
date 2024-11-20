class Solution {
    
public:
    int takeCharacters(string s, int k) {
        int a = 0, b = 0, c = 0;
        for(char x : s){
            if(x == 'a'){
                a++;
            }

            if(x == 'b'){
                b++;
            }

            if(x == 'c'){
                c++;
            }
        }

        int A = a-k, B = b-k, C = c-k;
        // cout<<A<<" "<<B<<" "<<C<<endl;
        if(A < 0 || B < 0 || C < 0) return -1;
        int ans = 0;
        int l = 0;
        unordered_map<char, int> m;
        int n = s.length();
        if(A == 0 && B == 0 && C == 0) return n;
        for(int i = 0; i<n; i++){
            m[s[i]]++;
            if(m['a'] <= A && m['b'] <= B && m['c'] <= C){
                ans = max(ans, i - l + 1);
            }

            while(m['a'] > A || m['b'] > B || m['c'] > C){
                if(l <= i){
                    m[s[l]]--;
                }
                l++;
                if(l == i+1){
                    break;
                }
            }
        }

        return n - ans;
    }
};