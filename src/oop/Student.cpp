#include<iostream>
#include<string>
#include<vector>
using namespace std;
class DateTime{
    private:
        int day;
        int month;
        int year;
    public:
        DateTime(){
            this->day = 1;
            this->month =1;
            this->year =1;
        }
        DateTime(int day,int month,int year){
            this->day = day;
            this->month = month;
            this->year = year;
        }
        friend istream &operator>>(istream &input, DateTime &dateTime);
        friend ostream &operator<<(ostream &output,const DateTime dateTime){
            cout<<dateTime.day<<"/"<<dateTime.month<<"/"<<dateTime.year;
        }

};
class Student{
    private:
        string id;
        string name;
        DateTime birthday;
    public:
        Student(){
            this->id= "001";
            this->name= "Anh";
            this->birthday= DateTime();
        }
        Student(string id, string name,DateTime birthday){
            this->id = id;
            this->name = name;
            this->birthday = birthday;
        }
        string getId(){
            return this->id;
        }
        friend istream& operator>>(istream &input, Student &student);
        void print(){
            cout<<"{id:"<<id<<" name:"<<name<<" birthday:"<<birthday<<"}";
        }     

};
class Students{
    private:
        vector<Student> students;
        int count;
    public:
        Students(){
            students = vector<Student>();
            count = 0;
        }
        bool exist(string id){
            bool found=false;
            for(auto student = students.begin(); student != students.end(); ++student){
                if(student->getId() == id){
                    found=true;
                    break;
                }
            }
            return found;
        }
        void add(Student student){
            if(!this->exist(student.getId())){
                this->students.push_back(student);// NOTE: thêm 1 studnet vào cuối vector
                count++;//NOTE: số lượng phần tử trong vector sẽ tăng lên 1
            }else{
                cout<<"This id existed"<<endl;
            }
        }
        void remove(string id){
            for(auto student = students.begin(); student != students.end(); ++student){
                if(student->getId() == id){
                    students.erase(student);
                }
            }
        }
        void print(){
            for (auto student = students.begin(); student != students.end(); ++student) {//NOTE: đi từ đầu đến cuối vector để in từng phần tử
                student->print();
                cout<<endl;
            }
        }
};
istream &operator>>(istream &input, DateTime &dateTime){
    cout<<"Enter day: "<<endl;
    cin>>dateTime.day;
    cout<<"Enter month: "<<endl;
    cin >>dateTime.month;
    cout<<"Enter year: "<<endl;
    cin >>dateTime.year;
}
istream &operator>>(istream &input, Student &student){
    cout<<"Enter id: "<<endl;
    cin >>student.id;
    cout<<"Enter name: "<<endl;
    cin >>student.name;
    cout<<"Enter birthday: "<<endl;
    cin>>student.birthday;
}
int main(){
    Student student;
    Students students = Students();
    for(int i = 0; i < 3; i++){
        cin >>student;
        students.add(student);
    }
    students.print();
    students.remove("001");
    students.print();
    return 0;
}