#include <iostream>
#include <memory>
using namespace std;

class vanDongVien{
    private:
        string hoTen;
        int tuoi;
        string monthidau;
        float canNang;
        float chieuCao;
// Constructor with no input parameter
    public: 
       vanDongVien(){
           this -> hoTen =  " ";
           this -> tuoi   = 0;
           this -> monthidau = " ";
           this -> canNang = 0;
           this -> chieuCao = 0; 
       } 
//  Constructor with 5 input parameters
        vanDongVien(string hoTen, int tuoi, string monthidau, float canNang, float chieuCao){
            this -> hoTen = hoTen;
            this -> tuoi = tuoi;
            this -> monthidau = monthidau;
            this -> canNang = canNang;
            this -> chieuCao = chieuCao;
        }
// Destructor
       ~vanDongVien(){
           this -> hoTen =  " ";
           this -> tuoi   = 0;
           this -> monthidau = " ";
           this -> canNang = 0;
           this -> chieuCao = 0; 
       } 
// Nạp chồng toán tử nhập >>

         friend istream &operator>>(istream &is, vanDongVien &vdv){
            cout << " Nhập vào họ và tên vận động viên: \n"; 
            is >> vdv.hoTen;
            cout << "Nhập vào tuổi của vận động viên: \n" ;
            is >> vdv.tuoi;
            cout << "Nhập vào môn thi đấu của vận động viên: \n";
            is >> vdv.monthidau;
            cout << "Nhập vào cân nặng của vận động viên: \n";
            is >> vdv.canNang;
            cout << "Nhập vào chiều cao của vận động viên: \n";
            is >> vdv.chieuCao;
         }
// Nạp chồng toán tử xuất <<
         friend ostream& operator << (ostream& os, vanDongVien &vdv ){
            os << " Họ và Tên của vận đông viên: "<< vdv.hoTen << "\n" << endl; 
            os << " Tuổi của vận động viên: " << vdv.tuoi << "\n" << endl;
            os << " Môn thi đấu của vận đông viên: "<< vdv.monthidau << "\n" << endl; 
            os << " Cân nặng của vận động viên: " << vdv.canNang << "\n" << endl;
            os << " Chiều cao của vận động viên: " << vdv.chieuCao << "\n" << endl;
         }
// Nạp chồng toán tử so sánh > (một vận động viên là lớn hơn nếu chiều cao lớn hơn,
//trong trường hợp chiều cao bằng nhau thì xét cân nặng lớn hơn)
         bool operator > (const vanDongVien &vdv)
        {
            if (this->chieuCao > vdv.chieuCao)
                return true;
            else if (this->chieuCao < vdv.chieuCao)
                return false;
            else if(this->chieuCao == vdv.chieuCao){
                if ( this->canNang > vdv.canNang)
                    return true;
            }
            else
                return false;
        }

};
void swap(vanDongVien &a, vanDongVien &b){
    vanDongVien temp =a;
    a=b;
    b=temp;
}
// Ham sap xep tang
void sortArrTang(vanDongVien a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i], a[j]);
            }
        }
}

int main(){
// + Khai báo p là đối tượng lớp Vandongvien (sử dụng hàm thiết lập 5 tham số), hiển thị thông tin của p ra màn hình.
    vanDongVien p("AAAAAAAA",20,"Bóng đá",60.1,1.7);
    cout << p;
// Nhập vào một mảng gồm n vận động viên. và Hiển thị danh sách đã nhập ra màn hình.
    int n ;
    cout << "Nhập vào số lượng vận động viên: ";
    cin >> n;
    vanDongVien *arr_vanDongVien = new vanDongVien[n];
    for(int i= 0; i<=n; i++){
        cout << "Nhập thông tin vận động viên \n";
        cin >> arr_vanDongVien[i];
        cout << "Danh sách vận động viên \n" << arr_vanDongVien[i] << endl;
    }
//Sắp xếp mảng đã nhập theo thứ tự tăng dần, hiển thị danh sách đã sắp ra màn hình.
    cout <<  "Sắp xếp mảng theo thứ tự tăng dần: \n";
    sortArrTang(arr_vanDongVien, n);
     for(int i =0; i<=n; i++){
        cout << "Sắp xếp danh sách vận động viên \n" << arr_vanDongVien[i] << endl;
     }
}