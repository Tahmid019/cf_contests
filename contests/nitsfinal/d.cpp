#include <iostream>
#include <vector>
#define ll long long
#define db double
#define dbl long double

using namespace std;



void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    string b = "";
    for(auto c:s){
        if(c == 'a') b.push_back('a');
    }
    b.push_back('a');
    cout << b << endl;

}

int main(){
    int t; cin >> t;
    while(t--){
        solve(); 
    }

    return 0;
}


