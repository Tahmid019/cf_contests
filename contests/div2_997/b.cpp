/*
    Author: Tahmid Choudhury
    Scholar ID: 2312184
*/
#include<bits/stdc++.h>


using namespace std;

#define tahmid                          \
    ios_base::sync_with_stdio(false);   \
    cin.tie(NULL);

#define pf push_front
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

const int MAXS = 200000;

void solve()
{
    ll n;
    cin >> n;

    vector<vector<ll>> a(n , vector<ll>(n, 0));
    forn(i, n){
        string s;
        cin >> s;

        for(ll j  = 0; j < n; j++){
            a[i][j] = (int)(s[j] - '0');
            // cout << a[i][j] << " ";
        }
        // cout << endl;
    }

    unordered_map<ll, int> ck;
    ck[1] = 1;
    deque<ll> dq;
    dq.pb(1);
    for(int i = 1; i <= n; i++){
        // if(ck[i] == 1) continue;
        deque<ll> temp;
        for(auto it : dq){
            if(ck[i] == 1) continue;
            if(i == it) continue;
            if(i > it){
                dq.pf(i);
                ck[i] = 1;
                continue;
            }
            if(a[i-1][it-1] == 1){
                dq.pf(i);
                ck[i] = 1;
            }else{
                temp.pb(dq.front());
                dq.pop_front();
            }
        }
        // cout << endl;
        while(!temp.empty()){
            ck[temp.back()] = 1;
            dq.pf(temp.back());
            temp.pop_back();
        }
        for(int j = i+1; j <= n; j++){
            if(ck[j] == 1) continue;
            if(a[i-1][j-1] == 1){
                dq.pb(j);
                ck[j] = 1;
            }
        }
    }
    for(auto it: dq){
        cout << it << " ";
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