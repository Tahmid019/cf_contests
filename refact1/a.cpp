#include <iostream>
#include <vector>
#define ll long long
#define db double
#define dbl long double

using namespace std;

// void solve(){

// }

int main(){
    int t; cin >> t;
    while(t--){
        ll l,r,k; cin >> l >> r >>k;
        ll cnt = 0;
        if(r/l < k){
            cout << 0 << endl;
        }else{
            cout << abs(r/k - l) + 1 << endl;
        }
        
    }

    return 0;
}