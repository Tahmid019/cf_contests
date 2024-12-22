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


void solve(){
ll n,k;cin>>n>>k;
vll a(n);
vll b(n);
inpur(a,n);
inpur(b,n);
vpll just;
vpll negs;
for(ll i=0;i<n;i++){
	just.pb({a[i],0});
	just.pb({b[i],0});
	just.pb({b[i]+1,-1});
	negs.pb({a[i]+1,+1});
	negs.pb({b[i]+1,-1});
}

asort(just);
asort(negs);
//cout<<just.size()<<endl;
//cout<<endl;
ll idx=0;
ll ptr=0;
ll neg=0;
ll buys=n;
ll ans=0;
ll ans1=0;
while(ptr<3*n){
	ll val=just[ptr].ff;
	buys+=(just[ptr].ss);
	while(ptr<3*n-1&&just[ptr+1].ff==val){
		ptr++;
		buys+=(just[ptr].ss);
	}
	while(idx<2*n&&val>=negs[idx].ff){
		neg+=negs[idx].ss;
		idx++;
	}
	//cout<<val<<' '<<neg<<endl;
	if(neg<=k){
		//cout<<buys<<' '<<val<<' '<<neg<<endl;
	ans=max(ans,buys*val);
	}
	
	ptr++;
}
cout<<ans<<endl;
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