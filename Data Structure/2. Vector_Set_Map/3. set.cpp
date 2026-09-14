#include <iostream>
#include <set>
using namespace std;

int main(){
    // SET LÀ TẬP HỢP, ĐƯỢC XẾP THEO THỨ TỰ TĂNG DẦN
    set<int> s; // KHAI BÁO MỘT SET S RỖNG
    set<int, greater<int>> se; // SET RỖNG SẮP XẾP GIẢM DẦN
    s.insert(5); // THÊM PHẦN TỬ VÀO SET, KHÔNG TRÙNG NHAU
    s.size() // SỐ PHẦN TỬ TRONG SET
    s.clear(); // XÓA HẾT PHẦN TỬ TRONG SET
    if(s.empty()){} // KIỂM TRA XEM SET CÓ RỖNG KHÔNG

    // SET KHÔNG CÓ INDEX NÊN PHẢI DUYỆT BẰNG RANGE_BASED HOẶC ITERATOR
    for( auto x : s) cout << x << " "; // DUYỆT
    for( auto it = s.begin(); it != s.end(); it++){ // DUYỆT
        cout << *it << " "; // GIẢI THAM CHIẾU ITER
    }
    for( auto it = s.rbegin(); it != s.rend(); it++){ // DUYỆT NGƯỢC SET
        cout << *it << " ";
    }
    // CÁC HÀM KHÁC
    s.count(1); // TRẢ VỀ SỐ LẦN XUẤT HIỆN (0,1) -> CÓ HOẶC KHÔNG
    if(s.find(1) != s.end()){}; // HẦM FIND TÌM PHẦN TỬ TRONG SET
    s.erase(s.find(1)); // XÓA PHẦN TỬ BẰNG ITER, 1 PHẢI TỒN TẠI TRONG SET
    s.erase(x); // XÓA GIÁ TRỊ
    auto it = s.lower_bound(x); // PHẦN TỬ ĐẦU TIÊN >= X
    auto it = s.upper_bound(x); // PHẦN TỬ ĐẦU TIÊN > X

    // MULTISET: LƯU CÁC GIÁ TRỊ TRÙNG NHAU
    // XÓA GIÁ TRỊ SẼ XÓA HẾT -> XÓA BẰNG ITER PHẦN TỬ XH ĐẦU TIÊN: SE.FIND(X)
    // SE.COUNT(X): TRẢ VỀ NHIỀU HƠN 1
}