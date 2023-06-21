#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int findMinBoxes(int N, std::vector<long long>& A) {
    std::vector<std::vector<long long>> boxes;
    
    for (const auto& x : A) {
        bool found_box = false;
        
        for (auto& box : boxes) {
            long long box_xor = std::accumulate(box.begin(), box.end(), 0, [](long long a, long long b) { return a ^ b; });
            
            if (box_xor >= x) {
                box.push_back(x);
                found_box = true;
                break;
            }
        }
        
        if (!found_box) {
            boxes.push_back({x});
        }
    }
    
    return boxes.size();
}

int main() {
    int T;
    std::cin >> T;
    
    while (T--) {
        int N;
        std::cin >> N;
        
        std::vector<long long> A(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }
        
        int min_boxes = findMinBoxes(N, A);
        std::cout << min_boxes << std::endl;
    }
    
    return 0;
}
