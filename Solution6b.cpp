#include <bits/stdc++.h>
using namespace std;

struct Info {
    string name; // Ten
    float math;  // Diem Toan
    float lit;   // Diem Van
    float eng;   // Diem Anh
    double tb;   // Diem Trung Binh

    // Kiem tra tinh hop le cua ten
    bool check(const string &fullName) {
        // Kiem tra do dai chuoi
        if (fullName.length() > 50) {
            return false;
        }

        bool newWord = true; // Bien de kiem tra vi tri cua chu cai dau tien

        for (char c : fullName) {
            if (isspace(c)) {
                if(newWord==true) return false; // tranh hai khoang trang lien tiep
                newWord = true; // Gap khoang trang thi danh dau bat dau tu moi
            } else {
                // Kiem tra ky tu khong phai chu cai
                if (!isalpha(c)) {
                    return false;
                }
                // Kiem tra chu cai dau tien cua tu
                if (newWord) {
                    if (!isupper(c)) {
                        return false; // Neu chu cai dau khong phai hoa
                    }
                    newWord = false; // Danh dau da khong con o vi tri dau tu
                }
                else{
                     if(!islower(c)) {
                        return false;
                     }
                }
            }
        }
        return true; // Neu tat ca dieu kien deu thoa man
    }

    // Kiem tra diem so co hop le khong
    bool check_score(float score) {
        return (0.0 <= score && score <= 10.0);
    }

    // Nhap thong tin sinh vien
    void init() {
        cout << "Nhap ten khong qua 50 ki tu, in hoa chu cai dau cua moi tu va chi chua ky tu alphabet tieng anh:\n";
        getline(cin, this->name);
        while (!check(this->name)) {
            cout << "Ten khong hop le. Vui long nhap lai:\n";
            getline(cin, this->name);
        }

        cout << "Diem toan: ";
        cin >> this->math;
        while (!check_score(this->math)) {
            cout << "Diem khong hop le. Vui long nhap lai:\n";
            cin >> this->math;
        }

        cout << "Diem van: ";
        cin >> this->lit;
        while (!check_score(this->lit)) {
            cout << "Diem khong hop le. Vui long nhap lai:\n";
            cin >> this->lit;
        }

        cout << "Diem anh: ";
        cin >> this->eng;
        while (!check_score(this->eng)) {
            cout << "Diem khong hop le. Vui long nhap lai:\n";
            cin >> this->eng;
        }
    }

    // Xep loai dua tren diem trung binh
    string xeploai(double score) {
        if (score >= 9.0) return "Xuat Sac";
        else if (score >= 8.0) return "Gioi";
        else if (score >= 6.5) return "Kha";
        else if (score >= 5.0) return "Trung Binh";
        else return "Yeu";
    }

    // Xuat thong tin sinh vien
    void xuat() {
        cout << this->name << ", " << this->math << ", " << this->lit << ", " << this->eng << '\n';
        this->tb = (this->math * 2.0 + this->lit + this->eng) / 4.0; // Tinh diem trung binh
        cout << "Diem trung binh: " << fixed << setprecision(3) << this->tb << '\n';
        cout << "Xep loai: " << xeploai(this->tb) << '\n';
    }
};

vector<Info> A(3); // Danh sach sinh vien
Info hs_max_score; // Sinh vien co diem trung binh cao nhat

int main() {
    for (auto &i : A) {
        i.init();
        cin.ignore(); // Bo qua ky tu newline
    }

    cout << "Bang thong tin:\n";
    for (auto i : A) {
        i.xuat();
        if (i.tb > hs_max_score.tb) {
            hs_max_score = i; // Cap nhat sinh vien co diem cao nhat
        }
    }

    cout << "Hoc sinh co diem trung binh cao nhat:\n";
    cout << hs_max_score.name << ' ' << hs_max_score.tb << '\n';

    // Tra cuu ten sinh vien
    cin.ignore();
    cout << "Nhap ten tra cuu:\n";
    string name;
    getline(cin, name);
    while (!A[0].check(name)) {
        cout << "Ten khong hop le. Vui long nhap lai:\n";
        cin.ignore();
        getline(cin, name);
    }
    cout << "Danh sach tim kiem:\n";
    for (auto i : A) {
        if (i.name == name) {
            i.xuat();
        }
    }
     cout<<'\n';
    // Tim diem Toan thap nhat
    float lowest_math = 10;
    for (auto i : A) {
        lowest_math = min(lowest_math, i.math);
    }

    cout << "Diem toan thap nhat la: " << lowest_math << '\n';
    cout << "Hoc sinh co diem toan thap nhat:\n";
    for (auto i : A) {
        if (i.math == lowest_math) {
            cout << i.name << '\n';
        }
    }

    return 0;
}