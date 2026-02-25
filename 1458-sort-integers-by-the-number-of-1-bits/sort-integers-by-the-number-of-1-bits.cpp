class Solution {
public:
    static bool comp(int a, int b){
        int ba = __builtin_popcount(a), bb = __builtin_popcount(b);
        if(ba == bb) return a < b;
        return ba < bb;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};