class Solution {
    bool possible(unordered_map<char,int> m)
    {
        vector<int> check = {m['a'], m['b'], m['c']};
        sort(check.begin(), check.end(), greater<int>());
        cout<<check[0]<<" "<<check[1]<<" "<<check[2]<<endl;
        if(check[0] == check[1] && check[0] >= check[2]) return true;
        return false;
    }

    string giveString(unordered_map<char,int> m){
        cout<<"hi";
        string ans = "";
        while(m['a'] > 0 || m['b'] > 0 || m['c'] > 0){
            if(m['a'] > 0){
                ans.push_back('a');
                m['a']--;
            }
            if(m['b'] > 0){
                ans.push_back('b');
                m['b']--;
            }
            if(m['c'] > 0){
                ans.push_back('c');
                m['c']--;
            }
        }
        return ans;
    }
public:
    string longestDiverseString(int a, int b, int c) {
        unordered_map<char,int> m;
        m['a'] = a;
        m['b'] = b;
        m['c'] = c;

        priority_queue<pair<int,char>> pq;

        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});

        string ans = "";

        while(!possible(m)){
            cout<<ans<<endl;
            pair<int,char> topp = pq.top();
            pq.pop();
            pair<int,char> sec = pq.top();
            pq.pop();
            if(topp.first > 1){
                ans.push_back(topp.second);
                ans.push_back(topp.second);
                pq.push({topp.first-2, topp.second});
                m[topp.second] -= 2;
                if(sec.first == 0) return ans;

                ans.push_back(sec.second);
                pq.push({sec.first-1, sec.second});
                m[sec.second] -= 1;
            }else if(topp.first == 1){
                ans.push_back(topp.second);
                return ans;
            }
        }

        ans += giveString(m);
        return ans;
    }
};