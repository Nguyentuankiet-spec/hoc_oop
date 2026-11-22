#include <bits/stdc++.h>
using namespace std;
class tl{
    private:
        char ten[20];
        char mau[20];
        long gia;
    public:
        tl(){
            strcpy(ten," ");
            strcpy(mau," ");       
            gia = 0;
        }
        tl(char *ten,char *mau,long gia){
            strcpy(this->ten,ten);
            strcpy(this->mau,mau);
            this->gia=gia;
        }
    friend istream& operator>>(istream& a,tl &b){
        cout<<"Nhap ten: "; fflush(stdin); gets(b.ten);
        cout<<"Nhap mau: "; fflush(stdin); gets(b.mau);
        cout<<"Nhap gia: "; a>>b.gia;
        return a;
    }
    friend ostream& operator<<(ostream &a,tl &b){
        a<<"Ten: "<<b.ten<<endl;
        a<<"Mau: "<<b.mau<<endl;
        a<<"Gia: "<<b.gia<<endl;
        return a;
    }
        bool operator !(){
            if(strcmp(mau,"Trang")==0&&gia>250){
                return true;
            }
            else{
                return false;
            }
        }
        tl operator+(tl b){
            tl c;
            if(strcmp(ten,b.ten)==0){
                c.gia=gia+b.gia;
            }
            else{
                c.gia=gia;
            }
            return c;
        }
        bool operator > (tl b){
            if(strcmp(ten,b.ten)==0&&gia==b.gia&&strcmp(mau,b.mau)==0){
                return true;
            }
            else{
                return false;
            }
        }
        char* getten(){
            return ten;
        }
        long getgia(){
            return gia;
        }
};
int main(){
    tl a,b("Sony","Trang",300),c;
    cout<<"Nhap thong tin tu lanh a: "<<endl;
    cin>>a;
    cout<<"Thong tin tu lanh a: "<<endl;
    cout<<a;
    if(!a){
        cout<<"Tu lanh a mau trang va gia > 250"<<endl;
    }
    else{
        cout<<"Tu lanh a khong thoa man dieu kien"<<endl;
    }
    if(!b){
        cout<<"Tu lanh b mau trang va gia > 250"<<endl;
    }
    else{
        cout<<"Tu lanh b khong thoa man dieu kien"<<endl;
    }
    if(strcmp(a.getten(),b.getten())==0){
        c=a+b;
        cout<<"Tong gia cua 2 tu lanh: "<<c.getgia()<<endl;
    }
    if(a>b){
        cout<<"2 tu lanh giong nhau"<<endl;
    }
    else{
        cout<<"2 tu lanh khac nhau"<<endl;
    }
    ofstream f;
    f.open("tu_lanh.txt",ios::out);
    f<<"Thong tin tu lanh a: "<<endl;
    f<<a;
    f<<"Thong tin tu lanh b: "<<endl;
    f<<b;
    if(!a){
        f<<"Tu lanh a mau trang va gia > 250"<<endl;
    }
    else{
        f<<"Tu lanh a khong thoa man dieu kien"<<endl;
    }
    if(!b){
        f<<"Tu lanh b mau trang va gia > 250"<<endl;
    }
    else{
        f<<"Tu lanh b khong thoa man dieu kien"<<endl;
    }
    if(strcmp(a.getten(),b.getten())==0){
        c=a+b;
        f<<"Tong gia cua 2 tu lanh: "<<c.getgia()<<endl;
    }
    if(a>b){
        f<<"2 tu lanh giong nhau"<<endl;
    }
    else{
        f<<"2 tu lanh khac nhau"<<endl;
    }
    f.close();
}