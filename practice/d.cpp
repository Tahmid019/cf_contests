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



void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    inpur(a, n);
    // cout << a[0] << endl;
    
    unordered_map<ll, ll> mp(n);
    ll _mx = 1; //lead val
    ll cnt = 1; // lead count
    int f = 0;

    vll b(n);
    b[0] = a[0];
    for(int i = 1; i<n-1; i++){
        ll k = (f == 0) ?  ++mp[a[i]] : ++mp[a[i+1]];
        // cout << k << endl;
        // _mx = max(_mx, k);
        cout << "max = " << _mx << " " << "k = " << k << " " << "cnt = " << cnt << "--> ";
        if(_mx < k){
            _mx = k;
            cnt = 1;
        }else if(_mx == k ) {
            cnt++;
        }
        cout << cnt << endl;

        // cout << _mx << " " << cnt << endl;

        if(cnt == 1){
            //relax cond
            f = 1;
            if(i == n-1){
                b[i] = a[i];
            }else{
                b[i] = a[i+1];
            }
        }else{
            //ness cond
            f = 0;
            b[i] = a[i];
        }
    }
    b[n-1] = a[n-1];
    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    cout << endl;

}

int main()
{
    tahmid
    ll tt; cin >> tt;
    while(tt--)
    {
        solve();
    }
    

    return 0;
}