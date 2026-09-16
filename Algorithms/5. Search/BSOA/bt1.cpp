// CÓ N MÁY, MẢNG A[I]: TỐC ĐỘ LÀM RA SẢN PHẨM MÁY THỨ I, TÌM MIN TIME TẠO RA ÍT NHẤT T SP.
// CÁC MÁY HOẠT ĐỘNG ĐỒNG THỜI ĐỂ TẠO RA SP
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define ll long long // DÙNG LL ĐỂ TRÁNH TRÀN SỐ

bool check(int a[], ll len, ll time, ll product){
    ll work = 0; // SỐ SẢN PHẨM LÀM RA TRONG TIME (S)
    for(int i = 0; i < len; i++){ // DUYỆT QUA THỜI GIAN TỪNG SP
        work += time/a[i]; // MỖI SP ĐÓNG GÓP VÀO SỐ MÁY TRONG TIME S
    }
    return work >= product; // NẾU TRONG TIME S TẠO ĐƯỢC SP >= YÊU CẦU THÌ THỎA
}

int main(){
    ll n,t; cin >> n >> t; int a[1005]; // NHẬP N SỐ MÁY VÀ T SỐ SẢN PHẨM CẦN LÀM RA
    for(ll i = 0; i < n; i++) cin >> a[i]; // THỜI GIAN MÁY THỨ I 
    // ƯỚC CHỪNG SEARCH SPACE: THỜI GIAN MÁY LÂU NHẤT LÀM TẤT CẢ SPI
    ll left = 0, right = 1LL*t*(*max_element(a,a+n)); 
    ll res = LLONG_MAX; // BIẾN LƯU KẾT QUẢ: TÌM MIN NÊN ĐẶT BAN ĐẦU LÀ MAX
    while(left <= right){ // ĐIỀU KIỆN LẶP
        ll mid = left + (right-left)/2; // TÌM VÀO GIỮA, MỖI LẦN BỎ ĐI NỬA KHOẢNG
        if(check(a,n,mid,t)){ // GT THỎA THÌ TÌM VỀ PHÍA TRÍA: ĐỂ TÌM GIÁ TRỊ TỐT HƠN
            right = mid - 1;
            res = mid; // LƯU LẠI KQ THỎA
        }
        else left = mid + 1;
    }
    cout << res;
}