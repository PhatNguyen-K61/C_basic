#include <iostream>
using namespace std;
class Polynomial{
    private:
            int exponential;//bậc
            int *coefficient;//hệ số
    public:
            // Hàm khởi tạo
            Polynomial();
            Polynomial(int *coefficient, int exponential);
            // hàm Xuất
            friend ostream &operator<<(ostream &output,const Polynomial polynomial);

};
Polynomial::Polynomial(){
    exponential = 0;
    coefficient = NULL;
}
Polynomial::Polynomial(int *coefficient, int exponential){
    this->exponential = exponential;
    this->coefficient = new int[exponential+1];// khởi tạo coefficient
    for(int index=0; index<=exponential;index++){
        this->coefficient[index] = coefficient[index];
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
int main(){
    int coefficient[4] = {4,3,2,1};// a0,a1,a2,a3
    Polynomial polynomial = Polynomial(coefficient,3);
    cout<<polynomial;
    return 0;
}