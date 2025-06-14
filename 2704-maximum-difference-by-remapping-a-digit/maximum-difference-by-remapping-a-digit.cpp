class Solution {
public:
    int minMaxDifference(int num) {
        cout<<num<<endl;
        string a = to_string(num);
        string temp = a;
        bool flag = false;
        char q = a[0];
        for(char x : a){
            if(x != '9'){
                q = x;
                flag = true;
                break;
            }
        }
        if(flag)
        for(int i = 0; i<a.length(); i++){
            if(a[i] == q){
                a[i] = '9';
            }
        }
        
        int ma = stoi(a);
        a = temp;
        q = a[0];
        for(int i = 0; i<a.length(); i++){
            if(a[i] == q){
                a[i] = '0';
            }
        }
        int mi = stoi(a);
        return ma - mi;
    }
};