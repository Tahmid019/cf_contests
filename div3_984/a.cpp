
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int flag = 0;
        for(int i = 1; i < n; i++){
            if(abs(a[i] - a[i-1]) == 7 || abs(a[i] - a[i-1]) == 5){
                continue;
            }else{
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }

        if(flag == 0)
            cout<< "YES" <<endl;
        
        
    }
    return 0;
}
