#include <iostream>
using namespace std;
class Polynomial{
    private:
            int exponential;//bậc
            int *coefficient;//hệ số
    public:
            //NOTE: Hàm khởi tạo
            Polynomial();// khởi tạo mặc định
            Polynomial(int *coefficient, int exponential); // khởi tạo có tham số
            Polynomial(const Polynomial &other);
            //TODO: Hàm nhập
            friend istream &operator>>(istream &input, Polynomial &polynomial);
            //NOTE: hàm Xuất
            friend ostream &operator<<(ostream &output,const Polynomial polynomial);
            // TODO: tìm giá trị của đa thức
            //TODO: cộng trừ 2 đa thức
            Polynomial operator+(const Polynomial &other);
            //TODO: Tích 2 đa thức (TƯ DUY) 
};
Polynomial::Polynomial(){
    exponential = 0;
    coefficient = NULL;
}
Polynomial::Polynomial(int *coefficient, int exponential){
    //NOTE: gán bậc
    this->exponential = exponential;
    // NOTE: cấp phát bộ nhớ động
    this->coefficient = new int[exponential+1];// khởi tạo coefficient
    // NOTE: gán giá trị của hệ số
    for(int index=0; index<=exponential;index++){
        this->coefficient[index] = coefficient[index];
    }
}
istream &operator>>(istream &input, Polynomial &polynomial){
    cout<<"enter exponential of polynomial"<<endl;
    cin>>polynomial.exponential;
    for(int index = polynomial.exponential; index>=0; index--){
        cout<<"enter x^"<<index<<endl;
        cin>>polynomial.coefficient[index];
    }
}
ostream &operator<<(ostream &output,const Polynomial polynomial){
    for(int index = polynomial.exponential;index>=0;index--){
        cout<<polynomial.coefficient[index]<<"*x^"<<index;
        if(index>0){
            cout<<"+";
        }
    }
}
Polynomial Polynomial::operator+(const Polynomial &other){
    Polynomial result;
    
}
int main(){
    int coefficient[4] = {4,3,2,1};// a0,a1,a2,a3
    Polynomial polynomial = Polynomial(coefficient,3);
    cin >>polynomial;
    cout<<polynomial;
    return 0;
}