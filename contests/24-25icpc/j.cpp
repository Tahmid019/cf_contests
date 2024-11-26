#include <iostream>
#include <vector>

#define ll long long
#define db double
#define dbl long double

using namespace std;



void solve(ll& p, ll& b) {
   char c; ll a;
   cin >> c >> a;
   
   if(c == 'P'){
    p+= a;
    
   } else{
    b= a;
    if(p >= b){
        p-=b;
        cout << "NO" << endl;
    }else{
        p = 0;
        cout << "YES" << endl;
    }
   }
//    cout << p << endl;
}

int main(){
    ll t; cin >> t;
    ll p = 0, b = 0;
    while(t--){
        solve(p,b); 

    }

    return 0;
}


