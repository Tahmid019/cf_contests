#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define ll long long
#define ff first
#define ss second

std::unordered_map<ll, std::vector<ll>> d;
std::unordered_map<ll, ll> depth, height;
std::unordered_map<ll, ll> subtree_cnt, even_cnt;

void dfs(std::unordered_map<ll, std::vector<ll>>& d, std::unordered_map<ll, bool>& vis, ll key) {
    std::cout << key << " ";
    
    for (auto val : d[key]) {
        if (vis[val]) continue;
        vis[val] = true;
        dfs(d, vis, val);
    }
}

void dfsTree(int key, int par = 0){
    
    subtree_cnt[key] += key;
    if(key % 2 == 0) even_cnt[key] += key;

    for(auto val:d[key]){
       
        if(val == par) continue;
        depth[val] = depth[key] + 1;

        
 
        dfsTree(val, key);
    
        subtree_cnt[key] += subtree_cnt[val];
        even_cnt[key] += even_cnt[val];
        height[key] = std::max(height[key], height[val] + 1);
 
 
 
    }



}

int main() {
    ll v, e;
    std::cin >> v >> e;

    // std::unordered_map<ll, std::vector<ll>> d;
    std::unordered_map<ll, bool> vis; 

    for (ll i = 0; i < e; i++) {
        ll a, b;
        std::cin >> a >> b;
        d[a].push_back(b);
        d[b].push_back(a);
        vis[a] = vis[b] = false; 
    }

    // for (const auto& pair : d) {
    //     ll key = pair.first;
    //     if (!vis[key]) {
    //         vis[key] = true;
    //         dfs(d, vis, key);
    //     }
    // }
    dfsTree(1,0);
    for(auto p : depth){
        std::cout << p.ff << " == " << p.ss << std::endl;
    }
    std::cout << "\nHeight\n";
    for(auto p : height){
        std::cout << p.ff << " == " << p.ss << std::endl;
    }
    std::cout << "subtree count" << std::endl;
    for(auto p : subtree_cnt){
        std::cout << p.ff << " == " << p.ss << std::endl;
    }
    std::cout << " even count" << std::endl;
    for(auto p : even_cnt){
        std::cout << p.ff << " == " << p.ss << std::endl;
    }


    return 0;
}
