#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 50;

// 1. Nhập ma trận vuông
void nhapMaTran(int a[][MAX], int &n) {
    cout << "Nhap cap ma tran n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
}

// 2. In ma trận
void inMaTran(int a[][MAX], int n) {
    cout << "Ma tran:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

// 3. Tính tổng các phần tử
int tongMaTran(int a[][MAX], int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            s += a[i][j];
    return s;
}

// 4. Phần tử lớn nhất của hàng k
int maxHangK(int a[][MAX], int n, int k) {
    int maxVal = a[k][0];
    for (int j = 1; j < n; j++)
        if (a[k][j] > maxVal)
            maxVal = a[k][j];
    return maxVal;
}

// 5. Đếm số âm của cột k
int demSoAmCotK(int a[][MAX], int n, int k) {
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (a[i][k] < 0)
            dem++;
    return dem;
}

// Kiểm tra số chính phương
bool laSoChinhPhuong(int x) {
    if (x < 0) return false;
    int t = sqrt(x);
    return t * t == x;
}

// 6. In số chính phương trên đường chéo chính
void inChinhPhuongCheoChinh(int a[][MAX], int n) {
    cout << "So chinh phuong tren duong cheo chinh: ";
    for (int i = 0; i < n; i++)
        if (laSoChinhPhuong(a[i][i]))
            cout << a[i][i] << " ";
    cout << endl;
}

// Kiểm tra ước của 150
bool laUoc150(int x) {
    return x != 0 && 150 % x == 0;
}

// 7. Trung bình cộng các ước của 150 trên đường chéo phụ
double trungBinhCheoPhu(int a[][MAX], int n) {
    int tong = 0, dem = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i][n - i - 1];
        if (laUoc150(x)) {
            tong += x;
            dem++;
        }
    }
    if (dem == 0) return 0;
    return (double)tong / dem;
}

// 8. Sắp xếp các hàng giảm dần
void sapXepHangGiamDan(int a[][MAX], int n) {
    for (int i = 0; i < n; i++)
        sort(a[i], a[i] + n, greater<int>());
}

// ================= MAIN =================
int main() {
    int a[MAX][MAX], n, k;

    nhapMaTran(a, n);
    inMaTran(a, n);

    cout << "Tong cac phan tu = " << tongMaTran(a, n) << endl;

    cout << "Nhap hang k: ";
    cin >> k;
    cout << "Max hang " << k << " = " << maxHangK(a, n, k) << endl;

    cout << "Nhap cot k: ";
    cin >> k;
    cout << "So am cot " << k << " = " << demSoAmCotK(a, n, k) << endl;

    inChinhPhuongCheoChinh(a, n);

    cout << "TBC cac uoc cua 150 tren cheo phu = "
         << trungBinhCheoPhu(a, n) << endl;

    sapXepHangGiamDan(a, n);
    cout << "Ma tran sau khi sap xep giam dan theo hang:\n";
    inMaTran(a, n);

    return 0;
}
