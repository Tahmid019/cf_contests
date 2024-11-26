#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        cin >> a[0];
        if(n == 1){
            cout << "1" << endl;
        }else{
            for(int i = 1; i < n;i++)
                cin >> a[i];
            if(n == 2){
                cout << a[1] - a[0] << endl;
            }else{
                int _even = INT_MIN;
                int _odd = INT_MIN;
                for(int i = 1; i < n; i++){
                    if(i%2 == 0){
                        _even = max(_even, a[i] - a[i-1]);
                    }else{
                        _odd = max(_odd, a[i] - a[i-1]);
                    }
                }
                cout << min(_odd, _even) << endl;
            }
        } 
        
        
        // if(n%2 == 0)
        //     cout << n/2 << endl;
        // else   
        //     cout << (n+1)/2 << endl;
        
    }
    return 0;
}