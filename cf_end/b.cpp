#include <iostream>
#include <string>

using namespace std;

long long fun(long long n){
    if(n == 1 || n == 3){
        return -1;
    }else if(n == 2){
        return 66;
    }else if(n == 4){
        return 3366;
    } else if( n%2 == 0){
        string s = "3366";
        for(long long i = 0; i<n-4; i++){
            s = '3' + s;
        }
        return stoi(s);
    }else{
        string s = "36366";
        for(long long i = 0; i<n-5; i++){
            s = '3' + s;
        }
        return stoi(s);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << fun(n) << endl;
        
    }
    return 0;
}