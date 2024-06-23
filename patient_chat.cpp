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
    char duKien[1000]; // Lịch tiêm chủng dự kiến
    char nhacNho[1000]; // Nhắc nhở về các mũi tiêm sắp đến hạn
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

// khai báo hàm nhập data lịch tiêm chủng
void dtLichTiemChung(lichTiemChung* , int); 

// display funcions:

// hien thi thong tin ca nhan
void displayCaNhan(caNhan*,yTe*,LichSuTiemChung*,lichTiemChung* ,int,int*);  // use  this funcion to display all information

// // hien thi thong tin y te
// void displayYTe(yTe*,int);

// // hien thi lich su tiem chung cua benh nhan ( neu co )
// void displayLinhSuTiemChung(LichSuTiemChung , int);

// // hien thi lich tiem chung cua benh nhan ( neu co )
// void displayLichTiemChung(lichTiemChung* , int);
// // if_patient funcion: this funcion use in main code (if_patient,if_staff)
// void if_bn();  // now, i dont know what i need to add in this funcion

int main()
{
    // khai bao va cap phat
    int numOfBn; // so luong of patient
    LichSuTiemChung lichSuTiemChung[100]; //   khai báo 1 mang struct ( khong han )
    int numOfVaccine[1000];   // so luong vaccine cua 1 object
    caNhan* infor_cn;  // khai co con tro kieu caNhan
    yTe* infor_yt;  // khai bao con tro kieu yTe
    lichTiemChung* infor_ltc;


    printf("Nhap so luong benh nhan: ");
    scanf("%d",&numOfBn);
    clear(); // Xóa bộ đệm sau khi nhập số lượng bệnh nhân

    
    infor_cn =(caNhan*)malloc(numOfBn*sizeof(caNhan)); // cấp phát động thông tin cá nhân
    infor_yt =(yTe*)malloc(numOfBn*sizeof(yTe)); // cấp phát động thông tin y tế
    infor_ltc =(lichTiemChung*)malloc(numOfBn*sizeof(lichTiemChung)); // cấp phát động thông tin lịch tiêm
    


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
                int temp=0;
                printf("\n Vaccien thu %d\n",j+1);
                printf("  Ten vaccine la: ");
                fgets(lichSuTiemChung[j].nameOfVaccine,99,stdin);
                strtok(lichSuTiemChung[j].nameOfVaccine, "\n");

                do{		
		            printf("  Thoi gian tiem (dd/mm/yyyy): ");
                    scanf("%d/%d/%d",&lichSuTiemChung[j].dayT,&lichSuTiemChung[j].monthT,&lichSuTiemChung[j].yearT);
                    clear();
	            	if( 0>=lichSuTiemChung[j].dayT || 31<lichSuTiemChung[j].dayT || lichSuTiemChung[j].monthT<=0 || lichSuTiemChung[j].monthT >12 || lichSuTiemChung[j].yearT > 2024 || lichSuTiemChung[j].yearT < infor_cn[i].year)
		            {
			            printf("khong hop le, nhap lai ngay thang nam!! \n");
		            }
		            else temp =1;
		
	            }while(temp==0);

                
                printf("  Dia diem tiem: ");
                fgets(lichSuTiemChung[j].DDT,99,stdin);
                strtok(lichSuTiemChung[j].DDT,"\n");
            }
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

    dtLichTiemChung(infor_ltc,numOfBn);   // entry data of lich tiem chung 

    printf("\nHien thi thong tin da nhap cua cac benh nhan");
    displayCaNhan(infor_cn,infor_yt,lichSuTiemChung,infor_ltc,numOfBn,numOfVaccine);


    free(infor_cn);
    free(infor_yt);
    free(infor_ltc);
    return 0;
}

/* dinh nghia ca ham da khai bao */

// dinh nghia data nhap thong tin ca nhan
void dtCaNhan(caNhan* infor_cn, yTe*infor_yt , int numOfBn)
{
    for(int i=0; i < numOfBn; i++)
    {
        int temp=0;
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
        
        do{  // check infor 
		
		    printf(" Ngay thang nam sinh (dd/mm/yyyy): ");
		    scanf("%d/%d/%d", &infor_cn[i].day, &infor_cn[i].month, &infor_cn[i].year);
            clear(); // Xóa bộ đệm sau khi nhập ngày tháng năm sinh
		    if( 0>=infor_cn[i].day || 31<infor_cn[i].day || infor_cn[i].month<=0 || infor_cn[i].month >12 || infor_cn[i].year > 2024 )
		    {
			    printf("khong hop le, nhap lai ngay thang nam!! \n");
		    }
		    else temp =1;
		
	    }while(temp==0);
        
        
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


// nhap thong tin cho lich tiem chung
void dtLichTiemChung(lichTiemChung* infor_ltc, int numOfBn)
{
    for(int i =0 ; i< numOfBn ; i++)
    {
        printf("\nLen lich tiem chung cho benh nhan %d:\n",i+1);
        printf(" Lich tiem chung du kien: ");
        fgets(infor_ltc[i].duKien,999,stdin);
        strtok(infor_ltc[i].duKien, "\n");

        printf(" Nhung dieu can luu y: ");
        fgets(infor_ltc[i].nhacNho,999,stdin);
        strtok(infor_ltc[i].duKien, "\n");
    }
}

void displayCaNhan(caNhan* infor_cn,yTe* infor_yt,LichSuTiemChung* lichSuTiemChung,lichTiemChung* infor_ltc ,int numOfBn,int* numOfVaccine)
{
    for (int i = 0; i < numOfBn; i++) {
        printf("\nThong tin benh nhan %d:\n", i + 1);
        printf("Tai khoan: %s\n", infor_cn[i].tk);
        printf("Mat khau: %s\n", infor_cn[i].mk);
        printf("Ho va ten: %s\n", infor_cn[i].name);
        printf("Ngay sinh: %d/%d/%d\n", infor_cn[i].day, infor_cn[i].month, infor_cn[i].year);
        printf("Gioi tinh: %s\n", infor_cn[i].sex);
        printf("Dia chi: %s\n", infor_cn[i].address);
        printf("So dien thoai: %s\n", infor_cn[i].numPhone);
        printf("Tien su benh ly: %s\n", infor_yt[i].tienBenhLy);

        if (infor_yt[i].tienTiemChung == 1) {
            printf("Lich su tiem chung:\n");
            for (int j = 0; j < numOfVaccine[i]; j++) {
                printf("  Vaccine thu %d:\n", j + 1);
                printf("    Ten vaccine: %s\n", lichSuTiemChung[j].nameOfVaccine);
                printf("    Thoi gian tiem: %d/%d/%d\n", lichSuTiemChung[j].dayT, lichSuTiemChung[j].monthT, lichSuTiemChung[j].yearT);
                printf("    Dia diem tiem: %s\n", lichSuTiemChung[j].DDT);
            }
        } else {
            printf("Khong co lich su tiem chung.\n");
        }

        printf("Lich tiem chung du kien: %s\n", infor_ltc[i].duKien);
        printf("Nhac nho tiem chung: %s\n", infor_ltc[i].nhacNho);
    }for (int i = 0; i < numOfBn; i++) {
        printf("\nThong tin benh nhan %d:\n", i + 1);
        printf("Tai khoan: %s\n", infor_cn[i].tk);
        printf("Mat khau: %s\n", infor_cn[i].mk);
        printf("Ho va ten: %s\n", infor_cn[i].name);
        printf("Ngay sinh: %d/%d/%d\n", infor_cn[i].day, infor_cn[i].month, infor_cn[i].year);
        printf("Gioi tinh: %s\n", infor_cn[i].sex);
        printf("Dia chi: %s\n", infor_cn[i].address);
        printf("So dien thoai: %s\n", infor_cn[i].numPhone);
        printf("Tien su benh ly: %s\n", infor_yt[i].tienBenhLy);

        if (infor_yt[i].tienTiemChung == 1) {
            printf("Lich su tiem chung:\n");
            for (int j = 0; j < numOfVaccine[i]; j++) {
                printf("  Vaccine thu %d:\n", j + 1);
                printf("    Ten vaccine: %s\n", lichSuTiemChung[j].nameOfVaccine);
                printf("    Thoi gian tiem: %d/%d/%d\n", lichSuTiemChung[j].dayT, lichSuTiemChung[j].monthT, lichSuTiemChung[j].yearT);
                printf("    Dia diem tiem: %s\n", lichSuTiemChung[j].DDT);
            }
        } else {
            printf("Khong co lich su tiem chung.\n");
        }

        printf("Lich tiem chung du kien: %s\n", infor_ltc[i].duKien);
        printf("Nhac nho tiem chung: %s\n", infor_ltc[i].nhacNho);
    }
}