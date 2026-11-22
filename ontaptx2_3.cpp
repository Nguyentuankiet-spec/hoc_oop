#include <bits/stdc++.h>
using namespace std;
class Vector{
    private:
        float x,y,z;
    public:
        Vector(){
            x=0;
            y=0;
            z=0;
        }
        Vector(float x,float y,float z){
            this->x=x;
            this->y=y;
            this->z=z;
        }
    friend istream& operator>>(istream &a,Vector &b){
        cout<<"Nhap x: "; a>>b.x;
        cout<<"Nhap y: "; a>>b.y;
        cout<<"Nhap z: "; a>>b.z;
        return a;
    }
    friend ostream& operator << (ostream& a,Vector &b){
        a<<"x: "<<b.x<<endl;
        a<<"y: "<<b.y<<endl;
        a<<"z: "<<b.z<<endl;
        return a;
    }
         Vector operator+(Vector b){
            Vector c;
            c.x=x+b.x;
            c.y=y+b.y;
            c.z=z+b.z;
            return c;
        }
        bool operator > (Vector b){
            if(x>b.x&&y>b.y&&z>b.z){
                return true;
            }
            else{
                return false;
            }
        }
};
int main(){
    Vector a,b(1,2,3),c;
    cout<<"Nhap thong tin vector a: "<<endl;
    cin>>a;
    cout<<"Thong tin vector a: "<<endl;
    cout<<a;
    cout<<"Thong tin vector b: "<<endl;
    if(a>b){
        cout<<"Vector a lon hon vector b"<<endl;
    }
    else{
        cout<<"Vector a nho hon vector b"<<endl;
    }
    c=a+b;
    cout<<"Tong vector a va vector b: "<<endl;
    cout<<c;
    ofstream f;
    f.open("vector.txt",ios::out);
    f<<a;
    f<<b;
    if(a>b){
        f<<"Vector a lon hon vector b"<<endl;
    }
    else{
        f<<"Vector a nho hon vector b"<<endl;
    }
    c=a+b;
    f<<"Tong vector a va vector b: "<<endl;
    f<<c;
    f.close();
}