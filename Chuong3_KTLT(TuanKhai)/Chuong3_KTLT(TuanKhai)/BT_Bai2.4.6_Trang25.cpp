#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
// Hàm đếm số khoảng trắng trong chuỗi
int demKhoangTrang(const char *str) {
	int dem = 0;
	while (*str != '\0') { // Duyệt đến hết chuỗi
		if (*str == ' ') { // Kiểm tra ký tự hiện tại có phải là khoảng trắng không
			dem++;
		}
		str++; // Di chuyển đến ký tự tiếp theo
	}
	return dem;
}

// Hàm để chuyển ký tự thành chữ in hoa
char toUpper(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + 'A';
	}
	return c;
}

// Hàm để chuyển ký tự thành chữ thường
char toLower(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 'a';
	}
	return c;
}

// Hàm đổi ký tự đầu tiên của mỗi từ thành chữ in hoa và các ký tự còn lại thành chữ thường
void chuyenDoiChuoi(char *str) {
	int inWord = 0; // Biến để theo dõi xem có đang ở trong từ không

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			// Nếu ký tự là khoảng trắng, đánh dấu là không còn ở trong từ
			inWord = 0;
		}
		else {
			if (!inWord) {
				// Nếu không phải đang ở trong từ, thì đây là ký tự đầu tiên của từ
				str[i] = toUpper(str[i]);
				inWord = 1;
			}
			else {
				// Nếu đang ở trong từ, thì đổi ký tự thành chữ thường
				str[i] = toLower(str[i]);
			}
		}
	}
}
// Hàm cắt chuỗi họ tên thành chuỗi họ lót và chuỗi tên
void catChuanHoTen(const char *fullName, char *hoLot, char *ten) {
	// Tìm ký tự khoảng trắng cuối cùng trong chuỗi
	const char *lastSpace = strrchr(fullName, ' ');

	if (lastSpace == NULL) {
		// Nếu không có khoảng trắng, toàn bộ chuỗi là tên
		size_t len = strlen(fullName);
		if (len < 100) {
			for (size_t i = 0; i < len; i++) {
				ten[i] = fullName[i];
			}
			ten[len] = '\0';
		}
		hoLot[0] = '\0'; // Chuỗi họ lót rỗng
	}
	else {
		// Cắt chuỗi họ lót từ đầu đến khoảng trắng cuối cùng
		size_t hoLotLength = lastSpace - fullName;
		if (hoLotLength < 100) {
			for (size_t i = 0; i < hoLotLength; i++) {
				hoLot[i] = fullName[i];
			}
			hoLot[hoLotLength] = '\0';
		}

		// Cắt chuỗi tên từ ký tự sau khoảng trắng cuối cùng đến hết chuỗi
		const char *nameStart = lastSpace + 1;
		size_t nameLength = strlen(nameStart);
		if (nameLength < 100) {
			for (size_t i = 0; i < nameLength; i++) {
				ten[i] = nameStart[i];
			}
			ten[nameLength] = '\0';
		}
	}
}
int main() {
	char chuoi[100]; // Đảm bảo chuỗi không vượt quá 99 ký tự
	char hoLot[100];
	char ten[100];
	printf("Nhap chuoi: ");
	fgets(chuoi, sizeof(chuoi), stdin); // Đọc chuỗi từ người dùng, bao gồm khoảng trắng

	int soKhoangTrang = demKhoangTrang(chuoi);
	printf("So luong khoang trang trong chuoi la: %d\n", soKhoangTrang);

	// Loại bỏ ký tự newline nếu có
	size_t len = strlen(chuoi);
	if (len > 0 && chuoi[len - 1] == '\n') {
		chuoi[len - 1] = '\0';
	}

	chuyenDoiChuoi(chuoi);
	printf("Chuoi sau khi chuyen doi: %s\n", chuoi);

	catChuanHoTen(chuoi, hoLot, ten);
	printf("Chuoi ho lot: %s\n", hoLot);
	printf("Chuoi ten: %s\n", ten);

	printf("Nhan Enter de ket thuc chuong trinh...\n");
	getchar(); // Đọc ký tự Enter còn lại từ buffer
	getchar(); // Chờ người dùng nhấn Enter 
	return 0;
}
