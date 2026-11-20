#include <bits/stdc++.h>
using namespace std;
class dienthoai{
    private:
        char tenmay[20];
        char hangsx[20];
        int sl;
        long gia;
    public:
        dienthoai(){
            strcpy(tenmay," ");
            strcpy(hangsx," ");       
            sl = 0;
            gia = 0;
        }
        dienthoai(char *tenmay,char *hangsx,int sl,long gia){
            strcpy(this->tenmay,tenmay);
            strcpy(this->hangsx,hangsx);
            this->sl=sl;
            this->gia=gia;
        }
    friend istream& operator>>(istream &a,dienthoai &b){
        cout<<"Nhap ten may: "; fflush(stdin); gets(b.tenmay);
        cout<<"Nhap hang san xuat: "; fflush(stdin); gets(b.hangsx);
        cout<<"Nhap so luong: "; a>>b.sl;
        cout<<"Nhap gia: "; a>>b.gia;
        return a;
    }
    friend ofstream&operator<<(ofstream &a,dienthoai b){
        a<<"Ten may: "<<b.tenmay<<endl;
        a<<"Hang san xuat: "<<b.hangsx<<endl;
        a<<"So luong: "<<b.sl<<endl;
        a<<"Gia: "<<b.gia<<endl;
        return a;
    }
        dienthoai operator+(dienthoai b){
            dienthoai c;
            if(strcmp(hangsx,b.hangsx)==0){
                c.sl=sl+b.sl;
            }
            else{
                c.sl=sl;
            }   
            return c;
        }  
        bool operator--(){
            if(strcmp(hangsx,"Apple")==0&&gia>20000000){
                return true;
            }
            else{
                return false;
            }
        }
        bool operator > (dienthoai b){
            if(gia*sl>b.gia*b.sl){
                return true;
            }
            else{
                return false;
            }
        }
        int getsl(){
            return sl;
        }
        long getgia(){
            return gia;
        }
        char *gethangsx(){
            return hangsx;
        }
};
int main(){
    dienthoai a,b("apple","Apple",5,25000000),c;
    cout<<"Nhap thong tin dien thoai a: "<<endl;
    cin>>a;
    if(--a){
        cout<<"Dien thoai a la hang Apple va gia lon hon 20 trieu!"<<endl;
    }
    else{
        cout<<"Dien thoai a khong phai hang Apple hoac gia nho hon 20 trieu!"<<endl;
    }
    if(--b){
        cout<<"Dien thoai b la hang Apple va gia lon hon 20 trieu!"<<endl;
    }
    else{
        cout<<"Dien thoai b khong phai hang Apple hoac gia nho hon 20 trieu!"<<endl;
    }
    if(a>b){
        cout<<"Dien thoai a co gia tri lon hon dien thoai b!"<<endl;
    }
    else{
        cout<<"Dien thoai a co gia tri nho hon dien thoai b!"<<endl;
    }
    if(strcmp(a.gethangsx(),b.gethangsx())==0){
        c=a+b;
        cout<<"Tong so luong dien thoai a va b la: "<<c.getsl()<<endl;
    }
    else{
        cout<<"Dien thoai a va b khong cung hang san xuat!"<<endl;
    }
}