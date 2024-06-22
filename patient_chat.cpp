/**
 * @file patient_chat.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Hồ sơ cá nhân:
typedef struct 
{
    char tk[100];
    char mk[100];
    int ID;
    char name[100]; // Họ và tên
    int day,month,year; // Ngày tháng năm sinh
    char sex[100]; // Giới tính
    char address[100]; // Địa chỉ
    char numPhone[100]; // Số điện thoại
}caNhan;

// Thông tin y tế:
typedef struct  
{
    char tienBenhLy[100]; // Tiền sử bệnh lý
    int tienTiemChung; // Tiền sử tiêm chủng (các loại vắc xin đã tiêm)
}yTe;

// Lịch sử tiêm chủng:
typedef struct   
{
    char nameOfVeccine[100]; // Danh sách các loại vắc xin đã tiêm
    int dayT,monthT,yearT; // Ngày tiêm
    char DDT[100]; // Địa điểm tiêm
}LichSuTiemChung;

// Lịch tiêm chủng:
typedef struct   
{
    char duKien[100]; // Lịch tiêm chủng dự kiến
    char nhacNho[100]; // Nhắc nhở về các mũi tiêm sắp đến hạn
}lichTiemChung;

// xoa bo nho dem dau vao scanf
void clear() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// bien toan cuc
int dem=0;
int tangDem()  // dem gan cho phan ID voi moi benh nhan duoc nhap, id duoc gan tang 1
{
    ++dem;
    return dem;
}
int reset()    // reset dem ve 0
{
    dem=0;
    return dem;
}

// khai báo hàm nhập data thông tin cá nhân
void dtCaNhan(caNhan* , int);  

// khai báo hàm nhập data thông tin y tế
void dtYTe(yTe* , int); 

// khai báo hàm nhập data lịch sử tiêm chủng
void dtLichSuTiemChung(LichSuTiemChung  , int);  

// khai báo hàm nhập data lịch tiêm chủng
void dtLichTiemChung(lichTiemChung* , int); 

// display funcions:

// hien thi thong tin ca nhan
void displayCaNhan(caNhan*,int);

// hien thi thong tin y te
void displayYTe(yTe*,int);

// hien thi lich su tiem chung cua benh nhan ( neu co )
void displayLinhSuTiemChung(LichSuTiemChung , int);

// hien thi lich tiem chung cua benh nhan ( neu co )
void displayLichTiemChung(lichTiemChung* , int);
// if_patient funcion: this funcion use in main code (if_patient,if_staff)
void if_bn();  // now, i dont know what i need to add in this funcion

int main()
{
    // khai bao va cap phat
    int numOfBn; // so luong of patient
    printf("Nhap so luong benh nhan: ");
    scanf("%d",&numOfBn);
    clear(); // Xóa bộ đệm sau khi nhập số lượng bệnh nhân

    caNhan* infor_cn;  // khai co con tro kieu caNhan
    infor_cn =(caNhan*)malloc(numOfBn*sizeof(caNhan)); // cấp phát động thông tin cá nhân

    yTe* infor_yt;  // khai bao con tro kieu yTe
    infor_yt =(yTe*)malloc(numOfBn*sizeof(yTe)); // cấp phát động thông tin y tế
    


    // funcion thuc thi nhiem vu
    dtCaNhan(infor_cn,numOfBn);  // entry data of patient
    dtYTe(infor_yt,numOfBn); // entry data of patient

    free(infor_cn);
    free(infor_yt);
    return 0;
}

/* dinh nghia ca ham da khai bao */

// dinh nghia data nhap thong tin ca nhan
void dtCaNhan(caNhan* infor, int numOfBn)
{
    for(int i=0; i < numOfBn; i++)
    {
        printf("Benh nhan %d", i + 1 );

        printf("\n Tai khoan: ");
        fgets(infor[i].tk, 99, stdin);
        strtok(infor[i].tk, "\n"); // Loại bỏ ký tự xuống dòng

        printf(" Mat khau: ");
        fgets(infor[i].mk, 99, stdin);
        strtok(infor[i].mk, "\n"); // Loại bỏ ký tự xuống dòng
        
        printf(" Ten benh nhan: ");
        fgets(infor[i].name, 99, stdin);
        strtok(infor[i].name, "\n"); // Loại bỏ ký tự xuống dòng
        
        printf(" Ngay thang nam sinh (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &infor[i].day, &infor[i].month, &infor[i].year);
        clear(); // Xóa bộ đệm sau khi nhập ngày tháng năm sinh
        
        printf(" Gioi tinh: ");
        fgets(infor[i].sex, 99, stdin);
        strtok(infor[i].sex, "\n"); // Loại bỏ ký tự xuống dòng
        
        printf(" Dia chi thuong chu: ");
        fgets(infor[i].address, 99, stdin);
        strtok(infor[i].address, "\n"); // Loại bỏ ký tự xuống dòng
        
        infor[i].ID = tangDem();
        
        printf(" So dien thoai ca nhan: ");
        fgets(infor[i].numPhone, 99, stdin);
        strtok(infor[i].numPhone, "\n"); // Loại bỏ ký tự xuống dòng
    }
}

// dinh nghia data nhap thong tin y te
void dtYTe(yTe*infor, int numOfBn)
{
    for(int i=0; i<numOfBn; i++)
    {   
        printf("Thong tin y te benh nhan %d", i+1 );
        clear();

        printf(" Tien su benh ly:");
        fgets(infor[i].tienBenhLy,99,stdin);
        
        printf(" Tien su tiem chung \n Neu co, nhan phim (1) \n Neu khong, nhan phim (2)\n Lua chon: ");
        scanf("%d",&infor[i].tienTiemChung);
        clear();
    }
}
