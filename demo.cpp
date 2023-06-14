#include <iostream>
#include <vector>

using namespace std;

string checkSubsequenceExists(vector<int>& arr, int target) {
        int n = arr.size();
    int bitwiseAnd = arr[0];

    for (int i = 1; i < n; i++) {
        bitwiseAnd &= arr[i];
        if (bitwiseAnd == target) {
            return "YES";
        }
    }
    for (int i = 1; i < (1 << n); i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                if(!flag)
                {
                    bitwiseAnd = arr[j];
                    flag = true;
                }
                bitwiseAnd &= arr[j];
            }
        }
        if (bitwiseAnd == target) {
            return "YES";
        }
    }
    return "NO";
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, b;
        cin >> n >> b;

        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        string result = checkSubsequenceExists(a, b);

        cout << result << endl;
    }

    return 0;
}
