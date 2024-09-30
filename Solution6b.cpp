#include <bits/stdc++.h>
using namespace std;

struct Info {
    string name;
    float math;
    float lit;
    float eng;
    double tb;

    Info(const string& name, float math, float lit, float eng) : name(name), math(math), lit(lit), eng(eng) {
        this->tb = (2.0 * math + lit + eng) / 4.0;
    }

    static bool check_score(float score) {
        return (0.0 <= score && score <= 10.0);
    }

    static bool check_name(const string &fullName) {
        if (fullName.length() > 50) return false;

        bool newWord = true;
        for (char c : fullName) {
            if (isspace(c)) {
                if (newWord == true) return false;
                newWord = true;
            } else {
                if (!isalpha(c)) return false;
                if (newWord && !isupper(c)) return false;
                if (!newWord && !islower(c)) return false;
                newWord = false;
            }
        }
        return true;
    }

    string xeploai() const {
        if (tb >= 9.0) return "Xuat Sac";
        else if (tb >= 8.0) return "Gioi";
        else if (tb >= 6.5) return "Kha";
        else if (tb >= 5.0) return "Trung Binh";
        else return "Yeu";
    }

    void print() const {
        cout << name << ": Toan = " << math << ", Van = " << lit << ", Anh = " << eng << '\n';
        cout << "Diem Trung Binh: " << fixed << setprecision(2) << tb << '\n';
        cout << "Xep loai: " << xeploai() << '\n';
    }
};

Info input_info() {
    string name;
    float math, lit, eng;

    cin.ignore();
    cout << "Nhap ten (in hoa chu cai dau cua moi tu): ";
    getline(cin, name);

    while (!Info::check_name(name)) {
        cout << "Ten khong hop le, vui long nhap lai: ";
        getline(cin, name);
    }

    cout << "Nhap diem Toan: ";
    cin >> math;
    while (!Info::check_score(math)) {
        cout << "Diem khong hop le, vui long nhap lai: ";
        cin >> math;
    }

    cout << "Nhap diem Van: ";
    cin >> lit;
    while (!Info::check_score(lit)) {
        cout << "Diem khong hop le, vui long nhap lai: ";
        cin >> lit;
    }

    cout << "Nhap diem Anh: ";
    cin >> eng;
    while (!Info::check_score(eng)) {
        cout << "Diem khong hop le, vui long nhap lai: ";
        cin >> eng;
    }

    return Info(name, math, lit, eng);
}

int main() {
    vector<Info> students;

    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":\n";
        students.push_back(input_info());
    }

    cout << "\nBang thong tin hoc sinh:\n";
    for (const auto& student : students) {
        student.print();
        cout << '\n';
    }

    auto max_student = max_element(students.begin(), students.end(),
                                   [](const Info& a, const Info& b) { return a.tb < b.tb; });
    cout << "Hoc sinh co diem trung binh cao nhat: \n";
    max_student->print();
    cout << '\n';

    cout << "Nhap ten hoc sinh de tra cuu: ";
    string search_name;
    cin.ignore();
    getline(cin, search_name);

    auto found_student = find_if(students.begin(), students.end(),
                                 [&](const Info& student) { return student.name == search_name; });

    if (found_student != students.end()) {
        cout << "Thong tin hoc sinh tim thay:\n";
        found_student->print();
    } else {
        cout << "Khong tim thay hoc sinh co ten " << search_name << '\n';
    }

    auto min_math_student = min_element(students.begin(), students.end(),
                                        [](const Info& a, const Info& b) { return a.math < b.math; });

    cout << "\nHoc sinh co diem Toan thap nhat: \n";
    min_math_student->print();

    return 0;
}