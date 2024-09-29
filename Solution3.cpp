#include <bits/stdc++.h>
using namespace std;

struct phan_so {
    int tu, mau;

    // Ham khoi tao nhap tu va mau
    void init() {
        cout << "Nhap tu: " << '\n';
        cin >> this->tu;

        cout << "Nhap mau: " << '\n';
        cin >> this->mau;

        // Kiem tra mau co bang 0 khong
        if (this->mau == 0) {
            cout << "Loi: Mau so khong the bang 0.\n";
            exit(0);
        }
    }

    // Ham rut gon phan so
    void rut_gon() {
        int g = __gcd(this->tu, this->mau);
        this->tu /= g;
        this->mau /= g;
    }

    // Ham xuat phan so
    void xuat() {
        cout << this->tu << '/' << this->mau << '\n';
    }

    // Ham cong hai phan so
    void sum(phan_so b) {
        phan_so c;
        c.tu = (this->tu * b.mau + b.tu * this->mau);
        c.mau = (this->mau * b.mau);
        c.rut_gon();
        cout << "Cong = ";
        c.xuat();
    }

    // Ham tru hai phan so
    void sub(phan_so b) {
        phan_so c;
        c.tu = (this->tu * b.mau - b.tu * this->mau);
        c.mau = (this->mau * b.mau);
        c.rut_gon();
        cout << "Tru = ";
        c.xuat();
    }

    // Ham nhan hai phan so
    void mul(phan_so b) {
        phan_so c;
        c.tu = (this->tu * b.tu);
        c.mau = (this->mau * b.mau);
        c.rut_gon();
        cout << "Nhan = ";
        c.xuat();
    }

    // Ham chia hai phan so
    void divide(phan_so b) {
        phan_so c;
        c.tu = (this->tu * b.mau);
        c.mau = (this->mau * b.tu);
        c.rut_gon();
        cout << "Chia = ";
        c.xuat();
    }
};

int main() {
    phan_so a, b;

    cout << "Phan so 1:\n";
    a.init();  // Nhap phan so 1
    a.rut_gon(); // Rut gon phan so 1

    cout << "Phan so 2:\n";
    b.init();  // Nhap phan so 2
    b.rut_gon(); // Rut gon phan so 2

    // Thuc hien cac phep toan
    a.sum(b);
    a.sub(b);
    a.mul(b);
    a.divide(b);

    return 0;
}