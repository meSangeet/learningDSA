class Solution {
public:
    int maxDistance(string s, int k) {
        int a = 0, b = 0, c = 0, d = 0;
        string hori = "", ver = "";
        int hd = 0; // horizontal distance
        int vd = 0; // vertical distance
        int mhd = 0;
        int mvd = 0;
        int ans = 0;
        for (char x : s) {
            int temp = k;
            if (x == 'N') {
                a++;
            }
            if (x == 'S') {
                b++;
            }
            if (x == 'E') {
                c++;
            }
            if (x == 'W') {
                d++;
            }
            // if (a > b)
            //     swap(a, b);
            // if (c > d)
            //     swap(c, d);
            int aa = a, bb = b, cc = c, dd = d;
            if(aa > bb) swap(aa,bb);
            if(cc > dd) swap(cc,dd);
            // what the hell
            // swapping a position in opposite direction will make twice the
            // difference ig
            if (aa >= k) {
                // we will be able to replace k of the steps and then there will
                // be no more k
                bb -= aa;
                bb += 2 * k;
                // as there are no more k no alterations in d
                dd -= cc;
                ans = max(ans, bb + dd);
            } else {
                // k will remain
                k -= aa;
                bb += aa;
                if (cc >= k) {
                    dd -= cc;
                    dd += 2 * k;
                    ans = max(ans, bb + dd);
                } else {

                    dd += cc;
                    ans = max(ans, bb + dd);
                }
            }
            k = temp;
            // cout<<ans<<endl;
        }
        return ans;
    }
};