#include <iostream>
using namespace std;
// TÌM ĐOẠN CON NGẮN NHẤT CÓ TỔNG >= K: MẢNG DƯƠNG
int main(){
    int n, k; cin >> n >> k; int a[1000];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int left = 1, right = 1; int sum = 0, length = INT_MAX;
    while(right <= n){
        sum += a[right];
        while(sum >= k){
            length = min(length, right-left+1);
            sum -= a[left];
            left++;
        }
        right++;
    }
    if(length == INT_MAX) cout << 0 << endl;
    else cout << length << endl;
}