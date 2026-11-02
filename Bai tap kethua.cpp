#include <bits/stdc++.h>
using namespace std;
class khoa{
    private:
        char makhoa[30];
        char tenkhoa[30];
        char truongkhoa[30];
    public:
        void nhap(){
            cout<<"Nhap ma khoa: ";fflush(stdin);gets(makhoa);
            cout<<"Nhap ten khoa: ";fflush(stdin);gets(tenkhoa);
            cout<<"Nhap truong khoa: ";fflush(stdin);gets(truongkhoa);
        }
        void xuat(){
            cout<<"Ma khoa: "<<makhoa<<endl;
            cout<<"Ten khoa: "<<tenkhoa<<endl;
            cout<<"Truong khoa: "<<truongkhoa<<endl;
        }    
};
class ban{
    private:
        char maban[30];
        char tenban[30];
        int d,m,y;
    public:
        void nhap(){
            cout<<"Nhap ma ban: ";fflush(stdin);gets(maban);
            cout<<"Nhap ten ban: ";fflush(stdin);gets(tenban);
            cout<<"Nhap ngay thanh lap: ";cin>>d>>m>>y;
        }
        void xuat(){
            cout<<"Ma ban: "<<maban<<endl;
            cout<<"Ten ban: "<<tenban<<endl;
            cout<<"Ngay thanh lap: "<<d<<"/"<<m<<"/"<<y<<endl;
        }    
};
class truongdh{
    private:
        khoa x[100];
        int n;
        ban y[100];
        int m;
    public:
        void nhap(){
            do{
                cout<<"Nhap so luong khoa: ";cin>>n;
            }while(n<=0);
            for(int i=0;i<n;i++){
                cout<<"Nhap thong tin khoa thu "<<i+1<<endl;
                x[i].nhap();
            }
            do{
                cout<<"Nhap so luong ban: ";cin>>m;
            }while(m<=0);
            for(int i=0;i<m;i++){
                cout<<"Nhap thong tin ban thu "<<i+1<<endl;
                y[i].nhap();
            }
        }
        void xuat(){
            cout<<"Thong tin cac khoa: "<<endl;
            for(int i=0;i<n;i++){
                cout<<"Khoa thu "<<i+1<<endl;
                x[i].xuat();
            }
            cout<<"Thong tin cac ban: "<<endl;
            for(int i=0;i<m;i++){
                cout<<"Ban thu "<<i+1<<endl;
                y[i].xuat();
            }
        }
};
class truong:public truongdh{
    private:
        char matruong[30];
        char tentruong[30];
        char diachi[30];
    public:
        void nhap(){
            cout<<"Nhap ma truong: ";fflush(stdin);gets(matruong);
            cout<<"Nhap ten truong: ";fflush(stdin);gets(tentruong);
            cout<<"Nhap dia chi: ";fflush(stdin);gets(diachi);
            truongdh::nhap();
        }
        void xuat(){
            cout<<"Ma truong: "<<matruong<<endl;
            cout<<"Ten truong: "<<tentruong<<endl;
            cout<<"Dia chi: "<<diachi<<endl;
            truongdh::xuat();
        }
};
int main(){
    truong a;
    a.nhap();
    a.xuat();
    return 0;
}