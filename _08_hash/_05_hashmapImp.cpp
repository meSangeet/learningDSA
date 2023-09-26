#include <bits/stdc++.h>
using namespace std;
#define ll long long

template<class T, class U> 
class hashmap{
int hash[10000] = {0};
int size = 0;

int hashing(T x)
{
    if(hash[x] == 0)
    {
        return x;
    }

    while(hash[x] != 0)
    {
        (x *= x)%1000;
    }

    return x;
}
v
public:
hashmap(pair<T,U> p)
{
    int index = hashing(p.first);
    hash[p.first] = p.second; 
    if(p.second > 0)
    {
        size++;
    }
}

void insert(pair<T,U> p)
{
    int index = hashing(p.first);
    if(hash[p.first] == 0)
    {
        size++;
    }
    hash[p.first] = p.second;
    if(p.second == 0)
    {
        size--;
    } 
}

U print(T x)
{
    int index = hashing(x);
    return hash[index];
}

void printhash()
{
    cout<<"\n hashmap \n";
    for(int i = 0; i < 1000; i++)
    {
        if(hash[i] > 0)
        {
            cout<<i<<" "<<hash[i]<<endl;
        }
    }
}
};
//main function
int main()
{
    hashmap<int,int> h({1,2});
    h.insert({2,3});
    h.insert({3,4});
    h.printhash();
    return 0;
}