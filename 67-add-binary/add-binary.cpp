class Solution {
public:
    string addBinary(string a, string b) {
        //its not needed but let's do it stupidly
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int l = max(a.length(), b.length());
        int i = 0;
        if(a.length() < b.length()){
            swap(a,b);
        }
        int carry = 0;
        while(i < l){
            cout<<"i -> "<<i<<endl;
            cout<<ans<<" ";
            int no = a[i] -  '0';
            if(i > b.length()-1){
                if(no){
                    if(carry){
                        ans.push_back('0');
                    }else{
                        ans.push_back('1');
                    }
                }else{
                    if(carry){
                        ans.push_back('1');
                        carry = 0;
                    }else{
                        ans.push_back('0');
                    }
                }
            }else{
                int no1 = a[i] - '0';
                int no2 = b[i] - '0';
                cout<<" -> "<<no1<<" "<<no2<<endl;
                int total = no1 + no2 + carry;
                if(total == 0){
                    ans.push_back('0');
                }else if(total == 1){
                    ans.push_back('1');
                    carry = 0;
                }else if(total == 2){
                    ans.push_back('0');
                    carry = 1;
                }else if(total == 3){
                    ans.push_back('1');
                    carry = 1;
                }
            }
            i++;
            cout<<ans<<endl;
        }
            if(carry){
                ans.push_back('1');
            }
            if(ans.length() > 1 and ans.back() == '0'){
                ans.pop_back();
            }

            reverse(ans.begin(), ans.end());
            return ans;
    }
};