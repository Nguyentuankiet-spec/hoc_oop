#include <bits/stdc++.h>
using namespace std;
class HH{
    private:
        float dai,rong,cao;
    public:
        HH(){
            dai=0;
            rong=0;
            cao=0;
        }
        HH(float dai,float rong,float cao){
            this->dai=dai;
            this->rong=rong;
            this->cao=cao;
        }
    friend istream& operator>>(istream &a,HH &b){
        cout<<"Nhap dai: "; a>>b.dai;
        cout<<"Nhap rong: "; a>>b.rong;
        cout<<"Nhap cao: "; a>>b.cao;
        return a;
    }
    friend ostream& operator << (ostream& a,HH &b){
        a<<"Dai: "<<b.dai<<endl;
        a<<"Rong: "<<b.rong<<endl;
        a<<"Cao: "<<b.cao<<endl;
        return a;
    }
        float thetich(){
            return dai*rong*cao;
        }
        HH operator+(HH b){
            HH c;
            c.dai=dai+b.dai;
            c.rong=rong+b.rong;
            c.cao=cao+b.cao;
            return c;
        }
};
int main(){
    HH a,b(1,2,3),c;
    cout<<"Nhap thong tin hinh hop a: "<<endl;
    cin>>a;
    cout<<"Thong tin hinh hop a: "<<endl;
    cout<<a;
    cout<<"The tich hinh hop a: "<<a.thetich()<<endl;
    cout<<"Thong tin hinh hop b: "<<endl;
    cout<<b;
    cout<<"The tich hinh hop b: "<<b.thetich()<<endl;
    c=a+b;
    cout<<"Tong hinh hop a va hinh hop b: "<<endl;
    cout<<c;
    cout<<"The tich tong hinh hop: "<<c.thetich()<<endl;
    ofstream f;
    f.open("hinh_hop.txt",ios::out);
    f<<"Thong tin hinh hop a: "<<endl;
    f<<a;
    f<<"The tich hinh hop a: "<<a.thetich()<<endl;
    f<<"Thong tin hinh hop b: "<<endl;
    f<<b;
    f<<"The tich hinh hop b: "<<b.thetich()<<endl;
    f<<"Tong hinh hop a va hinh hop b: "<<endl;
    f<<c;
    f<<"The tich tong hinh hop: "<<c.thetich()<<endl;
    f.close();
}