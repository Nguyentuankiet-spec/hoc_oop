#include <bits/stdc++.h>
using namespace std;
class qlyxe;
class phuongtien{
    protected:
        char mapt[30];
        char tenpt[30];
        char hangsx[30];
        int d,m,y;
    public:
        void nhap(){
            cout<<"Nhap ma phuong tien: ";fflush(stdin);gets(mapt);
            cout<<"Nhap ten phuong tien: ";fflush(stdin);gets(tenpt);
            cout<<"Nhap hang san xuat: ";fflush(stdin);gets(hangsx);
            cout<<"Nhap ngay san xuat (dd mm yyyy): ";cin>>d>>m>>y;
        }    
        void xuat(){
            cout<<"Ma phuong tien: "<<mapt<<endl;
            cout<<"Ten phuong tien: "<<tenpt<<endl;
            cout<<"Hang san xuat: "<<hangsx<<endl;
            cout<<"Ngay san xuat: "<<d<<"/"<<m<<"/"<<y<<endl;
        }
    friend void sapxepnamsx(qlyxe &c);
};
class xedap:public phuongtien{
    private:
        float kichcobanh;
    public:
        void nhap(){
            phuongtien::nhap();
            cout<<"Nhap kich co banh: ";cin>>kichcobanh;
        }
        void xuat(){
            phuongtien::xuat();
            cout<<"Kich co banh: "<<kichcobanh<<endl;
        }
    friend void xoaxedap(qlyxe &c);
};
class xemotor:public phuongtien{
    private:
        int phankhoi;
        int tocdomax;
    public:
        void nhap(){
            phuongtien::nhap();
            cout<<"Nhap phan khoi: ";cin>>phankhoi;
            cout<<"Nhap toc do max: ";cin>>tocdomax;
        }
        void xuat(){
            phuongtien::xuat();
            cout<<"Phan khoi: "<<phankhoi<<endl;
            cout<<"Toc do max: "<<tocdomax<<endl;
        }
    friend void phankhoihon150(qlyxe &c);
};
class qlyxe{
    private:
        xedap *a;
        xemotor *b;
        int n,m;
    public:
        void nhap(){
            do{
                cout<<"Nhap so luong xe dap: ";cin>>n;
            }while(n<=0);
            do{
                cout<<"Nhap so luong xe motor: ";cin>>m;
            }while(m<=0);
            a=new xedap[n];
            b=new xemotor[m];
            for(int i=0;i<n;i++){
                cout<<"Nhap thong tin xe dap thu "<<i+1<<endl;
                a[i].nhap();
            }
            for(int i=0;i<m;i++){
                cout<<"Nhap thong tin xe motor thu "<<i+1<<endl;
                b[i].nhap();
            }
        }    
        void xuat(){
            cout<<"Danh sach xe dap: "<<endl;
            for(int i=0;i<n;i++){
                a[i].xuat();
            }
            cout<<"Danh sach xe motor: "<<endl;
            for(int i=0;i<m;i++){
                b[i].xuat();
            }
        }
        ~qlyxe(){
            delete[] a;
            delete[] b;
        }
    friend void xoaxedap(qlyxe &c);
    friend void phankhoihon150(qlyxe &c);
    friend void sapxepnamsx(qlyxe &c);
};
void phankhoihon150(qlyxe &c){
    for(int i=0;i<c.m;i++){
        if(c.b[i].phankhoi>150){
            c.b[i].xuat();
        }
    }
}
void sapxepnamsx(qlyxe &c){
    for(int i=0;i<c.n-1;i++){
        for(int j=i+1;j<c.n;j++){
            if(c.a[i].y>c.a[j].y){
                swap(c.a[i],c.a[j]);
            }
        }
    }
    for(int i=0;i<c.m-1;i++){
        for(int j=i+1;j<c.m;j++){
            if(c.b[i].y>c.b[j].y){
                swap(c.b[i],c.b[j]);
            }
        }
    }
}
void xoaxedap(qlyxe &c){
    int kt;
    cout<<"Nhap kich thuoc banh can xoa: ";cin>>kt;
    for(int i=0;i<c.n;i++){
        if(c.a[i].kichcobanh<=kt){
            for(int j=i;j<c.n-1;j++){
                c.a[j]=c.a[j+1];
            }
            c.n--;
            i--;
        }
    }
}
int main(){
    qlyxe c;
    c.nhap();
    c.xuat();
    cout<<"Danh sach xe motor co phan khoi > 150: "<<endl;
    phankhoihon150(c);
    cout<<"Danh sach xe sau khi sap xep theo nam san xuat: "<<endl;
    sapxepnamsx(c);
    c.xuat();
    xoaxedap(c);
    cout<<"Danh sach xe sau khi xoa xe dap co kich thuoc banh nho hon hoac bang kich thuoc nhap vao: "<<endl;
    c.xuat();
}