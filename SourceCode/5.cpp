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
    
    // Xóa khoang trang
    while (*src == ' ') src++;

    // Xóa khoang trang giua cac tu
    while (*src) {
        *dest++ = *src++;
        if (*(dest - 1) == ' ') {
            while (*src == ' ') src++;
            if (*src == '\0') break;
        }
    }
    
    // Xoa khoang trang cuoi chuoi
    if (dest > str && *(dest - 1) == ' ') dest--;
    *dest = '\0';
}

int main() {
    char hoTen[100];
    char tenCanTim[50];
    

    nhapChuoi(hoTen, sizeof(hoTen));
    xoaKhoangTrang(hoTen);


    printf("Nhap ten can tim: ");
    fgets(tenCanTim, sizeof(tenCanTim), stdin);
    tenCanTim[strcspn(tenCanTim, "\n")] = '\0';
    xoaKhoangTrang(tenCanTim);

    if (strstr(hoTen, tenCanTim) != NULL) {
        printf("Da nhap dung.\n");
    } else {
        printf("Da nhap sai.\n");
    }

    return 0;
}

