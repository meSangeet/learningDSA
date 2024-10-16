//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        vector<int> a(arr);
        sort(a.begin(), a.end());
        vector<int> mis;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] != a[i]){
                mis.push_back(i);
            }
        }
        
        if(mis.size() == 0 || mis.size() == 3) return true;
        
        if(mis.size() == 4){
            int ind = mis[0];
            int ind2;
            int elem = a[mis[0]];
            
            for(int i = 1; i<4; i++){
                if(arr[mis[i]] == elem){
                    ind2 = mis[i];
                }
            }
            
            if(a[ind2] == arr[mis[0]]) return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends