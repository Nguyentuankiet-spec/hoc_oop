#include <bits/stdc++.h>
using namespace std;
class qly;
class thietbi{
    protected:
        char maTB[10];
        char tenTB[30];
        int namsx;
        long gia;
    public:
        void nhap(){
            cout << "Nhap ma thiet bi: "; fflush(stdin); gets(maTB);
            cout << "Nhap ten thiet bi: "; fflush(stdin); gets(tenTB);
            cout << "Nhap nam san xuat: "; cin >> namsx;
            cout << "Nhap gia: "; cin >> gia;
        }
        void xuat(){
            cout << "Ma thiet bi: " << maTB << endl;
            cout << "Ten thiet bi: " << tenTB << endl;
            cout << "Nam san xuat: " << namsx << endl;
            cout << "Gia: " << gia << endl;
        }
    friend void sapxep(qly &q);
};
class maytinh:public thietbi{
    private:
        char cpu[20];
        int ram;
        char card[20];
    public:
        void nhap(){
            thietbi::nhap();
            cout << "Nhap CPU: "; fflush(stdin); gets(cpu);
            cout << "Nhap RAM: "; cin >> ram;
            cout << "Nhap card man hinh: "; fflush(stdin); gets(card);
        }
        void xuat(){
            thietbi::xuat();
            cout << "CPU: " << cpu << endl;
            cout << "RAM: " << ram << endl;
            cout << "Card man hinh: " << card << endl;
        }    
    friend void maxram(qly q);
};
class dienthoai:public thietbi{
    private:
        int dungluongpin;
        bool co5g;
    public:
        void nhap(){
            thietbi::nhap();
            cout << "Nhap dung luong pin: "; cin >> dungluongpin;
            cout << "Co ho tro 5G (1: Co, 0: Khong): "; cin >> co5g;
        }
        void xuat(){
            thietbi::xuat();
            cout << "Dung luong pin: " << dungluongpin << endl;
            cout << "Co ho tro 5G: " << (co5g ? "Co" : "Khong") << endl;
        }
    friend void sapxep(qly &q);
};
class qly{
    private:
        maytinh *a;
        dienthoai *b;
        int n, m;
    public:
        void nhap(){
            do{
                cout << "Nhap so luong may tinh: "; cin >> n;
            } while(n <= 0);
            a = new maytinh[n];
            for(int i = 0; i < n; i++){
                cout << "Nhap thong tin may tinh thu " << i + 1 << ":\n";
                a[i].nhap();
            }
            do{
                cout << "Nhap so luong dien thoai: "; cin >> m;
            } while(m <= 0);
            b = new dienthoai[m];
            for(int i = 0; i < m; i++){
                cout << "Nhap thong tin dien thoai thu " << i + 1 << ":\n";
                b[i].nhap();
            }
        }
        void xuat(){
            cout << "Danh sach may tinh:\n";
            for(int i = 0; i < n; i++){
                cout << "Thong tin may tinh thu " << i + 1 << ":\n";
                a[i].xuat();
            }
            cout << "Danh sach dien thoai:\n";
            for(int i = 0; i < m; i++){
                cout << "Thong tin dien thoai thu " << i + 1 << ":\n";
                b[i].xuat();
            }
        }
        ~qly(){
            delete[] a;
            delete[] b;
        }
    friend void maxram(qly q);
    friend void sapxep(qly &q);
};
void maxram(qly q){
    int maxRam = 0;
    for(int i = 0; i < q.n; i++){
        if(q.a[i].ram > maxRam){
            maxRam = q.a[i].ram;
        }
    }
    cout << "Cac may tinh co RAM lon nhat (" << maxRam << " GB):\n";
    for(int i = 0; i < q.n; i++){
        if(q.a[i].ram == maxRam){
            q.a[i].xuat();
        }
    }
}
void sapxep(qly &q){
    for(int i = 0; i < q.n - 1; i++){
        for(int j = i + 1; j < q.n; j++){
            if(q.a[i].gia > q.a[j].gia){
                swap(q.a[i], q.a[j]);
            }
        }
    }
    for(int i = 0; i < q.m - 1; i++){
        for(int j = i + 1; j < q.m; j++){
            if(q.b[i].gia > q.b[j].gia){
                swap(q.b[i], q.b[j]);
            }
        }
    }
    cout << "Danh sach may tinh sau khi sap xep theo gia tang dan:\n";
    for(int i = 0; i < q.n; i++){
        q.a[i].xuat();
    }
    cout << "Danh sach dien thoai sau khi sap xep theo gia tang dan:\n";
    for(int i = 0; i < q.m; i++){
        q.b[i].xuat();
    }
}
int main(){
    qly q;
    q.nhap();
    q.xuat();
    maxram(q);
    sapxep(q);
    return 0;
}