#include <bits/stdc++.h>
using namespace std;
class phanso{
    private:
        int tuso;
        int mauso;
    public:
        friend istream &operator>>(istream &x,phanso &y){
            cout<<"Nhap tu so: ";
            x>>y.tuso;
            cout<<"Nhap mau so: ";
            x>>y.mauso;
            return x;
        }
        friend ostream &operator<<(ostream &x,phanso &y){
            x<<y.tuso<<"/"<<y.mauso;
            return x;
        }
        phanso(int a,int b){
            tuso=a;
            mauso=b;
        }
        phanso operator+(phanso y){
            phanso z(0,0);
            z.tuso=tuso*y.mauso+mauso*y.tuso;
            z.mauso=mauso*y.mauso;
            return z;
        }
        phanso operator-(phanso y){
            phanso z(0,0);
            z.tuso=tuso*y.mauso-mauso*y.tuso;
            z.mauso=mauso*y.mauso;
            return z;
        }
        phanso operator*(phanso y){
            phanso z(0,0);
            z.tuso=tuso*y.tuso;
            z.mauso=mauso*y.mauso;
            return z;
        }
        phanso operator/(phanso y){
            phanso z(0,0);
            z.tuso=tuso*y.mauso;
            z.mauso=mauso*y.tuso;
            return z;
        }
};
int main(){
    phanso a(0,0),b(0,0);
    cin>>a>>b;
    cout<<"Phan so a: "<<a<<endl;
    cout<<"Phan so b: "<<b<<endl;
    phanso c=a+b;   
    cout<<"Tong hai phan so: "<<c<<endl;
    c=a-b;
    cout<<"Hieu hai phan so: "<<c<<endl;
    c=a*b;
    cout<<"Tich hai phan so: "<<c<<endl;
    c=a/b;
    cout<<"Thuong hai phan so: "<<c<<endl;
    return 0;
}