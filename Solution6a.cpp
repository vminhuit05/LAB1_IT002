#include <bits/stdc++.h>
using namespace std;

class Sub {
private:
    const vector<int>& A;
    const vector<int>& B;

    bool isSub(int pos) const {
        for (int j = 0; j < A.size(); ++j) {
            if (B[pos + j] != A[j]) {
                return false;
            }
        }
        return true;
    }

public:
    Sub(const vector<int>& A, const vector<int>& B) : A(A), B(B) {}

    void CountSub() const {
        if (A.size() > B.size()) {
            cout << "A khong the la chuoi con cua B vi A co kich thuoc lon hon." << endl;
            return;
        }

        int cnt = 0;
        vector<int> positions;

        for (int i = 0; i <= B.size() - A.size(); ++i) {
            if (isSub(i)) {
                cnt++;
                positions.push_back(i);
            }
        }

        cout << "So lan xuat hien cua A trong B: " << cnt << endl;
        if (!positions.empty()) {
            cout << "Cac vi tri xuat hien: ";
            for (int pos : positions) {
                cout << pos << " ";
            }
            cout << endl;
        } else {
            cout << "Khong tim thay A trong B." << endl;
        }
    }
};

int main() {
    int n, m;
    
    cout << "Nhap so phan tu cua A va B: ";
    cin >> n >> m;

    vector<int> A(n), B(m);

    cout << "Nhap cac phan tu cua A: ";
    for (int& x : A) {
        cin >> x;
    }

    cout << "Nhap cac phan tu cua B: ";
    for (int& x : B) {
        cin >> x;
    }

    Sub counter(A, B);
    counter.CountSub();

    return 0;
}
