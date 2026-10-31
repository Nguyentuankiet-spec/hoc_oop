#include <bits/stdc++.h>
using namespace std;
class ptb2{
    private:
        float a,b,c;
    public:
        ptb2(){
            a=0;
            b=0;
            c=0;
        }
        ptb2(float a,float b,float c){
            this->a=a;
            this->b=b;
            this->c=c;
        }
        ~ptb2(){
            a=0;
            b=0;
            c=0;
        }
        void nhap(){
            cout<<"Nhap he so a: ";
            cin>>a;
            cout<<"Nhap he so b: ";
            cin>>b;
            cout<<"Nhap he so c: ";
            cin>>c;
        }
        void xuat(){
            cout<<"Phuong trinh bac 2: "<<a<<"x^2 + "<<b<<"x + "<<c<<" =0"<<endl;
        }
        void giai(){
            if(a==0){
                if(b==0){
                    if(c==0){
                        cout<<"Phuong trinh co vo so nghiem"<<endl;
                    }else{
                        cout<<"Phuong trinh vo nghiem"<<endl;
                    }
                }else{
                    cout<<"Phuong trinh co 1 nghiem duy nhat x la: "<<-c/b<<endl;
                }
            }else{
                float delta=b*b-4*a*c;
                if(delta<0){
                    cout<<"Phuong trinh vo nghiem"<<endl;
                }if(delta==0){
                    cout<<"Phuong trinh co cap nghiem kep x la: "<<-b/2*a<<endl;
                }if(delta>0){
                    cout<<"Phuong trinh co 2 nghiem phan biet la: "<<endl;
                    cout<<"x1= "<<-b+sqrt(delta)/(2*a)<<endl;
                    cout<<"x2= "<<-b-sqrt(delta)/(2*a)<<endl;
                }
            }
        }
};
int main(){
    ptb2 pt;
    pt.nhap();
    pt.xuat();
    pt.giai();
}