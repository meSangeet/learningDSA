#define ll int

class DSU {
private:
    vector<ll> parent; // Stores the parent of each element
    vector<ll> rank;   // Stores the rank of each set (for union by rank)
    vector<ll> size;   // Stores the size of each set (optional, but useful)

public:
    // Constructor to initialize DSU with 'n' elements
    DSU(ll n) {
        parent.resize(n+2);
        rank.resize(n+2, 1); // Initially, rank of each set is 1
        size.resize(n+2, 1); // Initially, size of each set is 1
        for (ll i = 0; i < n; i++) {
            parent[i] = i; // Each element is its own parent initially
        }
    }

    // Find the root of the set containing 'x' (with path compression)
    ll find(ll x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union of two sets containing 'x' and 'y' (with union by rank)
    void unite(ll x, ll y) {
        ll rootX = find(x);
        ll rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY]; // Update size
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX]; // Update size
            } else {
                parent[rootY] = rootX;
                rank[rootX]++; // Increase rank if ranks are equal
                size[rootX] += size[rootY]; // Update size
            }
        }
    }

    // Check if 'x' and 'y' are in the same set
    bool sameSet(ll x, ll y) {
        return find(x) == find(y);
    }

    // Get the size of the set containing 'x'
    ll getSize(ll x) {
        ll root = find(x);
        return size[root];
    }

    // Get the number of disjoint sets (optional)
    ll countSets() {
        ll count = 0;
        for (ll i = 0; i < parent.size(); i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ans;
        DSU ds(n);
        for(auto x : edges){
            int a = x[0];
            int b = x[1];
            if(ds.sameSet(a,b)){
                ans = {a,b};
            }else{
                ds.unite(a,b);
            }
        }
        return ans;
    }
};