//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        
        int n = str.length()-1;
        bool flag;
        if(str[n] > '5'){
            flag = true;
        }else{
            flag = false;
        }
        
        str[n] = '0';
        bool flag1 = false;
        if(flag){
            int ind = n-1;
            while(ind >= 0){
                if(str[ind]  == '9'){
                    str[ind] = '0';
                }else{
                    str[ind] += 1;
                    flag1 = true;
                    break;
                }
                ind--;
            }
            
            if(str[0] == '0' && !flag1){
                str = "1" + str;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends