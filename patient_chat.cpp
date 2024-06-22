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
    char nameOfVaccine[100]; // Danh sách các loại vắc xin đã tiêm
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

// khai báo hàm nhập data thông tin cá nhân và thông tin y tế 
void dtCaNhan(caNhan* , yTe* , int);  


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
    LichSuTiemChung lichSuTiemChung[100]; //   khai báo 1 mang struct ( khong han )
    int numOfVaccine[1000];   // so luong vaccine cua 1 object
    printf("Nhap so luong benh nhan: ");
    scanf("%d",&numOfBn);
    clear(); // Xóa bộ đệm sau khi nhập số lượng bệnh nhân

    caNhan* infor_cn;  // khai co con tro kieu caNhan
    infor_cn =(caNhan*)malloc(numOfBn*sizeof(caNhan)); // cấp phát động thông tin cá nhân

    yTe* infor_yt;  // khai bao con tro kieu yTe
    infor_yt =(yTe*)malloc(numOfBn*sizeof(yTe)); // cấp phát động thông tin y tế
    


    // funcion thuc thi nhiem vu
    dtCaNhan(infor_cn,infor_yt,numOfBn);  // entry data of patient
    for(int i=0; i<numOfBn; i++)  // note: chuyển ra hàm
    {
        if(infor_yt[i].tienTiemChung==1)
        {
            printf("\nThong tin lich su tiem chung cua benh nhan %d :\n",i+1);
            printf(" So luong vaccine da tiem: ");
            scanf("%d",&numOfVaccine[i]);  // so luong vaccine cua object i+1
            clear();
            for(int j=0; j<numOfVaccine[i] ; j++)
            {
                printf("\n Vaccien thu %d\n",j+1);
                printf("  Ten vaccine la: ");
                fgets(lichSuTiemChung[j].nameOfVaccine,99,stdin);
                strtok(lichSuTiemChung[j].nameOfVaccine, "\n");

                printf("  Thoi gian tiem (dd/mm/yyyy): ");
                scanf("%d/%d/%d",&lichSuTiemChung[j].dayT,&lichSuTiemChung[j].monthT,&lichSuTiemChung[j].yearT);
                clear();
                printf("  Dia diem tiem: ");
                fgets(lichSuTiemChung[j].DDT,99,stdin);
                strtok(lichSuTiemChung[j].DDT,"\n");
            }
            printf("*************************\nKiem tra thong tin vaccine\n");
            // this is an option
            // for(int j=0; j<numOfVaccine[i] ; j++)  // display
            // {
            //     printf("\n Vaccien thu %d\n",j+1);
            //     printf("  Ten vaccine la: %s",lichSuTiemChung[j].nameOfVaccine);
            //     printf("\n  Thoi gian tiem: %d/%d/%d",lichSuTiemChung[j].dayT,lichSuTiemChung[j].monthT,lichSuTiemChung[j].yearT);
            //     printf("\n  Dia diem tiem: %s",lichSuTiemChung[j].DDT);
        
            // }
        }
        else    printf("Benh nhan %d khong co lich su tiem chung !",i+1);
    }


    free(infor_cn);
    free(infor_yt);
    return 0;
}

/* dinh nghia ca ham da khai bao */

// dinh nghia data nhap thong tin ca nhan
void dtCaNhan(caNhan* infor_cn, yTe*infor_yt , int numOfBn)
{
    for(int i=0; i < numOfBn; i++)
    {
        printf("Benh nhan %d", i + 1 );

        printf("\n Tai khoan: ");
        fgets(infor_cn[i].tk, 99, stdin);
        strtok(infor_cn[i].tk, "\n"); // Loại bỏ ký tự xuống dòng

        printf(" Mat khau: ");
        fgets(infor_cn[i].mk, 99, stdin);
        strtok(infor_cn[i].mk, "\n"); // Loại bỏ ký tự xuống dòng
        
        printf(" Ten benh nhan: ");
        fgets(infor_cn[i].name, 99, stdin);
        strtok(infor_cn[i].name, "\n"); // Loại bỏ ký tự xuống dòng
        
        printf(" Ngay thang nam sinh (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &infor_cn[i].day, &infor_cn[i].month, &infor_cn[i].year);
        clear(); // Xóa bộ đệm sau khi nhập ngày tháng năm sinh
        
        
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
        fgets(infor_yt[i].tienBenhLy,99,stdin);
        strtok(infor_yt[i].tienBenhLy, "\n"); // Loại bỏ ký tự xuống dòng
        
        printf(" Tien su tiem chung \n Neu co, nhan phim (1) \n Neu khong, nhan phim (2)\n Lua chon: ");
        scanf("%d",&infor_yt[i].tienTiemChung);
        clear();
    }
}
