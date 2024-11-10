#include <iostream>
#include <vector>
#define ll long long
#define db double
#define dbl long double

using namespace std;



void solve() {
    ll n, t, k; cin >> n >> t >> k;
    if(n >= k){
        if(t == 0){
            if(n >= 2*k){
                cout << "YES" << endl;
                
            }else{
                cout << "NO" << endl;
                
            }
        }else{
            if(2*(k-1) > t){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
        
    }else{
        if(t <= 2){
            cout << "NO" << endl;
        }else if(2*n > t){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    

}

int main(){
    int t; cin >> t;
    while(t--){
        solve(); 
    }

    return 0;
}


