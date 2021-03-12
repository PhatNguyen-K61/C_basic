#include<iostream>
using namespace std;
class Complex{
    private:
        float realPart;
        float imagPart;
    public:
        //TODO: xây dựng constructor
        Complex(); //NOTE: khởi tạo mặc định
        ~Complex();//hàm hủy
        Complex(float realPart, float imagPart);//khởi tạo đầy đủ đối số
        Complex(const Complex &other);
        // TODO: xây dựng setter,getter
        void setRealPart(float realPart);
        void setImagPart(float imagPart);
        float getRealPart();
        float getImagPart();
        //TODO: xây dựng nạp chồng toán tử
        friend istream &operator>>(istream &input, Complex &complex);
        friend ostream &operator<<(ostream &output,const Complex complex);
        Complex operator+(const Complex &other);
        Complex operator-(const Complex &other);
        Complex operator*(const Complex &other);
        Complex operator/(const Complex &other);
        // TODO: cộng, trừ, nhân, chia 2 số phức
        Complex add(const Complex other);
        Complex sub(const Complex other);
        // TODO: xây dựng hàm so sánh
        //TODO: xây dựng hàm tính độ dài số phức
};
Complex::Complex(){
    realPart = 0;
    imagPart = 0;
}
Complex::Complex(float realPart, float imagPart){
    this->realPart = realPart;
    this->imagPart = imagPart;
}
Complex::Complex(const Complex &other){
        this->realPart = other.realPart;
        this->imagPart = other.imagPart;
}
void Complex::setRealPart(float realPart){
    this->realPart = realPart;
}
void Complex::setImagPart(float imagPart){
    this->imagPart = imagPart;
}
float Complex::getRealPart(){
    return realPart;
}
float Complex::getImagPart(){
    return imagPart;
}
istream &operator>>(istream &input, Complex &complex){
    cout<<"Real part: ";
    cin>>complex.realPart;
    cout<<" imag part: ";
    cin>>complex.imagPart;
}
ostream &operator<<(ostream &output,const Complex complex){
    cout<<complex.realPart<<" + "<<complex.imagPart<<"i";
}
Complex Complex::operator+(const Complex &other){
    Complex result;
    result.realPart=this->realPart+other.realPart;
    result.imagPart=this->imagPart+other.imagPart;
    return result;
}
Complex Complex::operator-(const Complex &other){
    Complex result;
    result.realPart=this->realPart-other.realPart;
    result.imagPart=this->imagPart-other.imagPart;
    return result;
}
Complex Complex::operator*(const Complex &other){
    Complex result;
    result.realPart=this->realPart*other.realPart;
    result.imagPart=this->imagPart*other.imagPart;
    return result;
}
Complex Complex::operator/(const Complex &other){
    Complex result;
    result.realPart=this->realPart/other.realPart;
    result.imagPart=this->imagPart/other.imagPart;
    return result;
}
Complex Complex::add(const Complex other){
    Complex result;
    result.realPart = this->realPart + other.realPart;
    result.imagPart = this->imagPart + other.imagPart;
    return result;
}
Complex Complex::sub(const Complex other){
    Complex result;
    result.realPart = this->realPart - other.realPart;
    result.imagPart =this->imagPart - other.imagPart;
    return result;
}
int main(){
    // Complex complex;
    Complex complex1(3,3);
    Complex complex2(3,6);
    //Complex complex2(complex);
    // complex.setRealPart(4);
    // complex.setImagPart(7);
    // cin>>complex;
    cout<<"first:"<<complex1<<endl;
    cout<<"second:"<<complex2<<endl;
    cout<<"total:"<<complex1+complex2<<endl;
    cout<<"subtrac:"<<complex1-complex2<<endl;
    cout<<"Mul:"<<complex1*complex2<<endl;
    cout<<"Div:"<<complex1/complex2<<endl;
    // cout<<"realPart: "<<complex.getRealPart()<<endl;
    // cout<<"imagPart: "<<complex.getImagPart()<<endl;
    return 0;
}