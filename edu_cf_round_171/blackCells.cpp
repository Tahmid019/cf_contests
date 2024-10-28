#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;

bool is_pos(int n, const vector<ll>& a, ll k){
    vector<bool> dp0(n+1, false);
    vector<bool> dp1(n+1, false);
    dp0[0] = true;
    dp1[0] = false;
    for(int i=0; i<n; i++){
        vector<bool> next0(n+1, false);
        vector<bool> next1(n+1, false);
        if(dp0[i]){
            if(i + 1 < n && abs(a[i+1] - a[i]) <= k){
                next0[i+2] = true;
            }
            if(k >=1){
                next1[i+1] = true;
            }
            if(dp1[i]){
                if(i + 1 < n && abs(a[i+1] - a[i]) <= k){
                    next1[i+2] = true;
                }
            }
            for(int j = 0; j <= n; ++j){
                if(next0[j]) dp0[j] = true;
                if(next1[j]) dp1[j] = true;
            }
        }
        return dp0[n] || dp1[n];
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for(auto &x: a) cin >> x;
        ll left  = 0, right = (ll)1e18;
        ll ans = right;
        while(left <= right){
            ll mid = left + (right  - left)/2;
            if(is_pos(n, a, mid)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        cout << ans << endl;
        
    }
    return 0;
}

// int main() {
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<long long> a(n);
//         for(int i = 0; i < n;i++){
//             cin>>a[i];
//         }
//         long long ans = 0;
//         for(int  i = 0; i < n;i+=2){
//             if(i != n-1){
//                 ans = max(ans,a[i+1]-a[i]);
//             }
//         }
//         if(n%2 != 0){
//             long long again = 0;
//             for(int  i = 1; i < n;i+=2){
//                 again = max(again,a[i+1]-a[i]);
//             }
//             ans = min(ans,again);
//         }
//         if(n == 1){
//             cout<<1<<endl;
//         }else {
//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }