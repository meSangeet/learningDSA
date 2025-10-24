class Solution {
public:
    int nextBeautifulNumber(int n) {
          string no = to_string(n);
          int len = no.length();
          while(true){
            n++;
            string num = to_string(n);
            vector<int> temp(10, 0);
            for(char x : num){
                temp[x-'0']++;
            }
            bool flag = true;
            for(int i = 0; i<=9; i++){
                if(temp[i] != i){
                    if(i == 0){
                        flag = false;
                        break;
                    }else{
                        if(temp[i] != 0){
                            flag = false;
                            break;
                        }
                    }
                }
            }

            if(flag) return n;
          }
              return 0;
    }
    
};