/**
 * @file patient.cpp
 * @author vu hoang hiep (hiep.vh234005@sis.hust.edu.vn)
 * @brief informations of patient
 * @version 0.1
 * @date 2024-06-18
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
// code for test logic

char clearr[100];


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

    caNhan* infor_cn;  // khai co con tro kieu caNhan
    infor_cn =(caNhan*)malloc(numOfBn*sizeof(caNhan)); // cấp phát động thông tin cá nhân


    // funcion thuc thi nhiem vu
    dtCaNhan(infor_cn,numOfBn);  // entry data of patient
    free(infor_cn);
    return 0;
}

/* dinh nghia ca ham da khai bao */

// dinh nghia data thong tin ca nhan
void dtCaNhan(caNhan* infor, int numOfBn)
{
    for(int i=0; i < numOfBn; i++)
    {
        printf("Tai khoan ca nhan\n");
        fgets(clearr,99,stdin);
        printf("Tai khoan: ");
        // clear();
        fgets(infor[i].tk,99,stdin);
        printf("Mat khau: ");
        fgets(infor[i].mk,99,stdin);
        
        printf("Ten benh nhan: ");
        fgets(infor[i].name,99,stdin);
        
        printf("Ngay thang nam sinh (dd/mm/yyyy): ");
        scanf("%d/%d/%d",&infor[i].day,&infor[i].month,&infor[i].year);
        clear();
        
        printf("Gioi tinh: ");
        fgets(infor[i].sex,99,stdin);
        
        printf("Dia chi thuong chu: ");
        fgets(infor[i].address,99,stdin);
        
        infor[i].ID=tangDem();
        
        printf("So dien thoai ca nhan: ");
        fgets(infor[i].numPhone,99,stdin);
    }
}