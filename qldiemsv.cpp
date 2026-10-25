#include <bits/stdc++.h>
using namespace std;
class sv{
    private:
        char masv[30];
        char hoten[30];
        float dtoan,dly,dhoa;
    public:
        void nhap(){
            cout<<"Nhap ma sinh vien: ";fflush(stdin);cin.getline(masv,30);
            cout<<"Nhap ho va ten: ";fflush(stdin);cin.getline(hoten,30);
            cout<<"Nhap diem toan: ";cin>>dtoan;
            cout<<"Nhap diem ly: ";cin>>dly;
            cout<<"Nhap diem hoa: ";cin>>dhoa;
        }
        void xuat(){
            float tong=0;
            cout<<"Ma sinh vien: "<<masv<<endl;
            cout<<"Ho va ten: "<<hoten<<endl;
            cout<<"Diem toan: "<<dtoan<<endl;
            cout<<"Diem ly: "<<dly<<endl;
            cout<<"Diem hoa: "<<dhoa<<endl;
            tong=dtoan+dly+dhoa;
            cout<<"Tong diem: "<<tong<<endl;
        }
};
int main(){
    int n;
    do{
        cout<<"Nhap n: ";cin>>n;
    }while(n<=0);
    sv a[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap sinh vien thu "<<i+1<<": ";a[i].nhap();
    }
    for(int i=0;i<n;i++){
        cout<<"Sinh vien thu "<<i+1<<": "<<endl;
        a[i].xuat();
    }   
}