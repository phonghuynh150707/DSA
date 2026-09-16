// CÓ N KIỆN HÀNG: A[I]: TRỌNG LƯỢNG KIỆN HÀNG THỨ I
// ĐƯA VÀO CONTAINER ĐỂ VẬN CHUYỂN: <= K NGÀY
// MỖI NGÀY CHỞ CONTAINER HÀNG, TRỌNG LƯỢNG CONTAINER MIN?
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long


bool check(ll a[], ll n, ll mass, ll day){
    ll cnt = 0; // SỐ NGÀY
    ll sum = 0; // BIẾN TẠM ĐẾM SỐ NGÀY
    for(ll i = 0; i < n; i++){
        sum += a[i];
        if(sum > mass){ // LỚN HƠN MASS
            sum = a[i]; // CẬP NHẬT LẠI NGÀY ĐÓ
            cnt++; // ĐẾM++
        }
    }
    cnt++; // NGÀY THỪA SAU CÙNG
    return cnt <= day;
}

int main(){
    ll n, k; cin >> n >> k; ll a[1005]; ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i]; sum += a[i];
    }
    ll left = *max_element(a,a+n), right = sum; // CÂN NẶNG PHẢI TỐI THIỂU MAX ĐỂ CHỞ ĐƯỢC HẾT, RIGHT: CHỞ 1 LẦN
    ll res = -1; // BIẾN LƯU KQ
    while(left <= right){
        ll mid = left + (right-left)/2;
        if(check(a,n,mid,k)){
            right = mid - 1; // DỜI SANG TRÁI ĐỂ TÌM MIN
            res = mid; // GHI NHẬN KQ
        }
        else left = mid + 1; // DỜI SANG PHẢI ĐỂ TÌM TỐT HƠN
    }
    cout << res << endl;
}