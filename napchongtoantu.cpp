#include <bits/stdc++.h>
using namespace std;
class tamthucbac2{
    private:
        float a,b,c;
    public:
        tamthucbac2(float a=0,float b=0,float c=0){
            this->a=a;
            this->b=b;
            this->c=c;
        }
        friend istream& operator>>(istream &x,tamthucbac2 &y){
            cout<<"Nhap a: "; x>>y.a;
            cout<<"Nhap b: "; x>>y.b;
            cout<<"Nhap c: "; x>>y.c;
            return x;
        }
        friend ostream& operator<<(ostream &x,tamthucbac2 y){
            x<<"a= "<<y.a<<endl;
            x<<"b= "<<y.b<<endl;
            x<<"c= "<<y.c<<endl;
            return x;
        }
        tamthucbac2 operator -(){
            tamthucbac2 z;
            z.a=-this->a;
            z.b=-this->b;
            z.c=-this->c;
            return z;
        }
        tamthucbac2 operator +(tamthucbac2 y){
            tamthucbac2 z;
            z.a=this->a+y.a;
            z.b=this->b+y.b;
            z.c=this->c+y.c;
            return z;
        }
        tamthucbac2 operator -(tamthucbac2 y){
            tamthucbac2 z;
            z.a=this->a-y.a;
            z.b=this->b-y.b;
            z.c=this->c-y.c;
            return z;
        }
};
int main(){
    tamthucbac2 a,b,c,d,t,h;
    cin>>a;
    cout<<"Nhap tam thuc bac 2 a: "<<endl;
    cout<<a<<endl;
    cout<<"Nhap tam thuc bac 2 b: "<<endl;
    cin>>b;
    cout<<"Tam thuc bac 2 b: "<<endl;
    cout<<b<<endl;
    c=-a;
    d=-b;
    t=c+d;
    h=a+b;
    cout<<"Tong cua 2 tam thuc sau khi dao dau la: "<<endl;
    cout<<t<<endl;
    cout<<"Hieu cua 2 tam thuc sau khi dao dau la: "<<endl;
    cout<<h<<endl;
}    