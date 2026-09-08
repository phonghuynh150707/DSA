// GIẢI PHƯƠNG TRÌNH AX^2 + BX + C = 0
#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

int main(){
    double a,b,c; cin >> a >> b >> c;
    double res1, res2;
    if(a == 0){
        if(b == 0){
            if(c != 0){
                cout << "No solution" << endl;
                return 0;
            }
            else{
                cout << "Infinite Solution" << endl;
                return 0;
            }
        }
        else{
            res1 = -c/b;
            cout << res1 << endl;
            return 0;
        }
    }
    else{
        double delta = b*b - 4*a*c;
        if(delta < 0){
            cout << "No solution" << endl;
            return 0;
        }
        else if(delta == 0){
            res1 = -b/(2*a);
            cout << res1 << endl;
            return 0;
        }
        else{
            res1 = (-b+sqrt(delta))/(2*a);
            res2 = (-b-sqrt(delta))/(2*a);
            cout << res1 << " " << res2 << endl;
            return 0;
        }
    }
}