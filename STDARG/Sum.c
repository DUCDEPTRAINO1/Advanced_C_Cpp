#include <stdio.h>
#include <stdarg.h>
/* Đơn giản hóa hàm tong bằng cách tạo một Variadic macro với tham số truyền vào thoải mái */
#define tong(...) sum(__VA_ARGS__, 0)


int sum(int labels, ...)
{
    /*dùng để khai báo một biến mà sau đó sẽ được sử dụng để truy cập các đối số biến đổi trong một hàm.*/
    va_list va;
    int sum = labels;

    /* một hàm dùng để nhận biết nơi bắt đầu đọc các biến có thể thay đổi và được đánh dấu bằng một nhãn kiểu char.*/
    va_start(va, labels);
    int value = 0;

    /*
    truy cập từng đối số trong danh sách các đối số biến đổi được tính từ cái nhãn và ép kiểu chúng từ kiểu char về 
    kiểu mong muốn, ví dụ kiểu int, float,... Mỗi lần gọi va_arg, macro này sẽ trả về giá trị của đối số tiếp theo và 
    tự động di chuyển đến đối số tiếp theo.
    */
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