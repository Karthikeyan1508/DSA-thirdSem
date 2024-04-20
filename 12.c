#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main() {
    int a[100], a1[100], i, j, result, n, cnt = 0;
    clrscr();
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < 10; i++)
        a1[i] = -1;

    for (i = 0; i < n; i++) {
        result = a[i] % 10;
        if (a1[result] == -1) {
            a1[result] = a[i];
            printf("Location: a1[%d], Value: %d\n", result, a1[result]);
        } else {
            j = result + 1;
            while (1) {
                if (a1[j] == -1) {
                    a1[j] = a[i];
                    printf("Location: a1[%d], Value: %d\n", j, a1[j]);
                    break;
                }
                if (j > n - 1)
                    j = 0;
                if (cnt == n)
                    break;
                cnt++;
                j++;
            }
        }
        result = 0;
    }

    printf("Hash table using open addressing mode:\n");
    for (i = 0; i < 10; i++) {
        if (a1[i] != -1)
            printf("%d ", a1[i]);
    }

    getch();
}
