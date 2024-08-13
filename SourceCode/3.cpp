#include <stdio.h>
#include <string.h>
#include <ctype.h>



void nhapChuoi(char *str, int maxLength) {
    printf("Nhap chuoi: ");
    fgets(str, maxLength, stdin);
    // Xóa xuong dong
    str[strcspn(str, "\n")] = '\0';
}


void xuatChuoi(const char *str) {
    printf("Chuoi nhap: %s\n", str);
}

void xoaKhoangTrang(char *str) {
    char *dest = str;
    const char *src = str;
    
    // Xóa dau chuoi
    while (*src == ' ') src++;

    // Xóa giua cac tu
    while (*src) {
        *dest++ = *src++;
        if (*(dest - 1) == ' ') {
            while (*src == ' ') src++;
            if (*src == '\0') break;
        }
    }
    
    // Xóa cuoi chuoi
    if (dest > str && *(dest - 1) == ' ') dest--;
    *dest = '\0';
}

int main() {
    char chuoi[100];
    nhapChuoi(chuoi, sizeof(chuoi));
    xoaKhoangTrang(chuoi);
    xuatChuoi(chuoi);
    return 0;
}

