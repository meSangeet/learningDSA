#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define pie 3.1415926535898

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s = 1, e = n;
        int mid = s + (e-s)/2;
        while(s<=e)
        {
            if(guess(mid) == 0)
            {
                return mid;
            }else if(guess(mid) == 1)
            {
                s = mid+1;
            }else{
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return 0;
    }
};

int main()
{
    
    return 0;
}