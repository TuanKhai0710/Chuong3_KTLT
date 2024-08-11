#include <stdio.h>
#include <string.h>

// Hàm xóa từ khỏi chuỗi
void xoaTu(char *chuoi, const char *tuXoa) {
	char *pos;
	size_t lenTuXoa = strlen(tuXoa);
	size_t lenChuoi = strlen(chuoi);

	while ((pos = strstr(chuoi, tuXoa)) != NULL) {
		// Nếu từ cần xóa nằm ở đầu chuỗi
		if (pos == chuoi) {
			// Di chuyển phần còn lại của chuỗi về trước
			memmove(chuoi, chuoi + lenTuXoa, lenChuoi - lenTuXoa + 1);
		}
		else {
			// Xóa từ khỏi giữa chuỗi
			memmove(pos, pos + lenTuXoa, lenChuoi - (pos - chuoi) - lenTuXoa + 1);
		}

		// Cập nhật độ dài của chuỗi sau khi xóa
		lenChuoi = strlen(chuoi);
	}
}

int main() {
	char chuoi[100];
	char tuXoa[50];

	printf("Nhap chuoi: ");
	fgets(chuoi, sizeof(chuoi), stdin);

	// Loại bỏ ký tự newline nếu có
	size_t len = strlen(chuoi);
	if (len > 0 && chuoi[len - 1] == '\n') {
		chuoi[len - 1] = '\0';
	}

	printf("Nhap tu can xoa: ");
	fgets(tuXoa, sizeof(tuXoa), stdin);

	// Loại bỏ ký tự newline nếu có
	len = strlen(tuXoa);
	if (len > 0 && tuXoa[len - 1] == '\n') {
		tuXoa[len - 1] = '\0';
	}

	// Xóa từ khỏi chuỗi
	xoaTu(chuoi, tuXoa);

	printf("Chuoi sau khi xoa: %s\n", chuoi);
	printf("Nhan Enter de ket thuc chuong trinh...\n");
	getchar(); // Đọc ký tự Enter còn lại từ buffer
	getchar(); // Chờ người dùng nhấn Enter 
	return 0;
}
