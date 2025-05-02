class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans = "";
        bool rc = false;
        int n = dominoes.length();
        int cr = 0;
        int le = 0;
        for(int i = 0; i<n; i++){
            if(dominoes[i] == 'R'){
                rc = true;
                cr = 0;
                le = 0;
                ans.push_back('R');
                continue;
            }
            if(dominoes[i] == '.'){
                if(rc){
                    ans.push_back('R');
                    cr++;
                }else{
                    ans.push_back('.');
                    le++;
                }
                continue;
            }
            if(dominoes[i] == 'L'){
                ans.push_back('L');
                if(le){
                    int ind = i-1;
                    while(le){
                        ans[ind] = 'L';
                        le--;
                        ind--;
                    }
                    continue;
                }
                if(rc){
                    rc = false;
                    if(cr%2 == 0){
                        cr /= 2;
                        int ind = i-1;
                        while(cr){
                            ans[ind] = 'L';
                            cr--;
                            ind--;
                        }
                        continue;
                    }
                    if(cr%2){
                        cr--;
                        cr /= 2;
                        int ind = i-1;
                        while(cr){
                            ans[ind] = 'L';
                            cr--;
                            ind--;
                        }
                        ans[ind] = '.';
                        continue;
                    }
                }
            }
        }
        return ans;
    }
};