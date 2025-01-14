class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        map<int,int> m;
        map<int,int> sec;
        int n = A.size();
        int anss = 0;
        for(int i = 0; i<n; i++){
            int p = A[i], q = B[i];
            if(m[p] == 0 && sec[p] != 0){
                anss++;
            }
            m[p]++;
            if(sec[q] == 0 and m[q] != 0){
                anss++;
            }
            sec[q]++;
            ans.push_back(anss);
        }
        return ans;
    }
};