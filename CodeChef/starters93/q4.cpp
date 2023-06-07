#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isPalindrome(int num)
{
    string decimal_str = to_string(num);
    int i = 0, j = decimal_str.length() - 1;

    while (i < j)
    {
        if (decimal_str[i++] != decimal_str[j--])
        {
            return false;
        }
    }

    return true;
}

int countPalindromePairs(const vector<int> &A)
{
    unordered_map<int, int> freq;
    int count = A.size();

    for (int i = 0; i < A.size(); i++)
    {

        for (int j = i + 1; j < A.size(); j++)
        {
            int xor_result = (A[i] ^ A[j]);
            if (freq[xor_result] == 1)
            {
                count++;
            }
            else if (freq[xor_result] == 2)
            {
                count += 0;
            }
            else
            {
                if (isPalindrome(xor_result))
                {
                    count++;
                    freq[xor_result] = 1;
                }
                else
                {
                    freq[xor_result] = 2;
                }
            }
        }
    }

    return count;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        int result = countPalindromePairs(A);
        cout << result << endl;
    }

    return 0;
}
