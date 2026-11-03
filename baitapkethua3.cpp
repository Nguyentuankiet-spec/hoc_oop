#include <bits/stdc++.h>
using namespace std;
 class nguoi{
    protected:
        char heten[30];
        int tuoi;
    public:
        void nhap(){
            cout<<"Nhap ho ten: "; fflush(stdin); gets(heten);
            cout<<"Nhap tuoi: "; cin>>tuoi;
        }
        void xuat(){
            cout<<"Ho ten: "<<heten<<endl;
            cout<<"Tuoi: "<<tuoi<<endl;
        }    
 };
 class benhvien{
    private:
        char tenbv[30];
        char diachi[30];
        nguoi giamdoc; 
        friend class benhnhan;  
 };
 class benhnhan:public nguoi{
    private:
        char ma[10];
        char tieusu[100];
        char chandoan[100];
        benhvien bv;
    public:
        void nhap(){    
            nguoi::nhap();
            cout<<"Nhap ma benh nhan: "; fflush(stdin); gets(ma);
            cout<<"Nhap tieu su: "; fflush(stdin); gets(tieusu);
            cout<<"Nhap chan doan: "; fflush(stdin); gets(chandoan);
            cout<<"Nhap thong tin benh vien: "<<endl;
            cout<<"Nhap ten benh vien: "; fflush(stdin); gets(bv.tenbv);
            cout<<"Nhap dia chi benh vien: "; fflush(stdin); gets(bv.diachi);
            cout<<"Nhap thong tin giam doc benh vien: "<<endl;
            bv.giamdoc.nhap();
        }
        void xuat(){
            nguoi::xuat();
            cout<<"Ma benh nhan: "<<ma<<endl;
            cout<<"Tieu su: "<<tieusu<<endl;
            cout<<"Chan doan: "<<chandoan<<endl;
            cout<<"Thong tin benh vien: "<<endl;
            cout<<"Ten benh vien: "<<bv.tenbv<<endl;
            cout<<"Dia chi benh vien: "<<bv.diachi<<endl;
            cout<<"Thong tin giam doc benh vien: "<<endl;
            bv.giamdoc.xuat();
        }    
    friend int lonhon30(benhnhan *a,int n);
    friend void suattin(benhnhan *a,int n);
 };
 int lonhon30(benhnhan *a,int n){
    int dem=0;
    for(int i=0;i<n;i++){
        if(a[i].tuoi>30){
            dem++;
        }
    }
    return dem;
 }
 void suattin(benhnhan *a,int n){
    for(int i=0;i<n;i++){
        if(strcmp(a[i].ma,"BN01")==0){
            a[i].tuoi=20;
        }
    }
 }
int main(){
    benhnhan *a;
    int n;
    do{
        cout<<"Nhap so luong benh nhan: ";cin>>n;
    }while(n<=0);
    a=new benhnhan[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin benh nhan thu "<<i+1<<endl;
        a[i].nhap();
    }
    cout<<"Thong tin cac benh nhan: "<<endl;
    for(int i=0;i<n;i++){
        a[i].xuat();
    }
    cout<<"So benh nhan tren 30 tuoi: "<<lonhon30(a,n)<<endl;
    suattin(a,n);
    cout<<"Thong tin sau khi sua: "<<endl;
    for(int i=0;i<n;i++){
        a[i].xuat();
    }
    delete[] a;
}