// #include<iostream>
// #include<cmath>

// using namespace std;

// int oddfloor(int n){
//     int k = floor(n);
//     if(k%2 == 0) return k-1;
//     return k; 
// }

// int main() {
    
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         // int a = 1;
//         // int b = 3;
//         if(n == 1){
//             cout << "Sakurako" << endl;
//         }else if(n == 3){
//             cout << "Kosuke" << endl;
//         }else {
//             int k = oddfloor(n);
//             if((k-1)%4 == 0 && (k-3)%4 != 0) 
//                 cout << "Kosuke" << endl;
//             else
//                 cout << "Sakurako" << endl;
//         }
        


//         // if(a - b < 0.5)
//             // cout << "Kosuke" << endl;
//         // else
//             // cout << "Sakurako" << endl;

//     }

//     return 0;
// }



#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> matrix(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        
        int operations = 0;
        
        for (int size = 1; size <= n; size++) {  // Iterate over submatrix sizes
            for (int i = 0; i + size <= n; i++) {  // Top-left corner row
                for (int j = 0; j + size <= n; j++) {  // Top-left corner column
                    for (int k = 0; k < size; k++) {  // Walk along the diagonal of the submatrix
                        if (matrix[i + k][j + k] < 0) {
                            operations += -matrix[i + k][j + k];  // Fix the negative value
                            matrix[i + k][j + k] = 0;  // Set it to 0
                        }
                    }
                }
            }
        }
        
        cout << operations << endl;
    }

    return 0;
}
