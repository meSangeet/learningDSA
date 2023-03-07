#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int x) {
        if(x < 0) return false;
        bool flag = true;
        vector<int> no;
        while(x!=0)
        {
            long long int temp = x%10;
            x /= 10;
            no.push_back(temp);
        }
        int size = no.size();
        int i = 0, j = (size - 1);
        while(i < j)
        {
            if(no[i] != no[j])
            {
                flag = false;
            }
                i++;
                j--;
        }

        return flag;
    }    
int main()
{
    int c; cin>>c;
    cout<<isPalindrome(c);
    return 0;
}