/**
 * @file patient_chat.cpp
 * @brief Patient chat program
 * @version 0.1
 * @date 2024-06-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Hồ sơ cá nhân:
class CaNhan {
public:
    string tk;
    string mk;
    int ID;
    string name; // Họ và tên
    int day, month, year; // Ngày tháng năm sinh
    string sex; // Giới tính
    string address; // Địa chỉ
    string numPhone; // Số điện thoại
};

// Thông tin y tế:
class YTe {
public:
    string tienBenhLy; // Tiền sử bệnh lý
    int tienTiemChung; // Tiền sử tiêm chủng (các loại vắc xin đã tiêm)
};

// Lịch sử tiêm chủng:
class LichSuTiemChung {
public:
    string nameOfVaccine; // Danh sách các loại vắc xin đã tiêm
    int dayT, monthT, yearT; // Ngày tiêm
    string DDT; // Địa điểm tiêm
};

// Lịch tiêm chủng:
class LichTiemChung {
public:
    string duKien; // Lịch tiêm chủng dự kiến
    string nhacNho; // Nhắc nhở về các mũi tiêm sắp đến hạn
};

// Xóa bộ nhớ đệm đầu vào
void clear() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Biến toàn cục
int dem = 0;

int tangDem()  // đếm gần cho phần ID với mỗi bệnh nhân được nhập, id được gán tăng 1
{
    return ++dem;
}

void reset()    // reset đếm về 0
{
    dem = 0;
}

// Khai báo hàm nhập data thông tin cá nhân và thông tin y tế 
void dtCaNhan(vector<CaNhan>&, vector<YTe>&, int);  

// Khai báo hàm nhập data lịch tiêm chủng
void dtLichTiemChung(vector<LichTiemChung>&, int); 

// Display functions:

// Hiển thị thông tin cá nhân
void displayCaNhan(const vector<CaNhan>&, const vector<YTe>&, const vector<vector<LichSuTiemChung>>&, const vector<LichTiemChung>&, int, const vector<int>&);  // Use this function to display all information

int main() {
    // Khai báo và cấp phát
    int numOfBn; // số lượng bệnh nhân
    vector<vector<LichSuTiemChung>> lichSuTiemChung(100); // khai báo một mảng vector struct (không hạn)
    vector<int> numOfVaccine; // số lượng vaccine của một object
    vector<CaNhan> infor_cn; // khai báo vector kiểu CaNhan
    vector<YTe> infor_yt; // khai báo vector kiểu YTe
    vector<LichTiemChung> infor_ltc; // khai báo vector kiểu LichTiemChung

    cout << "Nhap so luong benh nhan: ";
    cin >> numOfBn;
    clear(); // Xóa bộ đệm sau khi nhập số lượng bệnh nhân

    infor_cn.resize(numOfBn); // Cấp phát động thông tin cá nhân
    infor_yt.resize(numOfBn); // Cấp phát động thông tin y tế
    infor_ltc.resize(numOfBn); // Cấp phát động thông tin lịch tiêm
    numOfVaccine.resize(numOfBn);

    // Hàm thực thi nhiệm vụ
    dtCaNhan(infor_cn, infor_yt, numOfBn); // Entry data of patient

    for (int i = 0; i < numOfBn; i++) {
        if (infor_yt[i].tienTiemChung == 1) {
            cout << "\nThong tin lich su tiem chung cua benh nhan " << i + 1 << ":\n";
            cout << " So luong vaccine da tiem: ";
            cin >> numOfVaccine[i]; // số lượng vaccine của object i
            clear();

            lichSuTiemChung[i].resize(numOfVaccine[i]);
            for (int j = 0; j < numOfVaccine[i]; j++) {
                int temp = 0;
                cout << "\n Vaccine thu " << j + 1 << "\n";
                cout << "  Ten vaccine la: ";
                getline(cin, lichSuTiemChung[i][j].nameOfVaccine);

                do {
                    cout << "  Thoi gian tiem (dd/mm/yyyy): ";
                    cin >> lichSuTiemChung[i][j].dayT >> lichSuTiemChung[i][j].monthT >> lichSuTiemChung[i][j].yearT;
                    clear();
                    if (lichSuTiemChung[i][j].dayT <= 0 || lichSuTiemChung[i][j].dayT > 31 || lichSuTiemChung[i][j].monthT <= 0 || lichSuTiemChung[i][j].monthT > 12 || lichSuTiemChung[i][j].yearT > 2024 || lichSuTiemChung[i][j].yearT < infor_cn[i].year) {
                        cout << "khong hop le, nhap lai ngay thang nam!! \n";
                    } else {
                        temp = 1;
                    }
                } while (temp == 0);

                cout << "  Dia diem tiem: ";
                getline(cin, lichSuTiemChung[i][j].DDT);
            }
        } else {
            cout << "Benh nhan " << i + 1 << " khong co lich su tiem chung!\n";
        }
    }

    dtLichTiemChung(infor_ltc, numOfBn); // entry data of lich tiem chung

    cout << "\nHien thi thong tin da nhap cua cac benh nhan\n";
    displayCaNhan(infor_cn, infor_yt, lichSuTiemChung, infor_ltc, numOfBn, numOfVaccine);

    return 0;
}

/* Dinh nghia cac ham da khai bao */

// Dinh nghia data nhap thong tin ca nhan
void dtCaNhan(vector<CaNhan>& infor_cn, vector<YTe>& infor_yt, int numOfBn) {
    for (int i = 0; i < numOfBn; i++) {
        int temp = 0;
        cout << "Benh nhan " << i + 1 << "\n";

        cout << " Tai khoan: ";
        getline(cin, infor_cn[i].tk);

        cout << " Mat khau: ";
        getline(cin, infor_cn[i].mk);

        cout << " Ten benh nhan: ";
        getline(cin, infor_cn[i].name);

        do {  // Check infor
            cout << " Ngay thang nam sinh (dd/mm/yyyy): ";
            cin >> infor_cn[i].day >> infor_cn[i].month >> infor_cn[i].year;
            clear(); // Xóa bộ đệm sau khi nhập ngày tháng năm sinh
            if (infor_cn[i].day <= 0 || infor_cn[i].day > 31 || infor_cn[i].month <= 0 || infor_cn[i].month > 12 || infor_cn[i].year > 2024) {
                cout << "khong hop le, nhap lai ngay thang nam!! \n";
            } else {
                temp = 1;
            }
        } while (temp == 0);

        cout << " Gioi tinh: ";
        getline(cin, infor_cn[i].sex);

        cout << " Dia chi thuong chu: ";
        getline(cin, infor_cn[i].address);

        infor_cn[i].ID = tangDem();

        cout << " So dien thoai ca nhan: ";
        getline(cin, infor_cn[i].numPhone);

        cout << " Tien su benh ly: ";
        getline(cin, infor_yt[i].tienBenhLy);

        cout << " Tien su tiem chung \n Neu co, nhan phim (1) \n Neu khong, nhan phim (2)\n Lua chon: ";
        cin >> infor_yt[i].tienTiemChung;
        clear();
    }
}

// Nhap thong tin cho lich tiem chung
void dtLichTiemChung(vector<LichTiemChung>& infor_ltc, int numOfBn) {
    for (int i = 0; i < numOfBn; i++) {
        cout << "\nLen lich tiem chung cho benh nhan " << i + 1 << ":\n";
        cout << " Lich tiem chung du kien: ";
        getline(cin, infor_ltc[i].duKien);

        cout << " Nhung dieu can luu y: ";
        getline(cin, infor_ltc[i].nhacNho);
    }
}

// Hien thi thong tin ca nhan
void displayCaNhan(const vector<CaNhan>& infor_cn, const vector<YTe>& infor_yt, const vector<vector<LichSuTiemChung>>& lichSuTiemChung, const vector<LichTiemChung>& infor_ltc, int numOfBn, const vector<int>& numOfVaccine) {
    for (int i = 0; i < numOfBn; i++) {
        cout << "\nBenh nhan " << i + 1 << ":\n";
        cout << " Tai khoan: " << infor_cn[i].tk << "\n";
        cout << " Mat khau: " << infor_cn[i].mk << "\n";
        cout << " Ho va ten: " << infor_cn[i].name << "\n";
        cout << " Ngay thang nam sinh: " << infor_cn[i].day << "/" << infor_cn[i].month << "/" << infor_cn[i].year << "\n";
        cout << " Gioi tinh: " << infor_cn[i].sex << "\n";
        cout << " Dia chi thuong chu: " << infor_cn[i].address << "\n";
        cout << " So dien thoai ca nhan: " << infor_cn[i].numPhone << "\n";
        cout << " Tien su benh ly: " << infor_yt[i].tienBenhLy << "\n";

        if (infor_yt[i].tienTiemChung == 1) {
            for (int j = 0; j < numOfVaccine[i]; j++) {
                cout << "  Tiem chung thu " << j + 1 << "\n";
                cout << "   Ten vaccine: " << lichSuTiemChung[i][j].nameOfVaccine << "\n";
                cout << "   Ngay tiem: " << lichSuTiemChung[i][j].dayT << "/" << lichSuTiemChung[i][j].monthT << "/" << lichSuTiemChung[i][j].yearT << "\n";
                cout << "   Dia diem tiem: " << lichSuTiemChung[i][j].DDT << "\n";
            }
        } else {
            cout << " Khong co lich su tiem chung.\n";
        }

        cout << " Lich tiem chung du kien: " << infor_ltc[i].duKien << "\n";
        cout << " Nhung dieu can luu y: " << infor_ltc[i].nhacNho << "\n";
    }
}
