#include <iostream>
#include <cmath>
using namespace std;

// 1. Nhập mảng
void nhapMang(int a[], int &n) {
    cout << "Nhap so phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

// 2. Xuất mảng
void xuatMang(int a[], int n) {
    cout << "Mang: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// 3. Tính tổng các phần tử
int tongMang(int a[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    return s;
}

// 4. Đếm số âm
int demSoAm(int a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
            dem++;
    return dem;
}

// 5. Kiểm tra số chính phương
bool laSoChinhPhuong(int x) {
    if (x < 0) return false;
    int t = sqrt(x);
    return t * t == x;
}

// 6. Tính trung bình cộng các số chính phương
double trungBinhChinhPhuong(int a[], int n) {
    int tong = 0, dem = 0;
    for (int i = 0; i < n; i++) {
        if (laSoChinhPhuong(a[i])) {
            tong += a[i];
            dem++;
        }
    }
    if (dem == 0) return 0;
    return (double)tong / dem;
}

// 7. In các số chính phương
void inSoChinhPhuong(int a[], int n) {
    cout << "Cac so chinh phuong: ";
    for (int i = 0; i < n; i++)
        if (laSoChinhPhuong(a[i]))
            cout << a[i] << " ";
    cout << endl;
}

// 8. Tìm max
int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

// 9. Tìm min
int timMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

// 10. In các số trong khoảng (min, max)
void inTrongKhoang(int a[], int n, int min, int max) {
    cout << "Cac so nam trong khoang (" << min << ", " << max << "): ";
    for (int i = 0; i < n; i++)
        if (a[i] > min && a[i] < max)
            cout << a[i] << " ";
    cout << endl;
}

// ================= MAIN =================
int main() {
    int a[100], n;

    nhapMang(a, n);
    xuatMang(a, n);

    cout << "Tong cac phan tu = " << tongMang(a, n) << endl;
    cout << "So luong so am = " << demSoAm(a, n) << endl;

    inSoChinhPhuong(a, n);
    cout << "Trung binh cong so chinh phuong = "
         << trungBinhChinhPhuong(a, n) << endl;

    int max = timMax(a, n);
    int min = timMin(a, n);

    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;

    inTrongKhoang(a, n, min, max);

    return 0;
}
