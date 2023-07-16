#include <iostream>
#include <string>
using namespace std;


bool isSubset(const string& s1, const string& s2) {
    size_t i = 0, j = 0;

    while (i < s1.length() && j < s2.length()) {
        if (s1[i] == s2[j]) {
            i++;
        }
        j++;
    }

    return (i == s1.length());
}

int main() {
    string s1, s2;

    cout << "Enter string s1: ";
    getline(std::cin, s1);

    cout << "Enter string s2: ";
    getline(std::cin, s2);

    if (isSubset(s1, s2)) {
        cout << "s1 is a subset of s2.\n";
    } else {
        cout << "s1 is not a subset of s2.\n";
    }

    return 0;
}
