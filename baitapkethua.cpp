#include <bits/stdc++.h>
using namespace std;
class student;
class school{
    private:
        char name[30];
        int d,m,y;
    friend class fac;    
    friend class student;
    friend void sua(student &s);
};
class fac{
    private:
        char name[30];
        int d,m,y;
        school x;
    public:
        void nhap(){
            cout<<"Nhap ten truong: ";fflush(stdin);gets(x.name);
            cout<<"Nhap ngay thanh lap: ";cin>>x.d>>x.m>>x.y;
            cout<<"Nhap ten khoa: ";fflush(stdin);gets(name);
            cout<<"Nhap ngay thanh lap: ";cin>>d>>m>>y;
        }
        void xuat(){
            cout<<"Ten truong: "<<x.name<<endl;
            cout<<"Ngay thanh lap: "<<x.d<<"/"<<x.m<<"/"<<x.y<<endl;
            cout<<"Ten khoa: "<<name<<endl;
            cout<<"Ngay thanh lap: "<<d<<"/"<<m<<"/"<<y<<endl;
        }
    friend void sua(student &s);    
};
class person{
    protected:
        char name[30];
        int d,m,y;
        char address[30];
    public:
        void nhap(){
            cout<<"Nhap ten: ";fflush(stdin);gets(name);
            cout<<"Nhap ngay sinh: ";cin>>d>>m>>y;
            cout<<"Nhap dia chi: ";fflush(stdin);gets(address);
        }
        void xuat(){
            cout<<"Ten: "<<name<<endl;
            cout<<"Ngay sinh: "<<d<<"/"<<m<<"/"<<y<<endl;
            cout<<"Dia chi: "<<address<<endl;
        }
        person(){
            strcpy(name,"");
            d=0;
            m=0;
            y=0;
            strcpy(address,"");
        } 
};
class student:public person{
    private:
        fac y;
        char lop[30];
        float score;
    public:
        void nhap(){
            person::nhap();
            y.nhap();
            cout<<"Nhap lop: ";fflush(stdin);gets(lop);
            cout<<"Nhap diem: ";cin>>score;
        }
        void xuat(){
            person::xuat();
            y.xuat();
            cout<<"Lop: "<<lop<<endl;
            cout<<"Diem: "<<score<<endl;
        }
        student():person(){
            strcpy(lop,"");
            score=0;
        }
    friend void sua(student &s);    
};
void sua(student &s){
    strcpy(s.y.x.name,"DHCNHN");
}
int main(){
    student s;
    s.nhap();
    s.xuat();
    cout<<"Sua ten truong: "<<endl;
    sua(s);
    s.xuat();
}