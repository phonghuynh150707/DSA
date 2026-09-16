#include <iostream>
using namespace std;
#define ll long long

ll bin_pow(ll a, ll b){ // TÍNH A^B
    if(b == 0) return 1; // A^0 = 1: BASE CASE
    ll X = bin_pow(a,b/2);
    if(b%2 == 0) return X*X; // B CHẴN: A^B = A^(B/2)*A^(B/2)
    else return X*X*a; // B LẺ: A^B = A^(B/2)*A^(B/2)*A
}
int main(){
    ll a,b; cin >> a >> b;
    cout << bin_pow(a,b) << endl;
}