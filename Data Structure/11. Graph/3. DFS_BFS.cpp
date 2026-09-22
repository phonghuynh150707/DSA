#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

// THUẬT TOÁN DFS (DEPTH_FIRST_SEARCH): TÌM KIẾM THEO CHIỀU SÂU
// - TÌM KIẾM, DUYỆT ĐỒ THỊ DÙNG ĐỆ QUY (RECURSION)
// - ĐI SÂU NHẤT CÓ THỂ VÀO MỘT NHÁNH RỒI QUAY LUI THỬ NGHIỆM DẦN NHÁNH KẾ

// THUẬT TOÁN BFS (BREATH_FIRST_SEARCH): TÌM KIẾM THEO CHIỀU RỘNG
// - ƯU TIÊN MỞ RỘNG VỚI CÁC ĐỈNH GẦN VỚI ĐỈNH NGUỒN
int vertex; // SÓ ĐỈNH
int matrix[1005][1005]; // MA TRẬN KỀ
bool visited[1005]; // MẢNG ĐÁNH DẤU NHỮNG ĐỈNH ĐÃ THĂM

vector<pair<int,int>> edges; // DANH SÁCH CẠNH
vector<vector<int>> adj(1005); // DANH SÁCH KỀ

void DFS_MatrixAdj(int u){ // INPUT LÀ ĐỈNH TA BẮT ĐẦU ĐỂ ĐI
    visited[u] = 1; // ĐÁNH DẤU ĐỈNH U ĐÃ THĂM
    cout << u << " "; // IN RA DUYỆT
    for(int i = 1; i <= vertex; i++){ // TỪ 1 ĐỈNH, DUYỆT QUA TẤT CẢ CÁC ĐỈNH
        if(matrix[u][i] == 1 && visited[i] == 0){ // KIỂM TRA XEM CÓ ĐƯỜNG ĐI, VÀ CHƯA ĐI
            DFS_MatrixAdj(i); // GỌI ĐỆ QUY TỚI ĐỈNH HỢP LỆ
        }
    }
}

void DFS_EdgeList(int u){
    visited[u] = 1; // ĐÁNH DẤU ĐỈNH U ĐÃ THĂM
    cout << u << " "; // XỬ LÝ DỮ LIỆU: DUYỆT
    for(auto edge : edges){
        if(edge.first == u && visited[edge.second] == 0){ // NẾU ĐỈNH ĐẦU LÀ U VÀ ĐỈNH CÒN LẠI CHƯA THĂM
            DFS_EdgeList(edge.second); // TIẾP TỰC ĐI Ở ĐỈNH CÒN LẠI
        }
        else if(edge.second == u && visited[edge.first] == 0){ // NẾU ĐỈNH SAU LÀ U VÀ ĐỈNH ĐẦU CHƯA THĂM
            DFS_EdgeList(edge.first); // TIẾP TỤC ĐI Ở ĐỈNH CÒN LẠI
        }
        else; // KHÔNG THỎA THÌ QUAY LUI THỬ TRƯỜNG HỢP KHÁC
        // KHÔNG THỎA THÌ KHÔNG LÀM GÌ CẢ
    }
}

void DFS_AdjList(int u){
    visited[u] = 1; // ĐÁNH DẤU U ĐÃ THĂM
    cout << u << " "; // XỬ LÝ DỮ LIỆU: DUYỆT
    for(auto v : adj[u]){ // DUYỆT QUA NHỮNG ĐỈNH KỀ VỚI ĐỈNH U
        if(visited[v] == 0){ // CHƯA THĂM
            DFS_AdjList(v); // TIẾP TỤC VÀO ĐỈNH V
        }
    }
}

void DFS_AdjList_Stack(int start){
    stack<int> st; // TẠO STACK RỖNG CHỨA CÁC ĐỈNH ĐƯỢC DUYỆT
    st.push(start); // ĐƯA ĐỈNH VÀO STACK
    while(!st.empty()){ // CHỪNG NÀO STACK CÒN ĐỈNH THÌ CÒN TIẾP TỤC DFS
        int u = st.top(); st.pop(); // XÉT PHẦN TỬ Ở ĐẦU: LẤY RA
        if(visited[u] == 1) continue; // ĐỈNH ĐANG XÉT ĐÃ ĐƯỢC THĂM THÌ BỎ QUA
        visited[u] = 1; // CHƯA THÌ ĐÁNH DẤU U ĐÃ THĂM
        cout << u << " "; // XỬ LÝ DỮ LIỆU
        for(auto v : adj[u]){ // XÉT QUA ĐỈNH KỀ VỚI ĐỈNH ĐANG XÉT
            if(visited[v] == 0){ // NẾU ĐỈNH XÉT CHƯA ĐƯỢC THĂM
                st.push(v); // THÊM ĐỈNH ĐÓ VÀO STACK
            }
        }
    }
}

void BFS_AdjList(int start){
    queue<int> q; // TẠO QUEUE RỖNG
    q.push(start); // ĐƯA ĐỈNH BẮT ĐẦU VÀO QUEUE
    visited[start] = 1; // ĐÁNH DẤU START ĐÃ ĐƯỢC THĂM
    while(!q.empty()){ // CHỪNG NÀO QUEUE CÒN ĐỈNH
        int u = q.front(); q.pop(); // LẤY ĐỈNH Ở ĐẦU QUEUE LOẠI U KHỎI QUEUE
        cout << u << " "; // XỬ LÝ DỮ LIỆU
        for(auto v : adj[u]){ // DUYỆT TẤT CẢ CÁC ĐỈNH KỀ VỚI U
            if(visited[v] == 0){ // NẾU V CHƯA ĐƯỢC THĂM
                visited[v] = 1; // ĐÁNH DẤU V ĐÃ THĂM
                q.push(v); // ĐƯA ĐỈNH ĐÓ VÀO QUEUE ĐỂ XÉT
            }
        }
    }
}

int main(){
    
}