// CÓ N CÂY, CÂY THỨ I CAO A[I]
// CẦN THU HOẠCH ÍT NHẤT L ĐƠN VỊ GỖ
// MỖI LẦN CỬA Ở ĐỘ CAO H: NẾU A[I] > H: CƯA A[I]-H, NGƯỢC LẠI 0
// TÌM ĐỘ CAO H LỚN NHẤT
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define ll long long

bool check(ll a[], ll n, ll H, ll L){
    // H: ĐỘ CAO CẮT, L: LƯỢNG GỖ TỐI THIỂU
    ll work = 0; // LƯỢNG GỖ CẮT ĐƯỢC Ở ĐỘ CAO CƯA H
    for(int i = 0; i < n; i++){ // DUYỆT QUA TỪNG CÂY
        if(a[i] > H) work += a[i] - H; // CAO HƠN THÌ CẮT!
    }
    return work >= L; // LƯỢNG GỖ TỐI THIỂU THỎA MÃN 
}

int main(){
    ll n, l; cin >> n >> l; ll a[1005]; // SỐ CÂY VÀ LƯỢNG GỖ TỐI THIỂU
    for(ll i = 0; i < n; i++) cin >> a[i]; // ĐỘ CAO CÂY THỨ I
    ll left = 0, right = *max_element(a,a+n); // RIGHT: ĐẶT Ở CÂY CAO NHẤT
    int res = INT_MIN;
    while(left <= right){ // ĐK LẶP BS
        ll mid = left + (right-left)/2; // ĐỘ CAO Ở GIỮA
        if(check(a,n,mid,l)){
            left = mid + 1; // TÌM BÊN PHẢI ĐỂ CÓ KQ TỐT HƠN
            res = mid; // GHI NHẬN LẠI KQ
        }
        else right = mid-1; // TÌM BÊN TRÁI
    }
    cout << res; // XUẤT RA KQ
}