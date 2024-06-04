#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = NULL;        // Con trỏ cấp 1
    int **ptr_ptr = NULL;   // Con trỏ cấp 2

    ptr = &num;      // Gán địa chỉ của biến num cho con trỏ ptr
    ptr_ptr = &ptr;  // Gán địa chỉ của con trỏ ptr cho con trỏ ptr_ptr

    printf("Giá trị của biến num: %d\n", num);
    printf("Địa chỉ của biến num: %p\n", &num);
    printf("Giá trị của con trỏ ptr: %p\n", ptr);
    printf("Giá trị tại địa chỉ của con trỏ ptr: %d\n", *ptr);
    printf("Giá trị của địa chỉ cấp 1 ptr: %p\n", &ptr);
    printf("Giá trị của con trỏ cấp 2 ptr: %p\n", ptr_ptr);
    printf("Giá trị tại địa chỉ của con trỏ cấp 2 ptr_ptr: %p\n", *ptr_ptr);
    printf("Giá trị tại địa chỉ mà con trỏ cấp 2 ptr_ptr trỏ đến: %d\n", **ptr_ptr);

    return 0;
}
