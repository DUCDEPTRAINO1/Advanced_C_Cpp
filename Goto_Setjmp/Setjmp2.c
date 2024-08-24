#include <stdio.h>
#include <setjmp.h>
#include <string.h>

jmp_buf buf;
int exception_code;
char error_message[256];

enum ErrorCodes
{
    NO_ERROR,
    FILE_ERROR,
    NETWORK_ERROR,
    CALCULATION_ERROR
};

#define TRY if ((exception_code = setjmp(buf)) == 0)

#define CATCH(x) else if (exception_code == (x))

#define THROW(x, mess)             \
    strcpy(error_message, (mess)); \
    longjmp(buf, (x));

// Hàm mô phỏng đọc file
void readFile()
{
    printf("Đọc file...\n");
    
    THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
}

// Hàm mô phỏng hoạt động mạng
void networkOperation()
{
    printf("Thực hiện hoạt động mạng...\n");
    THROW(NETWORK_ERROR, "Lỗi mạng: Không thể kết nối đến máy chủ.");
}

// Hàm mô phỏng tính toán dữ liệu
void calculateData()
{
    printf("Tính toán dữ liệu...\n");
    THROW(CALCULATION_ERROR, "Lỗi tính toán: Phép tính không hợp lệ.");
}

int main()
{
    TRY
    {
        readFile();
        networkOperation();
        calculateData();
    }
    CATCH(FILE_ERROR)
    {
        printf("Lỗi: %s\n", error_message);
    }
    CATCH(NETWORK_ERROR)
    {
        printf("Lỗi: %s\n", error_message);
    }
    CATCH(CALCULATION_ERROR)
    {
        printf("Lỗi: %s\n", error_message);
    }
    printf("Kết thúc chương trình.\n");
    return 0;
}
