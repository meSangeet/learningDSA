class Solution {
public:
    int maxProduct(int n) {
        int a = -1, b = -1;
        while(n){
            int temp = n%10;
            if(a == -1){
                a = temp;
            }else{
                if(temp > a){
                    b = a;
                    a = temp;
                }else{
                    if(temp > b) b = temp;
                }
            }

            n /= 10;
        }

        return a*b;
    }
};