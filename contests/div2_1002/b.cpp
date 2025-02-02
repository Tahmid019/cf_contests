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
    ll n, k;
    cin >> n >> k;
    ll x, y = 0, yy = 1, m = n-k;
    vll a;
    cin >> x;
    ll idx = 2 + m;
    ll _min = yy;
    ll f = 0;
    vll ko;
  
    forn(i, m + 1){
        cin >> x;
        // cout << x << " == " << endl;
        if(x != yy){
            f = 1;
            if(_min != 1){
                _min = min(_min,yy);


            }else{
                _min = yy;
            }
            // cout << _min << "  -- " << endl;
        }
        yy++;
        a.pb(x);
        ko.pb(x);
    }
    for(; idx < n; idx++){
        cin >> x;
        // cout << x << " =+= " << endl;
        if(y == 1){
            if(x != yy){
                f = 1;
                if(_min != 1){
                _min = min(_min,yy);

            }else{
                _min = yy;
            }
                // _min = min(_min, yy);
                // cout << _min << "  -+- " << endl;
            }
            yy++;
            a.pb(x);
            y = 0;
        }else{
            y = 1;
        }
    }

    if(f == 0){
        cout << yy << endl;
        return;
    }
    ll ii;
    // cout << ko.size() << "ko" << endl;
    for(ii = ko.size() - 1; ii> 0; ii--){
        if(ko[ii] != ko[ii-1] && f==1){
            _min = min(_min, ii);
            // cout << _min << "[][]" << endl;
        }
    }
    cout << _min << endl;

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