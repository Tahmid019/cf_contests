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
#include <algorithm>
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

        vector<int> b;
        vector<bool> visited(n + 1, false);
        for(int i = 0; i< n; i++){
            if(!visited[a[i]]){
                visited[a[i]] = true;
                b.push_back(a[i]);
            }
        }
        sort(b.begin(), b.end(), [](int x, int y) {
            return x > y;
        });

        cout << b.size() << endl;

        for(int i = 0; i< b.size(); i++) {
            if(i %2 == 0){
                cout << -b[i] << " ";
            }else{
                cout << b[i] << " ";
            }
        }

        cout << endl;
        
        
    }
    return 0;
}
