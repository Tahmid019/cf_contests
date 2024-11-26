/*
  Author: Pranava
  scholar id -> 2312177
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define pranav                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ll long long
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
 
class DisjointSets
{
private:
    vector<int> parents;
    vector<int> sizes;
 
public:
    DisjointSets(int size) : parents(size), sizes(size, 1)
    {
        for (int i = 0; i < size; i++)
        {
            parents[i] = i;
        }
    }
 
    /** @return the "representative" node in x's component */
    int find(int x)
    {
        return parents[x] == x ? x : (parents[x] = find(parents[x]));
    }
 
    /** @return whether the merge changed connectivity */
    bool unite(int x, int y)
    {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root)
        {
            return false;
        }
 
        if (sizes[x_root] < sizes[y_root])
        {
            swap(x_root, y_root);
        }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }
 
    /** @return whether x and y are in the same connected component */
    bool connected(int x, int y) { return find(x) == x; }
};
 
/************************************TEMPLATE ENDS*****************************************************/

void solve(){
ll n,k;cin>>n>>k;
if(n==1){
	if(k==1){
		cout<<1<<endl;
		cout<<1<<endl;
		return;
	}
	cout<<-1<<endl;
	return;
}
if(k==1||k==n){
	cout<<-1<<endl;
	return;
}

if(k%2==0){
	cout<<3<<endl;
	cout<<1<<' '<<k<<' '<<k+1<<endl;
	return;
}
cout<<3<<endl;
cout<<1<<' '<<k-1<<' '<<k+2<<endl;


}
 
 
int main()
{
    pranav
    ll tt; cin>>tt;
    while(tt--){
    solve();
    }
}