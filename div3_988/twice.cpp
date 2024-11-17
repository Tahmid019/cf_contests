#include <iostream>
#include <vector>
#define ll long long
#define db double
#define dbl long double

using namespace std;



void solve() {
    ll n; cin >> n;
    vector<int> a(n);
    ll cnt = 0;
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n ; i++){
        for(ll j = i+1; j < n ; j++){
            if(a[j] == a[i] && a[i] != -1 && a[j] != -1){
                cnt++;
                a[i] = -1;
                a[j] = -1;
            }
        }
    }
    cout << cnt << endl;

}

int main(){
    int t; cin >> t;
    while(t--){
        solve(); 
    }

    return 0;
}


