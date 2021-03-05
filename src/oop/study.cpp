#include<stdio.h>
#include<string.h>
enum Gender{
    MALE = 0, FEMALE = 1
};
typedef struct Person {
    char name[30];
    int age;
    Gender gender;
    char address[30];
};
typedef struct Animal{
    char name[30];
    int age;
    Gender gender;
};
void setPerson(Person &person,const char name[30],const int age, Gender gender,const char address[30]);
void setAnimal(Animal &animal,const char name[30],const int age,Gender gender);
void run(Person *person);
void run(Animal *animal);
void teach(Person *person);
void swim(Person *person);
void swim(Animal *animal);
int main(){
    Person person;
    Animal animal;
    setPerson(person,"Minh",13,MALE,"La Xuan Oai, Ha Noi");
    run(&person);
    teach(&person);
    swim(&person);
    setAnimal(animal,"Lulu",3,FEMALE);
    run(&animal);
    swim(&animal);
    return 0;
}
void setPerson(Person &person,const char name[30],const int age, Gender gender,const char address[30]){
    strcpy(person.name,name);
    person.age = age;
    person.gender = gender;
    strcpy(person.address,address);
}
void run(Person *person){
    printf("%s is running!",person->name);
}
void teach(Person *person){
    printf("\n%s is teaching", person->name);
}
void swim(Person *person){
    printf("\n%s is swimming", person->name);
}
void setAnimal(Animal &animal,const char name[30],const int age,Gender gender){
    strcpy(animal.name,name);
    animal.age = age;
    animal.gender = gender;
}
void run(Animal *animal){
    printf("\n%s is running", animal->name);
}
void swim(Animal *animal){
    printf("\n%s is swimming", animal->name);
}