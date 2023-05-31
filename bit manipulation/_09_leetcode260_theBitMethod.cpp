#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        // second method
        int xoor = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            xoor = xoor ^ nums[i];
        }

        // now we will calculate which bit is the rightmost one

        long int count = 0;
        while (xoor)
        {
            if ((xoor & 1) == 1)
            {
                break;
            }

            xoor = xoor >> 1;
            count++;
        }
        // now our count contain which is the right most differnet bits between the two unique elements in the array

        // now we will start dividing elements on the basis  of their bit on count position

        int num1 = 0, num2 = 0;

        for (int i = 0; i < size; i++)
        {
            if ((nums[i] & (1 << count)) == 0)
            {
                num1 = num1 ^ nums[i];
            }
            else
            {
                num2 = num2 ^ nums[i];
            }
        }

        return {num1, num2};
    }
};

int main()
{

    return 0;
}