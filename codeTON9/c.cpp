#include <iostream>

#define ll long long
#define db double
#define dbl long double

using namespace std;


void sol(){
    ll x, m; cin >> x >> m ;
    ll cnt = 0;
    // if(x < m){
    //     cnt = 1;
    //     for(int i = 2; i<x; i++){
    //         if(x%i==0)cnt++;
    //     }
    //     cout << cnt << endl;
    // }else{
    ll y = min(8*x, m) + 1;
    for(ll i = 1; i< y; i++){
        ll xx = x^i;
        if(xx!= 0 &&(x%xx==0 || i%xx == 0 )){
            cnt++;
        }
    }
    cout << cnt<< endl;
    //}
}

int main(){
    int t; cin >> t;
    while(t--){
        sol(); 
    }

    return 0;
}


