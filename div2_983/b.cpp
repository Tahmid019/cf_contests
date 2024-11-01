#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long mx = min(k - 1, n - k);
        bool f = false;
        long long pos[1000];
        long long m = 0;
        int psize = 0;

        for (long long x = 1; x <= mx; x++) {
            long long tmp = k - 1 - x;
            if (tmp < 0)
                continue;
            long long tv = tmp % 2;
            long long pmin = min(k - 1 - x, n - k - x);
            if (tv > pmin)
                continue;
            long long cm = 1 + 2 * x;
            long long l = k - tv - 1;
            long long r = n - k - tv;
            if (l < x || r < x)
                continue;
            long long pl[1000];
            int plsize = 0;
            long long p = 1;

            for (long long i = 1; i <= x - 1; i++) {
                pl[plsize++] = p;
                p += 1;
            }
            if (x > 0) {
                pl[plsize++] = p;
                p += (l - (x - 1));
            }
            pl[plsize++] = p;
            p += (2 * tv + 1);
            for (long long i = 1; i <= x - 1; i++) {
                pl[plsize++] = p;
                p += 1;
            }
            if (x > 0) {
                pl[plsize++] = p;
                p += (r - (x - 1));
            }
            if (p - 1 == n) {
                m = cm;
                for (int i = 0; i < plsize; i++) {
                    pos[i] = pl[i];
                }
                psize = plsize;
                f = true;
                break;
            }
        }

        if (f) {
            cout << m << endl;
            for (int i = 0; i < psize; i++) {
                cout << pos[i] << " ";
            }
            cout << endl;
            continue;
        }
        long long t0 = (n - 1) / 2;
        if (t0 == k - 1) {
            cout << 1 << endl;
            cout << 1 << endl;
            continue;
        }
        cout << -1 << endl;
    }
    return 0;
}