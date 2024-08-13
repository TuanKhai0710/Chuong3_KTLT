#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void chenTu(char* str, const char* word, int vitri) {
    char result[MAX_LENGTH];
    int len = strlen(str);
    int wordLen = strlen(word);

    if (vitri > len) {
        vitri = len; 
    }

    strncpy(result, str, vitri);
    result[vitri] = '\0';

    strcat(result, word);

    strcat(result, str + vitri);

    strcpy(str, result);
}

int main() {
    char str[MAX_LENGTH];
    char word[100];
    int vitri;

    printf("Nhap chuoi ban dau: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Nhap tu can chen: ");
    fgets(word, 100, stdin);
    word[strcspn(word, "\n")] = '\0';

    printf("Nhap vao vi tri chen: ");
    scanf("%d", &vitri);

    chenTu(str, word, vitri);

    printf("Chuoi ket qua: %s\n", str);

    return 0;
}
