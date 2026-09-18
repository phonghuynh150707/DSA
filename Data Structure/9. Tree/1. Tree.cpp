#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node{
    int data; // DỮ LIỆU NODE
    node* left; // CON TRỎ NÚT CON TRÁI
    node* right; // CON TRỎ NÚT CON PHẢI
};

void init(node* &root){ // KHỞI TẠO CÂY RỖNG (EMPTY TREE)
    root = nullptr; // ROOT LÀ NULL
}

bool empty(node* root){
    return root == nullptr; // ROOT TRỎ TỚI NULL THÌ CÂY RỖNG
}

// DUYỆT THEO PREORDER (NLR HOẶC NRL)
void NLR(node* root){ // DUYỆT BẰNG ĐỆ QUY
    if(root != nullptr){
        cout << root->data << " "; // XỬ LÝ DỮ LIỆU
        NLR(root->left); // DUYỆT CÂY CON BÊN TRÁI
        NLR(root->right); // DUYỆT CÂY CON BÊN PHẢI
        // ĐỔI THỨ TỰ RIGHT -> LEFT SẼ RA NRL
    }
}

void NLR2(node* root){ // DUYỆT NLR BẰNG VÒNG LẶP VÀ STACK
    stack<node*> st; // KHỞI TẠO STACK RỖNG
    if(root != nullptr){
        st.push(root); // THÊM ROOT
        while(!st.empty()){ // CHỪNG NÀO HẾT CÂY
            node* temp = st.top(); st.pop(); // LẤY CON TRỎ NODE RA
            cout << temp->data << " "; // XỬ LÝ DỮ LIỆU
            if(temp->right != nullptr) st.push(temp->right); // THÊM CON TRỎ NODE BÊN PHẢI TRƯỚC
            if(temp->left != nullptr) st.push(temp->left); // THÊM CON TRỎ NODE BÊN TRÁI SAU
            // ĐỔI THỨ TỰ DUYỆT LEFT -> RIGHT ĐỂ ĐƯỢC NRL
        }
    }
}

// DUYỆT THEO INORDER (LNR HOẶC RNL)
void LNR(node* root){ // DUYỆT LNR BẰNG ĐỆ QUY
    if(root != nullptr){
        LNR(root->left); // XÉT CON TRỎ NODE BÊN TRÁI
        cout << root->data << " "; // XỬ LÝ DỮ LIỆU NODE
        LNR(root->right); // XÉT CON TRỎ NODE BÊN PHẢI
        // ĐỔI NGƯỢC RIGHT -> LEFT: RNL
    }
}

void LNR2(node* root){
    stack<node*> st; // KHỞI TẠO STACK RỖNG
    while(!st.empty() || root != nullptr){
        if(root != nullptr){
            st.push(root);
            root = root->left; // ĐI QUA NODE CON BÊN TRÁI
        }
        else{
            node* temp = st.top(); st.pop();
            cout << temp->data << " "; // XỬ LÝ DỮ LIỆU NODE
            root = temp->right; // ĐI QUA NODE CON BÊN PHẢI
        }
        // TƯƠNG TỰ ĐỔI RIGHT -> LEFT: RNL
    }
}

// DUYỆT THEO POSTORDER (LRN HOẶC RLN)
void LRN(node* root){ // DUYỆN LRN BẰNG ĐỆ QUY
    if(root != nullptr){
        LRN(root->left); // DUYỆT SANG NODE CON BÊN PHẢI
        LRN(root->right); // DUYỆT SANG NODE CON BÊN PHẢI
        cout << root->data << " "; // XỬ LÝ DATA
    }
    // ĐỔI RIGHT -> LEFT: RLN
}

void LRN2(node* root){
    stack<node*> st; // KHỞI TẠO STACK RỖNG
    node* lastNode = nullptr; // NÚT XỬ LÝ TRƯỚC ĐÓ
    while(!st.empty() || root != nullptr){
        if(root != nullptr){
            st.push(root);
            root = root->left;
        }
        else{
            node* temp = st.top();
            if((temp->right != nullptr) && (lastNode != temp->right)){
                root = temp->right;
            }
            else{
                cout << temp->data << " ";
                lastNode = st.top(); st.pop();
            }
        }
    }
}

// DUYỆT CÂY THEO MỨC (TỪ TRÁI -> PHẢI)
void TraverseLevel(node* root){
    if(!empty(root)){ // KIỂM TRA CÂY KHÔNG RỖNG
        queue<node*> q; // KHỞI TẠO HÀNG ĐỢI RỖNG
        q.push(root);
        while(!q.empty()){
            node* temp = q.front(); q.pop(); // LẤY Ở ĐẦU
            cout << temp->data << " "; // XỬ LÝ DỮ LIỆU CỦA NODE
            if(temp->left != nullptr) q.push(temp->left); // THÊM TRÁI
            if(temp->right != nullptr) q.push(temp->right); // THÊM PHẢI
        }
    }
}

// TẠO CÂY TỪ MẢNG
node* CreateTreeNLR(int a[], int& i){ // TRUYỀN I GỐC, TRÁNH TẠO BẢN SAO
    node* p; // TRÁNH MEMORY LEAK KHI GIÁ TRỊ NULL
    if(a[i] == 0) return nullptr; // 0 THÌ LÀ NULL
    else{
        p = new node; // TẠO NODE MỚI
        p->data = a[i]; ++i; // GÁN GIÁ TRỊ, DỊCH MẢNG
        p->left = CreateTreeNLR(a,i);
        p->right = CreateTreeNLR(a,i);
    }
    return p;
}

// TÍNH CHIỀU CAO CỦA CÂY
// CÂY RỖNG CÓ CHIỀU CAO LÀ 0, CHIỀU CAO = MAX(LEFT HEIGHT, RIGHT HEIGHT) + 1
int Height(node* root){
    int height; // CHIÊU CAO CỦA CÂY
    if(root == nullptr) return 0; // CÂY RỖNG
    else{
        int leftHeight = Height(root->left); // TÍNH CHIỀU CAO CÂY CON BÊN TRÁI
        int rightHeight = Height(root->right); // TÍNH CHIỀU CAO CÂY CON BÊN PHẢI
        height = max(leftHeight,rightHeight) + 1; // CÔNG THỨC!
    }
    return height;
}

// ĐẾM SỐ NODE CỦA CÂY
// SỐ NÚT CÂY RỖNG = 0, SỐ NÚT = SỐ NÚT (TRÁI) + SỐ NÚT(PHẢI) + 1
int CountNode(node* root){
    if(root == nullptr) return 0; // CÂY RỖNG THÌ NODE = 0
    return CountNode(root->left) + CountNode(root->right) + 1; // NHƯ TRÊN
}

// TÍNH SỐ NODE LÁ CỦA CÂY
// SỐ NÚT LÁ CÂY RỖNG = 0
// SỐ NÚT LÁ CÂY CÓ MỘT NODE GỐC = 1
// SỐ NÚT LÁ = SỐ NÚT LÁ (TRÁI) + SỐ NÚT LÁ (PHẢI)
int CountLeaves(node* root){
    if(root == nullptr) return 0;
    else if(root->left == nullptr && root->right == nullptr) return 1; // CHỈ CÓ NODE GỐC
    else return CountLeaves(root->left) + CountLeaves(root->right);
}

// TÍNH SỐ NODE TRUNG GIAN (INTERNAL) CỦA CÂY
// SỐ NTG CỦA CÂY RỖNG = 0
// SỐ NTG CỦA CÂY MỘT NODE GỐC = 0
// SỐ NTG = NTG(TRÁI) + NTG(PHẢI) +  1
int CountInternal(node* root){
    if(root == nullptr) return 0;
    else if(root->left == nullptr && root->right == nullptr) return 0;
    else return CountInternal(root->left) + CountInternal(root->right) + 1;
}

// HỦY CÂY (CLEAR): DUYỆT LRN ĐỂ XÓA TỪNG NODE: SAU CÙNG GÁN NULL CHO ROOT
void clear(node* &root){
    if(root != nullptr){
        clear(root->left);
        clear(root->right);
        delete root; // XÓA TỪNG NODE
        root = nullptr; // GÁN NULL CHO GỐC
    }
}


int main(){
    node* root; // CON TRỎ GỐC
    init(root); // KHỞI TẠO CÂY RỖNG
}