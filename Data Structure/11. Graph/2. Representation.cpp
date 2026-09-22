#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// B1: CHO N ĐỈNH M CẠNH: BIỂU DIỄN MA TRẬN KỀ
void AdjMatrix(int matrix[1005][1005], int vertex, int edge){
    // CÁC ĐỈNH NHẬN GIÁ TRỊ TỪ 1 -> VERTEX
    memset(matrix, 0, 1005*1005*sizeof(int)); // ĐƯA TOÀN BỘ MẢNG VỀ 0
    for(int i = 1; i <= edge; i++){ // ĐI QUA TẤT CẢ CÁC CẠNH
        int m,n; cin >> m >> n;
        matrix[m][n] = matrix[n][m] = 1; // 1 NẾU CÓ CẠNH NỐI
    }
    for(int i = 1; i <= vertex; i++){ // DUYỆT MA TRẬN
        for(int j = 1; j <= vertex; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

// B2: CHO N ĐỈNH, M CẠNH: BIỂU DIỄN DANH SÁCH CẠNH
vector<pair<int,int>> Edlist(int vertex, int edge){
    // CÁC ĐỈNH NHẬN GIÁ TRỊ TỪ 1 -> VERTEX
    vector<pair<int,int>> edges; // DANH SÁCH CẠNH
    for(int i = 1; i <= edge; i++){ // DUYỆT QUA CÁC CẠNH
        int u,v; cin >> u >> v;
        edges.push_back({u,v}); // ĐẨY CÁC CẶP CẠNH VÀO
    }
    return edges;
}

// B3: CHO N ĐỈNH, M CẠNH: BIỂU DIỄN DANH SÁCH KỀ
vector<vector<int>> AdjList(int vertex, int edge){
    vector<vector<int>> Adj(vertex+5); // DANH SÁCH KỀ
    for(int i = 1; i <= edge; i++){ // DUYỆT QUA CÁC CẠNH
        int u,v; cin >> u >> v;
        Adj[u].push_back(v); Adj[v].push_back(u); // VÔ HƯỚNG, CÓ HƯỚNG THÌ XÉT CHIỀU
    }
    return Adj;
}

// B4: CHUYỂN TỪ DANH SÁCH CẠNH SANG MA TRẬN KỀ
void EdgeListToMatrix(vector<pair<int,int>>& edges, int vertex){
    int matrix[1005][1005] = {}; // GÁN GIÁ TRỊ MẢNG BAN ĐẦU LÀ 0
    for(pair<int,int> e : edges){ // CHUYỂN TỪ DSC -> MTK
        int u = e.first, v = e.second;
        matrix[u][v] = matrix[v][u] = 1;
    }
    for(int i = 1; i <= vertex; i++){ // DUYỆT QUA MA TRẬN
        for(int j = 1; j <= vertex; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// B5: CHUYỂN TỪ DANH SÁCH CẠNH SANG DANH SÁCH KỀ
void EdgeListToAdjList(vector<pair<int,int>>& edges, int vertex){
    vector<vector<int>> Adj(vertex + 1); // DANH SÁCH KỀ
    for(auto e : edges){
        int u = e.first; // ĐỈNH 1
        int v = e.second; // ĐỈNH 2
        Adj[u].push_back(v); Adj[v].push_back(u); // ĐỒ THỊ VÔ HƯỚNG
    }
    for(int i = 1; i <= vertex; i++){
        cout << i << ": ";
        sort(Adj[i].begin(), Adj[i].end()); // XẾP IN THỨ TỰ TĂNG DẦN
        for(auto x : Adj[i]){ // IN RA CÁC PHẦN TỬ KỀ VỚI ĐỈNH ĐÓ
            cout << x << " ";
        }
        cout << endl;
    }
}

// B6: CHUYỂN TỪ MA TRẬN KỀ SANG DANH SÁCH KỀ
void MatrixToAdjList(int matrix[1005][1005], int vertex){
    vector<vector<int>> Adj(vertex + 1); // DANH SÁCH KỀ
    for(int i = 1; i <= vertex; i++){ // DUYỆT QUA CÁC Ô
        for(int j = 1; j <= vertex; j++){
            if(matrix[i][j] == 1){
                Adj[i].push_back(j); // THÊM VÀO DSK
            }
        }
    }
    for(int i = 1; i <= vertex; i++){
        cout << i << ": ";
        sort(Adj[i].begin(), Adj[i].end()); // XẾP IN THỨ TỰ TĂNG DẦN
        for(auto x : Adj[i]){ // IN RA CÁC PHẦN TỬ KỀ VỚI ĐỈNH ĐÓ
            cout << x << " ";
        }
        cout << endl;
    }
}

// B7: CHUYỂN TỪ MA TRẬN KỀ SANG DANH SÁCH CẠNH
void MatrixToEdgeList(int matrix[1005][1005], int vertex){
    vector<pair<int,int>> edges; // DANH SÁCH CẠNH
    for(int i = 1; i <= vertex; i++){
        for(int j = i + 1; j <= vertex; j++){ // CHỈ XÉT MỘT NỬA MA TRẬN ĐỂ LẶP
            if(matrix[i][j] == 1) edges.push_back({i,j});
        }
    }
}

// B8: CHUYỂN TỪ DANH SÁCH KỀ SANG DANH SÁCH CẠNH
void AdjListToEdgeList(vector<vector<int>>& Adj, int vertex){
    vector<pair<int,int>> edges; // DANH SÁCH CẠNH
    for(int i = 1; i <= vertex; i++){ // DUYỆT QUA TỪNG ĐỈNH
        for(auto x : Adj[i]){ // ĐI VÀO TỪNG ĐỈNH KỀ VỚI ĐỈNH I
            if(i < x) edges.push_back({i,x}); // DS CẠNH LƯU (U,V) U < V
        }
    }
    for(auto x : edges){ // IN DANH SÁCH CẠNH
        cout << x.first << " " << x.second << endl;
    }
}

// B9: CHUYỂN TỪ DANH SÁCH KỀ SANG MA TRẬN KỀ
void AdjListToMatrix(vector<vector<int>>& Adj, int vertex){
    int matrix[1005][1005] = {}; // MA TRẬN BAN ĐẦU TOÀN 0
    for(int u = 1; u <= vertex; u++){ // DUYỆT TỪNG ĐỈNH
        for(auto v : Adj[u]){ // DUYỆT CÁC ĐỈNH KỀ CỦA ĐỈNH U
            matrix[u][v] = 1; // VÌ DS KỀ LƯU 2 CHIỀU 
        }
    }
    for(int i = 1; i <= vertex; i++){ // IN RA MA TRẬN KỀ
        for(int j = 1; j <= vertex; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    // MA TRẬN KỀ (ADJACENCY MATRIX):
    // - VÔ HƯỚNG: LẬP MA TRẬN N HÀNG, CỘT: CÁC PHẦN TỬ CÓ THỂ NHẬN GIÁ TRỊ 0 HOẶC 1
    // -- A[I][J] = A[J][I] = 1, NẾU GIỮA 2 ĐỈNH I VÀ J CÓ CẠNH NỐI, NGƯỢC LẠI BẰNG 0
    // - CÓ HƯỚNG: LẬP MA TRẬN VUÔNG N HÀNG, CỘT: CÁC PHẦN TỬ CÓ THỂ NHẬN GIÁ TRỊ 0 HOẶC 1
    // -- A[I][J] = 1 NẾU I HƯỚNG J, A[J][I] = 1 NẾU J HƯỚNG I, NGƯỢC LẠI BẰNG 0
    // - MA TRẬN TRỌNG SỐ: A[I][J] = TRỌNG SỐ
    // --> NẾU ĐA ĐỒ THỊ: A[I][J] = N (SỐ CẠNH GIỮA 2 ĐỈNH)
    // ---> TỐN BỘ NHỚ (SPACE): KHÔNG THỂ BIỂU DIỄN NHIỀU ĐỈNH ĐƯỢC

    // DANH SÁCH CẠNH (EDGE LIST):
    // VÔ HƯỚNG: LIỆT KÊ CÁC CẶP CẠNH (U,V) VÀO DANH SÁCH (VECTOR), (U,V) THƯỜNG U < V (QUY ƯỚC)
    // CÓ HƯỚNG: CÁC CẶP CẠNH TRONG DANH SÁCH (VECTOR): XÉT THỨ TỰ ĐỈNH ĐẦU CUỐI
    // TRỌNG SỐ: DÙNG STRUCT ĐỊNH NGHĨA: HEAD, END, WEIGHT

    // DANH SÁCH KỀ (ADJACENCY LIST):
    // VỚI MỖI ĐỈNH U: TA LƯU DANH SÁCH CÁC ĐỈNH KỀ VỚI ĐỈNH U
    // --> CÁCH BIỂU DIỄN TỐI ƯU NHẤT
}