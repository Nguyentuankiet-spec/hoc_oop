#include <bits/stdc++.h>
using namespace std;
class nsx{
    private:
        char mansx[30];
        char tennsx[30];
        char dcnsx[30];
    public:
        friend class hang;
};
class hang{
    private:
        char mah[30];
        char tenh[30];
        long gia;
        float tluong;
        nsx x;
    public:
        void nhap(){
            cout<<"Nhap ma hang: ";fflush(stdin);cin.getline(mah,30);
            cout<<"Nhap ten hang: ";fflush(stdin);cin.getline(tenh,30);
            cout<<"Nhap gia hang: ";cin>>gia;
            cout<<"Nhap trong luong hang: ";cin>>tluong;
            cout<<"Nhap ma nsx: ";fflush(stdin);cin.getline(x.mansx,30);
            cout<<"Nhap ten nsx: ";fflush(stdin);cin.getline(x.tennsx,30);
            cout<<"Nhap dia chi nsx: ";fflush(stdin);cin.getline(x.dcnsx,30);
        }    
        void xuat(){
            cout<<"Nhap ma hang: "<<mah<<endl;
            cout<<"Nhap ten hang: "<<tenh<<endl;
            cout<<"Nhap gia hang: "<<gia<<endl;
            cout<<"Nhap trong luong hang: "<<tluong<<endl;
            cout<<"Nhap ma nsx: "<<x.mansx<<endl;
            cout<<"Nhap ten nsx: "<<x.tennsx<<endl;
            cout<<"Nhap dia chi nsx: "<<x.dcnsx<<endl;
        }
};
int main(){
    hang a;
    a.nhap();
    a.xuat();
}