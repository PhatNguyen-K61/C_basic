#include <stdio.h>
#include <string.h>
#include <math.h>
struct Point
{
    float x, y;
};
struct Points
{
    Point points[100];
    int amount;
};
void enter(Points &input);
void printValue(Points output);
void printResult(Points source);
void findMaxDistance(Points source);
void printLinecutOY(Points source);
float theLengthOfCordinates(Points source);
void checkBelongToPart1(Points source);
int linecut_Oy(Points source);
int main()
{
    Points list;
    enter(list);
    printValue(list);
    printResult(list);
    findMaxDistance(list);
    printLinecutOY(list);
    checkBelongToPart1(list);
    return 0;
}
void enter(Points &input)
{
    printf("\nenter the amount of cordinates: ");
    scanf("%d", &input.amount);
    for (int i = 1; i <= input.amount; i++)
    {
        printf("enter the cordinate %d: ", i);
        scanf("%f%f", &input.points[i].x, &input.points[i].y);
    }
}
void printValue(Points output)
{
    printf("\nList of cordinates: ");
    for (int i = 1; i <= output.amount; i++)
    {
        printf("\nCordinate of point %d is (%.2f, %.2f) ", i, output.points[i].x, output.points[i].y);
    }
}
float theLengthOfCordinates(Points source)
{
    printf("\n\nQuestion 1:");
    float s = 0;
    for (int i = 1; i <= source.amount; i++)
    {
        float u = source.points[i + 1].x - source.points[i].x;
        float v = source.points[i + 1].y - source.points[i].y;
        s += sqrt(u * u + v * v);
    }
    return s;
}
void printResult(Points source)
{
    float result = theLengthOfCordinates(source);
    printf("\nthe length of cordinates is %.2f", result);
}
void findMaxDistance(Points source)
{
    printf("\n\nQuestion 2: ");
    float max = fabs(source.points[1].y);
    for (int i = 2; i <= source.amount; i++)
    {
        if (max < fabs(source.points[i].y))
        {
            max = fabs(source.points[i].y);
            printf("\nThe max distance is %.2f include points", max);
        }
    }
    for (int i = 1; i < source.amount; i++)
    {
        if (fabs(source.points[i].y) == max)
        {
            printf("\nCordinate %d is (%.2f,%.2f) ", i, source.points[i].x, source.points[i].y);
        }
    }
}
int linecut_Oy(Points source)
{
    printf("\n\nQuestion3: ");
    int count = 0;
    for (int i = 1; i <= source.amount; i++)
    {
        for (int j = i + 1; j <= source.amount; j++)
        {
            if ((source.points[i].x * source.points[j].x <= 0) && (fabs(source.points[i].x) + fabs(source.points[j].x) > 0))
            {
                count++;
                printf("straight segment %d,%d cut vertical axis", i, j);
            }
            return count;
        }
    }
}
void printLinecutOY(Points source)
{
    int result = linecut_Oy(source);
    printf("\nyour result is %d", result);
}
void checkBelongToPart1(Points source)
{
    printf("\n\nQuestion4: ");
    for (int i = 1; i <= source.amount; i++)
    {
        if (source.points[i].x > 0 && source.points[i].y > 0)
        {
            printf("\nthe cordinate (%.2f, %.2f) belong to part 1", source.points[i].x, source.points[i].y);
        }
        else
        {
            printf("\nthe cordinate (%.2f, %.2f) don't belong to part 1", source.points[i].x, source.points[i].y);
        }
    }
}