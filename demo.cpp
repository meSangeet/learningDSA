#include <iostream>
#include <vector>
#include <algorithm>

bool isBalanced(const std::vector<int>& difficulties, int d, int k) {
    int n = difficulties.size();
    int prev_difficulty = difficulties[0];

    for (int i = 1; i < n; ++i) {
        int current_difficulty = difficulties[i];
        int diff = current_difficulty - prev_difficulty;

        if (diff > d) {
            int num_removed = (diff - 1) / d;
            k -= num_removed;
            if (k < 0)
                return false;
        }

        prev_difficulty = current_difficulty;
    }

    return true;
}

int minProblemsToRemove(std::vector<int>& difficulties, int d) {
    int n = difficulties.size();
    std::sort(difficulties.begin(), difficulties.end());

    int left = 0, right = n - 1, result = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (isBalanced(difficulties, d, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, d;
        std::cin >> n >> d;

        std::vector<int> difficulties(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> difficulties[i];
        }

        int result = minProblemsToRemove(difficulties, d);
        std::cout << result << std::endl;
    }

    return 0;
}
