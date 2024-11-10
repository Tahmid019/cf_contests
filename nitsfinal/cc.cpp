#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

ll findS(ll s) {
    ll sum = 0, i = 1;
    while (sum < s) {
        sum += i;
        i++;
    }
    return i - 1;
}

void solve() {
    ll n;
    cin >> n;
    double sum = 1*sqrt(2);
    double j = 0;
    for(double i = 1; i<=n ; ){
        
        if((j*j)/sqrt(2) < sum){
            cout << "++ ";
            j++;
        }else{
            i++;
            sum = i*i*sqrt(2);;
            
        }
    }
    cout << j << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
