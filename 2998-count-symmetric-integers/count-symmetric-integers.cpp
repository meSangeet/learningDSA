class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int t=0;
        for(int i=low;i<=high;i++){
            string x = to_string(i);
            if(x.length()%2==1) continue;
            int c1=0,c2=0;
            for(int j = 0;j<x.length()/2;j++){
                c1+=x[j]-'0';
            }
            for(int j = x.length()/2;j<x.length();j++){
                c2+=x[j]-'0';
            }
            if(c1==c2) t++;
        }
        return t;
    }
};