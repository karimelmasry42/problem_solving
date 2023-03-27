#include <stdio.h>

int main() {
    char ch = 'a';
    char *p = &ch;
    (*p)+=26;
    printf("%c\n", ch);
    printf("%d\n%d\n", p, &ch);
    return 0;
}
