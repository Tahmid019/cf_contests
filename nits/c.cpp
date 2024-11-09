#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<int> a(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }

        ll _max = 1; 
        ll cnt = 1;
        for(ll i = 1; i < n; i++){
            if(abs(a[i] - a[i-1]) <= 1){
                cnt++;
            } else {
                _max = max(_max, cnt);
                cnt = 1;
            }
        }
        _max = max(_max, cnt); 
        
        cout << _max << endl;
    }
    return 0;
}
