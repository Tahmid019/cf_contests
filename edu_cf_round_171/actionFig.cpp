#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    vector<int> prevzeros(0);
    vector<int> prevones(0);
    for (int i{};i<n-1;i++){
        if (s[i] == '0')
            prevzeros.pb(i);
        else
            prevones.pb(i);
    }
    reverse(all(prevones));
    int pzi = prevzeros.size();
    int poi = prevones.size();
    pzi--;
    poi--;

    //cout<<poi<<" "<<pzi<<endl;

    int total = n * (n+1);
    total /= 2;

    for (int i{n-1};i>=0;i--){
        //cout<<i<<" "<<total<<endl;
        while(pzi>=0 && prevzeros[pzi]>=i)
            pzi--;
        while(poi>=0 && prevones[poi]>=i)
            poi--;
        if (s[i] == '1'){
            if (pzi >= 0){
                total -= i+1;
                pzi--;
            }
            else if (poi >= 0){
                total -= i+1;
                poi--;
            }
        }
    }
    cout<<total<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        
    }
    return 0;
}