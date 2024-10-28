#include <iostream>
#include <cmath>

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        if(x == y){
            cout << "0 0 " << x << " " << y << endl;
            cout << "0 " << y << " " << x << " 0" << endl;
        }else{
            int m = (x > y)? y : x;
            cout << "0 0 " << m << " " << m << endl;
            cout << "0 " << m << " " << m << " 0" << endl;
        }
        // if(k <= x && k <= y){
        //     cout << "0 0 0 " << k<< endl;
        //     cout << "0 0 " << k << " 0 "<< endl;
        // }else{
        //     /*
        //       p p p B
        //       p p p p 
        //       A p p p

        //       A = ( 0 0)
        //       B = (x ,  ceil(root(k**2 - (x+1)**2)) - 1   )
        //       C = (0, y)
        //       D = ( ceil(root(k**2 - (y+1)**2)) - 1, 0)
        //     */
            
        //     // cout <<"0 0 " << x << " "<< ceil(sqrt(k*k - (x)*(x))) - 1 << endl;
        //     // cout << "0 " << y << " " << ceil(sqrt(k*k - (y)*(y)))  << " 0" << endl;
        // }
        
    }
    return 0;
}