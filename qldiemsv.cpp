#include <bits/stdc++.h>
using namespace std;
class sv{
    private:
        char masv[30];
        char hoten[30];
        float dtoan,dly,dhoa;
    public:
        void nhap(){
            cout<<"Nhap ma sinh vien: ";fflush(stdin);gets(masv);
            cout<<"Nhap ho va ten: ";fflush(stdin);gets(hoten);
            cout<<"Nhap diem toan: ";cin>>dtoan;
            cout<<"Nhap diem ly: ";cin>>dly;
            cout<<"Nhap diem hoa: ";cin>>dhoa;
        }
        void xuat(){
            cout<<"Nhap ma sinh vien: "<<masv<<endl;
            cout<<"Nhap ho va ten: "<<hoten<<endl;
            cout<<"Nhap diem toan: "<<dtoan<<endl;
            cout<<"Nhap diem ly: "<<dly<<endl;
            cout<<"Nhap diem hoa: "<<dhoa<<endl;
        }
};
int main(){
    sv a;
    a.nhap();
    a.xuat();
}