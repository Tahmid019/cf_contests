#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

const int MOD = 998244353;

long long mod_exp(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long mod_inverse(long long a, long long p) {
    return mod_exp(a, p - 2, p);
}

int main() {
    ifstream input_file("input.txt");
    ofstream output_file("output.txt");
    
    

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        long long W, G, L;
        cin >> W >> G >> L;

        if (L == 0) {
            cout << "Case #" << t << ": " << (W - G) % MOD << endl;
            continue;
        }

        long long diff = W - G;
        long long p = 2 * diff - L;
        long long q = L + 1;

        long long g = __gcd(p, q);
        p /= g;
        q /= g;

        long long q_inv = mod_inverse(q, MOD);
        long long result = (p * q_inv) % MOD;

        cout << "Case #" << t << ": " << result << endl;
    }

    return 0;
}
