# Bài 1:  Compiler - Macro
## 1, Compiler 
+ Compiler là một quá trình biến đổi từ file source code người dùng viết ra thành một file nào đó mà máy tính có thể hiểu và thực thi được.

**Để hiểu rõ hơn thì hình dưới đây sẽ thể hiện 4 bước của quá trình Compiler:**
![](https://tapit.vn/wp-content/uploads/2017/07/GCC_CompilationProcess.png)

Ở ***bước 1 là quá trình Preprocessor*** sau khi chúng ta viết được một source code (.c, .cpp, .h) sau khi qua bước này file source sẽ chuyển thành file (.i)

Câu lệnh ở đây sẽ là: ` gcc -E file.c -o file.i `
+  Ở bước này file .i xóa bỏ tất cả chú thích, comments của chương trình cũ 
+ Mấy cái code trong file thư viện #include cũng được dán vào hết file .i
+ Các định nghĩa của #define cũng được dán vào những nơi đã được sử dụng trong file .i

Ví dụ như hình dưới đây:
![](Processor.png)

Ở ***bước 2 là quá trình Compiler*** sau khi đã có file .i chương trình tiếp tục chuyển file .i thành file .s được gọi là Assembly code là một ngôn ngữ gần với ngôn ngữ máy nhất.

Câu lệnh ở đây sẽ là: ` gcc -S file.i -o file.s `
File nó sẽ có kiểu như hình dưới đây
![](fileASM.png)

Ở ***bước 3 là quá trình assembler*** sau khi đã có file assembly code (.s) chương trình tiếp tục chuyển file .s thành file .o Để dễ hiểu thì file .o là file code mà máy tính có thể hiểu được và trong file này thì chỉ toàn là mã máy 0 và 1. File nó sẽ có kiểu như hình dưới đây:

Câu lệnh ở đây sẽ là:` gcc -c file.s -o file.i `
![](fileO.png)  

Ở ***bước  là quá trình Linker*** Sau khi thực hiện các bước phía bên trên chúng ta sẽ có một đống file .o thì nhiệm vụ bây giờ chúng ta phải hợp nhất chúng lại thành một file duy nhất để máy tính có thể chạy được và đó là tác dụng của quá trình linker, chúng sẽ liên kết tất cả file .o lại thành 1 file .exe duy nhât để có thể thực thi chương trình hoàn chỉnh.

Câu lệnh ở đây sẽ là:` gcc file1.o file2.o file3.o -o output.exe`
![](Linker.png)

Đây cũng chỉ là quá trình liên kết nhiều file.o lại với nhau nên định dạng của file.exe cũng chỉ là mã máy 0 và 1.


## 2,Macro
Hiểu đơn giản thôi thì ***Macro*** là những thứ được định nghĩa trước quá trình Preprocessor diễn ra như: các thư viện được thêm vào #include, hoặc là các định nghĩa được viết vào #define.
Thư viện **#inlcude** thì hiểu đơn giản đó là một file code khác được dán vào chương trình của mình là mình có thể sử dụng các thứ được viết sẵn trong file code đó ra để sử dụng.
+ Có hai loại include: 
  + ` #include <file> ` có dấu ngoặc nhọn thì preprocessor sẽ được dẫn tới Include Directory của Compiler.
  + ` #include "file" ` sử dụng dấu ngoặc kép thì preprocessor sẽ tìm kiếm file trong thư mục cùng chứa với file chương trình của bạn.

**#define** hiểu đơn giản như là thay thế một đoạn code này bằng một cái tên khác cho dễ đọc và dễ hình dung hơn, và giúp chương trình dễ bảo trì.
ví dụ:
``` C
#inclde <stdio.h>
#define SIZE 100
int main()
{
printf(“ size is %d”, SIZE);
return 0;
}
```
Output: ` size is 100`

Hoặc macro có thể được viết nhiều dòng bằng cách sử dụng dấu ‘\’. như hình dưới:
``` C
#include <stdio.h>
#define PRINT(i,n) while (i<n)     \
{                  \
printf(“XinChao”);   \
i++;               \
}

int main()
{
int i=0;
PRINT(i,3);
return 0;
}
```
Output: ` XinChaoXinChaoXinChao`

**Token-Pasting** được truyền cho các macro có thể được nối bằng cách sử dụng toán tử ##. Nó sẽ giống kiểu nối chuỗi lại với nhau á mà. Ở đây ta có ví dụ lun cho nóng.
``` C
#include <stdio.h>
#define merge(X,Y) X##Y
int main()
{

printf(“%d\n”,merge(12, 34));
return 0;

}
```
Output: ` 1234`

Ngoài #define chúng ta còn có **#undef** dùng để định nghĩa lại các macro đã định nghĩa trước đó.
``` C
#include <stdio.h>
#define NUMBER 212
int main()
{

printf(“%d\n”, NUMBER);
#undef NUMBER
#define NUMBER  100;
   printf(“%d”, NUMBER);
return 0;

}
``` 
Output: ` 100 `

Ngoài ra còn có **#if, #elif, #else** thì nó cũng giống như các lệnh if else sài bình thương thôi, nó sẽ dựa theo các #define đã định nghĩa ở trước đó để thực hiện các điều kiện đúng. Nhớ phải có **#endif** nữa nha.
ví dụ:
``` C
#include <stdio.h>
#define NUMBER 3
int main()
{

#if NUMBER >= 2
printf(“Hello World!!!”);
#else
printf(“No define”);
#endif

}
``` 
Output: ` Hello World!!!`


Chỉ thị tiền xử lý **#ifdef, #ifndef** được hiểu đơn giản là đã được định nghĩa hoặc là chưa được định nghĩa. Với #ifdef thì nếu một #define trong điều kiện của #ifdef đã được định nghĩa thì nó sẽ thực hiện các câu lệnh trong điều kiện còn không thì chương trình sẽ không thực hiện nữa. Còn với #ifndef thì ngược lại, nếu một #define trong điều kiện của #ifndef chưa được định nghĩa thì nó sẽ thực hiện các câu lệnh trong điều kiện còn nếu đã được định nghĩa rồi thì nó sẽ không thực hiện nữa. Với #ifndef thì được sử dụng như là tránh các lỗi liên quan tới việc chèn thư viện bị trùng nhau trong một file.

Ta có một ví dụ sau: Nếu macro MATH_H đã được define trước đó thì ifndef không thực hiện gì cả, còn nếu nó chưa được define trước đó thì nó sẽ define MATH_H và thực hiện các lệnh ở dưới như bình thường:
``` C
#include <stdio.h>
#ifndef MATH_H
#define MATH_H
#include <math.h>
int main()
{

int a=9;
printf(“%d”, sqrt(a));

}
#endif
``` 
Output: ` 3.0000`

**Variadic macro** Là một dạng macro cho phép nhận một số lượng biến tham số có thể thay đổi. Giúp định nghĩa các macro có thể xử lý một lượng biến đầu vào khác nhau.
**Variadic macro** được định nghĩa bằng cách sử dụng dấu ba chấm (...) trong phần định nghĩa của macro. Sau đây là một ví dụ cơ bản:
``` C
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
```
Ở đây, __VA_ARGS__ là các đối số truyền vào hàm sum.



# Bài 2: STDARG - ASSERT
## 1, Thư viện stdarg
Hiểu đơn giản là thư viện này giúp cung cấp các macro và định nghĩa cần thiết để làm việc với các hàm nhận số lượng đối số không cố định, hay còn gọi là hàm **variadic**. Thư viện này cho phép bạn khai báo các hàm có thể nhận số lượng đối số tùy ý và xử lý chúng một cách linh hoạt.
#### Chức năng của các hàm trong thư viện 
+ **va_list** Đây là một kiểu dữ liệu được định nghĩa trong **stdarg.h**. Nó là một kiểu dùng để khai báo một biến mà sau đó sẽ được sử dụng để truy cập các đối số biến đổi trong một hàm. 
+ **va_start** thì là một hàm dùng để nhận biết nơi bắt đầu đọc các biến có thể thay đổi và được đánh dấu bằng một nhãn kiểu char.
+ **va_arg** truy cập từng đối số trong danh sách các đối số biến đổi được tính từ cái nhãn  và ép kiểu chúng từ kiểu char về kiểu mong muốn, ví dụ kiểu int, float,... Mỗi lần gọi va_arg, macro này sẽ trả về giá trị của đối số tiếp theo và tự động di chuyển đến đối số tiếp theo.
+ **va_end** dùng thể thu hồi con trỏ đã được khai báo của kiểu dữ liệu va_list.

ví dụ khi sử dụng thư viện 
``` C
int sum(int count, ...) {
    int total = 0;
    // Tạo ra con trỏ va dùng để truy cập các đối số biến đổi trong hàm sum
    va_list va; 

    // Khởi tạo danh sách các đối số với va, bắt đầu từ đối số sau count.
    va_start(va, count);

    for (int i = 0; i < count; i++) {
    // Truy cập từng đối số trong danh sách, mỗi lần lấy một đối số kiểu int. 
        total += va_arg(va, int);
    }
    // Thu hồi con trỏ đã được khai báo
    va_end(va);
    return total;
}
``` 

## 2, Thư viện assert
Hiểu đơn giản thì thư viện này nó giống như if else, có tác dụng kiểm tra một điều kiện nhưng đặc biệt ở chỗ nếu điều kiện sai thì nó sẽ trả về một thông điệp lỗi và cho biết điều kiện sai ở nơi nào.
ví dụ khi sử dụng:
``` C
#include <stdio.h>
#include <assert.h>

int divide(int a, int b) {
    assert(b != 0);  // Kiểm tra điều kiện: mẫu số không được bằng 0
    return a / b;
}

int main() {
    int a = 10, b = 0;

    // Gọi hàm divide, đây sẽ dẫn đến lỗi vì mẫu số là 0
    int result = divide(a, b);

    printf("Kết quả: %d\n", result);
    return 0;
}

``` 
Output: ` assertion "b != 0" failed: file "D:\tuhocC_hehe\Workspace_HALA\STDARG\test1.c", line 5, function: divide ` 
Ta có thể thấy thư viện này in cho chúng ta biết đây là lỗi gì và ở dòng nào, hàm nào. Quá là đẳng cấp xịn sò.


# Bài 3: Pointer 
Hiểu đơn giản thì pointer nó cũng chỉ là một biến thôi, nhưng đặc biệt hơn thì biến này sẽ chỉ lưu địa chỉ của một đối tượng khác ví dụ như biến khác hoặc hàm khác,... Điều này giúp nó có thể truy suất tới địa chỉ của một đối tượng khác và có thể thay đổi giá trị của đối tượng đó.
Về kích thước size của con trỏ thì phụ thuộc vào kiến trúc của vi xử lý thôi
#### Các loại pointer 
**void pointer** là con trỏ có thể trỏ tới bất kì đối tượng nào mà không cần quan tâm kiểu dữ liệu của đối tượng đó là gì.Nhưng mà nếu muốn làm việc gì với biến đó thì phải ép kiểu nó về chính kiểu của biến đó.

Dưới đây là một ví dụ cơ bản về con trỏ void
``` C
#include <stdio.h>

void printValue(void *ptr, char type) {
    switch (type) {
        case 'i':  // Kiểu int
            printf("Giá trị int: %d\n", *(int*)ptr);
            break;
        case 'f':  // Kiểu float
            printf("Giá trị float: %f\n", *(float*)ptr);
            break;
        case 'c':  // Kiểu char
            printf("Giá trị char: %c\n", *(char*)ptr);
            break;
        default:
            printf("Kiểu không hợp lệ\n");
    }
}

int main() {
    int a = 10;
    float b = 5.5;
    char c = 'A';

    printValue(&a, 'i');
    printValue(&b, 'f');
    printValue(&c, 'c');

    return 0;
}
```

**Function Pointer** 
Hiểu đơn giản thì nó cũng là một biến, và nó sẽ lưu địa chỉ của hàm thui, nó khai báo như nào thì nó có thể trỏ tới một hàm y như vậy.

ví dụ: ` void (*ptr)(int, int) ` thì có thể trỏ tới ` void add(int a,int b) ` kiểu kiểu như vậy.
hoặc đẳng cấp hơn thì là dùng làm đối số cho một hàm ví dụ:
``` C
#include <stdio.h>

// Định nghĩa một vài hàm đơn giản
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

// Hàm sử dụng con trỏ hàm để thực hiện phép toán
void compute(int (*operation)(int, int), int x, int y) {
    int result = operation(x, y);
    printf("Kết quả là: %d\n", result);
}

int main() {
    // Khai báo và gán con trỏ hàm
    int (*func_ptr)(int, int);

    // Gán hàm add cho con trỏ hàm
    func_ptr = add;
    compute(func_ptr, 5, 3);  // Kết quả là 8

    // Gán hàm subtract cho con trỏ hàm
    func_ptr = subtract;
    compute(func_ptr, 5, 3);  // Kết quả là 2

    return 0;
}

```

**Pointer to Constant** hiểu đơn giản là một con trỏ sẽ trỏ tới một đối tượng nhưng không thể thay đổi giá trị của đối tượng đó được mà chỉ có thể đọc giá trị của đối tượng đó mà thôi.
cú pháp: `int const *ptr = &value;`

Khi bạn truyền con trỏ đến hằng vào một hàm, bạn đảm bảo rằng hàm đó sẽ không thể thay đổi dữ liệu gốc. Điều này rất quan trọng trong các tình huống khi bạn chỉ muốn một hàm đọc dữ liệu mà không thay đổi nó.

ví dụ:
``` C
void printArray(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
/*hàm printArray nhận một con trỏ đến hằng arr. Điều này đảm bảo rằng hàm chỉ có thể
đọc dữ liệu từ mảng arr và không thể thay đổi nó.*/

```
**Constant pointer** hiểu đơn giản thì nó là một con trỏ nhưng chỉ được phép trỏ tới một cái địa chỉ duy nhất. Trong các hệ thống nhúng, nơi các con trỏ có thể trỏ đến các địa chỉ cố định trong bộ nhớ, việc sử dụng con trỏ hằng giúp đảm bảo rằng con trỏ sẽ luôn trỏ đến đúng vị trí bộ nhớ mà không bị thay đổi.
cú pháp: `int *const ptr = &value;`

ví dụ: Giả sử bạn có một thanh ghi điều khiển LED trên một vi điều khiển và bạn muốn viết một giá trị vào thanh ghi này để điều khiển LED. Bạn có thể sử dụng con trỏ hằng để đảm bảo rằng địa chỉ của thanh ghi này không bị thay đổi.
```C
#include <stdio.h>
#include <stdint.h>  // Để sử dụng các kiểu dữ liệu chính xác

// Địa chỉ của thanh ghi điều khiển LED (giả sử ở địa chỉ 0x40021000)
#define LED_CONTROL_REGISTER  ((volatile uint32_t *)0x40021000)

// Hàm để bật LED
void turnOnLED() {
    // Sử dụng con trỏ hằng để trỏ đến địa chỉ thanh ghi
    const uint32_t * const ledReg = LED_CONTROL_REGISTER;
    
    // Viết giá trị vào thanh ghi để bật LED
    *ledReg = 0x1;  // Giả sử giá trị 0x1 bật LED
}

int main() {
    turnOnLED();
    // Các mã khác
    return 0;
}

```

**Pointer to Pointer** hiểu đơn giản thì nó là một con trỏ cấp 2, nghĩa là nó sẽ trỏ tới một con trỏ khác cấp 1, và tất nhiên là nó sẽ thay đổi được giá trị của con trỏ mà nó trỏ tới.

Dưới đây là một số ví dụ cụ thể để minh họa cách sử dụng con trỏ đến con trỏ:
```C
#include <stdio.h>

int main() {
    // Khai báo và khởi tạo một mảng con trỏ
    int a = 10;
    int b = 20;
    int c = 30;
    int *array[3] = { &a, &b, &c }; // Mảng con trỏ

    // Khai báo một con trỏ đến con trỏ và trỏ đến mảng con trỏ
    int **ptr = array;

    // Duyệt và in giá trị của mảng con trỏ thông qua con trỏ đến con trỏ
    for (int i = 0; i < 3; i++) {
        printf("Giá trị tại ptr[%d] = %d\n", i, *ptr[i]);
    }

    return 0;
}

```

**NULL pointer** là con trỏ không trỏ tới bất kì một địa chỉ nào cả. Hiểu đơn giản là nếu chúng ta khai báo một con trỏ mà chưa cần sử dụng nó thì phải gán nó bằng **NULL** bởi vì nếu không gán bằng **NULL** rất có thể nó sẽ trỏ tới một địa chỉ bất kì trong chương trình và có thể gây xung đột biến. ``` 
int *ptr = NULL;``` 

# Bài 4: Extern - Static - Volatile - Register

## 1,Biến Extern
Tại sao phải sử dụng biến này? Biến này khác gì so với **#include**
**#include** được sử dụng để chèn nội dung tệp tiêu đề vào tệp nguồn và để khai báo các hàm, biến, hoặc cấu trúc mà bạn sẽ sử dụng trong tệp nguồn đó.

**extern** được sử dụng để khai báo rằng một biến hoặc hàm đã được định nghĩa ở nơi khác, và bạn muốn sử dụng nó mà không định nghĩa lại.  Khi bạn khai báo một biến với từ khóa **extern**, bạn đang nói với trình biên dịch rằng biến này đã được định nghĩa ở một nơi khác, và bạn chỉ đang tham chiếu đến nó. Ta có ví dụ sau đây:

```C
// file1.c
int x = 10;  // Định nghĩa biến x

// file2.c
extern int x;  // Tham chiếu đến biến x đã được định nghĩa ở file1.c

```
Chú ý: ***Một lưu ý nữa là đối với các hàm thì cũng có tác dụng tương tự như vậy***

Nếu bạn định nghĩa biến toàn cục trong tệp tiêu đề và sử dụng #include nó ở nhiều tệp nguồn khác nhau, bạn sẽ gặp lỗi liên kết do việc định nghĩa cùng một biến nhiều lần.

Và **#ifndef** không có tác dụng trong trường hợp này nha bởi vì là #ifndef chỉ có tác dụng trong 1 file thôi, còn nếu ta #include trong nhiều tệp nguồn khác nhau nó sẽ bị lỗi ở quá trình linker á.

ví dụ:
```C
// myheader.h
int x = 10;  // Định nghĩa biến x

// file1.c
#include "myheader.h"

// file2.c
#include "myheader.h"  // Lỗi do x đã được định nghĩa ở cả file1.c và file2.c
```

Nói chung là việc kết hợp đúng giữa **#include** và **extern** giúp bạn viết mã nguồn dễ bảo trì và tránh được các lỗi biên dịch không mong muốn.

## 2, Biến Static

Trong ngôn ngữ lập trình C, từ khóa static có nhiều ứng dụng khác nhau, tùy thuộc vào ngữ cảnh mà nó được sử dụng. static có thể được áp dụng cho biến cục bộ, biến toàn cục, và hàm. Nhưng hiểu đơn giản thì các bạn có thể hiểu là biến static được khai báo ở đâu thì nó chỉ có thể sử dụng trong đúng cái block đó thôi. Và biến static thì dù khai báo ở đâu thì nó luôn luôn được lưu ở vùng data trong **memory layout** nên là dù nó có khai báo với chức năng local thì nó cũng không bị mất đi giá trị sau mỗi lần gọi hàm.
Sau đây chúng ta sẽ đi chi tiết về các loại biến static:

**1, Biến static local**
Như đã nói ở trên thì biến static sẽ không bị mất giá trị sau mỗi lần gọi hàm. Thông thường, các biến cục bộ sẽ được khởi tạo lại mỗi khi hàm được gọi, nhưng với static, biến chỉ được khởi tạo một lần duy nhất và giữ nguyên giá trị của nó cho đến khi chương trình kết thúc.

ví dụ:
```C
void count() {
    static int counter = 0;  // Chỉ được khởi tạo một lần
    counter++;
    printf("%d\n", counter);
}

int main() {
    count();  
    count();  
    count();  
    return 0;
}
```
`Output 1`     `2`  `3`
**2, Biến static global**
Như đã nói ở trên thì biến static được khai báo ở đâu thì nó chỉ có thể sử dụng trong cái block đó thôi, vậy nên biến static global được khai báo thì có thể sử dụng trong toàn tệp tin mà nó định nghĩa, nhưng nó không thể được truy cập từ bất cứ 1 file nào khác cho dù là sử dụng từ khóa extern.

ví dụ:
```C
// file1.c
static int x = 10;  // Chỉ có thể truy cập trong file1.c

// file2.c
extern int x;  // Lỗi: không thể truy cập biến x trong file1.c

```
**3, Hàm static**
Đối với hàm thì nó cũng tương tự như biến static global thôi không khác gì cả. Điều này ngăn chặn hàm không thể bị truy cập từ các tệp tin khác

ví dụ:
```C
// file1.c
static void myFunction() {
    printf("Hello from static function\n");
}

// file2.c
extern void myFunction();  // Lỗi: không thể truy cập hàm myFunction trong file1.c
```
**4,Ứng dụng cụ thể của biến static trong các dự án lập trình lớn**
Đối với biến **static local** thì cho phép biến trong hàm giữ giá trị của nó mà không phải sử dụng biến toàn cục, giúp giữ cho mã nguồn gọn gàng và hạn chế phạm vi của biến.   

Ví dụ: Một hàm xử lý sự kiện có thể cần lưu trữ số lượng sự kiện đã xử lý mà không muốn tạo biến toàn cục:
```C
void processEvent() {
    static int eventCount = 0;
    eventCount++;
    printf("Processed %d events\n", eventCount);
}
```
Đối với biến **static global** và **hàm static** giúp tránh xung đột biến và hàm trong các modul dự án lớn. Bởi vì trong dự án nhiều file có thể đặt tên các biến giống nhau.

ví dụ: Giả sử bạn có hai module riêng biệt, mỗi module có một biến đếm
```C
// module1.c
static int counter = 0;
void incrementCounter1() {
    counter++;
    printf("Module 1 counter: %d\n", counter);
}

// module2.c
static int counter = 0;
void incrementCounter2() {
    counter++;
    printf("Module 2 counter: %d\n", counter);
}
```

Hoặc nếu bạn đã học tính đóng gói trong OOP thì biến static giúp ẩn thông tin chi tiết khi triển khai một hàm, để tranh việc ai đó có thể truy cập vô và sửa các chi tiết khiến hàm chính của chúng ta không còn được chính xác nữa.

Ví dụ: Bạn có thể có một hàm tiện ích hoặc biến hỗ trợ chỉ nên được sử dụng trong nội bộ một module, không muốn nó bị lộ ra ngoài
```C
// file_utils.c
static void helperFunction() {
    // do something
}

void publicFunction() {
    helperFunction();  // Sử dụng hàm tĩnh bên trong module
}
```

***Nhân tiện ở đây tui sẽ giải thích thêm về sự khác nhau giữa file.h và file.c***

**File.h** sẽ chứa các khai báo (declarations) như khai báo hàm, biến, macro, và các định nghĩa kiểu dữ liệu (struct, enum, typedef, v.v.). Chúng ta sẽ xem qua ví dụ ở đây để hiểu khai báo nghĩa là gì.
```C
int add(int a, int b);  // Khai báo hàm add với hai tham số kiểu int và trả về kiểu int

extern int x;  // Khai báo biến x, nhưng không cấp phát bộ nhớ cho nó
```
Vậy thì khai báo là việc thông báo cho trình biên dịch biết về sự tồn tại của một biến, hàm, hoặc kiểu dữ liệu mà không cung cấp toàn bộ thông tin chi tiết.

**File.c** chứa các định nghĩa (definitions) thực tế của hàm, biến, và các logic xử lý chương trình. Xem ví dụ dưới để hiểu thêm.
```C
int add(int a, int b) { // Cung cấp chi tiết cách hoạt động của hàm
    return a + b;
}
int x = 10;  // Định nghĩa biến x và cấp phát bộ nhớ cho nó với giá trị ban đầu là 10
```
Vậy thì định nghĩa là cung cấp toàn bộ thông tin chi tiết về một biến, hàm, hoặc kiểu dữ liệu, bao gồm cả việc cấp phát bộ nhớ (đối với biến) hoặc cung cấp nội dung chi tiết (đối với hàm).
## 3, Biến Volatile
Biến **volatile** rất quan trọng trong lập trình hệ thống nhúng, biến này chỉ ra cho trình biên dịch biết rằng là nó có thể thay đổi bất cứ lúc nào và trình biên dịch không cần thiết phải can thiệp tối ưu nó.

Bởi vì trình biên dịch có chức năng tối ưu biến, nghĩa là nếu trình biên dịch nhận thấy rằng một biến không hề bị thay đổi trong chương trình thì nó sẽ không quan tâm tới biến đó nữa, nhưng nếu biến đó đảm nhận một chức năng nào đó từ ngoại vi nó sẽ không được cập nhật kịp thời khiến chức năng của hệ thống bị sai.

ví dụ trong hệ thống nhúng:
```C
volatile int *statusUSB = (int *)0x40021000;  // Địa chỉ giả định của thanh ghi chứa trạng thái của USB
while (*statusUSB & 0x01 == 0) {
    // Chờ đến khi bit 0 của thanh ghi trạng thái được set
}
```
Ở đây, **statusUSB** trỏ tới một thanh ghi phần cứng mà giá trị của nó có thể thay đổi bất kỳ lúc nào bởi phần cứng. Từ khóa **volatile** đảm bảo rằng mỗi lần lặp, giá trị thực sự của thanh ghi được đọc từ bộ nhớ.

## 4, Biến register
Biến này được sử dụng trong trường hợp là biến này cần sử dụng nhiều và cần tốc độ truy cập nhanh nhất có thể. Các biến bình thường thì sẽ được lưu trữ ở Ram nhưng đối với biến Register sẽ được lưu trữ thẳng ở các thanh ghi điều này làm tăng tốc độ truy cập hơn rất nhiều. Ta có thể xem qua hình vẽ dưới đây để hiểu rõ hơn 

![](Bien_Register.png)

Hình vẽ này biểu thị việc xử lí tăng giá trị của biến a, nhưng nếu biến này lưu ở Ram thì quá trình này phải mất 4 bước kể từ lúc biến này được khai báo cho tới khi nó được tăng giá trị. Nó sẽ phải đi đến Register lưu giá trị rồi mới đi qua bộ tính toán ALU rồi sau đó mới chở về Register rồi mới trở về Ram. Nhưng nếu biến này được lưu trực tiếp ở Register thì nó sẽ chỉ mất 2 bước để thực hiện tính toán, điều này làm tăng đáng kể thời gian thực hiện chương trình.

**Các hạn chế khi sử dụng biến Register**

+ Bởi vì Ram thì nhiều nhưng Register thì ít nên việc tất cả các biến đều được sử dụng với từ khóa là Register là điều không thể. Người lập trình nên cân nhắc khi sử dụng biến Register.
+ **Không sử dụng với mảng hoặc biến có kích thước lớn**: Vì các thanh ghi có kích thước giới hạn, biến register không nên được sử dụng với mảng hoặc các cấu trúc dữ liệu lớn.
+ **Và một lưu ý nữa là** biến Register chỉ được khai báo dưới dạng local. Bởi vì các biến local chỉ tồn tại trong thời gian hàm chứa chúng đang thực thi. Khi hàm kết thúc, các biến này không còn tồn tại, và thanh ghi có thể được sử dụng cho các tác vụ khác. Điều này phù hợp với đặc tính của thanh ghi, vốn là tài nguyên có thời gian tồn tại ngắn và liên quan chặt chẽ đến luồng thực thi hiện tại.

ví dụ về 1 chương trình sử dụng biến Register
```C
void sumArray(int *arr, int size) {
    register int sum = 0;
    register int i;
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("Sum: %d\n", sum);
}
```

# Bài 5: Goto - setjmp.h 

## 1, Goto
**Goto** là gì? 
Đây là một từ khóa trong C, nó có tác dụng là sẽ nhảy tới vị trí một cái nhãn nào đó đã được tạo trước. Và Goto có tác dụng khá tốt khi có thể được dùng để thoát khỏi những vòng lặp một cách linh hoạt mà không phải sử dụng tới **break** nhiều lần. Xem ví dụ để dễ hiểu hơn.

```C
#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 3) {
                goto end_loops;  // Thoát khỏi cả hai vòng lặp
            }
            printf("i = %d, j = %d\n", i, j);
        }
    }

end_loops:
    printf("Đã thoát khỏi vòng lặp.\n");
    return 0;
}
```

**Lưu ý**: Và một lưu ý nhỏ ở đây là Goto chỉ có tác dụng ở local, có nghĩa là nó chỉ sử dụng được trong phạm vi 1 hàm nào đó, còn ở ngoài thì chịu chết nhá.

## 2, setjmp.h
Đây là một thư viện trong C thường được sử dụng để xử lý ngoại lệ và nó cung cấp cho người dùng 2 hàm chính đó là setjmp và longjmp.

**Trước tiên thì xử lí ngoại lệ có nghĩa là gì?**
**Xử lý ngoại lệ** (Exception Handling) là một cơ chế trong lập trình cho phép một chương trình phản ứng lại các tình huống bất thường hoặc lỗi xảy ra trong quá trình thực thi. Những lỗi này có thể là việc chia cho số 0, truy cập vào vùng nhớ không hợp lệ, lỗi I/O, hoặc các tình huống khác mà chương trình không thể dự đoán trước hoặc xử lý trong mã thông thường.

Vậy tác dụng của hàm thư viện setjmp là gì?
setjmp được dùng để quản lí quá trình nhảy tới mọi nơi trong chương trình (fix được các hạn chế của goto). Chúng cho phép bạn lưu trữ trạng thái của chương trình tại một thời điểm cụ thể và sau đó quay lại trạng thái đó từ bất kỳ vị trí nào trong mã. Để rõ hơn chúng ta sẽ đi tìm hiểu chức năng của hai hàm setjmp và longjmp rồi tới ví dụ.

**setjmp**: lưu trữ trạng thái hiện tại của môi trường chương trình vào một biến kiểu jmp_buf. Trạng thái này bao gồm các thông tin về con trỏ chương trình, ngăn xếp, và các biến cục bộ cần thiết để khôi phục trạng thái của chương trình sau này.
**longjmp**: Hàm longjmp được sử dụng để nhảy trở lại vị trí đã lưu bởi setjmp, khôi phục trạng thái môi trường đã được lưu trữ trước đó.

Chúng ta cùng xem qua ví dụ cụ thể để hiểu rõ hơn:
```C
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void second() {
    printf("Đang trong hàm second\n");
    longjmp(buf, 1);  // Nhảy trở lại vị trí setjmp
}

void first() {
    printf("Đang trong hàm first\n");
    second();  // Gọi hàm second
    printf("Điều này sẽ không bao giờ được in ra.\n");
}

int main() {
    if (setjmp(buf)) {
        printf("Đã nhảy trở lại từ hàm second\n");
    } else {
        printf("Gọi hàm first\n");
        first();  // Gọi hàm first
    }
    return 0;
}
```
Output:
```
Gọi hàm first
Đang trong hàm first
Đang trong hàm second
Đã nhảy trở lại từ hàm second
```
thư viện setjmp.h được ứng dụng rất nhiều trong nhúng trong việc xử lí các lỗi phần cứng. Giả sử bạn có một hệ thống nhúng điều khiển thiết bị cảm biến và bạn cần thực hiện một loạt các phép đo. Nếu xảy ra lỗi trong quá trình đọc dữ liệu từ cảm biến (ví dụ, cảm biến bị ngắt kết nối hoặc lỗi I/O), hệ thống cần khôi phục lại trạng thái trước đó mà không cần khởi động lại toàn bộ hệ thống.

**Một câu hỏi ở đây là việc sử lí lỗi của setjmp.h khác gì so với sử dụng thư viện assert.h?**
Hiểu đơn giản như z đi he:

khi sử dụng **assert** mà dính phải cái điều kiện sai, chương trình sẽ in ra thông báo lỗi và dừng chương trình ngay lập tức. Và cái assert này thì sử dụng trong trường hợp kiểm tra các lỗi logic mà không nên xảy ra trong điều kiện bình thường.

Còn đối với **setjmp** mà dính phải cái điều kiện bị lỗi chương trình thay vì dừng lại nó sẽ nhảy tới cái vị trí an toàn trước đó và tiếp tục thực hiện chương trình. Sử dụng cái thư viện **setjmp** này cực kì hữu ích trong các hệ thống nhúng mà việc dừng chương trình là không thể. 







