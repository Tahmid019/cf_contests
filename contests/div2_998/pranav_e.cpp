/*
  Author: Pranava
  scholar id -> 2312177
*/
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
 
// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// template <class T>
// using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define pranav                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define be begin()
#define en end()
#define rbe rbegin()
#define ren rend()
#define asort(vec) sort(vec.begin(), vec.end())
#define dsort(vec) sort(vec.begin(), vec.end(), greater<long long>())
#define vll vector<long long>
#define vpll vector<pair<long long, long long>>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define rep(var, start, end) for (long long var = start; var < end; var++)
#define ff first
#define ss second
#define vi vector<int>
#define apriority priority_queue<long long, vector<long long>, greater<long long>>
#define dpriority priority_queue<long long>
#define input(vec, n)                 \
    for (long long i = 0; i < n; i++) \
    {                                 \
        cin >> vec[i];                \
    }
#define lcm(a, b) ((a * b) / (__gcd(a, b)))
#define lpow(a, b) (ll) pow(a, b)
#define minel *min_element
#define maxel *max_element
 
// Debugging helpers
#define debug(x) cerr << #x << " = " << (x) << endl;
 
// Template for modular arithmetic (modular addition, subtraction, multiplication)
const ll MOD = 1e9 + 7;
ll mod_add(ll a, ll b, ll m = MOD) { return ((a % m) + (b % m)) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return (((a % m) - (b % m)) + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }
 
// Function to perform modular exponentiation
ll mod_exp(ll base, ll exp, ll mod)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = mod_mul(result, base, mod);
        }
        base = mod_mul(base, base, mod);
        exp /= 2;
    }
    return result;
}
 
// Function to compute modular inverse
ll mod_inv(ll a, ll mod)
{
    return mod_exp(a, mod - 2, mod);
}
 
bool isPrime(long long n)
{
    return n > 1 && (n == 2 || (n % 2 && none_of(begin(array<int, 5>{3, 5, 7, 11, 13}), end(array<int, 5>{3, 5, 7, 11, 13}), [n](int i)
                                                 { return i * i <= n && n % i == 0; })));
}
 
vector<bool> primesieve(ll n)
{
    vector<bool> ans(n + 1, true);
    ans[0] = false;
    ans[1] = false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (ans[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                ans[j] = false;
            }
        }
    }
    return ans;
}
 
vector<ll> spf(ll n)
{
    vector<ll> ret(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        ret[i] = i;
    }
 
    for (ll i = 2; i * i <= n; i++)
    {
        if (ret[i] == i)
        {
            for (ll j = i * i; j <= n; j += i)
            {
                if (ret[j] == j)
                {
                    ret[j] = i;
                }
            }
        }
    }
    return ret;
}
 
void factorisation(ll n)
{
    vll factors = spf(n);
    while (n != 1)
    {
        cout << factors[n] << ' ';
        n /= factors[n];
    }
    cout << endl;
}
 
void print(vll a)
{
    for (auto pos : a)
    {
        cout << pos << ' ';
    }
}
 
pair<ll, ll> prod(ll val)
{
    if ((val & 1) == 0)
    {
        return mp((val >> 1), (val >> 1));
    }
    return mp((val >> 1), ((val >> 1) + 1));
}
 
class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;
 
  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}
 
	/** @return the "representative" node in x's component */
	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }
 
	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }
 
		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}
 
	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};
 
 


/****TEMPLATE ENDS*******/

/*
struct Node{
	ll And=0;
	ll Or=0;
	ll len=0;
};
Node id;

Node merge(Node prev,Node left,Node right){
	prev.And=(left.And+right.And);
	prev.len=left.len+right.len;
	prev.And+=(prev.len*prev.Or);
	return prev;
}

Node segtree[1200005];
ll arr[300005];

void build(ll l,ll r,ll node){
	if(l>r)return;
	if(l==r){
		segtree[node].And=0;
		segtree[node].Or=0;
		segtree[node].len=1;
		return;
	}
	ll mid=(l+r)>>1;
	build(l,mid,2*node);
	build(mid+1,r,2*node+1);
	segtree[node]=merge(segtree[node],segtree[2*node],segtree[2*node+1]);
}

ll query(ll l,ll r,ll tl,ll tr,ll node){
	if(l>r||tl>tr||tl>r||tr<l)return 0LL;
	if(tl>=l&&tr<=r){
		return segtree[node].And;
	}
	ll mid=(tl+tr)>>1;
	ll L=max(l,tl);
	ll R=min(r,tr);
	return ((segtree[node].Or)*(R-L+1)+(query(l,r,tl,mid,2*node)+query(l,r,mid+1,tr,2*node+1)));
}

void update(ll l,ll r,ll val,ll tl,ll tr, ll node){
	ll mid=(tl+tr)>>1;
	if(tl>tr||tr<l||tl>r||l>r)return ;
	if(tl>=l&&tr<=r){
		segtree[node].Or+=val;
		segtree[node].And+=(val*segtree[node].len);
		return;
	}
	update(l,r,val,tl,mid,2*node);
	update(l,r,val,mid+1,tr,2*node+1);
	segtree[node]=merge(segtree[node],segtree[2*node],segtree[2*node+1]);
	
}
*/

vector<set<ll>>graph1,graph2;
vll visited;
vll visited1;

void cle(ll n){
	graph1.clear();
	graph2.clear();
	visited.clear();
	visited1.clear();
	graph1.resize(n+1);
	graph2.resize(n+1);
	visited.resize(n+1,0);
	visited1.resize(n+1,0);	
}


void solve(){
	ll n,m1,m2;
	
	cin>>n>>m1>>m2;
	cle(n);
	ll answer=0;
	while(m1--){
		ll u,v;cin>>u>>v;
		graph1[u].insert(v);
		graph1[v].insert(u);
	}
	while(m2--){
		ll u,v;cin>>u>>v;
		graph2[u].insert(v);
		graph2[v].insert(u);
	}
	for(ll i=1;i<=n;i++){
		if(!visited[i]){
			queue<ll>just;
			just.push(i);
			set<ll>temp;
			temp.insert(i);
			visited[i]=1;
			while(just.size()!=0){
				ll val=just.front();
				just.pop();
				for(auto pos:graph2[val]){
					if(!visited[pos]){
						visited[pos]=1;
						just.push(pos);
						temp.insert(pos);
					}
				}
			}
			
			//set<ll>other;
			//other.insert(i);
			visited1[i]=1;
			just.push(i);
			temp.erase(i);
			
			while(temp.size()!=0||just.size()!=0){
				ll val=just.front();
				just.pop();
				set<ll>rems;
				for(auto pos:graph1[val]){
					if(!visited1[pos]){
						if(temp.find(pos)==temp.en){
							rems.insert(pos);
							answer++;
						}
						else{
							just.push(pos);
							visited1[pos]=1;
							temp.erase(pos);
						} 
					}
				}
				for(auto pos:rems){
					graph1[val].erase(pos);
					graph1[pos].erase(val);
				}
				rems.clear();
				if(temp.size()!=0&&just.size()==0){
					answer++;
					visited1[*temp.be]=1;
					just.push(*temp.be);
					temp.erase(temp.be);
				}
			}
		
			//debug("\n");
		}
	}
	cout<<answer<<endl;
}








 
 
int main()
{
	pranav
    ll tt=1;cin>>tt;
    while(tt--){
    solve();
    }
}