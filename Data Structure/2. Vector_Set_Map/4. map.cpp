#include <iostream>
#include <map> // LƯU DẠNG PAIR, XẾP THEO KEY (KEY,VALUE)

int main(){
    map<int,int> mp; // KHAI BÁO MAP MP RỖNG
    mp[3] = 2; // TẠO CẶP KEY_VALUE {3,2} TRONG MAP
    mp.insert({3,2}); // THÊM CẶP KEY_VALUE BẰNG HÀM INSERT
    mp.size(); // SỐ LƯỢNG PHẦN TỬ TRONG MAP
    mp.empty(); // KIỂM TRA XEM MAP CÓ RỖNG KHÔNG
    mp.clear(); // XÓA HẾT MỌI PHẦN TỬ TRONG MAP
    
    // DUYỆT MAP
    for( auto x : mp) cout << x.first << " " << x.second;
    for( pair<int,int> x : mp) cout << x.first << " " << x.second;
    for( auto [key,value] : mp) cout << key << " " << value;
    for(auto it = mp.begin(); it != mp.end; it++){
        cout << (*it).first << " " << (*it).second;
    }

    // CÁC HÀM KHÁC
    auto it = mp.find(5); // TÌM KIẾM KEY
    mp.count(key); // SỐ LẦN XUẤT HIỆN CỦA KEY (0,1)
    mp.erase(it); // XÓA THEO ITER
    mp.erase(5); // XÓA THEO KEY
    // LƯU Ý CẦN XÁC NHẬN TỒN TẠI TRƯỚC KHI XÓA!
    auto it = mp.lower_bound(x); // TRẢ KEY >= X
    auto it = mp.upper_bound(x); // TRẢ KEY > X

    // BÀI TOÁN ĐẾM TẦN SUẤT
    int n; cin >> n; int a[100];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        mp[a[i]]++;
    } 
}