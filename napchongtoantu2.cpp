#include <bits/stdc++.h>
using namespace std;
class matran{
    private:
        double a[100][100];
        int m,n;
    public:
        matran(int m=0,int n=0){
            this->m=m;
            this->n=n;
        }
        friend istream& operator>>(istream& x,matran &y){
            cout<<"Nhap so hang: "; x>>y.m;
            cout<<"Nhap so cot: ";x>>y.n;
            for(int i=0;i<y.m;i++){
                for(int j=0;j<y.n;j++){
                    cout<<"a["<<i<<"]["<<j<<"]= "; x>>y.a[i][j];
                }
            }
            return x;
        }
        friend ostream& operator<<(ostream& x,matran& y){
            for(int i=0;i<y.m;i++){
                for(int j=0;j<y.n;j++){
                    x<<y.a[i][j]<<" ";
                }
                x<<endl;
            }
            return x;
        }
        matran operator -(){
            matran z;
            z.m=this->m;
            z.n=this->n;
            for(int i=0;i<z.m;i++){
                for(int j=0;j<z.n;j++){
                    z.a[i][j]=-this->a[i][j];
                }
            }
            return z;
        }
        matran operator +(matran y){
            matran z;
            z.m=this->m;
            z.n=this->n;
            if(this->m!=y.m || this->n!=y.n){
                cout<<"Khong the cong 2 ma tran"<<endl;
                return z;
            }if(this->m==y.m && this->n==y.n){
                for(int i=0;i<z.m;i++){
                    for(int j=0;j<z.n;j++){
                        z.a[i][j]=this->a[i][j]+y.a[i][j];
                    }
                }
            }
            return z;
        }
        matran operator -(matran y){
            matran z;
            z.m=this->m;
            z.n=this->n;
            if(this->m!=y.m || this->n!=y.n){
                cout<<"Khong the tru 2 ma tran"<<endl;
                return z;
            }if(this->m==y.m && this->n==y.n){
                for(int i=0;i<z.m;i++){
                    for(int j=0;j<z.n;j++){
                        z.a[i][j]=this->a[i][j]-y.a[i][j];
                    }
                }
            }
            return z;
        }
};
int main(){
    matran a,b,c;
    cout<<"Nhap ma tran a: "<<endl;
    cin>>a;
    cout<<"Ma tran a: "<<endl;
    cout<<a;
    b=-a;
    cout<<"Ma tran b: "<<endl;
    cout<<b;
    c=a+b;
    cout<<"Tong 2 ma tran: "<<endl;
    cout<<c;
    c=a-b;
    cout<<"Hieu 2 ma tran: "<<endl;
    cout<<c;
    return 0;
}