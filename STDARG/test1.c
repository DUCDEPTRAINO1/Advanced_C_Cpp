#include <stdio.h>
#include <stdarg.h>

#define tong(...) sum(__VA_ARGS__, 0)

int sum(int labels, ...)
{
    va_list va;
    int sum = labels;
    va_start(va, labels);
    int value = 0;
    while ((value = va_arg(va, int)) != 0)
    {
        sum += value;
    }
    va_end(va);
    return sum;
}

int main()
{
    printf("tong = %d", tong(1, 2, 3));
    return 0;
}