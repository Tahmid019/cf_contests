#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int MAX_N = 10000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<bool> is_prime(MAX_N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> subtractorization_count(MAX_N + 1, 0);
    vector<int> primes;
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }




    for (int i = 1; i <= MAX_N; i++) {
        cout << i << endl;
        for (int prime : primes) {
            if (prime > i) break;
            if (is_prime[i - prime]) {
                subtractorization_count[i]++;
            }
        }
    }

    for (int i = 1; i <= MAX_N; i++) {
        subtractorization_count[i] /= 2;
    }

    ifstream input("inputold.txt");
    ofstream output("output.txt");

    int T;
    input >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        input >> N;
        output << "Case #" << t << ": " << subtractorization_count[N] << "\n";
    }

    return 0;
}
