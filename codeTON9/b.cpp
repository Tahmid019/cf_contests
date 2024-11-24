#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#define ll long long
#define db double
#define dbl long double

using namespace std;

int summ(int n){
    return (n*(n+1))/2;
}

int full(string s){
    ll n = s.size();
    ll cnt = 0;
    ll cc = 1;
    for(ll i = 1; i<n; i++){
        if(s[i] == s[i-1]) cc++;
        else{
            cnt += summ(cc-1);
            cc = 1;
        }
    }
    return summ(n) - cnt;
}

void solve() {
    string s; cin>>s;
    ll n = s.size();
    
    int a = 0; 
    while(a<n){
        string res = s.substr(a, n-a);
        ll k = full(res);
        if(k%2 == 0){
            cout << res << endl;
            return;
        }
        a++;
    }
    if(a>= n) cout << -1 << endl;


}

void sol(){
    string s; cin>> s;
    int n = s.size();
    for(int i = 1; i<n; i++){
        if(s[i] == s[i-1]){
            cout << s.substr(i-1, 2) << endl;
            return;
        }
    }
    if(n == 1 || n== 2){cout << -1 << endl;return;}
    for(int i = 2;i<n; i++ ){
        if(s[i] != s[i-2]){
            cout << s.substr(i-2, 3)<< endl;
            return;
        }
    }
    cout << -1 << endl;
    
}

int main(){
    int t; cin >> t;
    while(t--){
        sol(); 
    }

    return 0;
}


