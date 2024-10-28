#include<iostream>
// #include<vector>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // vector<int> a(n);
        // vector<int> b(n);
        int maxa = 0;
        int maxb = 0;
        while(n--){
            int x, y;
            cin >> x >> y;
            maxa = max(maxa, x);
            maxb = max(maxb, y);
            
        }
        cout << maxa*2 + maxb*2<<endl;

    }

    return 0;
}