#include<iostream>
using namespace std;
class Caculator{
        private:// những thứ cấn bảo mật
                int first, second;// dữ liệu cần được bảo mật. Sau khi bảo mật thì chỉ được sử dụng trong phương thức thuộc class
        public:// những thứ k cần bảo mật
                // constructor
                Caculator();// khởi tạo mặc định
                Caculator(int first, int second);// khởi tạo có đầy đủ đối số
                Caculator(const Caculator &other);// khởi tạo sao chép
                friend istream &operator>>(istream &input, Caculator &caculator);
                friend ostream &operator<<(ostream &output,const Caculator caculator);
                //NOTE: setter, getter
                void setFirst(int first);// dữ liệu được bảo mật nên sài hàm set để tương tác với nó, che dấu dữ liệu
                void setSecond(int second);
                int getFirst();
                int getSecond();
                // other method
                void enter();
                void print();
                int sum();// phương thức trong class có thể sài được dữ liệu của class
                int sub();
                int mul();
                float div();
                int compare();
};
Caculator::Caculator(){
        first = 0;
        second = 0;
}
Caculator::Caculator(int first,int second){
        this->first = first;
        this->second = second;
}
Caculator::Caculator(const Caculator &other){
        this->first = other.first;
        this->second = other.second;
}
void Caculator::enter(){
        cout<<"first:";
        cin>>first;
        cout<<"second:";
        cin>>second;
}
void Caculator::print(){
        cout<<"first: "<<first<<", second: "<<second<<endl;
}
istream &operator>>(istream &input, Caculator &caculator){
        cout<<"first:";
        cin>>caculator.first;
        cout<<"second:";
        cin>>caculator.second;
}
ostream &operator<<(ostream &output,const Caculator caculator){
        cout<<"first: "<<caculator.first<<", second: "<<caculator.second<<endl;
}
void Caculator::setFirst(int first){
        this->first = first;// this->first là cái first trong dữ liệu của class. còn first là 
}
void Caculator::setSecond(int second){
        this->second = second;
}
int Caculator::getFirst(){
        return first;
}
int Caculator::getSecond(){
        return second;
}

int Caculator::sum(){
        return first + second;// first là dữ liệu trong class. do nó chỉ có 1 first nên k cần this 
}
int Caculator::sub(){
        return first - second;
}
int Caculator::mul(){
        return first*second;
}
float Caculator::div(){
        return (float)first/second;
}
int Caculator::compare(){
        return (first>second)?first:second;
}
int main(){
        Caculator caculator(3,0);// gọi hàm khởi tạo mặc định
        Caculator caculator2(caculator);
        // caculator.enter();
        // cin>>caculator;
        cout<<caculator;
        cout<<caculator2;
        // caculator.print();
        // caculator.setFirst(3);// không truy cập trực tiếp mà nhờ set nó sửa giùm. ví dụ: ẩn giấu được dữ liệu
        // caculator.setSecond(5);
        // cout<<"first:"<<caculator.getFirst()<<endl;
        // cout<<"second:"<<caculator.getSecond()<<endl;
        cout<<"sum:"<<caculator.sum()<<endl;
        cout<<"sub:"<<caculator.sub()<<endl;
        cout<<"mul:"<<caculator.mul()<<endl;
        cout<<"div:"<<caculator.div()<<endl;
        cout<<"bigger: "<<caculator.compare()<<endl;
        return 0;
}