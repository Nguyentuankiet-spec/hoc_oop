#include <bits/stdc++.h>
using namespace std;
class tamgiac{
    private:
        float a,b,c;
    public:
        tamgiac(){
            a=b=c=0;
        }
    friend istream& operator>>(istream &x,tamgiac &y){
        cout<<"Nhap canh a: "; x>>y.a;
        cout<<"Nhap canh b: "; x>>y.b;
        cout<<"Nhap canh c: "; x>>y.c;
        return x;
    }
    friend ostream& operator<<(ostream &x,tamgiac y){
        x<<"Canh a= "<<y.a<<endl;
        x<<"Canh b= "<<y.b<<endl;
        x<<"Canh c= "<<y.c<<endl;
        return x;
    }
        float operator ++(){
            return a+b+c;
        }
};
int main(){
    tamgiac P,Q;
    cout<<"Nhap tam giac P: "<<endl;
    cin>>P;
    cout<<"Nhap tam giac Q: "<<endl;
    cin>>Q;
    cout<<"Chu vi tam giac P la: "<<++P<<endl;
    cout<<"Chu vi tam giac Q la: "<<++Q<<endl;
    ofstream f("INOUT.txt");
    f<<"Tam giac P: "<<endl;
    f<<P;
    f<<"Tam giac Q: "<<endl;
    f<<Q;
    f<<"Chu vi tam giac P la: "<<++P<<endl;
    f<<"Chu vi tam giac Q la: "<<++Q<<endl;
    f.close();
}