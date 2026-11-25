#include <bits/stdc++.h>
using namespace std;
class hh{
    private:
        char mah[10];
        char tenh[20];
        int sl;
        float gia;
    public:
    friend istream &operator>>(istream &a, hh &b){
        cout << "Nhap ma hang: ";  a>> b.mah;
        cout << "Nhap ten hang: "; a >> b.tenh;
        cout << "Nhap so luong: "; a >> b.sl;
        cout << "Nhap gia: "; a >> b.gia;
        return a;
    }
    friend ostream &operator<<(ostream &a, hh b){
        a << "Ma hang: " << b.mah << endl;
        a << "Ten hang: " << b.tenh << endl;
        a << "So luong: " << b.sl << endl;
        a << "Gia: " << b.gia << endl;
        a<<"Thanh tien: "<<b.sl*b.gia<<endl;
        return a;
    }
        hh(){
            strcpy(mah,"");
            strcpy(tenh,"");
            sl=0;
            gia=0;
        }
        hh(char *ma, char *ten, int s, float g){
            strcpy(mah,ma);
            strcpy(tenh,ten);
            sl=s;
            gia=g;
        }
        hh operator+(hh b){
            hh c;
            c.sl=sl+b.sl;
            return c;
        }
        bool operator>(hh b){
            return sl*gia> b.sl*b.gia;
        }
        char* getMah(){
            return mah;
        }
        int getSl(){
            return sl;
        }
};
int main(){
    hh a,b,c;
    cout<<"Nhap thong tin hang a: "<<endl;
    cin>>a;
    cout<<"Thong tin hang a: "<<endl;
    cout<< a;
    cout<<"Nhap thong tin hang b: "<<endl;
    cin>>b;
    cout<<"Thong tin hang b: "<<endl;
    cout<<b;
    if(strcmp(a.getMah(),b.getMah())==0){
        c=a+b;
        cout<<"Tong so luong hang a va hang b: "<<c.getSl()<<endl;
    }else{
        cout<<"Ma hang a va hang b khac nhau nen khong the cong so luong"<<endl;
    }
    if(a>b){
        cout<<"Hang a co thanh tien lon hon hang b"<<endl;
    }else{ 
        cout<<"Hang b co thanh tien lon hon hang a"<<endl;
    } 
}