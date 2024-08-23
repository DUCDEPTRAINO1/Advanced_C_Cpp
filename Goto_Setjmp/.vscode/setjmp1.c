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

void readFile()
{
    printf("Đọc file...\n");
    THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
}

void networkOperation()
{
    // Bổ sung chương trình
}

void calculateData()
{
    // Bổ sung chương trình
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
        printf("%s\n", error_message);
    } 
    return 0;
}
