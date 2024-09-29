#include <bits/stdc++.h>
using namespace std;

// Cau truc dai dien cho mot ngay
struct info {
    int ngay;  // Ngay trong thang
    int thang; // Thang trong nam
    int nam;   // Nam
};

// Ham kiem tra nam nhuan
bool nhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

// Ham tra ve so ngay cua mot thang trong mot nam
int calc(int thang, int nam) {
    int soNgay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (thang == 2 && nhuan(nam)) {
        return 29; // Thang 2 nam nhuan co 29 ngay
    }
    return soNgay[thang];
}

// Ham tim ngay tiep theo
info ngayTiepTheo(info cur) {
    info now = cur;
    now.ngay++;
    if (now.ngay > calc(now.thang, now.nam)) {
        now.ngay = 1;
        now.thang++;
        if (now.thang > 12) {
            now.thang = 1;
            now.nam++;
        }
    }
    return now;
}

// Ham tim ngay truoc do
info ngayTruocDo(info cur) {
    info now = cur;
    now.ngay--;
    if (now.ngay == 0) {
        now.thang--;
        if (now.thang == 0) {
            now.thang = 12;
            now.nam--;
        }
        now.ngay = calc(now.thang, now.nam);
    }
    return now;
}

// Ham tinh so thu tu cua ngay trong nam
int dem(info ngay) {
    int soThuTu = ngay.ngay;
    for (int i = 1; i < ngay.thang; i++) {
        soThuTu += calc(i, ngay.nam);
    }
    return soThuTu;
}

int main() {
    info ngay;
    cout << "Nhap ngay, thang, nam: ";
    cin >> ngay.ngay >> ngay.thang >> ngay.nam;

    info ngaySau = ngayTiepTheo(ngay);
    info ngayTruoc = ngayTruocDo(ngay);
    int so = dem(ngay);

    cout << "Ngay tiep theo: " << ngaySau.ngay << "/" << ngaySau.thang << "/" << ngaySau.nam << endl;
    cout << "Ngay truoc do: " << ngayTruoc.ngay << "/" << ngayTruoc.thang << "/" << ngayTruoc.nam << endl;
    cout << "So thu tu cua ngay trong nam: " << so << endl;

    return 0;
}