#include <iostream>
#include <algorithm>
using namespace std;

// 1. Nhập mảng động
void nhapMang(int* &a, int &n) {
    cout << "Nhap so phan tu n: ";
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

// 2. Hiển thị mảng
void xuatMang(int* a, int n) {
    cout << "Mang: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// 3. Tìm phần tử nhỏ nhất
int timMin(int* a, int n) {
    int minVal = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < minVal)
            minVal = a[i];
    return minVal;
}

// 4. Tính tổng các phần tử
int tongMang(int* a, int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    return s;
}

// 5. Xóa phần tử tại vị trí k
void xoaViTriK(int* &a, int &n, int k) {
    if (k < 0 || k >= n) return;

    for (int i = k; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;
    int* temp = new int[n];
    for (int i = 0; i < n; i++)
        temp[i] = a[i];

    delete[] a;
    a = temp;
}

// 6. Thêm phần tử x sau vị trí k
void themSauK(int* &a, int &n, int k, int x) {
    if (k < 0 || k >= n) return;

    int* temp = new int[n + 1];
    for (int i = 0; i <= k; i++)
        temp[i] = a[i];

    temp[k + 1] = x;

    for (int i = k + 2; i < n + 1; i++)
        temp[i] = a[i - 1];

    delete[] a;
    a = temp;
    n++;
}

// 7. Sắp xếp giảm dần
void sapXepGiamDan(int* a, int n) {
    sort(a, a + n, greater<int>());
}

// 8. Xóa các phần tử có giá trị lớn nhất
void xoaGiaTriLonNhat(int* &a, int &n) {
    int maxVal = *max_element(a, a + n);
    int dem = 0;

    for (int i = 0; i < n; i++)
        if (a[i] != maxVal)
            dem++;

    int* temp = new int[dem];
    int idx = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != maxVal)
            temp[idx++] = a[i];

    delete[] a;
    a = temp;
    n = dem;
}

// ================= MAIN =================
int main() {
    int* a = nullptr;
    int n;

    nhapMang(a, n);
    xuatMang(a, n);

    cout << "Phan tu nho nhat = " << timMin(a, n) << endl;
    cout << "Tong cac phan tu = " << tongMang(a, n) << endl;

    int k, x;
    cout << "Nhap vi tri k can xoa: ";
    cin >> k;
    xoaViTriK(a, n, k);
    xuatMang(a, n);

    cout << "Nhap vi tri k va gia tri x can them: ";
    cin >> k >> x;
    themSauK(a, n, k, x);
    xuatMang(a, n);

    sapXepGiamDan(a, n);
    cout << "Mang sau sap xep giam dan:\n";
    xuatMang(a, n);

    xoaGiaTriLonNhat(a, n);
    cout << "Mang sau khi xoa gia tri lon nhat:\n";
    xuatMang(a, n);

    delete[] a;
    return 0;
}
