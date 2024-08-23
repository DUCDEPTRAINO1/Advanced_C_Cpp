#include <stdio.h>
#include <setjmp.h>
#include <string.h>

jmp_buf buf;
int exception_code;
char error_message[255];

#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == (x))
#define THROW(x, mess)             \
    strcpy(error_message, (mess)); \
    longjmp(buf, (x));

double divide(int a, int b)
{
    if (b == 0)
    {
        THROW(1, "Divide by 0 !!"); // Mã lỗi 1 cho lỗi chia cho 0
    }
    return (double)a / b;
}

void checkpointer(int *ptr)
{
    if (ptr == NULL)
    {
        THROW(2, "Pointer to NULL !!");
    }
}

int main()
{
    int a = 10;
    int b = 0;
    double result = 0.0;
    int *ptr = NULL;

    TRY
    {
        result = divide(a, b);
        printf("Result: %f\n", result);
    }
    CATCH(1)
    {
        printf("Error: %s \n", error_message);
    }
    TRY
    {
        checkpointer(ptr);
    }
    CATCH(2)
    {
        printf("Error: %s \n", error_message);
    }

    // Các xử lý khác của chương trình
    return 0;
}
