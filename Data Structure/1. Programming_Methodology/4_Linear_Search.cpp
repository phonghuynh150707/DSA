// LINEAR SEARCH
#include <iostream>
using namespace std;
#define ll long long

bool LS(int a[], int find, int n){
    for(int i = 0; i < n; i++){
        if(a[i] == find) return true;
    }
    return false;
}
int main(){
    int n, X; cin >> n >> X; int a[100];
    for(int i = 0; i < n; i++) cin >> a[i];
    if(LS(a,X,n)){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}