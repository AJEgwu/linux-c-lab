#include <stdio.h>
#include <string.h>

struct Person { char name[50]; int age; };

int main(void){
    int arr[3] = {1,2,3};
    int *ptr = arr;
    for (int i = 0; i < 3; i++) printf("%d\n", *(ptr + i));

    FILE *f = fopen("output.txt", "w");
    if (f) { fprintf(f, "Text\n"); fclose(f); }

    struct Person p;
    strcpy(p.name, "Alice");
    p.age = 25;
    printf("%s %d\n", p.name, p.age);
    return 0;
}
