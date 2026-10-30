#include <bits/stdc++.h>
using namespace std;
class ttin{
    private:
        char hoten[30];
        char chucvu[30];
        char phongkk[30];
        char maphong[30];
        char trgphong[30];
    public:
        void nhap(){
            cout<<"Nhap ho ten: "; fflush(stdin); gets(hoten);
            cout<<"Nhap chuc vu: "; fflush(stdin); gets(chucvu);
            cout<<"Nhap phong kiem ke: "; fflush(stdin); gets(phongkk);
            cout<<"Nhap ma phong: "; fflush(stdin); gets(maphong);
            cout<<"Nhap truong phong: "; fflush(stdin); gets(trgphong);
        }
        void xuat(){
            cout<<"Nhan vien kiem ke: "<<hoten<<setw(30)<<"Chuc vu: "<<chucvu<<endl;
            cout<<"Phong kiem ke: "<<phongkk<<setw(30)<<"Ma phong: "<<maphong<<endl;
            cout<<"Truong phong: "<<trgphong<<endl;
        }
};
class taisan{
    private:
        char tents[30];
        char tinhtrang[30];
        int soluong;
    public:
        void nhap(){
            cout<<"Nhap ten tai san: "; fflush(stdin); gets(tents);
            cout<<"Nhap so luong: "; cin>>soluong;
            cout<<"Nhap tinh trang: "; fflush(stdin); gets(tinhtrang);
        }
        void xuat(){
            cout<<setw(30)<<tents<<setw(30)<<soluong<<setw(30)<<tinhtrang<<endl;
        }
        int getsoluong(){
            return soluong;
        }
        void setsoluong(int sl){
            soluong=sl;
        }
        char* gettents(){
            return tents;
        }
};
int tongsoluong(taisan *ts, int n){
    int tong=0;
    for(int i=0;i<n;i++){
        tong+=ts[i].getsoluong();
    }
    return tong;
}
class phiekk{
    private:
        char maphieu[30];
        int d,m,y;
        int n;
        ttin nv;
        taisan *ts;
    public:
        void nhap(){
            cout<<"Nhap ma phieu: "; fflush(stdin); gets(maphieu);
            cout<<"Nhap ngay kiem ke: "; cin>>d>>m>>y;
            nv.nhap();
            do{
                cout<<"Nhap so luong tai san: ";
                cin>>n;
            }while(n<=0);
            ts = new taisan[n];
            for(int i=0;i<n;i++){
                ts[i].nhap();
            }
        }
        void xuat(){
            cout<<"Ma phieu: "<<maphieu<<setw(30)<<"Ngay kiem ke: "<<d<<"/"<<m<<"/"<<y<<endl;
            nv.xuat();
            cout<<setw(30)<<"Ten tai san"<<setw(30)<<"So luong"<<setw(30)<<"Tinh trang"<<endl;
            for(int i=0;i<n;i++){
                ts[i].xuat();
            }
            cout<<"So tai san da kiem ke: "<<n<<setw(30)<<"Tong so luong: "<<tongsoluong(ts, n)<<endl;
        }
        void suamayvitinh(){
            for(int i=0;i<n;i++){
                if(strcmp(ts[i].gettents(), "May vi tinh")==0){
                    ts[i].setsoluong(20);
                }
            }
        }
        void sapxep(){
            for(int i=0;i<n-1;i++){
                for(int j=0;j<n-1-i;j++){
                    if(ts[j].getsoluong() > ts[j+1].getsoluong()){
                        taisan tam = ts[j];
                        ts[j] = ts[j+1];
                        ts[j+1] = tam;
                    }
                }
            }
        }
};
int main(){
    phiekk p;
    p.nhap();
    p.xuat();
    p.suamayvitinh();
    cout<<"Danh sach tai san sau khi sua so luong may vi tinh: "<<endl;
    p.xuat();
    p.sapxep();
    cout<<"Danh sach tai san sau khi sap xep theo so luong: "<<endl;
    p.xuat();
}