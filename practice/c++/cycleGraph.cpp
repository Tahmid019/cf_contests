#include <iostream>
#include <vector>
#include <unordered_map>

#define ll long long

std::unordered_map<ll, std::vector<ll>> d;
std::unordered_map<ll, bool> vis; 

std::vector<std::vector<int>> cc;
std::vector<int> c_cc;
std::vector<bool> loops;

bool cycle(ll key, ll par) {
    vis[key] = true;
    bool isLoop = true;
    c_cc.push_back(key);
    for (auto val : d[key]) {
        if(val == par) continue;
        if (vis[val]) return true;;
        
        isLoop |= cycle(val, key);
    }
    return false;
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
        bool loop = cycle(key, key);
        cc.push_back(c_cc); 
        loops.push_back(loop);
        // cnt++;
    }

    std::cout << cc.size() << std::endl;

    for(int i = 0; i< cc.size(); i++){
        for(auto vertex : cc[i]){
            std::cout << vertex << " ";
        }
        std::cout << "  ==  " << loops[i] << std::endl;
    }

    return 0;
}
