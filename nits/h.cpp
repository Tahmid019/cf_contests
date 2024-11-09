#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;  
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        if (n == 2) {
            cout << "2 2\n";
        } else {
            if(n%2 != 0){
                cout << "2 ";            
                for (int i = 1; i < n - 1; ++i) {
                    cout << "1 ";       
                }
                cout << n << "\n";
            }else{
                for (int i = 1; i < n - 1; ++i) {
                    cout << "1 ";       
                }
                cout << "2 " << n << "\n";
            }      
        }
    }
    
    return 0;
}
