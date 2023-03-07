#include <bits/stdc++.h>
using namespace std;


int main()
{
    string str = "asdfsdfoibosdvbosidfvbohdfvohsbfvohfd";
    for(int i = 0; i<15; i++)
    {
        char tem = '0' + i;
        str.push_back(tem);
    }
    cout<<str;
    return 0;
}