#include <bits/stdc++.h>
using namespace std;
class duan;
class nhanvien{
    protected:
        char maNV[10];
        char tenNV[30];
        long luongcb;
    public:
        void nhap(){
            cout << "Nhap ma nhan vien: "; fflush(stdin); gets(maNV);
            cout << "Nhap ten nhan vien: "; fflush(stdin); gets(tenNV);
            cout << "Nhap luong co ban: "; cin >> luongcb;
        }
        void xuat(){
            cout << "Ma nhan vien: " << maNV << endl;
            cout << "Ten nhan vien: " << tenNV << endl;
            cout << "Luong co ban: " << luongcb << endl;
        }
};
class laptrinhvien:public nhanvien{
    private:
        int ot;
        int luongot;
    public:
        void nhap(){
            nhanvien::nhap();
            cout << "Nhap so gio lam them: "; cin >> ot;
            cout << "Nhap luong lam them: "; cin >> luongot;
        }
        void xuat(){
            nhanvien::xuat();
            cout << "So gio lam them: " << ot << endl;
            cout << "Luong lam them: " << luongot << endl;
        }
        long tinhluong(){
            return luongcb + ot * luongot;
        }
    friend void bangluong(duan &d);
    friend void tongluong(duan &d);
};
class kiemthuvien:public nhanvien{
    private:
        int soloiphathien;
        long tienphathienloi;
    public:
        void nhap(){
            nhanvien::nhap();
            cout << "Nhap so loi phat hien: "; cin >> soloiphathien;
            cout << "Nhap tien phat hien loi: "; cin >> tienphathienloi;
        }
        void xuat(){
            nhanvien::xuat();
            cout << "So loi phat hien: " << soloiphathien << endl;
            cout << "Tien phat hien loi: " << tienphathienloi << endl;
        }
        long tinhluong(){
            return luongcb + soloiphathien * tienphathienloi;
        }
    friend void bangluong(duan &d);
    friend void tongluong(duan &d);
    friend void xoaloi0(duan &d);
};
class duan{
    private:
        char mada[10];
        char tenduan[30];
        int n,m;
        laptrinhvien *a;
        kiemthuvien *b;
    public:
        void nhap(){
            cout << "Nhap ma du an: "; fflush(stdin); gets(mada);
            cout << "Nhap ten du an: "; fflush(stdin); gets(tenduan);
            do{
                cout << "Nhap so luong lap trinh vien: "; cin >> n;
            } while(n <= 0);
            a = new laptrinhvien[n];
            for(int i = 0; i < n; i++){
                cout << "Nhap thong tin lap trinh vien thu " << i + 1 << ":\n";
                a[i].nhap();
            }
            do{
                cout << "Nhap so luong kiem thu vien: "; cin >> m;
            } while(m <= 0);
            b = new kiemthuvien[m];
            for(int i = 0; i < m; i++){
                cout << "Nhap thong tin kiem thu vien thu " << i + 1 << ":\n";
                b[i].nhap();
            }
        }
        void xuat(){
            cout << "Ma du an: " << mada << endl;
            cout << "Ten du an: " << tenduan << endl;
            cout << "Danh sach lap trinh vien:\n";
            for(int i = 0; i < n; i++){
                cout << "Thong tin lap trinh vien thu " << i + 1 << ":\n";
                a[i].xuat();
                cout << "Luong: " << a[i].tinhluong() << endl;
            }
            cout << "Danh sach kiem thu vien:\n";
            for(int i = 0; i < m; i++){
                cout << "Thong tin kiem thu vien thu " << i + 1 << ":\n";
                b[i].xuat();
                cout << "Luong: " << b[i].tinhluong() << endl;
            }
        }
        ~duan(){
            delete[] a;
            delete[] b;
        }
    friend void bangluong(duan &d);
    friend void tongluong(duan &d);
    friend void xoaloi0(duan &d);
};
void bangluong(duan &d){
    cout<<"Bang luong du an " << d.mada << " - " << d.tenduan << ":\n";
    cout << "Lap trinh vien:\n";
    for(int i = 0; i < d.n; i++){
        cout << "Thong tin lap trinh vien thu " << i + 1 << ":\n";
        cout << "Luong: " << d.a[i].tinhluong() << endl;
    }
    cout << "Kiem thu vien:\n";
    for(int i = 0; i < d.m; i++){
        cout << "Thong tin kiem thu vien thu " << i + 1 << ":\n";
        cout << "Luong: " << d.b[i].tinhluong() << endl;
    }
}
void tongluong(duan &d){
    long tong=0;
    for(int i=0;i<d.n;i++){
        tong+=d.a[i].tinhluong();
    }
    for(int i=0;i<d.m;i++){
        tong+=d.b[i].tinhluong();
    }
    cout << "Tong luong: " << tong << endl;
}
void xoaloi0(duan &d){
    for(int i=0;i<d.m;i++){
        if(d.b[i].soloiphathien==0){
            for(int j=i;j<d.m-1;j++){
                d.b[j]=d.b[j+1];
            }
            d.m--;
            i--;
        }
    }
}
int main(){
    duan d;
    d.nhap();
    d.xuat();
    bangluong(d);
    tongluong(d);
    xoaloi0(d);
    cout << "Danh sach kiem thu vien sau khi xoa nhung nguoi khong phat hien loi:\n";
    d.xuat();
    return 0;
}