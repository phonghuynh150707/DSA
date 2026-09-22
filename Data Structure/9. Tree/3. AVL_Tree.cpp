#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// VẤN ĐỀ: BST TRƯỜNG HỢP XẤU NHẤT: CÁC PHẦN TỬ ĐỔ DẦN SANG PHẢI (TĂNG), HOẶC SANG TRÁI (GIẢM)
// --> TÌM KIẾM TUẦN TỰ
// - GIẢI PHÁP: 

// CÂY CÂN BẰNG (BALANCED HAY AVL): TẠI MỌI NODE CỦA CÂY THÌ CHIỀU CAO CÂY CON TRÁI VÀ CÂY CON PHẢI HƠN KÉM NHAU NHIỀU NHẤT 1 ĐV
// HỆ SỐ CÂN BẰNG (BALANCE FACTOR): CHIỀU CON CÂY CON TRÁI - PHẢI TẠI MỌI NODE BẤT KÌ: NHẬN GIÁ TRỊ -1,-0,1
// MỌI NODE TRÊN CÂY PHẢI THÓA ĐK CÂN BẰNG
// VẪN LÀ CÂY BST: MỌI NODE TRÁI < ROOT < MỌI NODE BÊN PHẢI

struct node{ // NODE CÂY CÂN BẰNG
    int data; // DỮ LIỆU NODE
    int count; // SỐ LẦN XH CỦA NODE
    int height; // CHIỀU CAO TẠI NODE
    node* left; // CON TRỎ TỚI NODE BÊN TRÁI
    node* right; // CON TRỎ TỚI NODE BÊN PHẢI
};

void init(node*& root){ // KHỞI TẠO CÂY RỖNG
    root = nullptr; // CON TRỎ CHỈ NODE GỐC TRỎ VÀO NULL
}

bool empty(node* root){ // KIỂM TRA CÂY RỖNG
    return root == nullptr; // CON TRỎ NODE GỐC LÀ NULL THÌ RỖNG
}

int getHeight(node* root){ // ĐỘ CAO CỦA CÂY, NHƯ CÂY NHỊ PHÂN!
    if(root == nullptr) return 0;
    return root->height;
}

void Height(node* p){ // TÍNH CHIỀU CAO CÂY P
    int HeightLeft = getHeight(p->left);
    int HeightRight = getHeight(p->right);
    if(HeightLeft >= HeightRight) p->height = HeightLeft + 1;
    else p->height = HeightRight + 1;
}

// CÂY MẤT CÂN BẰNG TRÁI: CHIỀU CAO CÂY TRÁI > CÂY PHẢI = 2
// CÂY MẤT CÂN BẰNG PHẢI: CHIỀU CAO CÂY PHẢI > CÂY TRÁI = 2
// --> PHẢI THỰC HIỆN PHÉP QUAY ĐỂ CÂN BẰNG: GÒM PHÉP QUAY ĐƠN, PHÉP QUAY KÉP

void RotateLL(node*& root){ // MẤT CÂN BẰNG TRÁI: QUAY ĐƠN LL
    node* L1 = root->left; // L1: ĐẾN NODE CON TRÁI CỦA NODE GỐC
    root->left = L1->right; // CÂY CON PHẢI CỦA NODE L1 LÀ CÂY CON TRÁI CỦA NODE ROOT
    L1->right = root; // CÂY CON PHẢI CỦA NODE L1 LÀ NODE GỐC ĐI XUỐNG
    Height(root); // CẬP NHẬT LẠI CHIỀU CAO Ở ROOT
    Height(L1); // CẬP NHẬT LẠI CHIỀU CAO Ở NODE CON TRÁI
    root = L1; // CHỈNH LẠI NODE GỐC: TRUYỀN THAM CHIẾU
}

void RotateDLRR(node*& root){ // MÂT CÂN BẰNG TRÁI: QUAY KÉP DLRR
    node* L = root->left; // L1: NODE CON TRÁI CỦA ROOT
    node* R = L->right; // R1: NODE CON PHẢI CỦA L1
    L->right = R->left; // GĂN CÂY CON TRÁI CỦA R1 VÀO CÂY CON PHẢI CỦA L1
    root->left = R->right; // GẮN CÂY CON PHẢI CỦA R1 VÀO BÊN TRÁI CỦA ROOT
    R->left = L; // GẮN L VÀO CÂY CON TRÁI CỦA R
    R->right = root; // GẮN ROOT VÀO CÂY CON PHẢI CỦA R
    Height(L); Height(root); Height(R); // CẬP NHẬT LẠI CHIỀU CAO CÁC NODE
    root = R; // CẬP NHẬT LẠI NODE GỐC
}

void RotateLeft(node*& root){
    // CÂY ROOT BỊ MẤT CÂN BẰNG BÊN TRÁI
    node* L = root->left;
    // CHIỀU CAO CÂY CON TRÁI >= CÂY CON PHẢI: QUAY ĐƠN LL
    if(getHeight(L->left) >= getHeight(L->right)) RotateLL(root);
    else RotateDLRR(root); // NGƯỢC LẠI QUAY KÉP DLRR
}

void RotateRR(node*& root){
    node* R = root->right; // R: NODE CON PHẢI CỦA ROOT
    root->right = R->left; // GẮN CÂY CON TRÁI CỦA R VÀO BÊN PHẢI ROOT
    R->left = root; // ĐƯA ROOT LÀM CÂY CON TRÁI CỦA R
    Height(root); Height(R); // CẬP NHẬT LẠI CHIỀU CAO
    root = R; // CẬP NHẬT LẠI GỐC: TRUYỀN THAM CHIẾU
}

void RotateDRLR(node*& root){
    node* R = root->right; // R: NODE CON PHẢI CỦA ROOT
    node* L = R->left; // L: NÚT CON TRÁI CỦA R
    R->left = L->right; // GẮN CÂY CON PHẢI CỦA L VÀO BÊN TRÁI R
    root->right = L->left; // GẮN CÂY CON TRÁI CỦA L VÀO BÊN PHẢI ROOT
    L->left = root; // ROOT LÀ NODE CON TRÁI CỦA L
    L->right = R; // R LÀ NODE CON PHẢI CỦA L
    Height(R); Height(root); Height(L); // CẬP NHẬT LẠI CHIỀU CAO
    root = L; // CẬP NHẬT LẠI GỐC: TRUYỀN THAM CHIẾU
}

void RotateRight(node*& root){
    // CÂY ROOT BỊ MẤT CÂN BẰNG BÊN PHẢI
    node* R = root->right; // R: NODE CON PHẢI CỦA ROOT
    if(getHeight(R->right) >= getHeight(R->left)) RotateRR(root);
    else RotateDRLR(root);
}

// THUẬT TOÁN THÊM NODE
void Insert(node*& root, int key){
    if(root == nullptr){
        root = new node;
        root->data = key;
        root->height = 1;
        root->count = 1;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if(key < root->data){
        Insert(root->left,key);
        if(getHeight(root->left) - getHeight(root->right) == 2){
            RotateLeft(root);
        }
        Height(root);
    }
    else if(key > root->data){
        Insert(root->right, key);
        if(getHeight(root->right) - getHeight(root->left) == 2){
            RotateRight(root);
        }
        Height(root);
    }
    else root->count++;
}

// THUẬT TOÁN TÌM KIẾM
node* Find(node* root, int key){ // TÌM KIẾM BẰNG VÒNG LẶP
    bool found = false;
    while(root != nullptr && !found){
        if(key < root->data) root = root->left;
        else if(key > root->data) root = root->right;
        else found = true;
    }
    return root;
}

node* Search(node* root, int key){ // TRẢ VỀ ĐỊA CHỈ BẰNG ĐỆ QUY
    node* res = nullptr; // KẾT QUẢ TÌM KIẾM
    if(root == nullptr) return res;
    if(key < root->data) res = Search(root->left, key); // KEY BÉ HƠN THÌ TÌM BÊN TRÁI
    else if(key > root->data) res = Search(root->right, key); // KEY LỚN HƠN THÌ TÌM BÊN PHẢI
    else res = root; // BẰNG THÌ LƯU KQ
    return res;
}

// XÓA NODE TRONG CÂY
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
    if(root == nullptr) return;
    Height(root);
    int balance = getHeight(root->left) - getHeight(root->right);

    if(balance > 1){
        RotateLeft(root);
    }
    else if(balance < -1){
        RotateRight(root);
    }
}
// KIỂM TRA CÂN BẰNG CỦA CÂY
bool IsBalanced(node* root){ // KIỂM TRA CÂY CÓ CÂN BẰNG HAY KHÔNG
    if(root == nullptr) return true;
    int balance = getHeight(root->left) - getHeight(root->right);
    if(balance < -1 || balance > 1) return false;
    return IsBalanced(root->left) && IsBalanced(root->right);
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

void clear(node*& root){ // HỦY CÂY
    if(root != nullptr){ // XÓA TỪ NODE LÁ ĐI LÊN
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
}
int main(){

}