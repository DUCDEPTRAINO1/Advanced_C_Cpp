#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Đây là định nghĩa của một node trong danh sách liên kết. Mỗi node có hai thành phần chính:
value: lưu trữ dữ liệu (ở đây là kiểu int).
next: là con trỏ trỏ tới node tiếp theo trong danh sách.
Khi kết hợp nhiều node lại với nhau qua con trỏ next, chúng ta tạo ra một danh sách liên kết (linked list).*/
typedef struct node
{
    int value;
    struct node *next;
} node;

/*Hàm này tạo ra một node mới với dữ liệu data được truyền vào.
+, malloc cấp phát động một vùng nhớ cho node mới. Vùng nhớ này đủ lớn để chứa một struct node.
+, newnode->value = data gán giá trị data vào phần value của node.
+, newnode->next = NULL thiết lập con trỏ next của node trỏ tới NULL, vì đây là node cuối cùng khi mới tạo.
+, Cuối cùng, trả về con trỏ trỏ đến node mới tạo.*/
node *create_node(int data)
{
    node *newnode = (node *)(malloc(sizeof(node)));
    newnode->value = data;
    newnode->next = NULL;
    return newnode;
}

/*Hàm này in ra toàn bộ danh sách liên kết từ node đầu đến node cuối.
+, head là con trỏ trỏ tới node đầu tiên trong danh sách.
+, Vòng lặp while (head != NULL) duyệt qua từng node và in ra giá trị của nó. Sau mỗi lần in, head di chuyển đến node kế tiếp (head = head->next).*/
void In(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
}

/*Hàm này thêm một node mới với giá trị data vào cuối danh sách.
+, Nếu danh sách trống (tức *head == NULL), node mới sẽ trở thành node đầu tiên.
+, Nếu danh sách đã có phần tử, hàm sẽ duyệt đến node cuối cùng thông qua vòng lặp while (p->next != NULL) 
và liên kết node cuối đó với node mới vừa tạo bằng cách p->next = newnode.*/
void push_node(node **head, int data)
{
    node *newnode = create_node(data);
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        node *p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newnode;
    }
}

/*Hàm này xóa node cuối cùng trong danh sách.
+, p là con trỏ trỏ tới node hiện tại và previous trỏ tới node trước đó.
+, Vòng lặp while (p->next != NULL) dùng để tìm đến node cuối cùng trong danh sách.
+, Sau đó, previous->next = NULL ngắt liên kết giữa node cuối và danh sách, rồi giải phóng bộ nhớ của node cuối (free(p)).*/
void pop_node(node **head)
{
    node *p = *head;
    node *previous = NULL;
    while (p->next != NULL)
    {
        previous = p;
        p = p->next;
    }
    previous->next = NULL;
    free(p);
}

/*Thêm một node mới với giá trị data vào đầu danh sách.
+, newnode->next = *head giúp node mới trỏ tới node hiện tại đang là đầu danh sách.
+, Sau đó, *head = newnode giúp cập nhật con trỏ đầu danh sách để trỏ đến node mới.*/
void push_front(node **head, int data)
{
    node *newnode = create_node(data);
    newnode->next = *head;
    *head = newnode;
}

/*Hàm này xóa node đầu tiên trong danh sách.
+, *head = p->next giúp cập nhật đầu danh sách để trỏ đến node thứ hai.
+, Sau đó, giải phóng bộ nhớ của node đầu tiên (free(p)).*/
void pop_front(node **head)
{
    node *p = *head;
    *head = p->next;
    free(p);
}
/*Hàm này sẽ lấy giá trị của node đầu tiên trong ds
+, nếu head bằng NULL thì ds trống 
+, nếu ds không trống thì trả luôn về giá trị của head chính là giá trị đầu tiên*/
int front(node *head)
{
    if(head == NULL){
        printf("Danh sách trống.\n");
        return -1;
    }
    return head->value;
}
/*Hàm này sẽ lấy giá trị của node cuối cùng trong ds
+, nếu head bằng NULL thì ds trống 
+, nếu ds không trống thì duyệt vòng lặp cho tới khi nào head bằng NULL tức là nằm ở 
node cuối cùng, sau đó chúng ta return luôn về giá trị của node đó*/
int back(node *head)
{
    if (head == NULL)
    {
        printf("Danh sách trống.\n");
        return -1;
    }
    while (head->next != NULL)
    {
        head = head->next;
    }
    return head->value;
}
/*Hàm này chèn một node mới vào vị trí id trong danh sách.
+,Nếu id == 0, hàm sẽ chèn node vào đầu danh sách.
+,Nếu không, hàm sẽ duyệt qua danh sách đến vị trí id, sau đó chèn node mới vào giữa.*/
void insert_id(node **head, int data, int id)
{
    node *newnode = create_node(data);
    if (*head == NULL)
    {
        *head = newnode;
    }

    else
    {
        node *p = *head;
        node *current = NULL;
        if (id == 0)
        {
        newnode->next = *head;
        *head = newnode;
        }
        else
        {
            for (int i = 0; i < id; i++)
            {
                current = p;
                p = p->next;
            }
            current->next = newnode;
            newnode->next = p;
        }
    }
}
/*Hàm này xóa node tại vị trí id trong danh sách.
Vòng lặp for giúp duyệt đến vị trí cần xóa. Sau đó, con trỏ current được liên kết với node sau node cần xóa (current->next = p->next), 
và node tại vị trí id sẽ bị xóa bằng free(p).*/
void delete_list(node **head, int id){
    node *p = *head;
    node *current = NULL;
    for (int i = 0; i < id; i++)
    {
        current = p;
        p = p->next;
        current->next = p->next;
    }
    free(p);
}
/*hàm này sẽ trả về số lượng node có trong ds bằng cách duyệt qua vòng lặp và đếm giá trị count cho tới node cuối cùng*/
int size(node *head){
    int count = 0;
    while (head !=NULL)
    {   
        count++;
        head = head->next;
    }
    return count;
}
/*Hàm này trả về giá trị của node tại vị trí id.
Nó duyệt qua danh sách đến khi đạt tới vị trí yêu cầu, sau đó trả về giá trị của node đó. Nếu id không hợp lệ, sẽ thông báo và trả về -1.*/
int get(node *head, int id){
    int i = 0;
    while (i!=id)
    {
        if(head->next==NULL){
            printf("id khong hop le");
            return -1;
        }
        i++;
        head = head->next;
    }
    return head->value;
}

bool empty(node* head){
    return head == NULL;
}
int main()
{
    node *head = NULL;

    push_node(&head,1);
    push_node(&head,2);
    push_node(&head,3);
    push_front(&head,0);
    // pop_node(&head);
    // pop_front(&head);
    // printf("%d \n",front(head));
    // printf("%d \n",back(head));
    insert_id(&head,4,1);
    delete_list(&head,1);
    printf("%d \n", size(head));
    printf("%d \n", get(head,1));

    In(head);
    return 0;
}