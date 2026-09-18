#include <iostream>
#include <algorithm>
using namespace std;

// CÂY NHỊ PHÂN TÌM KIẾM (BST): MỌI NÚT THÌ DATA > TẤT CẢ CÂY CON PHẢI, < TẤT CẢ CÂY CON TRÁI

struct node{ // ĐỊNH NGHĨA MỘT NODE
    int data; // DỮ LIỆU 
    int count; // SỐ LẦN XUẤT HIỆN CỦA DỮ LIỆU
    node* left; // CON TRỎ TỚI NODE BÊN TRÁI
    node* right; // CON TRỎ TỚI NODE BÊN PHẢI
};

void init(node*& root){ // KHỞI TẠO BST RỖNG
    root = nullptr; // GÁN NULL VÀO CÂY
}

bool empty(node* root){ // KIỂM TRA CÂY RỖNG
    return root == nullptr; // ROOT NULL THÌ CÂY RỖNG
}

void insert(node*& root, int key){ // CHÈN NODE VÀO CÂY BẰNG ĐỆ QUY
    if(root == nullptr){
        root = new node; // TẠO NODE MỚI
        root->data = key; // GÁN DỮ LIỆU
        root->count = 1; // CẬP NHẬT TẦN SUẤT
        root->left = nullptr; // CON TRỎ NODE BÊN TRÁI
        root->right = nullptr; // CON TRỎ NODE BÊN PHẢI
    }
    else if(root->data == key) root->count++; // BẰNG THÌ TĂNG TẦN SUẤT
    else if(root->data > key) insert(root->left,key); // BÉ THÌ CHÈN QUA CÂY BÊN TRÁI
    else insert(root->right,key); // LỚN THÌ CHÈN QUA CÂY BÊN PHẢI
}

// CÁC THUẬT TOÁN TÌM KIẾM
node* Find(node* root, int key){ // TRẢ VỀ ĐỊA CHỈ BẰNG VÒNG LẶP
    bool found = false; // CỜ ĐÁNH DẤU
    while(root != nullptr && !found){ // CHƯA TÌM THẤY
        if(key < root->data) root = root->left; // KEY BÉ HƠN THÌ QUA CÂY BÊN TRÁI TÌM
        else if(key > root->data) root = root->right; // KEY LỚN HƠN THÌ QUA CÂY BÊN PHẢI TÌM
        else found = true; // BẰNG THÌ ĐÁNH DẤU
    }
    return root;  // TRẢ VỀ NULL NẾU KHÔNG TÌM THẤY  
}

node* Search(node* root, int key){ // TRẢ VỀ ĐỊA CHỈ BẰNG ĐỆ QUY
    node* res = nullptr; // KẾT QUẢ TÌM KIẾM
    if(root == nullptr) return res;
    if(key < root->data) res = Search(root->left, key); // KEY BÉ HƠN THÌ TÌM BÊN TRÁI
    else if(key > root->data) res = Search(root->right, key); // KEY LỚN HƠN THÌ TÌM BÊN PHẢI
    else res = root; // BẰNG THÌ LƯU KQ
    return res;
}

// CÁC THUẬT TOÁN XÓA DATA


// DUYỆT CÂY
// LNR: TĂNG DẦN
// RNL: GIẢM DẦN
// NLR: KIỂM TRA CẤU TRÚC CỦA CÂY
void NLR(node* root){
    if(root != nullptr){
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LNR(node* root){
    if(root != nullptr){
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}

void LRN(node* root){
    if(root != nullptr){
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }
}

// KIỂM TRA CÂY BST
// DUYỆT THEO LNR: CÂY PHẢI TĂNG DẦN
bool IsBST(node* root, node*& prev){
    if(root == nullptr) return true;
    if(!IsBST(root->left, prev)) return false;
    if(prev != nullptr && root->data <= prev->data) return false;
    prev = root;
    return IsBST(root->right, prev);
}

bool IsBST(node* root, long long minValue, long long maxValue){
    if(root == nullptr) return true;
    if(root->data <= minValue || root->data >= maxValue) return false;
    return IsBST(root->left, minValue, root->data) && IsBST(root->right, root->data, maxValue);
}

void clear(node*& root){ // HỦY CÂY
    if(root != nullptr){
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
}

int Height(node* root){
    if(root == nullptr) return 0;
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

node* FindMin(node* root){
    if(root == nullptr) return nullptr;
    while(root->left != nullptr) root = root->left;
    return root;
}

void Delete(node*& root, int key){
    if(root == nullptr) return;
    if(key < root->data) Delete(root->left, key);
    else if(key > root->data) Delete(root->right, key);
    else{
        // Có duplicate
        if(root->count > 1) root->count--;
        // Không có con trái
        else if(root->left == nullptr){
            node* temp = root;
            root = root->right;
            delete temp;
        }
        // Không có con phải
        else if(root->right == nullptr){
            node* temp = root;
            root = root->left;
            delete temp;
        }
        // Có 2 con
        else{
            node* temp = FindMin(root->right);
            root->data = temp->data;
            root->count = temp->count;
            temp->count = 1;
            Delete(root->right, temp->data);
        }
    }
}
int main(){

}