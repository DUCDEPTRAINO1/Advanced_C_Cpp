# Bài 1  Compiler - Macro
## 1, Compiler 
+ Compiler là một quá trình biến đổi từ file source code người dùng viết ra thành một file nào đó mà máy tính có thể hiểu và thực thi được.
##### Để hiểu rõ hơn thì hình dưới đây sẽ thể hiện 4 bước của quá trình Compiler:
![](https://tapit.vn/wp-content/uploads/2017/07/GCC_CompilationProcess.png)

Ở ***bước 1 là quá trình Preprocessor*** sau khi chúng ta viết được một source code (.c, .cpp, .h) sau khi qua bước này file source sẽ chuyển thành file (.i)
+  Ở bước này file .i xóa bỏ tất cả chú thích, comments của chương trình cũ 
+ Mấy cái code trong file thư viện #include cũng được dán vào hết file .i
+ Các định nghĩa của #define cũng được dán vào những nơi đã được sử dụng trong file .i

Ở ***bước 2 là quá trình Compiler*** sau khi đã có file .i chương trình tiếp tục chuyển file .i thành file .s được gọi là Assembly code là một ngôn ngữ gần với ngôn ngữ máy nhất 

Ở ***bước 3 là quá trình assembler*** sau khi đã có file assembly code (.s) chương trình tiếp tục chuyển file .s thành file .o Để dễ hiểu thì file .o là file code mà máy tính có thể hiểu được và trong file này thì chỉ toàn là mã máy 0 và 1 

Ở ***bước  là quá trình Linker*** Sau khi thực hiện các bước phía bên trên chúng ta sẽ có một đống file .o thì nhiệm vụ bây giờ chúng ta phải hợp nhất chúng lại thành một file duy nhất để máy tính có thể chạy được và đó là tác dụng của quá trình linker, chúng sẽ liên kết tất cả file .o lại thành 1 file .exe duy nhât để có thể thực thi chương trình hoàn chỉnh.

## 2,Macro
Hiểu đơn giản thôi thì ***Macro*** là những thứ được định nghĩa trước quá trình Preprocessor diễn ra như: các thư viện được thêm vào #include, hoặc là các định nghĩa được viết vào #define.
+ thư viện **#inlcude** thì hiểu đơn giản đó là một file code khác được dán vào chương trình của mình là mình có thể sử dụng các thứ được viết sẵn trong file code đó ra để sử dụng.
+ **#define** hiểu đơn giản như là thay thế một đoạn code này bằng một cái tên khác cho dễ đọc và dễ hình dung hơn, và giúp chương trình dễ bảo trì.
+ Ngoài #define chúng ta còn có **#undef** dùng để định nghĩa lại các macro đã định nghĩa trước đó.
+ Ngoài ra còn có **#if, #elif, #else** thì nó cũng giống như các lệnh if else sài bình thương thôi, nó sẽ dựa theo các #define đã định nghĩa ở trước đó để thực hiện các điều kiện đúng
+ Chỉ thị tiền xử lý **#ifdef, #ifndef** được hiểu đơn giản là đã được định nghĩa hoặc là chưa được định nghĩa. Với #ifdef thì nếu một #define trong điều kiện của #ifdef đã được định nghĩa thì nó sẽ thực hiện các câu lệnh trong điều kiện còn không thì chương trình sẽ không thực hiện nữa. Còn với #ifndef thì ngược lại, nếu một #define trong điều kiện của #ifndef chưa được định nghĩa thì nó sẽ thực hiện các câu lệnh trong điều kiện còn nếu đã được định nghĩa rồi thì nó sẽ không thực hiện nữa. Với #ifndef thì được sử dụng như là tránh các lỗi liên quan tới việc chèn thư viện bị trùng nhau trong một file.
+ **Variadic macro** Là một dạng macro cho phép nhận một số lượng biến tham số có thể thay đổi. Giúp định nghĩa các macro có thể xử lý một lượng biến đầu vào khác nhau.


# Bài 2: STDARG - ASSERT
## 1, Thư viện stdarg
Hiểu đơn giản là thư viện này giúp thực hiện các hàm tính toán hoặc làm gì đó với số lượng tham số truyền vào là không cố định
#### Chức năng của các hàm trong thư viện 
+ **va_list** theo cách hiểu của em thì nó là một kiểu dữ liệu con trỏ kiểu char dùng để lưu các tham số truyền vào hàm rồi duyệt từ từ qua các tham số đó
+ **va_start** thì là một hàm dùng để nhận biết nơi bắt đầu đọc các biến có thể thay đổi và được đánh dấu bằng một nhãn kiểu char.
+ **va_arg** dùng để duyệt qua các biến có thể thay đổi được tính từ cái nhãn  và ép kiểu chúng từ kiểu char về kiểu mong muốn, ví dụ kiểu int, float,...
+ **va_end** dùng thể thu hồi con trỏ đã được khai báo của kiểu dữ liệu va_list.
## 2, Thư viện assert
Hiểu đơn giản thì thư viện này nó giống như if else, có tác dụng kiểm tra một điều kiện nhưng đặc biệt ở chỗ nếu điều kiện sai thì nó sẽ trả về một thông điệp lỗi và cho biết điều kiện sai ở nơi nào.


# Bài 3 Pointer 
Hiểu đơn giản thì pointer nó cũng chỉ là một biến thôi, nhưng đặc biệt hơn thì biến này sẽ chỉ lưu địa chỉ của một đối tượng khác ví dụ như biến khác hoặc hàm khác,... Điều này giúp nó có thể truy suất tới địa chỉ của một đối tượng khác và có thể thay đổi giá trị của đối tượng đó.
Về kích thước size của con trỏ thì phụ thuộc vào kiến trúc của vi xử lý thôi
#### Các loại pointer 
**void pointer** là con trỏ có thể trỏ tới bất kì đối tượng nào mà không cần quan tâm kiểu dữ liệu của đối tượng đó là gì.Nhưng mà nếu muốn làm việc gì với biến đó thì phải ép kiểu nó về chính kiểu của biến đó.
**Function Pointer** 
Hiểu đơn giản thì nó cũng là một biến, và nó sẽ lưu địa chỉ của hàm thui, nó khai báo như nào thì nó có thể trỏ tới một hàm y như vậy.
ví dụ: ` void (*ptr)(int, int) ` thì có thể trỏ tới ` void tong(int a,int b) ` kiểu kiểu như vậy.
hoặc đẳng cấp hơn thì là dùng làm đối số cho một hàm ví dụ:
``` C
void calculator(void (*ptr)(int, int), int a, int b)
{
    printf("Program calculate: \n");
    ptr(a,b);
} 
```
**Pointer to Constant** hiểu đơn giản là một con trỏ sẽ trỏ tới một đối tượng nhưng không thể thay đổi giá trị của đối tượng đó được mà chỉ có thể đọc giá trị của đối tượng đó mà thôi.
cú pháp: `int const *ptr = &value;`
**Constant pointer** hiểu đơn giản thì nó là một con trỏ nhưng chỉ được phép trỏ tới một cái địa chỉ duy nhất, được ứng dụng làm nhãn của các ngoại vi hay các gì đó của vi điều khiển.
cú pháp: `int *const ptr = &value;`
**Pointer to Pointer** hiểu đơn giản thì nó là một con trỏ cấp 2, nghĩa là nó sẽ trỏ tới một con trỏ khác cấp 1, và tất nhiên là nó sẽ thay đổi được giá trị của con trỏ mà nó trỏ tới.
**NULL pointer** là con trỏ không trỏ tới bất kì một địa chỉ nào cả. Hiểu đơn giản là nếu chúng ta khai báo một con trỏ mà chưa cần sử dụng nó thì phải gán nó bằng **NULL** bởi vì nếu không gán bằng **NULL** rất có thể nó sẽ trỏ tới một địa chỉ bất kì trong chương trình và có thể gây xung đột biến. ``` 
int *ptr = NULL;``` 








