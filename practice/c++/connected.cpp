#include <iostream>
#include <vector>
#include <unordered_map>

#define ll long long

std::unordered_map<ll, std::vector<ll>> d;
std::unordered_map<ll, bool> vis; 

std::vector<std::vector<int>> cc;
std::vector<int> c_cc;

inline void dfs(ll key) {
    vis[key] = true;
    c_cc.push_back(key);
    for (auto val : d[key]) {
        if (vis[val]) continue;
        dfs(val);
    }
}

int main(){
    ll v, e;
    std::cin >> v >> e;

    // ll cnt = 0;

    for (ll i = 0; i < e; i++) {
        ll a, b;
        std::cin >> a >> b;
        d[a].push_back(b);
        d[b].push_back(a);
        vis[a] = vis[b] = false; 
    }

    for (const auto& pair : d) {
        ll key = pair.first;
        if (vis[key]) continue;
        c_cc.clear();
        dfs(key);
        cc.push_back(c_cc);
        // cnt++;
    }

    std::cout << cc.size() << std::endl;

    for(auto ccc : cc){
        for(auto vertex : ccc){
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
