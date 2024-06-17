#include <stdio.h>

int main() {
    // Mở file để ghi
    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        // Xử lý lỗi khi mở file
        printf("Could not open file\n");
        return 1;
    }

    // Lưu thông tin vào file
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a test file.\n");
    fprintf(file, "Writing some more text into the file.\n");

    // Đóng file sau khi ghi xong
    fclose(file);

    printf("Information has been written to the file successfully.\n");

    return 0;
}
