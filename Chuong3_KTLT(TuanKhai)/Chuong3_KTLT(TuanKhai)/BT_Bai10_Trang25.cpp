#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256

char findMostFrequentChar(const char *str) {
	int count[MAX_CHARS] = { 0 };
	int maxCount = 0;
	char result;

	// Đếm số lần xuất hiện của mỗi ký tự
	for (int i = 0; str[i] != '\0'; i++) {
		count[(unsigned char)str[i]]++;
		if (count[(unsigned char)str[i]] > maxCount) {
			maxCount = count[(unsigned char)str[i]];
			result = str[i];
		}
	}

	return result;
}

int main() {
	char str[1000];

	printf("Nhap chuoi: ");
	fgets(str, sizeof(str), stdin);

	// Loại bỏ ký tự newline ở cuối chuỗi
	str[strcspn(str, "\n")] = '\0';

	char mostFrequentChar = findMostFrequentChar(str);

	printf("Ky tu xuat hien nhieu nhat la: '%c'\n", mostFrequentChar);
	printf("Nhan Enter de ket thuc chuong trinh...\n");
	getchar(); // Đọc ký tự Enter còn lại từ buffer
	getchar(); // Chờ người dùng nhấn Enter 
	return 0;
}
