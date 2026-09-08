#include <iostream>
#include <vector>
#include <utility> 

int main(){
    pair<int,int> p; // KHAI BÁO PAIR P
    pair<int,int> p = make_pair(1,2); // TẠO PAIR P VỚI HÀM MAKE_PAIR
    pair<int,int> p = {1,2}; // TẠO PAIR P VỚI {}
    pair<char,int> p; // PAIR CÓ THỂ KẾT HỢP NHIỀU KIỂU DỮ LIỆU
    p.first; // PHẦN TỬ THỨ NHẤT
    p.second; // PHẦN TỬ THỨ HAI

    // ARRAY OF PAIR
    int n; cin >> n;
    pair<int,int> a[100];
    for(int i = 0; i < n; i++){ // DUYỆT QUA PAIR
        cin >> a[i].first >> a[i].second; // NHẬP VỊ TRÍ 1,2
    }

    // VECTOR OF PAIR
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        v.push_back({x,y});
    }
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    for(auto x : p){ // DUYỆT
        cout << x.first << " " << x.second;
    }
    for( auto [x,y] : p){ // DUYỆT: STRUCTURED BINDING
        cout << x << " " << y;
    }
    // PAIR ĐƯỢC SO SÁNH THEO THỨ TỰ TỪ ĐIỂN (TỪ FIRST SANG SECOND)
}