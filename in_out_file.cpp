/**
 * @file patient_chat.cpp
 * @brief 
 * @version 0.1
 * @date 2024-06-21
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Hồ sơ cá nhân:
typedef struct {
    char tk[100];
    char mk[100];
    int ID;
    char name[100]; // Họ và tên
    int day, month, year; // Ngày tháng năm sinh
    char sex[100]; // Giới tính
    char address[100]; // Địa chỉ
    char numPhone[100]; // Số điện thoại
} caNhan;

// Thông tin y tế:
typedef struct {
    char tienBenhLy[100]; // Tiền sử bệnh lý
    int tienTiemChung; // Tiền sử tiêm chủng (các loại vắc xin đã tiêm)
} yTe;

// Lịch sử tiêm chủng:
typedef struct {
    char nameOfVaccine[100]; // Danh sách các loại vắc xin đã tiêm
    int dayT, monthT, yearT; // Ngày tiêm
    char DDT[100]; // Địa điểm tiêm
} LichSuTiemChung;

// Lịch tiêm chủng:
typedef struct {
    char duKien[1000]; // Lịch tiêm chủng dự kiến
    char nhacNho[1000]; // Nhắc nhở về các mũi tiêm sắp đến hạn
} lichTiemChung;

// Xóa bộ đệm đầu vào scanf
void clear() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Biến toàn cục
int dem = 0;

// Đếm và gán ID cho mỗi bệnh nhân nhập, ID được gán tăng 1
int tangDem() {
    return ++dem;
}

// Reset đếm về 0
int reset() {
    dem = 0;
    return dem;
}

// Khai báo hàm nhập data thông tin cá nhân và thông tin y tế
void dtCaNhan(caNhan*, yTe*, int);

// Khai báo hàm nhập data lịch sử tiêm chủng
void dtLichSuTiemChung(LichSuTiemChung*, int*, int);

// Khai báo hàm nhập data lịch tiêm chủng
void dtLichTiemChung(lichTiemChung*, int);

// Hàm hiển thị thông tin cá nhân
void displayCaNhan(caNhan*, int);

// Hàm hiển thị thông tin y tế
void displayYTe(yTe*, int);

// Hàm hiển thị lịch sử tiêm chủng của bệnh nhân
void displayLichSuTiemChung(LichSuTiemChung*, int*, int);

// Hàm hiển thị lịch tiêm chủng của bệnh nhân
void displayLichTiemChung(lichTiemChung*, int);

int main() {
    // Khai báo và cấp phát
    int numOfBn; // Số lượng bệnh nhân
    LichSuTiemChung* lichSuTiemChung[100]; // Khai báo 1 mảng struct (không hạn)
    int numOfVaccine[1000]; // Số lượng vaccine của 1 object
    caNhan* infor_cn; // Khai báo con trỏ kiểu caNhan
    yTe* infor_yt; // Khai báo con trỏ kiểu yTe
    lichTiemChung* infor_ltc; // Khai báo con trỏ kiểu lichTiemChung

    printf("Nhap so luong benh nhan: ");
    scanf("%d", &numOfBn);
    clear(); // Xóa bộ đệm sau khi nhập số lượng bệnh nhân

    // Cấp phát động thông tin cá nhân, y tế và lịch tiêm
    infor_cn = (caNhan*)malloc(numOfBn * sizeof(caNhan));
    infor_yt = (yTe*)malloc(numOfBn * sizeof(yTe));
    infor_ltc = (lichTiemChung*)malloc(numOfBn * sizeof(lichTiemChung));

    if (infor_cn == NULL || infor_yt == NULL || infor_ltc == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Thực thi nhiệm vụ
    dtCaNhan(infor_cn, infor_yt, numOfBn); // Entry data of patient

    for (int i = 0; i < numOfBn; i++) { // Note: chuyển ra hàm
        if (infor_yt[i].tienTiemChung == 1) {
            printf("\nThong tin lich su tiem chung cua benh nhan %d :\n", i + 1);
            printf(" So luong vaccine da tiem: ");
            scanf("%d", &numOfVaccine[i]); // Số lượng vaccine của object i+1
            clear();
            for (int j = 0; j < numOfVaccine[i]; j++) {
                int temp = 0;
                printf("\n Vaccine thu %d\n", j + 1);
                printf("  Ten vaccine la: ");
                fgets(lichSuTiemChung[j].nameOfVaccine, 99, stdin);
                strtok(lichSuTiemChung[j].nameOfVaccine, "\n");

                do {
                    printf("  Thoi gian tiem (dd/mm/yyyy): ");
                    scanf("%d/%d/%d", &lichSuTiemChung[j].dayT, &lichSuTiemChung[j].monthT, &lichSuTiemChung[j].yearT);
                    clear();
                    if (lichSuTiemChung[j].dayT <= 0 || lichSuTiemChung[j].dayT > 31 || lichSuTiemChung[j].monthT <= 0 || lichSuTiemChung[j].monthT > 12 || lichSuTiemChung[j].yearT > 2024 || lichSuTiemChung[j].yearT < infor_cn[i].year) {
                        printf("khong hop le, nhap lai ngay thang nam!! \n");
                    } else {
                        temp = 1;
                    }
                } while (temp == 0);

                printf("  Dia diem tiem: ");
                fgets(lichSuTiemChung[j].DDT, 99, stdin);
                strtok(lichSuTiemChung[j].DDT, "\n");
            }
        } else {
            printf("Benh nhan %d khong co lich su tiem chung !", i + 1);
        }
    }

    dtLichTiemChung(infor_ltc, numOfBn); // Entry data of lich tiem chung 

    // Giải phóng bộ nhớ đã cấp phát
    free(infor_cn);
    free(infor_yt);
    free(infor_ltc);

    return 0;
}

/* Định nghĩa các hàm đã khai báo */

// Định nghĩa hàm nhập thông tin cá nhân và thông tin y tế
void dtCaNhan(caNhan* infor_cn, yTe* infor_yt, int numOfBn) {
    for (int i = 0; i < numOfBn; i++) {
        int temp = 0;
        printf("Benh nhan %d\n", i + 1);

        printf(" Tai khoan: ");
        fgets(infor_cn[i].tk, 99, stdin);
        strtok(infor_cn[i].tk, "\n"); // Loại bỏ ký tự xuống dòng

        printf(" Mat khau: ");
        fgets(infor_cn[i].mk, 99, stdin);
        strtok(infor_cn[i].mk, "\n"); // Loại bỏ ký tự xuống dòng

        printf(" Ten benh nhan: ");
        fgets(infor_cn[i].name, 99, stdin);
        strtok(infor_cn[i].name, "\n"); // Loại bỏ ký tự xuống dòng

        do {
            printf(" Ngay thang nam sinh (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &infor_cn[i].day, &infor_cn[i].month, &infor_cn[i].year);
            clear(); // Xóa bộ đệm sau khi nhập ngày tháng năm sinh
            if (infor_cn[i].day <= 0 || infor_cn[i].day > 31 || infor_cn[i].month <= 0 || infor_cn[i].month > 12 || infor_cn[i].year > 2024) {
                printf("khong hop le, nhap lai ngay thang nam!! \n");
            } else {
                temp = 1;
            }
        } while (temp == 0);

        printf(" Gioi tinh: ");
        fgets(infor_cn[i].sex, 99, stdin);
        strtok(infor_cn[i].sex, "\n"); // Loại bỏ ký tự xuống dòng

        printf(" Dia chi thuong chu: ");
        fgets(infor_cn[i].address, 99, stdin);
        strtok(infor_cn[i].address, "\n"); // Loại bỏ ký tự xuống dòng

        infor_cn[i].ID = tangDem();

        printf(" So dien thoai ca nhan: ");
        fgets(infor_cn[i].numPhone, 99, stdin);
        strtok(infor_cn[i].numPhone, "\n"); // Loại bỏ ký tự xuống dòng

        printf(" Tien su benh ly: ");
        fgets(infor_yt[i].tienBenhLy, 99, stdin);
        strtok(infor_yt[i].tienBenhLy, "\n"); // Loại bỏ ký tự xuống dòng

        printf(" Tien su tiem chung \n Neu co, nhan phim (1) \n Neu khong, nhan phim (2)\n Lua chon: ");
        scanf("%d", &infor_yt[i].tienTiemChung);
        clear();
    }
}

// Định nghĩa hàm nhập thông tin lịch sử tiêm chủng
void dtLichSuTiemChung(LichSuTiemChung* lichSuTiemChung, int* numOfVaccine, int numOfBn) {
    for (int i = 0; i < numOfBn; i++) {
        if (numOfVaccine[i] > 0) {
            for (int j = 0; j < numOfVaccine[i]; j++) {
                printf("\n Vaccine thu %d\n", j + 1);
                printf("  Ten vaccine la: ");
                fgets(lichSuTiemChung[j].nameOfVaccine, 99, stdin);
                strtok(lichSuTiemChung[j].nameOfVaccine, "\n");

                printf("  Thoi gian tiem (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &lichSuTiemChung[j].dayT, &lichSuTiemChung[j].monthT, &lichSuTiemChung[j].yearT);
                clear();

                printf("  Dia diem tiem: ");
                fgets(lichSuTiemChung[j].DDT, 99, stdin);
                strtok(lichSuTiemChung[j].DDT, "\n");
            }
        } else {
            printf("Benh nhan %d khong co lich su tiem chung !\n", i + 1);
        }
    }
}

// Định nghĩa hàm nhập thông tin lịch tiêm chủng
void dtLichTiemChung(lichTiemChung* infor_ltc, int numOfBn) {
    for (int i = 0; i < numOfBn; i++) {
        printf("\nLen lich tiem chung cho benh nhan %d:\n", i + 1);
        printf(" Lich tiem chung du kien: ");
        fgets(infor_ltc[i].duKien, 999, stdin);
        strtok(infor_ltc[i].duKien, "\n");

        printf(" Nhung dieu can luu y: ");
        fgets(infor_ltc[i].nhacNho, 999, stdin);
        strtok(infor_ltc[i].nhacNho, "\n");
    }
}
