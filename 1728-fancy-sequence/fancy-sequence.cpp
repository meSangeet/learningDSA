constexpr int MOD = 1e9 + 7;
long long seq[100001];
class Fancy {
private:
    int len = 0;
    long long incre = 0, multi = 1;
    inline long long modPow(long long b , int exp){
        long long res = 1;
        while(exp){
            if(exp & 1) res = (res * b) % MOD;
            b = (b * b) % MOD;
            exp >>= 1;
        }
        return res;
    }
public:
    Fancy() {}
    void append(int val) {
        seq[len++] = (((MOD + val - incre) % MOD) * modPow(multi , MOD - 2)) % MOD;
    }
    void addAll(int inc) {
        incre = (incre + inc) % MOD;
    }
    void multAll(int m) {
        multi = (multi * m) % MOD;
        incre = (incre * m) % MOD;
    }
    int getIndex(int idx) {
        if(idx >= len) return -1;
        return (((seq[idx] * multi) % MOD) + incre) % MOD;
    }
};