#include<stdio.h>
#include<conio.h>

void main() {
    FILE *fout1, *fout2, *fout3, *fin1, *fin2, *fin3;
    char data1[30], data2[30], ch1, ch2, ch3;
    clrscr();

    fout1 = fopen("file1.txt", "w");
    fout2 = fopen("file2.txt", "w");

    if(fout1 == NULL) {
        printf("Could not open file1");
        getch();
        exit(0);
    }

    if(fout2 == NULL) {
        printf("Could not open file2");
        getch();
        exit(0);
    }

    printf("Enter content for file1:\n");
    gets(data1);

    printf("Enter content for file2:\n");
    gets(data2);

    fprintf(fout1, "%s", data1);
    fprintf(fout2, "%s", data2);

    fclose(fout1);
    fclose(fout2);

    fin1 = fopen("file1.txt", "r");
    fin2 = fopen("file2.txt", "r");
    fout3 = fopen("file3.txt", "w");

    if(fin1 == NULL) {
        printf("Could not read from file 1");
        getch();
        exit(0);
    }

    if(fin2 == NULL) {
        printf("Could not read from file 2");
        getch();
        exit(0);
    }

    if(fout3 == NULL) {
        printf("Could not open file 3");
        getch();
        exit(0);
    }

    ch1 = getc(fin1);
    ch2 = getc(fin2);

    while(ch1 != EOF && ch2 != EOF) {
        if(ch1 != ch2) {
            fputc(ch2, fout3);
        }
        ch1 = getc(fin1);
        ch2 = getc(fin2);
    }

    fclose(fin1);
    fclose(fin2);
    fclose(fout3);

    fin3 = fopen("file3.dat", "r");

    if(fin3 == NULL) {
        printf("Could not read from file 3");
        getch();
        exit(0);
    }

    if((ch3 = getc(fin3)) == NULL) {
        printf("No difference between file1 and file2");
        getch();
        exit(0);
    }

    printf("Differences between file1 and file2 are:\n");

    while(ch3 != EOF) {
        printf("%c", ch3);
        ch3 = getc(fin3);
    }

    fclose(fin3);
    getch();
}
