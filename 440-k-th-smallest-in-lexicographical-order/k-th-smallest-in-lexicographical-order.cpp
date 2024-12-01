class Solution {
public:

    int count(long int curr, long int next, long int n) {
        int count = 0;
        while (curr <= n) {
            count += next-curr;
            curr *= 10;
            next *= 10;

            next = min(long(next),long(n+1));
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;
        while (k > 0) {
            int countNumber = count(curr, curr + 1, n);

            if (countNumber <= k) {
                curr += 1;
                k -= countNumber;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};