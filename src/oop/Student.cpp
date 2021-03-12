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
        Student(string id, string name,DateTime birthday){
            this->id = id;
            this->name = name;
            this->birthday = birthday;
        }
        void print(){
            cout<<"{id:"<<id<<"name:"<<name<<"birthday:"<<birthday<<"}";
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
        void add(Student student){
                this->students.push_back(student);
                count++;
        }
        void print(){
            for (auto student = students.begin(); student != students.end(); ++student) {
                student->print();
                cout<<endl;
            }
        }
};
int main(){
    DateTime birthday = DateTime(3,2,2013);
    Student student1 = Student("001","Minh",birthday);
    Student student2 = Student("002","Anh",birthday);
    Students students = Students();
    students.add(student1);
    students.add(student2);
    students.print();
    return 0;
}