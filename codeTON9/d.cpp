#include <iostream>
#include <vector>
#define ll long long
#define db double
#define dbl long double

using namespace std;


void sol(){
    ll n, m; cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i<m; i++) cin >> a[i];
    if(m == 1){
        if(n == m )cout << 1 << endl;
        else cout << -1 << endl;
        return;
    }
    cout << a[a.size() - 1] << " ";
    for(int i = 1; i<n-1; i++){
        cout << a[a.size()-2] << " ";
    }
    cout << a[0] << endl;

}

int main(){
    int t; cin >> t;
    while(t--){
        sol(); 
    }

    return 0;
}


