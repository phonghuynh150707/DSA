#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    vector<int> v; // TẠO VECTOR V RỖNG, LOẠI INT
    vector<int> a(n); // // TẠO VECTOR N PHẦN TỬ
    vector<int> b = {1,2,3,4,5};
    v.push_back(2); // THÊM PHẦN TỬ VÀO CUỐI VECTOR
    v.pop_back(); // XÓA PHẦN TỬ Ở CUỐI VECTOR
    v.front(); // PHẦN TỬ ĐẦU
    v.back(); // PHẦN TỬ CUỐI
    v[v.size()-1] // PHẦN TỬ CUỐI TƯƠNG ĐƯƠNG V.BACK()
    int size = v.size(); // SỐ LƯỢNG PHẦN TỬ CỦA VECTOR
    v.clear(); // XÓA MỌI PHẦN TỬ TRONG VECTOR
    if(v.empty()){}; // KIỂM TRA VECTOR CÓ RỖNG HAY KHÔNG (TRẢ VỀ T F)
    
    // ITERATOR
    v.begin() // TRỎ VÀO ĐẦU
    v.end() // TRỎ VÀO PHẦN TỬ SAU CUỐI
    v.rbegin() // TRỎ VÀO PHẦN TỬ CUỐI
    v.rend() // TRỎ VÀO TRƯỚC PHẦN TỬ ĐẦU
    vector<int>::iterator it; // KHAI BÁO ITERATOR
    for(auto it = v.begin(); it != v.end(); it++){ // DUYỆT VECTOR
        cout << *it << " "; // GIẢI THAM CHIẾU ITER
    }
    for( auto x : v){ // DUYỆT MẢNG BẰNG AUTO
        cout << x << " ";
    }
    for(int i = 0; i < n; i++){ // GÁN GIÁ TRỊ TRONG MẢNG
        cin >> v[i];
    }
    int index, val; // VỊ TRÍ, GIÁ TRỊ
    v.insert(v.begin() + index, val); // CHÈN VÀO VỊ TRÍ INDEX
    v.erase(v.begin() + index); // XÓA PHẦN TỬ Ở VỊ TRÍ INDEX
    reverse(v.begin(), v.end()) // ĐẢO NGƯỢC MẢNG
    sort(v.begin(), v.end()) // SẮP XẾP MẢNG TĂNG DẦN
}