#include <iostream>
#include <vector>
using namespace std;

int main(){
    int row, col; cin >> row >> col; int a[1000][1000];
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            cin >> a[i][j]; // NHẬP TỪNG PHẦN TỬ TRONG MẢNG 2D
            cout << a[i][j] << " "; // XUẤT TỪNG PHẦN TỬ TRONG MẢNG 2D
        }
    }
    // VECTOR CÁC VECTOR LƯU MẢNG 2 CHIỀU
    vector<vector<int>> v;
    while(row--){ // SỐ HÀNG
        vector<int> x; // LƯU PHẦN TỬ TRONG HÀNG ĐÓ
        while(col--){
            int y; cin >> y; x.push_back(y);
        }
        v.push_back(x);
    }
    // MẢNG CÁC VECTOR
    vector<int> a[1000];
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            int x; cin >> x; 
            a[i].push_back(x);
        }
    }
    // TRONG MA TRẬN VUÔNG
    // CÁC PHẦN TỬ TRÊN ĐƯỜNG CHÉO CHÍNH: I = J
    // CÁC PHẦN TỬ TRÊN ĐƯỜNG CHÉO PHỤ: I + J = N+1

    // KỸ THUẬT DUYỆT Ô LIỀN KỀ
    // DUYỆT 8 Ô KỀ
    int dx_1[8] = {-1,-1,-1,0,0,1,1,1};
    int dy_1[8] = {-1,0,1,-1,1,-1,0,1};

    // DUYỆT 4 Ô KỀ
    int dx_2[4] = {-1,0,0,1};
    int dy_2[4] = {0,-1,1,0};

    // DUYỆT MÃ
    int dx_3[8] = {-2,-2,-1,-1,1,1,2,2};
    int dy_3[8] = {-1,1,-2,2,-2,2,-1,1};

    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            int sum = a[i][j];
            for(int k = 0; k <= 7; k++){
                int index_1 = i + dx_1[k];
                int index_2 = j + dy_1[k];
                if(index1 >= 1 && index1 <= row && index_2 >= 1 && index_2 <= col){
                    sum += a[index_1][index_2];
                }
            }
            cout << sum << " ";
        }
    }
}