#include <iostream>
#include <string>

bool isSubset(const std::string& s1, const std::string& s2) {
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
    std::string s1, s2;

    std::cout << "Enter string s1: ";
    std::getline(std::cin, s1);

    std::cout << "Enter string s2: ";
    std::getline(std::cin, s2);

    if (isSubset(s1, s2)) {
        std::cout << "s1 is a subset of s2.\n";
    } else {
        std::cout << "s1 is not a subset of s2.\n";
    }

    return 0;
}
