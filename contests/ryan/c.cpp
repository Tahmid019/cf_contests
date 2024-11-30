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
        cin >> vec[i];              \
    }    

/*======================================= TEMPLATE ENDS ============================================================================================================================================================================================================================================================================================*/

vector<pair<int , int>> dirs = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};

bool isValis(ll n, ll m, pair<ll, ll> pos)
{
    return pos.ff >= 0 && pos.ff < n && pos.ss >= 0 && pos.ss < m;
}

vector<char> findLoc(vector<vector<char>> grid, pair<ll, ll> pos){
    ll n = grid.size(), m = grid[0].size();
    if(pos.ff == 0){
        if(pos.ff == 0){
            return {'R', 'D'};
        }else if(pos.ss == m-1){
            return {'L', 'D'};
        }else{
            return {'L', 'R', 'D'};
        }
    }else if(pos.ff == n-1){
        if(pos.ss == 0){
            return {'R', 'U'};
        }else if(pos.ss == m-1)
        {
            return {'L', 'U'};
        }else[
            return {'L', 'R', 'U'};
        ]
    }else{
        if(pos.ss == 0){
            return {'U', 'D', 'R'};
        }else if(pos.ss == m-1){
            return {'U', 'D', 'L'};
        }else{
            return {'U', 'D', 'R', 'L'};
        }
    }
}

void neig(vector<vector<char>> grid, pair<ll, ll> pos)
{
    for(auto dir : dirs)
    {
        pair<ll, ll> newPos = {pos.ff + dir.ff, pos.ss + dir.ss};
        if(isValid(grid, newPos)){
            vector<char> posb = findLoc(grid, newPos);
            for(auto c: posb){
                if(grid[newPos.ff][newPos.ss] == c) goto: pp;
            }
            
            pp:
        }

    }

}

bool isBad(vector<vector<char>> grid, pair<ll, ll> pos)
{
    ll n = grid.size(), m = grid[0].size;

    if(pos.ff == 0){
        if(pos.ss == 0){
            
        }else if(pos.ss == m-1){

        }else if(pos.ss < m){

        }
    }else if(pos.ff == n-1){
        if(pos.ss == 0){

        }else if(pos.ss == m-1){

        }else if(pos.ss < m){

        }
    }else if(pos.ff < n){
        if(pos.ss == 0){

        }else if(pos.ss == m-1){

        }else if(pos.ss < m){

        }
    }
}



void solve()
{
   ll n, m; cin >> n >> m;
   vector<vector<char>> grid;

   for(int i = 0; i < n ; i++)
   {
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
   }
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
