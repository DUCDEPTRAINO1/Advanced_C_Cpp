#include <stdio.h>
#include <string.h>
/* định nghĩa một cấu trúc sinh viên */
typedef struct {
   char ten[50];
   float diemTrungBinh;
   int id;
} SinhVien;

/* 
Hàm này so sánh hai chuỗi ký tự str1 và str2. Nó hoạt động bằng cách so sánh từng ký tự từ đầu đến cuối. 
Nếu tìm thấy một ký tự khác nhau hoặc đến cuối chuỗi (ký tự null '\0'), nó sẽ trả về sự chênh lệch giữa hai ký tự hiện tại 
*/
int stringCompare(const char *str1, const char *str2) {
   while (*str1 && (*str1 == *str2)) {
       str1++;  
       str2++;
   }
   return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

// Hàm so sánh theo tên
/* Hàm này so sánh hai sinh viên dựa trên tên của họ bằng cách gọi hàm stringCompare */
int compareByName(const void *a, const void *b) {
   SinhVien *sv1 = (SinhVien *)a;
   SinhVien *sv2 = (SinhVien *)b;
   return stringCompare(sv1->ten, sv2->ten);
}

// Hàm so sánh theo điểm trung bình
/* Hàm này so sánh hai sinh viên dựa trên điểm trung bình. Nó trả về
1 nếu điểm của sinh viên sv1 lớn hơn điểm của sv2
0 nếu điểm của sinh viên sv1 bé hơn hoặc bằng điểm của sv2 */
int compareByDiemTrungBinh(const void *a, const void *b)
{
    SinhVien *sv1 = (SinhVien *)a;
    SinhVien *sv2 = (SinhVien *)b;
    if (sv1->diemTrungBinh > sv2->diemTrungBinh)
        return 1;
    else
        return 0;
}

// Hàm so sánh theo ID
/* Hàm này so sánh hai sinh viên dựa trên ID. Nó trả về sự chênh lệch giữa ID của sv1 và sv2 */
int compareByID(const void *a, const void *b) {
   SinhVien *sv1 = (SinhVien *)a;
   SinhVien *sv2 = (SinhVien *)b;
   return sv1->id - sv2->id;
}

// Hàm sắp xếp chung
/* Hàm sort thực hiện việc sắp xếp danh sách sinh viên (array) theo một tiêu chí so sánh được xác định bởi con trỏ hàm compareFunc.
Con trỏ hàm này có thể là một trong các hàm so sánh đã định nghĩa ở trên (compareByName, compareByDiemTrungBinh, hoặc compareByID). */
void sort(SinhVien array[], size_t size, int (*compareFunc)(const void *, const void *)) {
   int i, j;
   SinhVien temp;
   for (i = 0; i < size-1; i++)    
       for (j = i+1; j < size; j++)
           if (compareFunc(&array[i], &array[j]) > 0) {
               temp = array[i];
               array[i] = array[j];
               array[j] = temp;
           }
}
/* Hàm display dùng để hiển thị danh sách sinh viên. Nó in ra ID, tên và điểm trung bình của từng sinh viên trong mảng array */
void display(SinhVien *array, size_t size) {
   for (size_t i = 0; i < size; i++) {
       printf("ID: %d, Ten: %s, Diem Trung Binh: %.2f\n", array[i].id, array[i].ten, array[i].diemTrungBinh);
   }
   printf("\n");
}

int main() {
    /* Khởi tạo một danh sách sinh viên (danhSachSV) với các thông tin về tên, điểm trung bình, và ID */
   SinhVien danhSachSV[] = {
       {  
           .ten = "Hoang",
           .diemTrungBinh = 7.5,
           .id = 100
       },
       {
           .ten = "Tuan",
           .diemTrungBinh = 4.5,
           .id = 101
       },
       {
           .ten = "Vy",
           .diemTrungBinh = 6.8,
           .id = 102},
       {  
           .ten = "Ngan",
           .diemTrungBinh = 5.6,
           .id = 10
       },
   };

   /*Tính kích thước của danh sách.*/
   size_t size = sizeof(danhSachSV) / sizeof(danhSachSV[0]);

   /* Gọi hàm sort để sắp xếp danh sách sau đó display ra màn hình */
   // Sắp xếp theo tên
   sort(danhSachSV, size, compareByName); 
   printf("Sap xep theo ten:\n");
   display(danhSachSV, size);

   // Sắp xếp theo điểm trung bình
   sort(danhSachSV, size, compareByDiemTrungBinh);
   printf("Sap xep theo diem trung binh:\n");
   display(danhSachSV, size);

   // Sắp xếp theo ID
   sort(danhSachSV, size, compareByID);
   printf("Sap xep theo ID:\n");
   display(danhSachSV, size);

   return 0;
}
