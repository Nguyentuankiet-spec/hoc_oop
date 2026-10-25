#include <bits/stdc++.h>
using namespace std;
class date{
    private:
        int d,m,y;
    public:
         friend class hang;
};
class hang{
    private:    
        char mah[30];
        char tenh[30];
        date ngaysx;
    public:
        void nhap(){
            cout<<"Nhap ma hang: ";fflush(stdin);cin.getline(mah,30);
            cout<<"Nhap ten hang: ";fflush(stdin);cin.getline(tenh,30);
            cout<<"Nhap ngay thang nam san xuat: "<<endl;
            cout<<"Ngay: ";cin>>ngaysx.d;
            cout<<"Thang; ";cin>>ngaysx.m;
            cout<<"Nam: ";cin>>ngaysx.y;
        }
        void xuat(){
            if(ngaysx.y==2017){
                cout<<"Ma hang: "<<mah<<endl;
                cout<<"Ten hang: "<<tenh<<endl;
                cout<<"Nhap ngay thang nam san xuat: "<<endl;
                cout<<"Ngay: "<<ngaysx.d<<endl;
                cout<<"Thang: "<<ngaysx.m<<endl;
                cout<<"Nam: "<<ngaysx.y<<endl;
            }else{
                cout<<"Khong khong phai mat hang san xuat vao nam 2017.";
            }    
        }
};
int main(){
    int n;
    do{
        cout<<"Nhap n:";cin>>n;
    }while (n<=0);
    hang a[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap mat hang thu "<<i+1<<": ";a[i].nhap();
    }
    for(int i=0;i<n;i++){
        cout<<"Mat hang thu "<<i+1<<": ";a[i].xuat();cout<<endl;
    }
}