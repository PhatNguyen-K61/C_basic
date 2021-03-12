#include<string>
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
            this->year =1990;
        }
        DateTime(int day,int month,int year){
            this->day = day;
            this->month = month;
            this->year = year;
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
        
};
int main(){
    DateTime birthday = DateTime(3,2,2013);
    Student student = Student("001","Minh",birthday);
    return 0;
}