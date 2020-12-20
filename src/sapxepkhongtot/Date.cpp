#include<stdio.h>
#include<math.h>
typedef struct Date
{
    int day,month,year;//--> kiểu int
};
void enterInfo(Date &input);
void setDate(Date &date,int day,int month,int year);
Date findBeforeDay(Date input);
Date findNextDay(Date input);
int findPositionInYear(Date input);
bool isLeapYear(int year);
void printInfo(Date output);
void printLeapYear(Date input);
void printBeforeDay(Date input);
void printNextDay(Date input); 
void outputDistanceBetweenTwoDays(Date start, Date end);
void printPositionInYear(Date input);
int main(){
    Date start, end;
    enterInfo(start);
    printInfo(start);
    enterInfo(end);
    printInfo(end);
    printLeapYear(start);
    // printLeapYear(end);
    printBeforeDay(start);
    // printBeforeDay(end);
    printNextDay(start); 
    printPositionInYear(start);
    outputDistanceBetweenTwoDays(start,end);
    return 0;
}
void setDate(Date &date,int day,int month,int year){
    date.day = day;
    date.month = month;
    date.year = year;
}
void enterInfo(Date &input){
    printf("\nenter date: ");
    scanf("%d", &input.day);
    printf("\nenter month: ");
    scanf("%d", &input.month);
    printf("\nenter year: ");
    scanf("%d", &input.year);
}
void printInfo(Date output){
    printf("%d / %d / %d", output.day, output.month, output.year);
}

void printLeapYear(Date input){
    if(isLeapYear(input.year)){
        printf("\n%d is a leap year\n", input.year);
    } else {
        printf("\n%d is not a leap year\n", input.year);
    }
}
bool isLeapYear(int year){
    return year%4==0;
}
void printBeforeDay(Date input){
    Date beforeday = findBeforeDay(input);
    printf("\nbefore day: ");
    printInfo(beforeday);
}
Date findBeforeDay(Date input){
    Date result;
    int fistdayofmonth = 1;
    if (input.day == fistdayofmonth){
        switch (input.month)
        {
        case 1:
            setDate(result,31,12,input.year-1);
            break;
        case 3: if (isLeapYear(input.year)){
            setDate(result,29,input.month-1,input.year);
            } else{
            setDate(result,28,input.month-1,input.year);
            }
            break;
        case 4: case 6: case 9: case 11: case 2:
            setDate(result,30,input.month-1,input.year);
            break;
        default:
            break;            
        } 
    }else{ 
            setDate(result,input.day-1,input.month,input.year);
    }
    return result;
}
Date findNextDay(Date input){
    Date result_nextday;
    int finaldayOfMonth = 31;
    if(input.day == finaldayOfMonth){
        switch (input.month)
        {
        case 12: 
            setDate(result_nextday,1,1,input.year+1);
            break;
        case 2: if((isLeapYear(input.year))== true || (isLeapYear(input.year))==false){
            setDate(result_nextday, 1,3,input.year);
        }
            break;
        case 4: case 6: case 9: case 11: 
            if(input.day==30){
            setDate(result_nextday,1,input.month+1,input.year+1);
            }
        case 1: case 3: case 5: case 7: case 8: case 10:
            if(input.day == 31){
                setDate(result_nextday,1,input.month+1,input.year);
            }
            break;
        default: 
            setDate(result_nextday,input.day+1,input.month, input.year);
            break;
        }
    } else{
        setDate(result_nextday,input.day+1,input.month, input.year);
    }
    return result_nextday;
}
void printNextDay(Date input){
    Date nextday = findNextDay(input);
    printf("\nnext day: ");
    printInfo(nextday);
}

int  findPositionInYear(Date input){
    int  days_added;
    days_added=0;
    int position = 0;
    switch (input.month)
    {
        case 12: days_added += 30;
        case 11: days_added += 31;
        case 10: days_added += 30;
        case 9: days_added += 31;
        case 8: days_added += 31;
        case 7: days_added += 30;
        case 6: days_added += 31;
        case 5: days_added += 30;
        case 4: days_added += 31;
        case 3: if (isLeapYear(input.day))
                    days_added += 29;
                else    
                {
                    days_added += 28;
                }
            case 2: days_added += 31;
            case 1: days_added = days_added;
    }
    position = input.day + days_added;
    return position;
}
void printPositionInYear(Date input){
    int position_of_year = findPositionInYear(input);
    printf("\nposition in year: %d",position_of_year);
}
//  ------------------------   
// To store number of days in all months from January to Dec.
const int monthDays[12] = {
    31, 28, 31, 30, 31, 30, 
    31, 31, 30, 31, 30, 31
};
// This function counts number of leap years before the given date
int countLeapYears(Date cnt){
    int years = cnt.year;
    //check if the current year needs to be considered for the count of leap years
    if (cnt. year<= 2){
        years--;
    }
    //an year is a leap year if it is a multiple of 4; multiple of 400 and not a multiple of 100
    return years/4 - years/100 + years/400;
}
int getDifference(Date start, Date end){
    //count total number of days before first date 'date1' initialize count using years and day
    long int n1 = start.year*365 + start.day;
    //add days for months in given date
    for (int i = 0; i < end.month - 1; i++){
        n1 += monthDays[i];
    // Since every leap year is of 366 days,
    // Add a day for every leap year
        n1 += countLeapYears(end);
    }
    long int n2 = end.year *365 + end.day; 
    for (int i = 0; i < end.month - 1;i++){
        n2 += monthDays[i];
        n2 += countLeapYears(end);
    }
    return (n2 - n1);
};
void outputDistanceBetweenTwoDays(Date start, Date end){
    int gap_of_two_day = getDifference(start,end);
    printf("\nthe gap between two day %d", gap_of_two_day);
}