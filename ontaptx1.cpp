#include<bits/stdc++.h>
using namespace std;
class xemay{
    private:
        char maxe[20],tenxe[20];
        float dungtich;
        long gia;
    public:
        void nhap(){
            cout<<"Nhap ma xe: ";fflush(stdin);gets(maxe);
            cout<<"Nhap ten xe: ";fflush(stdin);gets(tenxe);
            cout<<"Nhap dung tich: ";cin>>dungtich;
            cout<<"Nhap gia: ";cin>>gia;
        }
        void xuat(){
            cout<<"Ma xe: "<<maxe<<endl;
            cout<<"Ten xe: "<<tenxe<<endl;
            cout<<"Dung tich: "<<dungtich<<endl;
            cout<<"Gia: "<<gia<<endl;
        }
    friend void getmaxgia(xemay *a,int n);
};
void getmaxgia(xemay *a,int n){
    long maxgia;
    maxgia=a[0].gia;
    for(int i=0;i<n;i++){
        if(a[i].gia>maxgia){
            maxgia=a[i].gia;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i].gia==maxgia){
            cout<<"Thong tin xe may co gia cao nhat: "<<endl;
            a[i].xuat();
        }
    }
}
void nhapds(xemay *a,int n){
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin xe may thu: "<<i+1<<endl;
        a[i].nhap();
    }
}
void xuatds(xemay *a,int n){
    for(int i=0;i<n;i++){
        cout<<"Thong tin xe may thu: "<<i+1<<endl;
        a[i].xuat();
    }
}
int main(){
    int n;
    do{
        cout<<"Nhap so luong xe may: ";cin>>n;
    }while(n<=0);
    xemay *a=new xemay[n];
    nhapds(a,n);
    xuatds(a,n);
    getmaxgia(a,n);
    delete[] a;
}