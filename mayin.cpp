#include <bits/stdc++.h>
using namespace std;
class mayin{
    private:
        char ten[20];
        char mau[20];
        int sl;
        long gia;
    public:
        mayin(){
            strcpy(ten,"");
            strcpy(mau,"");
            sl=0;
            gia=0;
        }
        mayin(char *ten, char *mau, int sl, long gia){
            strcpy(this->ten,ten);
            strcpy(this->mau,mau);
            this->sl=sl;
            this->gia=gia;
        }
    friend istream &operator>>(istream &a, mayin &b){
        cout<<"Nhap ten may in: "; fflush(stdin); gets(b.ten);
        cout<<"Nhap mau sac: "; fflush(stdin); gets(b.mau);
        cout<<"Nhap so luong: "; a>>b.sl;
        cout<<"Nhap gia: "; a>>b.gia;
        return a;
    }
    friend ostream &operator<<(ostream &a, mayin b){
        a<<"Ten may in: "<<b.ten<<endl;
        a<<"Mau sac: "<<b.mau<<endl;
        a<<"So luong: "<<b.sl<<endl;
        a<<"Gia: "<<b.gia<<endl;
        return a;
    }
        mayin operator+(mayin b){
            mayin c;
            c.sl=sl+b.sl;
            return c;
        }
        bool operator--(){
            if(strcmp(mau,"Trang")==0&&gia>95){
                return true;
            }
            else{
                return false;
            }
        }
        bool operator > (mayin b){
            if(gia*sl>b.gia*b.sl){
                return true;
            }
            else{
                return false;
            }
        }
        char *getmau(){
            return mau;
        }
        int getsl(){
            return sl;
        }
};
int main(){
    mayin a,b("canon","Trang",10,100),c;
    cout<<"Nhap thong tin may in a: "<<endl;
    cin>>a;
    cout<<"Thong tin may in a: "<<endl;
    cout<<a;
    cout<<"Thong tin may in b: "<<endl;
    cout<<b;
    if(--a){
        cout<<"May in a co mau trang va gia lon hon 95"<<endl;
    }
    else{
        cout<<"May in a khong co mau trang hoac gia nho hon 95"<<endl;
    }
    if(--b){
        cout<<"May in b co mau trang va gia lon hon 95"<<endl;
    }
    else{
        cout<<"May in b khong co mau trang hoac gia nho hon 95"<<endl;
    }
    if(strcmp(a.getmau(),b.getmau())==0){
        cout<<"Hai may in cung mau"<<endl;
        c=a+b;
        cout<<"Tong so luong cua hai may in cung mau: "<<c.getsl()<<endl;
    }
    else{
        cout<<"Hai may in khac mau"<<endl;
    }
    ofstream f("mayin.txt",ios::out);
    f<<a;
    f<<b;
    if(--a){
        f<<"May in a co mau trang va gia lon hon 95"<<endl;
    }
    else{
        f<<"May in a khong co mau trang hoac gia nho hon 95"<<endl;
    }
    if(--b){
        f<<"May in b co mau trang va gia lon hon 95"<<endl;
    }
    else{
        f<<"May in b khong co mau trang hoac gia nho hon 95"<<endl;
    }
    if(strcmp(a.getmau(),b.getmau())==0){
        f<<"Hai may in cung mau"<<endl;
        c=a+b;
        f<<"Tong so luong cua hai may in cung mau: "<<c.getsl()<<endl;
    }
    else{
        f<<"Hai may in khac mau"<<endl;
    }
    f.close();
}