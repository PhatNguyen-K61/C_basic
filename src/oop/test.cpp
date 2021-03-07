#include<iostream>
#include<string.h>
using namespace std;

enum Gender{
    MALE = 0, FEMALE = 1
};
class Person{
   private:
            char name[30];
            int age;
            Gender gender;
            char address[30];  
    public:
            Person(char name[30],int age,Gender gender,char address[30]);  // hàm khởi tạo có đối số 
            void run();
            void swim();
            void teach();
};
class Animal{
    private:
            char name[30];
            int age;
            Gender gender;
    public:
            Animal(char name[30],int age,Gender ender);
            void run();
            void swim();
};
Person::Person(char name[30],int age,Gender gender,char address[30]){
    strcpy(this->name,name);
    this->age = age;
    this->gender = gender;
    strcpy(this->address,address);
}
Animal::Animal(char name[30],int age,Gender gender){
    strcpy(this->name,name);
    this->age = age;
    this->gender = gender;
}
void Person::run(){
    cout<<this->name<<" is running!"<<endl;
    //printf("%s is running!",this->name);
}
void Person::teach(){
    cout<<this->name<<" is teaching"<<endl;
    //printf("%s is teaching!",this->name);
}
void Person::swim(){
    cout<<this->name<<" is swimming"<<endl;
    //printf("%s is swimming!",this->name);
}
void Animal::run(){
    cout<<this->name<<" is running"<<endl;
}
void Animal::swim(){
    cout<<this->name<<" is swimming"<<endl;
}
int main(){
    Person person = Person("hoang",13,MALE,"La Xuan Oai, Ha Noi");// gọi hàm khởi tạo có đối số
    Animal animal = Animal("Lulu",3,FEMALE);
    person.run();
    person.swim();
    person.teach();
    animal.run();
    animal.swim();
    return 0;
}