#include <bits/stdc++.h>
using namespace std;
class qlytb;
class thietbi{
    protected:
        char matb[30];
        char tentb[30];
        long giatien;
        int d,m,y;
    public:
        void nhap(){
            cout<<"Nhap ma thiet bi: ";fflush(stdin);gets(matb);
            cout<<"Nhap ten thiet bi: ";fflush(stdin);gets(tentb);
            cout<<"Nhap gia tien: ";cin>>giatien;
            cout<<"Nhap ngay san xuat (dd mm yyyy): ";cin>>d>>m>>y;
        }    
        void xuat(){
            cout<<"Ma thiet bi: "<<matb<<endl;
            cout<<"Ten thiet bi: "<<tentb<<endl;
            cout<<"Gia tien: "<<giatien<<endl;
            cout<<"Ngay san xuat: "<<d<<"/"<<m<<"/"<<y<<endl;
        }
    friend void tisxtruoc2021(qlytb &c);
    friend void sapxepgia(qlytb &c);
};
class tv:public thietbi{
    private:
        float kichthuoc;
        char loaimanhinh[30];
    public:
        void nhap(){
            thietbi::nhap();
            cout<<"Nhap kich thuoc: ";cin>>kichthuoc;
            cout<<"Nhap loai man hinh: ";fflush(stdin);gets(loaimanhinh);
        }
        void xuat(){
            thietbi::xuat();
            cout<<"Kich thuoc: "<<kichthuoc<<endl;
            cout<<"Loai man hinh: "<<loaimanhinh<<endl;
        }
};
class dieuhoa:public thietbi{
    private:
        int congSuat;
        int dungluongpin;
    public:
        void nhap(){
            thietbi::nhap();
            cout<<"Nhap cong suat: ";cin>>congSuat;
            cout<<"Nhap dung luong pin: ";cin>>dungluongpin;
        }
        void xuat(){
            thietbi::xuat();
            cout<<"Cong suat: "<<congSuat<<endl;
            cout<<"Dung luong pin: "<<dungluongpin<<endl;
        }
};
class qlytb{
    private:
        tv *a;
        dieuhoa *b;
        int n,m;
    public:
        void nhap(){
            do{
                cout<<"Nhap so luong TV: ";cin>>n;
            }while(n<=0);
            do{
                cout<<"Nhap so luong dieu hoa: ";cin>>m;
            }while(m<=0);
            a=new tv[n];
            b=new dieuhoa[m];
            for(int i=0;i<n;i++){
                cout<<"Nhap thong tin TV thu "<<i+1<<endl;
                a[i].nhap();
            }
            for(int i=0;i<m;i++){
                cout<<"Nhap thong tin dieu hoa thu "<<i+1<<endl;
                b[i].nhap();
            }
        }    
        void xuat(){
            cout<<"Danh sach TV: "<<endl;
            for(int i=0;i<n;i++){
                a[i].xuat();
            }
            cout<<"Danh sach dieu hoa: "<<endl;
            for(int i=0;i<m;i++){
                b[i].xuat();
            }
        }
        ~qlytb(){
            delete[] a;
            delete[] b;
        }
    friend void tisxtruoc2021(qlytb &c);
    friend void sapxepgia(qlytb &c);
};
void tisxtruoc2021(qlytb &c){
    cout<<"Danh sach thiet bi san xuat truoc nam 2021: "<<endl;
    for(int i=0;i<c.n;i++){
        if(c.a[i].y<2021){
            c.a[i].xuat();
        }
    }
    for(int i=0;i<c.m;i++){
        if(c.b[i].y<2021){
            c.b[i].xuat();
        }
    }
}
void sapxepgia(qlytb &c){
    for(int i=0;i<c.n-1;i++){
        for(int j=i+1;j<c.n;j++){
            if(c.a[i].giatien>c.a[j].giatien){
                swap(c.a[i],c.a[j]);
            }
        }
    }
    for(int i=0;i<c.m-1;i++){
        for(int j=i+1;j<c.m;j++){
            if(c.b[i].giatien>c.b[j].giatien){
                swap(c.b[i],c.b[j]);
            }
        }
    }
}
int main(){
    qlytb c;
    c.nhap();
    c.xuat();
    tisxtruoc2021(c);
    sapxepgia(c);
    cout<<"Danh sach thiet bi sau khi sap xep theo gia: "<<endl;
    c.xuat();
    return 0;
}