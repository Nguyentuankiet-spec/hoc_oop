#include <bits/stdc++.h>
using namespace std;
class phanso{
    private:
        int tu,mau;
    public:
        phanso(){
            tu=mau=0;
        }
    friend istream& operator>>(istream &x,phanso &y){
        cout<<"Nhap tu so: "; x>>y.tu;
        cout<<"Nhap mau so: "; x>>y.mau;
        return x;
    }
    friend ostream& operator<<(ostream &x,phanso y){
        x<<y.tu<<"/"<<y.mau;
        return x;
    }
        phanso operator+(phanso y){
            phanso z;
            z.tu=tu*y.mau+mau*y.tu;
            z.mau=mau*y.mau;
            return z;
        }
        phanso operator-(phanso y){
            phanso z;
            z.tu=tu*y.mau-mau*y.tu;
            z.mau=mau*y.mau;
            return z;
        }
        phanso operator*(phanso y){
            phanso z;
            z.tu=tu*y.tu;
            z.mau=mau*y.mau;
            return z;
        }
        phanso operator/(phanso y){
            phanso z;
            z.tu=tu*y.mau;
            z.mau=mau*y.tu;
            return z;
        }
        float operator ++(){
            return 1.0*tu/mau;
        }
};
int main(){
    phanso P,Q;
    cout<<"Nhap phan so P: "<<endl;
    cin>>P;
    cout<<"Nhap phan so Q: "<<endl;
    cin>>Q;
    cout<<"Tong hai phan so la: "<<P+Q<<endl;
    cout<<"Hieu hai phan so la: "<<P-Q<<endl;
    cout<<"Tich hai phan so la: "<<P*Q<<endl;
    cout<<"Thuong hai phan so la: "<<P/Q<<endl;
    cout<<"Gia tri cua phan so P la: "<<++P<<endl;
    cout<<"Gia tri cua phan so Q la: "<<++Q<<endl;
}