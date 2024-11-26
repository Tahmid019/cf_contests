#include <iostream>
#include <vector>
// #include <climits>

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(2*n);
        int aa = 0;
        for(int i = 0; i < 2*n; i++){
            cin >> a[i];
            if(a[i] == 1) aa++;
        }
        if(aa <= n){
            cout << aa%2 << " " << aa << endl;
        }else{
            cout <<aa%2 << " " << 2*n - aa << endl;
        }

        
    }
    return 0;
}