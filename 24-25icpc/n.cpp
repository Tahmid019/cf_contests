#include <iostream>
#include <vector>

#define ll long long
#define db double
#define dbl long double


const int MOD = 1e9 + 7;


using namespace std;



void solve() {
    string s; cin >> s;
    int a =  s[0] - '0', b =  s[2] - '0',c ;
    /*
    < - 1
    = - 2
    > - 3
    */
   if(s[1] == '<') c = 1;
   else if(s[1] == '=') c = 2;
   else c = 3;
   switch (c){
    case 1:
        if(a < b){cout << s << endl;}
        else{
            // cout << b - 1 << endl;
            // s[0] = (char)(b - 1 + '0');
            // cout << s << endl;
            if(a == b) s[1] = '=';
            else s[1] = '>';
            cout << s << endl;
        }
        return;

    case 2:
        if(a == b){cout << s << endl;}
        else{
            // s[0] = (char)(b + '0');
            if(a < b) s[1] = '<';
            else s[1] = '>';
            cout << s << endl;
        }
        return;
    case 3:
        if(a > b){cout << s << endl;}
        else{
            // s[0] = (char)(b + 1 + '0');
            if(a == b) s[1] = '=';
            else s[1] = '<';
            cout << s << endl;
        }
        return;
   }
}

int main(){
    ll t; cin >> t;
    while(t--){
        solve(); 
    }

    return 0;
}


