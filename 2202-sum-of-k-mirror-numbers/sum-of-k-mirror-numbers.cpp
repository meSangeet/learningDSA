class Solution {
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;
        
        // Start with single digits
        for (int i = 1; i <= 9 && count < n; i++) {
            if (isPalindromeInBaseK(i, k)) {
                sum += i;
                count++;
            }
        }
        
        // Then generate palindromes of increasing length
        for (int len = 2; count < n; len++) {
            vector<long long> palindromes;
            
            // Generate all palindromes of this length
            int halfLen = (len + 1) / 2;
            long long start = pow(10, halfLen - 1);
            long long end = pow(10, halfLen) - 1;
            
            for (long long i = start; i <= end && count < n; i++) {
                long long palindrome = createPalindrome(i, len);
                if (isPalindromeInBaseK(palindrome, k)) {
                    sum += palindrome;
                    count++;
                }
            }
        }
        
        return sum;
    }
    
private:
    long long createPalindrome(long long num, int len) {
        string s = to_string(num);
        string result = s;
        
        // Add the reverse part
        int start = (len % 2 == 0) ? s.length() - 1 : s.length() - 2;
        for (int i = start; i >= 0; i--) {
            result += s[i];
        }
        
        return stoll(result);
    }
    
    bool isPalindromeInBaseK(long long num, int k) {
        // Optimized base-k palindrome check
        long long original = num;
        long long reversed = 0;
        
        while (num > 0) {
            reversed = reversed * k + (num % k);
            num /= k;
        }
        
        return original == reversed;
    }
};