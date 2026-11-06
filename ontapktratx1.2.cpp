#include <bits/stdc++.h>
using namespace std;
class sach{
    private:
        char masach[30],tensach[30],tacgia[30];
        long gia;
    public:
        void nhap(){
            cout<<"Nhap ma sach: "; fflush(stdin); gets(masach);
            cout<<"Nhap ten sach: "; fflush(stdin); gets(tensach);
            cout<<"Nhap tac gia: "; fflush(stdin); gets(tacgia);
            cout<<"Nhap gia: "; cin>>gia;
        }
        void xuat(){
            cout<<"Ma sach: "<<masach<<endl;
            cout<<"Ten sach: "<<tensach<<endl;
            cout<<"Tac gia: "<<tacgia<<endl;
            cout<<"Gia: "<<gia<<endl;
        }
        long getgia(){
            return gia;
        }    
};
class phieumuon{
    private:
        char maphieu[30],ngaymuon[30],ngaytra[30];
        sach *s;
        int n;
    public:
        void nhap(){
            cout<<"Nhap ma phieu: "; fflush(stdin); gets(maphieu);
            cout<<"Nhap ngay muon: "; fflush(stdin); gets(ngaymuon);
            cout<<"Nhap ngay tra: "; fflush(stdin); gets(ngaytra);
            do{
                cout<<"Nhap so luong sach muon: "; cin>>n;
            }while(n<=0);
            s=new sach[n];
            for(int i=0;i<n;i++){
                cout<<"Nhap thong tin sach thu "<<i+1<<endl;
                s[i].nhap();
            }
        }
        void xuat(){
            cout<<"Ma phieu: "<<maphieu<<endl;
            cout<<"Ngay muon: "<<ngaymuon<<endl;
            cout<<"Ngay tra: "<<ngaytra<<endl;
            for(int i=0;i<n;i++){
                cout<<"Thong tin sach thu "<<i+1<<endl;
                s[i].xuat();
            }
        }
        long tongtien(){
            long tong=0;
            for(int i=0;i<n;i++){
                tong+=s[i].getgia();
            }
            return tong;
        }
};
int main(){
    phieumuon p;
    p.nhap();
    p.xuat();
    cout<<"Tong tien: "<<p.tongtien()<<endl;
    return 0;
}