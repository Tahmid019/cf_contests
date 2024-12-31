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



void solve() {
    ll n;
    cin >> n;
    string inputString;
    cin >> inputString;

    inputString = " " + inputString;

    vector<int> nextP(n + 2, n + 1);
    for (int i = n; i >= 1; i--) {
        if (inputString[i] == 'p') 
            nextP[i] = i;
        else 
            nextP[i] = nextP[i + 1];
    }

    vector<int> lastS(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (inputString[i] == 's') 
            lastS[i] = i;
        else 
            lastS[i] = lastS[i - 1];
    }

    vector<int> distances(n);
    for (int i = 1; i <= n; i++) {
        int nextPDistance = INT_MAX;
        if (nextP[i] <= n) {
            nextPDistance = nextP[i];
        }

        int lastSDistance = INT_MAX;
        if(lastS[i] >= 1){
            lastSDistance = n - lastS[i] + 1;
        }

        if(nextPDistance != INT_MAX && lastSDistance != INT_MAX){
            distances[i - 1] = min(nextPDistance, lastSDistance);
        }else if(nextPDistance != INT_MAX){
            distances[i - 1] = nextPDistance;
        }else if(lastSDistance != INT_MAX){
            distances[i - 1] = lastSDistance;
        }else{
            distances[i - 1] = n;
        }
    }

    sort(distances.begin(), distances.end());

    bool isValid = true;
    for(int i = 1; i <= n; i++){
        if (distances[i - 1] < i) {
            isValid = false;
            break;
        }
    }

    cout << (isValid ? "YES" : "NO") << "\n";
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