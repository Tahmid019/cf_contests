#include <iostream>
#include <vector>
#define ll long long
#define db double
#define dbl long double

using namespace std;



void solve() {
    int n; cin >> n;

    if(n < 5){
        cout << -1 << endl; return;
    }
    vector<int> od, ev;
    for(int i = 1; i<= n; i += 2){
        if(i != 5) od.emplace_back(i);
    }
    od.emplace_back(5);

    ev.emplace_back(4);
    for(int i = 2; i <= n; i += 2){
        if(i != 4) ev.emplace_back(i);
    }
    for(int i = 0; i<od.size(); i++) cout << od[i] << " ";
    for(int i = 0; i<ev.size(); i++) cout << ev[i] << " ";
    cout << endl;

}

int main(){
    int t; cin >> t;
    while(t--){
        solve(); 
    }

    return 0;
}


