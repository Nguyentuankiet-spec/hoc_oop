#include <bits/stdc++.h>
using namespace std;
class qlyxe;
class phuongtien{
    protected:
        char mapt[30];
        char tuyenduong[30];
        int sohieu;
        int namsudung;
    public:
        void nhap(){
            cout<<"Nhap ma phuong tien: ";fflush(stdin);gets(mapt);
            cout<<"Nhap tuyen duong: ";fflush(stdin);gets(tuyenduong);
            cout<<"Nhap so hieu: ";cin>>sohieu;
            cout<<"Nhap nam su dung: ";cin>>namsudung;
        }    
        void xuat(){
            cout<<"Ma phuong tien: "<<mapt<<endl;
            cout<<"Tuyen duong: "<<tuyenduong<<endl;
            cout<<"So hieu: "<<sohieu<<endl;
            cout<<"Nam su dung: "<<namsudung<<endl;
        }
};
class xebus:public phuongtien{
    private:
        int socho;
        bool trogia;
    public:
        void nhap(){
            phuongtien::nhap();
            cout<<"Nhap so cho: ";cin>>socho;
            cout<<"Nhap tro gia (1: co, 0: khong): ";cin>>trogia;
            if(trogia==1){
                trogia=true;
                cout<<"Xe co tro gia"<<endl;
            }else{
                trogia=false;
                cout<<"Xe khong co tro gia"<<endl;
            }
        }
        void xuat(){
            phuongtien::xuat();
            cout<<"So cho: "<<socho<<endl;
            if(trogia==1){
                cout<<"Xe co tro gia"<<endl;
            }else{
                cout<<"Xe khong co tro gia"<<endl;
            }
        }
    friend void buschongoimax(qlyxe &q);
};
class taxi:public phuongtien{
    private:
        float sokmdachay;
        float giamocua;
    public:
        void nhap(){
            phuongtien::nhap();
            cout<<"Nhap so km da chay: ";cin>>sokmdachay;
            cout<<"Nhap gia mo cua: ";cin>>giamocua;
        }
        void xuat(){
            phuongtien::xuat();
            cout<<"So km da chay: "<<sokmdachay<<endl;
            cout<<"Gia mo cua: "<<giamocua<<endl;
        }
    friend void xoataxikmdachay(qlyxe &q);
};
class qlyxe{
    private:
        xebus *a;
        taxi *b;
        int n;
        int m;
    public:
        void nhap(){
            do{
                cout<<"Nhap so luong xe bus: ";cin>>n;
            }while(n<=0);
            a=new xebus[n];
            for(int i=0;i<n;i++){
                cout<<"Nhap thong tin xe bus thu "<<i+1<<":"<<endl;
                a[i].nhap();
            }
            do{
                cout<<"Nhap so luong taxi: ";cin>>m;
            }while(m<=0);
            b=new taxi[m];
            for(int i=0;i<m;i++){
                cout<<"Nhap thong tin taxi thu "<<i+1<<":"<<endl;
                b[i].nhap();
            }
        }
        void xuat(){
            cout<<"Danh sach xe bus:"<<endl;
            for(int i=0;i<n;i++){
                cout<<"Thong tin xe bus thu "<<i+1<<":"<<endl;
                a[i].xuat();
            }
            cout<<"Danh sach taxi:"<<endl;
            for(int i=0;i<m;i++){
                cout<<"Thong tin taxi thu "<<i+1<<":"<<endl;
                b[i].xuat();
            }
        }
        ~qlyxe(){
            delete[] a;
            delete[] b;
        }
    friend void buschongoimax(qlyxe &q);
    friend void xoataxikmdachay(qlyxe &q);
};
void buschongoimax(qlyxe &q){
    int maxcho=0;
    for(int i=0;i<q.n;i++){
        if(q.a[i].socho>maxcho){
            maxcho=q.a[i].socho;
        }
    }
    cout<<"Danh sach xe bus co so cho lon nhat:"<<endl;
    for(int i=0;i<q.n;i++){
        if(q.a[i].socho==maxcho){
            q.a[i].xuat();
        }
    }
}
void xoataxikmdachay(qlyxe &q){
    float maxkm;
    do{
        cout<<"Nhap so km da chay cua taxi can xoa: ";cin>>maxkm;
    }while(maxkm<=0);
    for(int i=0;i<q.m;i++){
        if(q.b[i].sokmdachay>=maxkm){
            for(int j=i;j<q.m-1;j++){
                q.b[j]=q.b[j+1];
            }
            q.m--;
            i--;
        }
    }
}
int main(){
    qlyxe q;
    q.nhap();
    q.xuat();
    buschongoimax(q);
    xoataxikmdachay(q);
    cout<<"Danh sach taxi sau khi xoa:"<<endl;
    q.xuat();
    return 0;
}