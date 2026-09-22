#include <iostream>
using namespace std;

int main(){
    // ĐỈNH (VERTEX): ĐỐI TƯỢNG - CẠNH (EDGE): MQH
    // ĐỒ THỊ HỮU HẠN: SỐ ĐỈNH, CẠNH HỮU HẠN >< VÔ HẠN: SỐ ĐỈNH | CẠNH VÔ HẠN

    // ĐỒ THỊ VÔ HƯỚNG (UNDIRECTED GRAPH): CÁC CẠNH KHÔNG BIỂU THỊ HƯỚNG
    // - ĐƠN ĐỒ THỊ VÔ HƯỚNG: TẬP G<V,E>: VERTEX NỐI BỊ CÁC CẠNH KHÔNG THỨ TỰ, KHÔNG LOOP, GIỮA MỖI ĐỈNH KHÔNG QUÁ 1 CẠNH
    // - ĐA ĐỒ THỊ VÔ HƯỚNG: TẬP G(V,E): CHO PHÉP NHIỀU CẠNH NỐI GIỮA CÁC ĐỈNH (CẠNH BỘI)
    // - GIẢ ĐỒ THỊ VÔ HƯỚNG: TẬP G<V,E>, CÓ CẠNH BỘI VÀ KHUYÊN (LOOP)

    // ĐỒ THỊ CÓ HƯỚNG (DIRECTED GRAPH): CÁC CẠNH CÓ HƯỚNG ĐI
    // - ĐƠN ĐỒ THỊ CÓ HƯỚNG: TẬP G<V,E> CÁC CẠNH CÓ THỨ TỰ
    // - ĐA ĐỒ THỊ CÓ HƯỚNG: TẬP G<V,E> CÓ THỂ CÓ NHIỀU CẠNH CÓ HƯỚNG GIỮA CÁC ĐỈNH

    // --> MIXED GRAPH: CẢ VÔ HƯỚNG VÀ CÓ HƯỚNG CÙNG TỒN TẠI TRONG MỘT ĐỒ THỊ

    // ĐỈNH KỀ (ADJACENT): HAI ĐỈNH CÓ TỒN TẠI CẠNH NỐI
    // CẠNH LIÊN THUỘC (INCIDENT): CẠNH NỐI GIỮA 2 ĐỈNH
    // LÂN CẬN (NEIGHBOORHOOD) CỦA MỘT ĐỈNH: TẬP HỢP CÁC ĐỈNH KỀ VỚI ĐỈNH ĐÓ

    // BẬC CỦA ĐỒ THỊ:
    // - VÔ HƯỚNG: SỐ CẠNH LIÊN THUỘC VỚI ĐỈNH ĐÓ, KÍ HIỆU DEG(V)
    // -- ĐỈNH BẬC 0 LÀ ĐỈNH CÔ LẬP (ISOLATED), ĐỈNH BẬC 1 LÀ ĐỈNH TREO (PENDANT), LOOP ĐÓNG VÀO BẬC 2 ĐƠN VỊ
    // -- Đ/L VỀ BẬC: TỔNG BẬC CÓ ĐỈNH = 2*(SỐ CẠNH)
    // - CÓ HƯỚNG:
    // -- BÁN BẬC RA: SỐ CUNG ĐI RA KHỎI ĐỈNH, KÍ HIỆU DEG+(U)
    // -- BÁN BẬC VÀO SỐ CUNG ĐI VÀO ĐỈNH, KÍ HIỆU DEG-(U)
    // -- Đ/L VỀ BẬC: DEG+(U) = DEG-(U) = SỐ CẠNH

    // ĐỒ THỊ VÔ HƯỚNG NỀN: BỎ CÁC HƯỚNG CỦA ĐỒ THỊ CÓ HƯỚNG BIẾN THÀNH ĐỒ THỊ VÔ HƯỚNG

    // ĐƯỜNG ĐI (PATH): DÃY CÁC ĐỈNH (CẠNH), ĐỘ DÀI: SỐ CẠNH ĐI QUA
    // ĐƯỜNG ĐI ĐƠN: KHÔNG ĐI CÙNG MỘT CẠNH HAI LẦN
    // CHU TRÌNH (CYCLE): ĐƯỜNG ĐI CÓ ĐỈNH ĐẦU VÀO ĐỈNH CUỐI TRÙNG NHAU
    // CHU TRÌNH ĐƠN: ĐƯỜNG ĐI KHÔNG LẶP ĐỈNH TRỪ ĐỈNH ĐẦU VÀ CUỐI

    // LIÊN THÔNG (CONNECTED)
    // - VÔ HƯỚNG: GIỮA 2 ĐỈNH BẤT KÌ LUÔN CÓ ĐƯỜNG ĐI, HIỂU ĐƠN GIẢN THÌ NÓ LÀ MỘT CỤM
    // -- THÀNH PHẦN LIÊN THÔNG: ĐỒ THỊ KHÔNG LIÊN THÔNG PHÂN RÃ THÀNH CÁC ĐỒ THỊ LIÊN THÔNG, VD: ĐỈNH CÔ LẬP
    // - CÓ HƯỚNG: 
    // -- LIÊN THÔNG MẠNH: NẾU GIỮA 2 ĐỈNH U,V BẤT KÌ LUÔN CÓ ĐƯỜNG ĐI XUÔI VÀ NGƯỢC
    // -- LIÊN THÔNG YẾU: BỎ HƯỚNG, BIẾN THÀNH ĐỒ THỊ VÔ HƯỚNG THÌ LIÊN THÔNG
    // - THÀNH PHẦN LIÊN THÔNG MẠNH (SCC): CHIA ĐỒ THỊ CÓ HƯỚNG THÀNH CÁC THÀNH PHẦN LIÊN THÔNG MẠNH

}