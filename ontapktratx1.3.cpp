#include <bits/stdc++.h>
using namespace std;
class nhansu{
    protected:
        char hoten[30];
        int d,m,y;
        char diachi[30];
    public:
        void nhap(){
            cout<<"Nhap ho ten: "; fflush(stdin); gets(hoten);
            cout<<"Nhap ngay sinh (dd mm yyyy): "; cin>>d>>m>>y;
            cout<<"Nhap dia chi: "; fflush(stdin); gets(diachi);
        }
        void xuat(){
            cout<<"Ho ten: "<<hoten<<endl;
            cout<<"Ngay sinh: "<<d<<"/"<<m<<"/"<<y<<endl;
            cout<<"Dia chi: "<<diachi<<endl;
        }
};
class giangvien:public nhansu{
    private:
        char khoa[30];
        int sotiet;
        int gia1tiet;
    public:
        void nhap(){
            nhansu::nhap();
            cout<<"Nhap khoa: "; fflush(stdin); gets(khoa);
            cout<<"Nhap so tiet: "; cin>>sotiet;
            cout<<"Nhap gia 1 tiet: ";cin>>gia1tiet;
        }
        void xuat(){
            nhansu::xuat();
            cout<<"Khoa: "<<khoa<<endl;
            cout<<"So tiet: "<<sotiet<<endl;
            cout<<"Gia 1 tiet: "<<gia1tiet<<endl;
            cout<<"Thanh tien: "<<sotiet*gia1tiet<<endl;
        }       
    friend void thunhapcaonhat(giangvien *a,int n);    
};
class nhanvienhc:public nhansu{
    private:
        char phongban[30];
        int luongcb;
        int hsl;
    public:
        void nhap(){
            nhansu::nhap();
            cout<<"Nhap phong ban: "; fflush(stdin); gets(phongban);
            cout<<"Nhap luong co ban: "; cin>>luongcb;
            cout<<"Nhap he so luong: "; cin>>hsl;
        }
        void xuat(){
            nhansu::xuat();
            cout<<"Phong ban: "<<phongban<<endl;
            cout<<"Luong co ban: "<<luongcb<<endl;
            cout<<"He so luong: "<<hsl<<endl;
            cout<<"Thanh tien: "<<luongcb*hsl<<endl;
        }
};
void thunhapcaonhat(giangvien *a,int n){
        int max=a[0].sotiet*a[0].gia1tiet;
        for(int i=1;i<n;i++){
            if(a[i].sotiet*a[i].gia1tiet>max){
                max=a[i].sotiet*a[i].gia1tiet;
            }
        }
        for(int i=0;i<n;i++){
            if(a[i].sotiet*a[i].gia1tiet==max){
                a[i].xuat();
            }
        }
}
int main(){
    int n;
    do{
        cout<<"Nhap so luong giang vien: "; cin>>n;
    }while(n<=0);
    giangvien *a=new giangvien[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin giang vien thu "<<i+1<<endl;
        a[i].nhap();
    }
    for(int i=0;i<n;i++){
        cout<<"Thong tin giang vien thu "<<i+1<<endl;
        a[i].xuat();
    }
    cout<<"Thong tin giang vien co thu nhap cao nhat: "<<endl;
    thunhapcaonhat(a,n);
    delete[] a;
}