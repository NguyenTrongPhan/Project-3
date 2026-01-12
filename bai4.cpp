#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

// 1. Đếm chữ cái
int demChuCai(const string &s) {
    int dem = 0;
    for (char c : s)
        if (isalpha(c))
            dem++;
    return dem;
}

// 2. Đếm chữ số
int demChuSo(const string &s) {
    int dem = 0;
    for (char c : s)
        if (isdigit(c))
            dem++;
    return dem;
}

// 3. Chèn '@' trước "gmail.com"
void chenAt(string &s) {
    size_t pos = s.find("gmail.com");
    if (pos != string::npos)
        s.insert(pos, "@");
}

// 4. Chèn '-' giữa hai số chẵn
void chenGachGiuaSoChan(string &s) {
    for (size_t i = 0; i + 1 < s.size(); i++) {
        if (isdigit(s[i]) && isdigit(s[i + 1])) {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            if (a % 2 == 0 && b % 2 == 0) {
                s.insert(i + 1, "-");
                i++; // bỏ qua dấu vừa chèn
            }
        }
    }
}

// 5. Thay gmail.com → ctech.edu.vn
void thayGmail(string &s) {
    size_t pos = s.find("gmail.com");
    if (pos != string::npos)
        s.replace(pos, 9, "ctech.edu.vn");
}

// 6. In các từ trong xâu
void inCacTu(const string &s) {
    stringstream ss(s);
    string word;
    cout << "Cac tu trong xau:\n";
    while (ss >> word)
        cout << word << endl;
}

// 7. Đổi hoa ↔ thường
void doiHoaThuong(string &s) {
    for (char &c : s) {
        if (islower(c)) c = toupper(c);
        else if (isupper(c)) c = tolower(c);
    }
}

// 8. Tìm chữ số và tính tổng
int tongChuSo(const string &s) {
    int tong = 0;
    for (char c : s)
        if (isdigit(c))
            tong += c - '0';
    return tong;
}

// 9. Viết hoa chữ cái đầu mỗi từ
void vietHoaChuDau(string &s) {
    bool dauTu = true;
    for (char &c : s) {
        if (isalpha(c) && dauTu) {
            c = toupper(c);
            dauTu = false;
        } else if (c == ' ') {
            dauTu = true;
        }
    }
}

// 10. Đảo ngược xâu
string daoNguoc(const string &s) {
    string t = s;
    reverse(t.begin(), t.end());
    return t;
}

// 11. Tìm từ dài nhất
string tuDaiNhat(const string &s) {
    stringstream ss(s);
    string word, maxWord = "";
    while (ss >> word)
        if (word.length() > maxWord.length())
            maxWord = word;
    return maxWord;
}

// ================= MAIN =================
int main() {
    string s;
    cout << "Nhap xau: ";
    getline(cin, s);

    cout << "So chu cai: " << demChuCai(s) << endl;
    cout << "So chu so: " << demChuSo(s) << endl;

    chenAt(s);
    chenGachGiuaSoChan(s);
    thayGmail(s);

    inCacTu(s);

    doiHoaThuong(s);
    cout << "Sau doi hoa-thuong: " << s << endl;

    cout << "Tong cac chu so: " << tongChuSo(s) << endl;

    vietHoaChuDau(s);
    cout << "Viet hoa chu dau moi tu: " << s << endl;

    cout << "Xau dao nguoc: " << daoNguoc(s) << endl;

    cout << "Tu dai nhat: " << tuDaiNhat(s) << endl;

    return 0;
}
