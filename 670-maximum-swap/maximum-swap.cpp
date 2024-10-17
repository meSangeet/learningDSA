class Solution {
public:
    int maximumSwap(int num) {
        string strnum = to_string(num);
        int n = strnum.length();
        vector<int> pref(n);
        int maax = n-1;
        pref[maax] = n-1;
        for(int i = n-2; i>=0; i--){
            if(strnum[i] > strnum[maax]){
                pref[i] = i;
                maax = i;
            }else{
                pref[i] = maax;
            }
        }
        unordered_map<int,int> m;
        for(int i = 0; i<n; i++){
            if(strnum[i] < strnum[pref[i]]){
                swap(strnum[i], strnum[pref[i]]);
                break;
            }
        }
        return stoi(strnum);
    }
};