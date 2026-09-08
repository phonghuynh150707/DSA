// TÌM BỘI CHUNG NHỎ NHẤT CỦA 2 SỐ NGUYÊN
#include <iostream>
#include <numeric>
using namespace std;
#define ll long long
int main(){
    int a,b; cin >> a >> b;
    cout << (a/gcd(a,b))*b << endl;
}