#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void nhapChuoi(char *str, int maxLength) {
    printf("Nhap chuoi: ");
    fgets(str, maxLength, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void demKyTu(const char *str) {
    int count[256] = {0};  // Dem cac ky tu qua ASCII
    const char *ptr = str;

    // Dem so lan xuat hien
    while (*ptr) {
        unsigned char c = (unsigned char)*ptr;
        count[c]++;
        ptr++;
    }

    // In Kq
    printf("So lan xuat hien cua cac ky tu:\n");
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("'%c' xuat hien %d lan\n", i, count[i]);
        }
    }
}

int main() {
    char chuoi[MAX_LENGTH];

    nhapChuoi(chuoi, sizeof(chuoi));

    demKyTu(chuoi);

    return 0;
}

