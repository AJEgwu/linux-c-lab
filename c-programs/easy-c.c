#include <stdio.h>
int main(void) {
    printf("Hello, C!\n");
    int num = 5;
    printf("Number: %d\n", num);
    int age;
    printf("Enter age: ");
    if (scanf("%d", &age) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }
    printf("Age: %d\n", age);
    return 0;
}
