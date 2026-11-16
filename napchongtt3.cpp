#include <bits/stdc++.h>
using namespace std;
class mang{
    private:
        int n;
        float *value;
    public:
        mang(int n=0){
            this->n=n;
            value=nullptr;
        }
        ~mang(){
            if(value!=nullptr){
                delete[] value;
            }
        }
        friend istream& operator>>(istream &x,mang &y){
            cout<<"Nhap so phan tu trong mang: ";x>>y.n;
            if(y.value!=nullptr){
                delete[] y.value;
            }
            y.value=new float[y.n];
            for(int i=0;i<y.n;i++){
                cout<<"value["<<i<<"]= ";x>>y.value[i];
            }
            return x;
        }
        friend ostream& operator<<(ostream &x,const mang &y){
            for(int i=0;i<y.n;i++){
                x<<y.value[i]<<" ";
            }
            x<<endl;
            return x;
        }
        mang& operator ++(){
            for(int i=0;i<this->n;i++){
                for(int j=0;j<this->n-1-i;j++){
                    if(this->value[j]>this->value[j+1]){
                        swap(this->value[j],this->value[j+1]);
                    }
                }
            }
            return *this;
        }
        mang& operator --(){
            for(int i=0;i<this->n;i++){
                for(int j=0;j<this->n-1-i;j++){
                    if(this->value[j]<this->value[j+1]){
                        swap(this->value[j],this->value[j+1]);
                    }
                }
            }
            return *this;
        }
};
int main(){
    mang a;
    cin>>a;
    cout<<"Mang vua nhap: "<<a<<endl;
    ++a;
    cout<<"Mang tang dan: ";
    cout<<a<<endl;
    ofstream fileOut("mang.txt");
    if(fileOut.is_open()){
        fileOut<<"Mang tang dan: "<<a;
        cout<<"Mang tang dan da duoc ghi vao file mang.txt"<<endl;
        fileOut.close();
    }
    else{
        cout<<"Khong the mo file mang.txt de ghi du lieu!"<<endl;
    }
}