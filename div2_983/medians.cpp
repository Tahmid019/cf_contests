// #include <iostream>
// #include <vector>
// // #include <climits>

// using namespace std;


// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, k;
//         cin >> n >> k;
        
//         // if(n/2 + 1 != k){
//         //     cout << "-1" << endl;
//         // }else{
//         //     cout << n << endl;
//         //     for(int i = 1; i <= n; i++){
//         //         cout << i << " ";
//         //     }
//         //     cout << endl;
//         // }
//         int pre = k-1;
//         int post = n - k;
//         int g;
//         if(k == n){
//             if(k == 1){
//                 cout << 1 << endl << 1 << endl;
//             }else{
//                 cout << -1 << endl;
//             }
//         }else if(pre > post){
//             for(g = 1; pre%2 != 0; g *= 2){
//                 pre /= 2;
//             }
//             post /= g;
//             cout << 1+ 2*g << endl;
//             for(int i = 1; i<k; i = i + pre){
//                 cout << i << " ";
//             }
//             cout << k << " ";
//             for(int i = k+1; i<=n ; i= i+post){
//                 cout << i << " ";
//             }
//             cout << endl;

//         }else if(pre < post){
//             for(g = 1; post%2 != 0; g *= 2){
//                 post /= 2;
//             }
//             pre /= g;
//             cout << 1+ 2*g << endl;
//             for(int i = 1; i<k; i = i + pre){
//                 cout << i << " ";
//             }
//             cout << k << " ";
//             for(int i = k+1; i<=n ; i= i+post){
//                 cout << i << " ";
//             }
//             cout << endl;

//         }else {
//             cout << n << endl;
//             for(int i = 1; i <= n; i++){
//                 cout << i << " ";
//             }
//             cout << endl;
//         }

        
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
        int n, k;
        cin >> n >> k;
        
        if (k == n) {
            if (k == 1) {
                cout << 1 << endl << 1 << endl;
            } else {
                cout << -1 << endl;
            }
            continue;
        }

        int pre = k - 1;
        int post = n - k;
        
        if (pre == post) {
            cout << n << endl;
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << endl;
            continue;
        }

        int i_pre = (pre > post) ? pre / 2 : 1;
        int i_post = (post > pre) ? post / 2 : 1;
        
        cout << n << endl;

        for (int i = 1; i < k; i += i_pre) {
            cout << i << " ";
        }
        cout << k << " ";
        for (int i = k + 1; i <= n; i += i_post) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
