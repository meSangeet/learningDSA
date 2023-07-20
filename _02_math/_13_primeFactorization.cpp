#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// we will only calculate till 1000

vector<bool> sieve(1001, true);
vector<int> hp(1001, -1), lp(1001, -1);
// this function will mark the sieve array for us
void markingSieve(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] == true)
        {
            hp[i] = i;
            lp[i] = i;
            for (int j = 2 * i; j <= n; j += i)
            {
                sieve[j] = false;
                hp[j] = i;
                if (lp[j] == -1)
                    lp[j] = i;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    markingSieve(n);

    for (int i = 2; i <= n; i++)
    {
        if (i == (int)sqrt(n))
            cout << "observe - " << endl;
        cout << i << " " << ((sieve[i]) ? "prime" : "not prime") << " hp - > " << hp[i] << " lp -> " << lp[i] << "\n";
    }

    // now we will start the process of prime factorisation
    int q;
    cin >> q;
    while (q--)
    {
        int p;
        cin >> p;

        vector<int> pf;

        int hf = hp[p], lf = lp[p];

        while (p > 1)
        {
            int fact = hf;
            while (p % fact == 0)
            {
                pf.push_back(fact);
                p /= fact;
            }
            hf--;
            while (sieve[hf] == false)
            {
                hf--;
            }
        }

        cout << "\n the prime factorisation of " << p << " is - ";

        for (int i = 0; i < pf.size(); i++)
        {
            cout << pf[i] << " ";
        }
    }
    return 0;
}