#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// 1. Cấu trúc SinhVien
struct SinhVien {
    string MaSV;
    string HoTen;
    string Lop;
    float Diem;
};

// a. Nhập danh sách sinh viên
void nhapDanhSach(vector<SinhVien> &ds) {
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    cin.ignore();

    ds.clear();
    for (int i = 0; i < n; i++) {
        SinhVien sv;
        cout << "\nSinh vien thu " << i + 1 << endl;
        cout << "Ma SV: ";
        getline(cin, sv.MaSV);
        cout << "Ho ten: ";
        getline(cin, sv.HoTen);
        cout << "Lop: ";
        getline(cin, sv.Lop);
        cout << "Diem: ";
        cin >> sv.Diem;
        cin.ignore();
        ds.push_back(sv);
    }
}

// b. Hiển thị danh sách sinh viên
void hienThi(const vector<SinhVien> &ds) {
    cout << left << setw(10) << "MaSV"
         << setw(25) << "HoTen"
         << setw(10) << "Lop"
         << setw(5) << "Diem" << endl;

    for (const auto &sv : ds) {
        cout << left << setw(10) << sv.MaSV
             << setw(25) << sv.HoTen
             << setw(10) << sv.Lop
             << setw(5) << sv.Diem << endl;
    }
}

// c. Hiển thị sinh viên theo lớp
void hienThiTheoLop(const vector<SinhVien> &ds, const string &lop) {
    for (const auto &sv : ds)
        if (sv.Lop == lop)
            cout << sv.MaSV << " - " << sv.HoTen << " - " << sv.Diem << endl;
}

// d. Sinh viên lớp có điểm > 5
void hienThiTheoLopVaDiem(const vector<SinhVien> &ds, const string &lop) {
    for (const auto &sv : ds)
        if (sv.Lop == lop && sv.Diem > 5)
            cout << sv.MaSV << " - " << sv.HoTen << " - " << sv.Diem << endl;
}

// e. Hiển thị sinh viên có điểm lớn nhất
void sinhVienDiemMax(const vector<SinhVien> &ds) {
    float maxD = ds[0].Diem;
    for (const auto &sv : ds)
        if (sv.Diem > maxD)
            maxD = sv.Diem;

    cout << "Sinh vien co diem cao nhat:\n";
    for (const auto &sv : ds)
        if (sv.Diem == maxD)
            cout << sv.MaSV << " - " << sv.HoTen << endl;
}

// f. Thêm sinh viên vào cuối
void themCuoi(vector<SinhVien> &ds) {
    SinhVien sv;
    cin.ignore();
    cout << "Ma SV: "; getline(cin, sv.MaSV);
    cout << "Ho ten: "; getline(cin, sv.HoTen);
    cout << "Lop: "; getline(cin, sv.Lop);
    cout << "Diem: "; cin >> sv.Diem;
    ds.push_back(sv);
}

// g. Thêm sinh viên sau vị trí k
void themSauK(vector<SinhVien> &ds, int k) {
    if (k < 0 || k >= ds.size()) return;

    SinhVien sv;
    cin.ignore();
    cout << "Ma SV: "; getline(cin, sv.MaSV);
    cout << "Ho ten: "; getline(cin, sv.HoTen);
    cout << "Lop: "; getline(cin, sv.Lop);
    cout << "Diem: "; cin >> sv.Diem;

    ds.insert(ds.begin() + k + 1, sv);
}

// h. Xóa sinh viên tại vị trí k
void xoaTaiK(vector<SinhVien> &ds, int k) {
    if (k < 0 || k >= ds.size()) return;
    ds.erase(ds.begin() + k);
}

// k. Sắp xếp giảm dần theo điểm
void sapXepGiamDan(vector<SinhVien> &ds) {
    sort(ds.begin(), ds.end(),
         [](SinhVien a, SinhVien b) {
             return a.Diem > b.Diem;
         });
}

// l. Chuyển lớp theo mã sinh viên
void chuyenLop(vector<SinhVien> &ds, const string &ma, const string &lopMoi) {
    for (auto &sv : ds)
        if (sv.MaSV == ma)
            sv.Lop = lopMoi;
}

// n. Sinh viên điểm cao nhất của một lớp
void diemMaxTheoLop(const vector<SinhVien> &ds, const string &lop) {
    float maxD = -1;
    for (const auto &sv : ds)
        if (sv.Lop == lop && sv.Diem > maxD)
            maxD = sv.Diem;

    cout << "SV diem cao nhat lop " << lop << ":\n";
    for (const auto &sv : ds)
        if (sv.Lop == lop && sv.Diem == maxD)
            cout << sv.MaSV << " - " << sv.HoTen << endl;
}

// o. Xóa sinh viên cuối danh sách
void xoaCuoi(vector<SinhVien> &ds) {
    if (!ds.empty())
        ds.pop_back();
}

// ================= MAIN =================
int main() {
    vector<SinhVien> ds;
    nhapDanhSach(ds);
    hienThi(ds);

    string lop, ma;
    int k;

    cout << "\nNhap lop can hien thi: ";
    getline(cin, lop);
    hienThiTheoLop(ds, lop);

    cout << "\nSinh vien diem > 5 cua lop:\n";
    hienThiTheoLopVaDiem(ds, lop);

    sinhVienDiemMax(ds);

    cout << "\nThem sinh vien vao cuoi:\n";
    themCuoi(ds);

    cout << "Nhap vi tri k can them sau: ";
    cin >> k;
    themSauK(ds, k);

    cout << "Nhap vi tri k can xoa: ";
    cin >> k;
    xoaTaiK(ds, k);

    sapXepGiamDan(ds);

    cin.ignore();
    cout << "Nhap ma SV can chuyen lop: ";
    getline(cin, ma);
    cout << "Nhap lop moi: ";
    getline(cin, lop);
    chuyenLop(ds, ma, lop);

    cout << "Nhap lop can tim diem cao nhat: ";
    getline(cin, lop);
    diemMaxTheoLop(ds, lop);

    xoaCuoi(ds);

    cout << "\nDanh sach cuoi cung:\n";
    hienThi(ds);

    return 0;
}
