#include <bits/stdc++.h>
using namespace std;

// Ham tim kiem su xuat hien cua A trong B su dung hashing
int main() {
    // Nhap kich thuoc cua mang A va B
    int n, m;
    cin >> n >> m;

    // Khoi tao mang A va B
    vector<long long> A(n), B(m);

    // Doc du lieu cho mang A
    for (long long &i : A) cin >> i;

    // Doc du lieu cho mang B
    for (long long &i : B) cin >> i;

    // Gia tri hash va base cho hash cuon
    long long hashA = 0, hashB = 0;
    long long base = 1e18;
    vector<long long> powbase(m + 1, 0); // Luu tru cac luong luy thua

    // Tinh toan hash cho mang A
    for (long long i : A) {
        hashA = hashA * base + i;
    }

    // Tinh toan cac luong luy thua
    powbase[0] = 1;
    for (int i = 1; i < powbase.size(); i++) {
        powbase[i] = powbase[i - 1] * base;
    }

    // Tinh hash cho n-1 phan tu dau tien cua B
    for (int i = 0; i < n - 1; i++) {
        hashB = hashB * base + B[i];
    }

    // Vector de luu cac chi so bat dau cua su xuat hien
    vector<int> ans;

    // Hash cuon: Di chuyen qua B va so sanh cac hash
    for (int i = n - 1; i < m; i++) {
        // Them phan tu tiep theo vao hashB
        hashB = hashB * base + B[i];

        // Kiem tra xem hai hash co khop nhau khong
        if (hashB == hashA) {
            ans.push_back(i - n + 1); // Luu chi so bat dau
        }

        // Loai bo phan tu dau tien trong cua so ra khoi hashB
        hashB = hashB - powbase[n - 1] * B[i];
    }

    // Xuat so luong xuat hien va cac chi so
    cout << ans.size() << '\n';
    for (int v : ans) {
        cout << v << ' ';
    }

    return 0;
}