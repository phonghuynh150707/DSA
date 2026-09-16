// CÓ N SỢI DÂY, SỢI DÂY THỨ I CÓ ĐỘ DÀI A[I]
// CẮT TỪNG SỢI DÂY THÀNH NHỮNG ĐOẠN BẰNG NHAU L, TÌM L MAX
// CÓ TỐI THIỂU K SỢI DÂY
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define ll long long

bool check(ll a[], ll len, ll L, ll k){
    ll work = 0; // SỐ SỢI DÂY ĐỘ DÀI L
    for(int i = 0; i < len; i++){ // DUYỆT QUA TỪNG SỢI DÂY
        work += a[i]/L; // MỖI SỢI ĐÓNG GÓP A[I]/L SỢI
    }
    return work >= k; // SỐ SỢI >= K TỐI THIỂU
}

int main(){
    ll n, k; cin >> n >> k; ll a[1005];
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll left = 1, right = *max_element(a,a+n); // KHÔNG THỂ CẮT CAO HƠN SỢI DÂY DÀI NHẤT ĐƯỢC 
    ll res = 0; // BIẾN LƯU KQ, PHÒNG TH KHÔNG TỒN TẠI THÌ TRẢ 0
    while(left <= right){ // ĐK LẶP BS
        ll mid = left + (right-left)/2; // XÉT ĐỘ DÀI Ở GIỮA, RỒI NHẢY RA 2 BÊN
        if(check(a,n,mid,k)){
            left = mid + 1; // THỎA THÌ TÌM BÊN PHẢI ĐỂ CÓ GIÁ TRỊ LỚN HƠN
            res = mid; // CẬP NHẬT KQ
        }
        else right = mid - 1;
    }   
    cout << res;
}