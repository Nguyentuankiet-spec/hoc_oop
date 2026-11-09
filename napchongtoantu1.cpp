#include <bits/stdc++.h>
using namespace std;
class sophuc{
    private:
        float thuc;
        float ao;
    public:
        friend istream &operator>>(istream &x,sophuc &y){
            cout<<"Nhap phan thuc: ";
            x>>y.thuc;
            cout<<"nhap phan ao: ";
            x>>y.ao;
            return x;
        }
        friend ostream &operator<<(ostream &x,sophuc &y){
            x<<y.thuc<<" + "<<y.ao<<"i";
            return x;
        }
        sophuc(float a,float b){
            thuc=a;
            ao=b;
        }
        sophuc operator+(sophuc y){
            sophuc z(0,0);
            z.thuc=thuc+y.thuc;
            z.ao=ao+y.ao;
            return z;
        }
        sophuc operator-(sophuc y){
            sophuc z(0,0);
            z.thuc=thuc-y.thuc;
            z.ao=ao-y.ao;
            return z;
        }
};
int main(){
    sophuc a(0,0),b(0,0);
    cin>>a>>b;
    cout<<"So phuc a: "<<a<<endl;
    cout<<"So phuc b: "<<b<<endl;
    sophuc c=a+b;   
    cout<<"Tong hai so phuc: "<<c<<endl;
    c=a-b;
    cout<<"Hieu hai so phuc: "<<c<<endl;
    return 0;
}