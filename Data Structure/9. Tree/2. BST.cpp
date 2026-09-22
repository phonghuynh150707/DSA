#include <iostream>
#include <algorithm>
using namespace std;

// CÂY NHỊ PHÂN TÌM KIẾM (BST): MỌI NÚT THÌ DATA < TẤT CẢ CÂY CON PHẢI, > TẤT CẢ CÂY CON TRÁI
// CÂY CON BÊN TRÁI VÀ BÊN PHẢI CŨNG LÀ BST

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
    if(root != nullptr){ // XÓA TỪ NODE LÁ ĐI LÊN
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
}

int Height(node* root){ // ĐỘ CAO CỦA CÂY, NHƯ CÂY NHỊ PHÂN!
    if(root == nullptr) return 0;
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// THUẬT TOÁN XÓA NODE
node* FindMin(node* root){ // TÌM NODE NHỎ NHẤT (TRÁI CÙNG)
    if(root == nullptr) return nullptr; // CÂY RỖNG THÌ NULL
    while(root->left != nullptr) root = root->left; // ĐI HẾT VỀ PHÍA TRÁI CÙNG
    return root; // TRẢ VỀ CON TRỎ CHỈ TỚI NODE ĐÓ
}

void Delete(node*& root, int key){ // XÓA 1 GIÁ TRỊ TRONG CÂY
    if(root == nullptr) return;
    if(key < root->data) Delete(root->left, key); // BÉ HƠN THÌ ĐI QUA TRÁI
    else if(key > root->data) Delete(root->right, key); // LỚN HỚN THÌ ĐI QUA PHẢI 
    else{
        if(root->count > 1) root->count--; // XÉT GIẢM DUPLICATE
        else if(root->left == nullptr){ // KHÔNG CÓ CÂY CON TRÁI
            node* temp = root; // ĐƯA CON PHẢI LÊN THAY NODE HIỆN TẠI
            root = root->right; // RỒI XÓA NODE HIỆN TẠI
            delete temp;
        }
        else if(root->right == nullptr){ // KHÔNG CÓ CÂY CON PHẢI
            node* temp = root; // ĐƯA CÂY TRÁI LÊN NODE HIỆN TẠI
            root = root->left; // XÓA NODE HIỆN TẠI
            delete temp;
        }
        else{ // CÓ CẢ 2 CÂY CON TRÁI VÀ PHẢI
            node* temp = FindMin(root->right); // XÓA SAO CHO VẪN DUY TRÌ BST
            root->data = temp->data; // TÌM NODE NGOÀI CÙNG PHẢI
            root->count = temp->count; // ĐƯA LÊN TẠM THỜI (LẤY ĐÚNG DỮ LIỆU VÀ COUNT)
            temp->count = 1; // CHO COUNT TRÁI CÙNG PHẢI = 0 ĐỂ XÓA NÓ!
            Delete(root->right, temp->data); // SAU XÓA VẪN DUY TRÌ CÂY BST!
        }
    }
}

// THUẬT TOÁN THÊM NODE: NODE MỚI PHẢI ĐƯỢC THÊM VÀO VỊ TRÍ LÁ
void Insert(node*& root, int key) {
    if (root == nullptr) { // CÂY RỖNG → TẠO NODE MỚI
        root = new node; // TẠO NODE MỚI
        root->data = key;
        root->count = 1;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if (key < root->data) Insert(root->left, key); // KEY NHỎ HƠN → ĐI SANG CÂY CON TRÁI
    else if (key > root->data) Insert(root->right, key); // KEY LỚN HƠN → ĐI SANG CÂY CON PHẢI
    else root->count++; // KEY ĐÃ TỒN TẠI → TĂNG COUNT
}
int main(){

}