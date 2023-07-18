#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compress(vector<char> &chars)
{
    char curr = chars[0];
    int i = 1;
    int count = 1;
    int ansInd = 0;
    while (i < chars.size())
    {
        if (chars[i] == curr)
        {
            count++;
            i++;
        }
        else
        {
            chars[ansInd++] = curr;
            if (count > 1)
            {
                string str = to_string(count);
                for (int j = 0; j < str.length(); j++)
                {
                    chars[ansInd++] = str[j];
                }
            }

            curr = chars[i];
            count = 1;
            i++;
        }
    }
    chars[ansInd++] = curr;
    if (count > 1)
    {
        string str = to_string(count);
        for (int j = 0; j < str.length(); j++)
        {
            chars[ansInd++] = str[j];
        }
    }
    return ansInd;
}

int main()
{
    int n;
    cin >> n;
    vector<char> arr;
    for (int i = 0; i < n; i++)
    {
        char p;
        cin >> p;
        arr.push_back(p);
    }

    // printing original array

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;

    // calling method

    n = compress(arr);

    // compressed array

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}