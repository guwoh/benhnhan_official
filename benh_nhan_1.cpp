/**
 * @file benh_nhan_1.cpp
 * @author guwoh (hiep.vh234005@sis.hust.edu.vn)
 * @brief Hệ thống cho bệnh nhân
 * @version 0.1
 * @date 2024-06-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct // Hồ sơ cá nhân:
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
typedef struct  // Thông tin y tế:
{
    char tienBenhLy[100]; // Tiền sử bệnh lý
    int tienTiemChung; // Tiền sử tiêm chủng (các loại vắc xin đã tiêm)
}yTe;
typedef struct   // Lịch sử tiêm chủng:
{
    char nameOfVeccine[100]; // Danh sách các loại vắc xin đã tiêm
    int dayT,monthT,yearT; // Ngày tiêm
    char DDT[100]; // Địa điểm tiêm
}LichSuTiemChung;
typedef struct   // Lịch tiêm chủng:
{
    char duKien[100]; // Lịch tiêm chủng dự kiến
    char nhacNho[100]; // Nhắc nhở về các mũi tiêm sắp đến hạn
}lichTiemChung;
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
// Hàm để xóa bộ đệm đầu vào
void clear() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// dinh nghia cam ham su dung trong code
// entry funcions:
void dtCaNhan(caNhan* , int);  // khai báo hàm nhập data thông tin cá nhân
void dtYTe(yTe* , int);  // khai báo hàm nhập data thông tin y tế
void dtLichSuTiemChung(LichSuTiemChung  , int);  // khai báo hàm nhập data lịch sử tiêm chủng
void dtLichTiemChung(lichTiemChung* , int);  // khai báo hàm nhập data lịch tiêm chủng
// display funcions:
void displayCaNhan(caNhan*,int);
void displayYTe(yTe*,int);
void displayLinhSuTiemChung(LichSuTiemChung , int);
void displayLichTiemChung(lichTiemChung* , int);
// if_patient funcion: this funcion use in main code (if_patient,if_staff)
void if_bn();
int main()
{
    int numOfBn;
    caNhan* infor_cn;
    yTe* infor_yt;
    LichSuTiemChung lichSuTiemChung[100]; //   khai báo 1 mang struct ( khong han )
    lichTiemChung* infor_ltc;
    int numOfVaccine[1000];   // so luong vaccine cua 1 object
    printf("Nhap so luong benh nhan:");
    scanf("%d",&numOfBn);    
    infor_cn =(caNhan*)malloc(numOfBn*sizeof(caNhan)); // cấp phát động thông tin cá nhân
    infor_yt =(yTe*)malloc(numOfBn*sizeof(yTe)); // cấp phát động thông tin cá nhân
    infor_ltc =(lichTiemChung*)malloc(numOfBn*sizeof(lichTiemChung)); // cấp phát động thông tin cá nhân
    
    dtCaNhan(infor_cn,numOfBn);  // entry data of patient
    displayCaNhan(infor_cn,numOfBn);  // dis play data of patent 
    dtYTe(infor_yt,numOfBn);
    for(int i=0; i<numOfBn; i++)
    for(int i=0; i<numOfBn; i++)  // note: chuyển ra hàm
    {
        if(infor_yt[i].tienTiemChung==1)
        {
            printf("\nThong tin lich su tiem chung cua benh nhan %d :\n",i+1);
            printf("So luong vaccine da tiem:");
            scanf("%d",&numOfVaccine[i]);  // so luong vaccine cua object i+1
            for(int j=0; j<numOfVaccine[i] ; j++)
            {
                clear();
                printf("\nVaccien thu %d\n",j+1);
                printf("Ten vaccine la: ");
                // clear();
                fgets(lichSuTiemChung[j].nameOfVeccine,99,stdin);
                printf("Thoi gian tiem (dd/mm/yyyy): ");
                scanf("%d/%d/%d",&lichSuTiemChung[j].dayT,&lichSuTiemChung[j].monthT,&lichSuTiemChung[j].yearT);
                clear();
                printf("Dia diem tiem: ");
                fgets(lichSuTiemChung[j].DDT,99,stdin);
            }
            printf("*************************\n Kiem tra thong tin vaccine\n");
            for(int j=0; j<numOfVaccine[i] ; j++)
            {
                printf("\nVaccien thu %d\n",j+1);
                printf("Ten vaccine la: %s",lichSuTiemChung[j].nameOfVeccine);
                printf("Thoi gian tiem: %d/%d/%d",lichSuTiemChung[j].dayT,lichSuTiemChung[j].monthT,lichSuTiemChung[j].yearT);
                printf("\nDia diem tiem: %s",lichSuTiemChung[j].DDT);
        
            }
        }
        else    printf("Benh nhan %d khong co lich su tiem chung !",i+1);
    }
    displayYTe(infor_yt,numOfBn);
    free(infor_cn);
    free(infor_yt);
    free(infor_ltc);
    return 0;
}
// entry and display data of struct caNhan
void dtCaNhan(caNhan* infor, int numOfBn)
{
    for(int i=0; i < numOfBn; i++)
    {
        printf("_____________________________________________\n_____________________________________________\n");
        printf("Nhap thong tin cho benh nhan thu %d \n\n*****************\n",i+1);
        printf("Tai khoan ca nhan:\n");
        clear();
        printf("Tai khoan:");
        // clear();
        fgets(infor[i].tk,99,stdin);
        printf("Mat khau:");
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
void displayCaNhan(caNhan*infor, int numOfBn)
{
    printf("_____________________________________________\n_____________________________________________\n");
    printf(" Check thong tin benh nhan!\n");
    for(int i=0; i < numOfBn; i++)
    {
        printf(" Thong tin cho benh nhan thu %d \n",i+1);
        printf(" Tai khoan: %s",infor[i].tk);
        printf(" Mat khau: %s",infor[i].mk);
        printf(" ID ca nhan: %d\n",infor[i].ID);
        printf(" Ten benh nhan: %s",infor[i].name);
        printf(" Ngay thang nam sinh (dd/mm/yyyy): %d/%d/%d\n",infor[i].day,infor[i].month,infor[i].year);
        printf(" Gioi tinh: %s",infor[i].sex);
        printf(" Dia chi thuong chu: %s",infor[i].address);
        printf(" So dien thoai ca nhan: %s",infor[i].numPhone);
    }
}
// entry and display data of struct yTe
void dtYTe(yTe*infor, int numOfBn)
{
    for(int i=0; i<numOfBn; i++)
    {   
        printf("_____________________________________________\n");
        printf("Nhap thong tin lien quan de y te benh nhan %d :\n",i+1);
        
        printf("Tien su benh ly:");
        fgets(infor[i].tienBenhLy,99,stdin);
        
        printf("Tien su tiem chung co(1)/khong(0): ");
        scanf("%d",&infor[i].tienTiemChung);
        clear();
    }
}
void displayYTe(yTe* infor, int numOfBn)
{
    printf("\n_____________________________________________\n");
    printf("Check thong tin y te benh nhan!");
    for(int i=0; i<numOfBn; i++)
    {   
        printf("\n Thong tin lien quan den y te %d:\n",i+1);
        printf(" Tien su benh ly: %s",infor[i].tienBenhLy);
        if(infor[i].tienTiemChung == 0 )    printf(" Benh nhan khong co tien su su dung vaccine");
        else    printf(" Benh nhan co tien su su dung vaccine");
    }
}
// entry and display data of struct lichSuTiemChung 
// maybe its good in main
// void dtLichSuTiemChung(LichSuTiemChung lichSuTiemChung[100], int numOfBn)
// {
    
// } 
// void displayLinhSuTiemChung(LichSuTiemChung infor, int numOfBn)
// {
// }
// entry and display data of struct lichTiemChugn

// hihi
//haha test