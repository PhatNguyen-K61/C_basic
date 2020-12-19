#include <stdio.h>
typedef struct Monomial
{
    int coefficient; //hệ số
    int indexNumber; //số mũ
};
void input(Monomial &monomial);
void output(Monomial monomial);
void summationMonomial(Monomial first_monomial, Monomial second_monomial);
void subtractionMonomial(Monomial first_monomial, Monomial second_monomial);
void multiplicationMonomial(Monomial first_monomial, Monomial second_monomial);
void divisionMonomial(Monomial first_monomial, Monomial second_monomial);
int compareMonomial(Monomial first_monomial, Monomial second_monomial);
void outputCompareMonomial(Monomial first_monomial, Monomial second_monomial);
int main()
{
    Monomial first_monomial, second_monomial;
    input(first_monomial);  //Đơn thức 1
    input(second_monomial); //Đơn thức 2
    output(first_monomial);
    output(second_monomial);
    summationMonomial(first_monomial, second_monomial);
    subtractionMonomial(first_monomial, second_monomial);
    multiplicationMonomial(first_monomial, second_monomial);
    divisionMonomial(first_monomial, second_monomial);
    outputCompareMonomial(first_monomial, second_monomial);
}
void input(Monomial &monomial)
{
    printf("Enter the monorial: ");
    printf("\nEnter the coefficient: ");
    scanf("%d", &monomial.coefficient);
    printf("\tEnter the indexNumber: ");
    scanf("%d", &monomial.indexNumber);
}
void output(Monomial monomial)
{
    printf("\n%dX^%d", monomial.coefficient, monomial.indexNumber);
}
void summationMonomial(Monomial first_monomial, Monomial second_monomial)
{
    //tính tổng 2 đơn thức cùng bậc
    int total = 0;
    if (first_monomial.indexNumber == second_monomial.indexNumber)
    {
        total = first_monomial.coefficient + second_monomial.coefficient;
        printf("\nSummation of 2 monomial is %dX^%d", total, first_monomial.indexNumber);
    }
    else
    {
        printf("\nNo summation of 2 monomials");
    }
}
void subtractionMonomial(Monomial first_monomial, Monomial second_monomial)
{
    //tính hiệu 2 đơn thức cùng bậc
    int minus = 0;
    if (first_monomial.indexNumber == second_monomial.indexNumber)
    {
        minus = first_monomial.coefficient - second_monomial.coefficient;
        printf("\nSummation of 2 monomials is %dX^%d", minus, first_monomial.indexNumber);
    }
    else
    {
        printf("\nNo subtraction of 2 monomials");
    }
}
void multiplicationMonomial(Monomial first_monomial, Monomial second_monomial)
{
    //tính tích 2 đơn thức
    Monomial third_monomial;
    third_monomial.coefficient = first_monomial.coefficient * second_monomial.coefficient;
    third_monomial.indexNumber = first_monomial.indexNumber + second_monomial.indexNumber;
    printf("\nMultiplication of 2 monomials is %dX^%d", third_monomial.coefficient, third_monomial.indexNumber);
}
void divisionMonomial(Monomial first_monomial, Monomial second_monomial)
{
    //tính thương 2 đơn thức
    Monomial fourth_monomial;
    fourth_monomial.coefficient = first_monomial.coefficient / second_monomial.coefficient;
    fourth_monomial.indexNumber = first_monomial.indexNumber - second_monomial.indexNumber;
    printf("\nDivision of 2 monomials is %dX^%d", fourth_monomial.coefficient, fourth_monomial.indexNumber);
}
int compareMonomial(Monomial first_monomial, Monomial second_monomial)
{
    //so sánh 2 đơn thức
    if (first_monomial.indexNumber > second_monomial.indexNumber)
    {
        return 1;
    }
    else if (second_monomial.indexNumber > first_monomial.indexNumber)
    {
        return 0;
    }
    else
    {
        if (first_monomial.coefficient > second_monomial.coefficient)
        {
            return 1;
        }
        else if (second_monomial.coefficient > first_monomial.coefficient)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
}
void outputCompareMonomial(Monomial first_monomial, Monomial second_monomial)
{
    switch (compareMonomial(first_monomial, second_monomial))
    {
    case 0:
        printf("\nfirst monomial is smaller than second monomial");
        break;
    case 1:
        printf("\nfirst monomial is bigger than second monomial");
        break;
    default:
        printf("\nTwo monorials are equal");
        break;
    }
}