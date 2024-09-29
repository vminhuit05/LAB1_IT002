#include <bits/stdc++.h>
using namespace std;

struct phan_so {
    int tu, mau;

    // Ham khoi tao nhap tu va mau
    void init() {
        cout << "Nhap tu: ";
        cin >> this->tu;

        cout << "Nhap mau: ";
        cin >> this->mau;

        // Kiem tra mau co bang 0 khong
        if (this->mau == 0) {
            cout << "Nhap loi: Mau so khong the bang 0.\n";
            exit(0);
        }
    }

    // Ham xuat phan so
    void xuat() {
        cout << this->tu << '/' << this->mau << '\n';
    }

    // Ham so sanh phan so
    bool max_(phan_so b) {
        if (this->tu == -1e9) return true; // Neu phan so bi cho bang -1e9
        bool flag = ((this->mau < 0) ^ (b.mau < 0)); // Kiem tra mau
        if (flag) {
            return this->tu * b.mau > this->mau * b.tu; // So sanh phan so co mau khac dau
        } else {
            return this->tu * b.mau < this->mau * b.tu; // So sanh phan so co mau cung dau
        }
    }
};

int main() {
    phan_so a, b;

    cout << "Phan so 1\n";
    a.init(); // Nhap phan so 1

    cout << "Phan so 2\n";
    b.init(); // Nhap phan so 2

    cout << "Phan so lon nhat la: \n";
    if (a.max_(b)) {
        cout << b.tu << '/' << b.mau << '\n'; // Xuat phan so b
    } else {
        cout << a.tu << '/' << a.mau << '\n'; // Xuat phan so a
    }
}