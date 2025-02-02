/*
    Author: Tahmid Choudhury
    Scholar ID: 2312184
*/
#include<bits/stdc++.h>


using namespace std;

#define tahmid                          \
    ios_base::sync_with_stdio(false);   \
    cin.tie(NULL);

#define pb push_back
#define mp make_pair

#define ll long long
#define db double
#define ldb long double
#define ul unsigned long

#define be begin()
#define en end()
#define rbe rbegin()
#define ren rend()
#define asort(vec) sort(vec.begin(), vec.end())
#define dsort(vec) sort(vec.begin(), vec.end(), greater<long long>())

#define vc vector<char>
#define vi vector<int>
#define vll vector<long long>
#define vdb vector<double>
#define vldb vector<long double>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vpdb vector<pair<double, double>>
#define vpci vector<pair<char, int>>
#define vpic vector<pair<int, char>>
#define vpcll vector<pair<char, long long>>
#define vpllc vector<pair<long long, char>>

#define forn(i,n) for(long long i = 0; i<n; i++)
#define rep(var, start, end) for(long long var = start; var < end; var++)

#define ff first
#define ss second

#define apriority priority_queue<long long, vector<long long>, greater<long long>>
#define dpriority priority_queue<long long>

#define inpur(var, n)               \
    for(long long i = 0; i<n ; i++) \
    {                               \
        cin >> var[i];              \
    }    

/*======================================= TEMPLATE ENDS ============================================================================================================================================================================================================================================================================================*/


bool ncomb(vector<ll>& v, ll n) {
    ll k = v.size();
    for(ll i = k-1; i >= 0; --i) {
        if(v[i] < n - k + i + 1) {
            ++v[i];
            for(ll j = i+1; j < k; ++j) {
                v[j] = v[j-1] + 1;
            }
            return true;
        }
    }
    return false;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(auto& x : a) cin >> x;
    
    ll _min = LLONG_MAX;
    
    if(k == 0) {
        vector<ll> b;
        for(ll num : a) b.pb(num);
        b.pb(0);
        ll tc = 0;
        while(tc < b.size() && b[tc] == tc + 1) {
            ++tc;
        }
        _min = tc + 1;
    }else{
        vector<ll> sps(k);
        for(ll i = 0; i < k; ++i) {
            sps[i] = i + 1;
        }
        
        do{
            ll exp = 1;
            ll tc = 0;
            ll st = 0;
            bool stp = false;
            vector<ll> r = sps;
            for(ll i = 0; i < k; ++i) {
                if(i % 2 == 1) { 
                    ll end = r[i];
                    for(ll j = st; j < end; ++j) {
                        if(j >= n) break;
                        if(a[j] == exp) {
                            exp++;
                            tc++;
                        } else {
                            stp = true;
                            break;
                        }
                        if(tc + 1 >= _min) {
                            stp = true;
                            break;
                        }
                    }
                    if(stp) break;
                }
                st = r[i];
            }
            if(!stp){
                if(k % 2 == 1){ 
                    for(ll j = st; j < n; ++j){
                        if(a[j] == exp){
                            exp++;
                            tc++;
                        }else{
                            break;
                        }
                        if(tc + 1 >= _min){
                            break;
                        }
                    }
                }
            }
            _min = min(_min, tc + 1);
            if (_min == 1) break;
        }while(ncomb(sps, n));
    }
    
    cout << _min << endl;
}

int main() {
    tahmid
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}