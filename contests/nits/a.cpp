#include <iostream>
#include <algorithm>
#define double long long
using namespace std;

void swap(double& a, double& b){
    if(a > b){
        double temp = a;
        a = b;
        b = temp;
    }
}

int main() {
    int t;
    cin >> t;

    
    while (t--) {
        double n, m, r1, r2;
        cin>>n>>m>>r1 >>r2;
        swap(r1, r2);
        double rr1 = 2*r1 + 1;
        double rr2 = 2*r2 + 1;
        int f1 = 0, f2 = 0;

        double tt = 0.8*r2 - 3.2;
        

        if(rr1  + rr2 > m && r1 > tt){
            cout << -1 << endl;
        }
        else{
            if(rr1 > n || rr1 > m) f1 = 1;
            if(rr2 > n || rr2 > m) f2 = 1;
            
            if(f1 == 1) cout  << (r2 + 1 + r2 + 1) << endl;
            else if(f2 == 1) cout  << (r1 + 1 + r1 + 1) << endl;
            else if(f1 == 0 && f2 == 0){
                
                if(r1 <= tt){
                    // cout << "aa" << endl;
                    cout << (2*r1 + 2 + 2*r2 + 2) << endl;
                }else{
                    // double ko = r1- tt;
                    // cout << "bb == " << ko  << endl;
                    cout << (r1 + 1 + rr1 + 1 + r1 + 1 + r2 + 1 + r2) << endl;
                }
            }
        } 
        
    }
    
    return 0;
}

