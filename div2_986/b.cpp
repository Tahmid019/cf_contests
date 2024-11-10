#include <iostream>
#include <vector>
#define ll long long
#define db double
#define dbl long double

using namespace std;



void solve() {
    ll n, b, c; cin >> n >> b >> c ;
    if(b == 0 ){
        if(c == 0 ){
            cout << -1 << endl;
            return;
        }else{
            cout << n-1 << endl;
            return;
        }
        
    }
    ll m = (double)(n-c)/(double)(b);
    m = abs(m);
    if(m >= n){
        cout << 0 << endl;
        return;
    }else{
        cout << m+1<< endl;
        return;
    }
    
}

int main(){
    int t; cin >> t;
    while(t--){
        solve(); 
    }

    return 0;
}


