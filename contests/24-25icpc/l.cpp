#include <iostream>
#include <vector>

#define ll long long
#define db double
#define dbl long double

using namespace std;

/*



*/

void solve() {
   ll n; cin >> n;
   int k;
   if(n < 4){
    cout << n+1 << endl;
    return;
   }
   if(n%2 == 0){
    k = n + n/6;
    k += (n%6 == 0)? 0: 1;
   }else{
    k = n - 1 + ((n)/2)/3 + 2;
   }
   // cout << (7*n/6) + 1 << endl;
   cout << k << endl;
   

}

int main(){
    //ll t; cin >> t;
    //while(t--){
        solve(); 

    //}

    return 0;
}


