#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// CHO MẢNG NUMS, MẢNG OPE CÓ PT DẠNG {L,R,X}
// MỖI OPE TĂNG PHẦN TỬ TỪ L->R LÊN X ĐƠN VỊ
vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations){
    vector<int> Diff(nums.size()+5); // TẠO MẢNG HIỆU
    for(int i = 0; i < nums.size(); i++){ // XÂY DỰNG MẢNG HIỆU
        if(i == 0) Diff[i] = nums[i];
        else Diff[i] = nums[i] - nums[i-1];
    }
    for(vector<int> x : operations){ // DUYỆT QUA MỖI THAO TÁC
        int left = x[0], right = x[1], update = x[2]; // LẤY GIÁ TRỊ TRONG MỖI OPE
        Diff[left] += update;
        Diff[right + 1] -= update;
    }
    vector<int> prefix(nums.size()+5);
    for(int i = 0; i < nums.size(); i++){
        if(i == 0) prefix[i] = Diff[i];
        else prefix[i] = prefix[i-1] + Diff[i];
    }
    return prefix;
}

// CHO MẢNH NUMS, KIỂM TRA TẤT CẢ SỐ 1 CÓ XUẤT HIỆN LIÊN TIẾP NHAU KHÔNG
bool consecutiveOnes(vector<int>& nums){
    bool met = false; // ĐÁNH DẤU CHƯA GẶP SỐ 1
    int index = 0; // ĐÁNH DẤU INDEX SỐ 1
    for(int i = 0; i < nums.size(); i++){
        if(!met){
            if(nums[i] != 1) continue; // KHÔNG PHẢI SỐ 1 THÌ DUYỆT TIẾP
            else{ // GẶP SỐ 1 THÌ ĐÁNH DẤU LẠI
                met = true;
                index = i;
            } 
        }
        else{
            if(nums[i] == 1){ // GẶP LẠI 1 SAU KHI ĐÃ GẶP 1 TRƯỚC ĐÓ
                if(i - index >= 2) return false; // KC HỢP LỆ
                else index = i; // LƯU LẠI INDEX 1 NÀY ĐỂ SO SÁNH
            }
            else continue;
        }
    }
    return true;
}

// CHO MẢNG NUMS, TÌM INDEX I NHỎ NHẤT SAO CHO SUM(LEFT) = SUM(RIGHT)
// KHÔNG TỒN TẠI THÌ TRẢ VỀ -1
int equalSumIndex(vector<int>& nums){
    int sum = 0; // TỔNG MẢNG
    int left = 0; // TỔNG BÊN TRÁI INDEX
    for(int i = 0; i < nums.size(); i++) sum += nums[i]; // Tính tổng toàn bộ mảng
    for(int i = 0; i < nums.size(); i++){ // DUYỆT QUA TỪNG INDEX 
        int right = sum - left - nums[i]; // TÍNH TỔNG BÊN PHẢI TỪ INDEX QUA
        if(left == right) return i; // 2 TỔNG = THÌ TRẢ VỀ TRUE
        left += nums[i]; // CẬP NHẬT TỔNG TRÁI
    }
    return -1;
}


int main(){

}