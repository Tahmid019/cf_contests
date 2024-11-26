#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define db double
#define dbl long double

using namespace std;


ll findS(ll s){
    ll sum = 0;
 
    for (ll i = 1; sum < s; i++) {
        sum += i;
        if (sum >= s)
            return i;
    }
    return -1;
}

int nextPerfectSquare(int N)
{
    int nextN = floor(sqrt(N)) + 1;

    return nextN * nextN;
}




void solve() {
    ll n; cin >> n;
    ll nn = findS(n);
    double nnn = nn*nn*1.414;
    // cout << nn << "--" << nnn << endl;
    cout << sqrt(nextPerfectSquare(nnn)) << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve(); 
    }

    return 0;
}


