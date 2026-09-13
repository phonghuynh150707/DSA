#include <iostream>
#include <vector>
using namespace std;

// CHO 2 DÃY KHÔNG GIẢM M,N PHẦN TỬ -> XẾP THÀNH DÃY KHÔNG GIẢM
int main(){
    int m,n; cin >> m >> n; 
    vector<int> a(m); vector<int> b(n); // 2 DÃY KHÔNG GIẢM
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<int> res; // MẢNG ĐÃ ĐƯỢC MERGE
    int i = 0, j = 0; // ĐẶT 2 CON TRỎ VÀO ĐẦU
    while(i < m && j < n){
        if(a[i] < b[j]){ // BÉ HƠN THÌ XẾP VÀO TRƯỚC
            res.push_back(a[i]); i++;
        }
        else{
            res.push_back(b[j]); j++;
        }
    }
    while(i < m){ // PHẦN TỬ CÒN LẠI KHI ĐÃ DUYỆT XONG
        res.push_back(a[i]); i++;
    }
    while(j < n){ // PHẦN TỬ CÒN LẠI KHI ĐÃ DUYỆT XONG
        res.push_back(b[j]); j++;
    }
}