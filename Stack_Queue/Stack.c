#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Kích thước tối đa của ngăn xếp

/*Định nghĩa một stack bảo gồm mảng có Max phần tử và vị trí của đỉnh*/
typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

/*Khởi tạo Stack và gán giá trị của top bằng -1 vì ban đầu ở đây chưa có phần từ nào được thêm vào cả.*/
void initialize(Stack *s) {
    s->top = -1;
}

/*Hàm kiểm tra xem stack có full không bằng cách kiểm tra xem vị trí của top có bằng số size-1 không */
int is_full(Stack *s) {
    return s->top == MAX - 1;
}

/*Hàm kiểm tra xem Stack có rỗng không bằng cách check xem vị trí của top có bằng -1 không*/
int is_empty(Stack *s) {
    return s->top == -1;
}

/*Hàm push một phần từ vào stack:
+ đầu tiên check xem stack có đầy không, nếu có thì trả về luôn
+ Nếu ko thì chúng ta sẽ tăng vị trí của top stack lên và gán giá trị cho nó, lưu ý ở đây là lệnh tăng giá trị top trước rồi mới gán. */
void push(Stack *s, int value) {
    if (is_full(s)) {
        printf("Stack overflow\n");
    } else {
        s->items[++(s->top)] = value;
    }
}

/*Hàm pop một phần tử ra khỏi stack:
+ Đầu tiên check xem stack có rỗng không, nếu rỗng thì trả về luôn
+ Tiếp theo thì chúng ta sẽ pop 1 phần từ ra khỏi stack rồi mới giảm vị trí của top xuống*/
int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

/*Hàm kiểm tra xem vị trí của top đang là bao nhiêu, hàm này khá đơn giản khi chỉ cần truyền một con trỏ vào và kiểm tra giá trị của top rồi trả về thôi */
int peek(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is: %d\n", peek(&stack));
    printf("Popped element is: %d\n", pop(&stack));
    printf("Top element after pop: %d\n", peek(&stack));

    return 0;
}