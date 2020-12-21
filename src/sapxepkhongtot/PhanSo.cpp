#include <stdio.h>
#include <math.h>
struct Fraction
{
    int numerator;   //tử số
    int denominator; //mẫu số
};
void inputFraction(Fraction &fraction);
void outputFraction(Fraction fraction);
void outputDecimal(Fraction fraction);
int greatestCommonDivisor(int a, int b);
void compactFraction(Fraction &fraction);
Fraction summationFraction(Fraction first_fraction, Fraction second_fraction);
Fraction subtractionFraction(Fraction first_fraction, Fraction second_fraction);
Fraction multiplicationFraction(Fraction first_fraction, Fraction second_fraction);
Fraction devisionFraction(Fraction first_fraction, Fraction second_fraction);
int compareFraction(Fraction first_fraction, Fraction second_fraction);
void outputCompareFraction(Fraction first_fraction, Fraction second_fraction);
int main()
{
    Fraction first_fraction, second_fraction;
    inputFraction(first_fraction);  //phân số 1
    inputFraction(second_fraction); //phân số 2
    outputFraction(first_fraction);
    outputDecimal(first_fraction);
    outputFraction(second_fraction);
    outputDecimal(second_fraction);
    Fraction total = summationFraction(first_fraction, second_fraction);
    printf("\nSummation of 2 fractions is: ");
    outputFraction(total);
    outputDecimal(total);
    Fraction minus = subtractionFraction(first_fraction, second_fraction);
    printf("\nSubtraction of 2 fractions is: ");
    outputFraction(minus);
    outputDecimal(minus);
    Fraction times = multiplicationFraction(first_fraction, second_fraction);
    printf("\nSubtraction of 2 fractions is: ");
    outputFraction(times);
    outputDecimal(times);
    Fraction devides = devisionFraction(first_fraction, second_fraction);
    printf("\nDevision of 2 fractions is: ");
    outputFraction(devides);
    outputDecimal(devides);
    outputCompareFraction(first_fraction, second_fraction);
}
void inputFraction(Fraction &fraction)
{
    printf("Enter the numerator: ");
    scanf("%d", &fraction.numerator);
    do
    { //mẫu > 0
        printf("\nEnter the denominator: ");
        scanf("%d", &fraction.denominator);
        if (fraction.denominator == 0)
        {
            printf("Enter the denomiator again!");
        }
    } while (fraction.denominator == 0);
}
void outputFraction(Fraction fraction)
{
    printf("\n%d / %d", fraction.numerator, fraction.denominator);
}
int greatestCommonDivisor(int a, int b)
{

    a = abs(a);
    b = abs(b);
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}
void compactFraction(Fraction &fraction)
{
    int c = greatestCommonDivisor(fraction.numerator, fraction.denominator);
    fraction.numerator = fraction.numerator / c;
    fraction.denominator = fraction.denominator / c;
}
Fraction summationFraction(Fraction first_fraction, Fraction second_fraction)
{
    //tổng 2 phân số
    Fraction total;
    total.numerator = (first_fraction.numerator * second_fraction.denominator) + (second_fraction.numerator * first_fraction.denominator);
    total.denominator = first_fraction.denominator * second_fraction.denominator;
    compactFraction(total);
    return total;
}
Fraction subtractionFraction(Fraction first_fraction, Fraction second_fraction)
{
    //hiệu 2 phân số
    Fraction minus;
    minus.numerator = (first_fraction.numerator * second_fraction.denominator) - (second_fraction.numerator * first_fraction.denominator);
    minus.denominator = first_fraction.denominator * second_fraction.denominator;
    compactFraction(minus);
    return minus;
}
Fraction multiplicationFraction(Fraction first_fraction, Fraction second_fraction)
{
    //Tích 2 phân số
    Fraction times;
    times.numerator = first_fraction.numerator * second_fraction.numerator;
    times.denominator = first_fraction.denominator * second_fraction.denominator;
    compactFraction(times);
    return times;
}
Fraction devisionFraction(Fraction first_fraction, Fraction second_fraction)
{
    //Thương 2 phân số
    Fraction divides;
    divides.numerator = first_fraction.numerator * second_fraction.denominator;
    divides.denominator = first_fraction.denominator * second_fraction.numerator;
    compactFraction(divides);
    return divides;
}
int compareFraction(Fraction first_fraction, Fraction second_fraction)
{
    //So sánh 2 phân số
    int result = -1;
    if (first_fraction.denominator == second_fraction.denominator)
    {
        if (first_fraction.numerator > second_fraction.numerator)
        {
            result = 0;
        }
        else if (first_fraction.numerator < second_fraction.numerator)
        {
            result = 1;
        }
    }
    else
    {
        if (first_fraction.denominator > second_fraction.denominator)
        {
            result = 1;
        }
        else if (first_fraction.denominator < second_fraction.denominator)
        {
            result = 0;
        }
    }
    return result;
}
void outputCompareFraction(Fraction first_fraction, Fraction second_fraction)
{
    switch (compareFraction(first_fraction, second_fraction))
    {
    case 0:
        printf("\n-First fraction is bigger than second fraction");
        break;
    case 1:
        printf("\n-First fraction is smaller than second fraction");
        break;
    default:
        printf("\n-Two fractions are equal");
    }
}
void outputDecimal(Fraction fraction)
{
    //đổi ra số thập phân
    float decimal;
    decimal = (float)fraction.numerator / (float)fraction.denominator;
    printf("\n*Decimal of fraction is: %.4f", decimal);
}