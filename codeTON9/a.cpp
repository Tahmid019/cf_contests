#include <iostream>
#include <vector>
#define ll long long
#define db double
#define dbl long double

using namespace std;



void solve() {
    int n; cin >> n;
    cout << 2 << " ";
    int a = 3;
    for(int i = 1; i<n; i++){
        cout << a << " ";
        a = a + 2;
    } 
    cout << endl;

}

int main(){
    int t; cin >> t;
    while(t--){
        solve(); 
    }

    return 0;
}


