#define ll long long

class Solution {
public:
    void goahead(set<int> &o, set<int> &e, vector<int> &ans, long long k, int par, int n, vector<ll> &fact) {
        if (par == 1) {
            // we will traverse the even set
            ll p = n - 1;
            ll a = p / 2;
            ll b = (p + 1) / 2;
            ll count = fact[a] * fact[b];
            for (auto it = e.begin(); it != e.end(); ++it) {
                int x = *it;
                // cout<<x<<" "<<k<<endl;
                if (count >= k) {
                    ans.push_back(x);
                    e.erase(it);
                    goahead(o, e, ans, k, 0, n - 1, fact);
                    return;
                }
                k -= count;
            }
        } else {
            // we will traverse the odd set
            ll p = n - 1;
            ll a = p / 2;
            ll b = (p + 1) / 2;
            ll count = fact[a] * fact[b];
            for (auto it = o.begin(); it != o.end(); ++it) {
                int x = *it;
                if (count >= k) {
                    ans.push_back(x);
                    o.erase(it);
                    goahead(o, e, ans, k, 1, n - 1, fact);
                    return;
                }
                k -= count;
            }
        }
    }

    vector<int> permute(int n, long long k) {
        vector<int> ans;
        set<int> o, e;
        for (int i = 1; i <= n; i++) {
            if (i % 2) {
                o.insert(i);
            } else {
                e.insert(i);
            }
        }
        ll mm = sqrtl(LLONG_MAX-2);
        vector<ll> fact(51, 1);
        for (ll i = 2; i <= 50; i++) {
            fact[i] = min(fact[i - 1] * i, mm);
            // cout<<fact[i]<<" ";
        }
        // cout<<endl;

        ll p = n - 1;
        ll a = p / 2;
        ll b = (p + 1) / 2;

        ll count = fact[a] * fact[b];

        if (n % 2) {
            for (int i = 1; i <= n; i += 2) {
                if (count >= k) {
                    ans.push_back(i);
                    o.erase(i);
                    // cout<<i<<" "<<k<<endl;
                    goahead(o, e, ans, k, 1, n - 1, fact);
                    break;
                }
                k -= count;
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (count >= k) {
                    ans.push_back(i);
                    if(i%2)
                    o.erase(i);
                    else e.erase(i);
                    // cout<<i<<" "<<count<<" "<<k<<endl;
                    goahead(o, e, ans, k, i % 2, n - 1, fact);
                    break;
                }
                k -= count;
            }
        }

        return ans;
    }
};
