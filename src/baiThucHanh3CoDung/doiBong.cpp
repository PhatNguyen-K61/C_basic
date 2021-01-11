#include<stdio.h>
#include<conio.h>
#define MAX 100
struct Team{
    char name[30];
    int amount;
    float mark;
};
void inputTeam(Team &team);
void inputNTeam(Team a[], int &n);
void outputTeam(Team team);
void outputNTeam(Team a[], int n);
void threeTeamsHaveHighestScore(Team a[], int n);
void output3Team(Team a[]);
int main(){
    int n;
    Team a[MAX], team;
    printf("\nEnter the number of Football teams: ");
    scanf("%d", &n);
    inputNTeam(a, n);
    outputNTeam(a, n);
    threeTeamsHaveHighestScore(a, n);
    output3Team(a);
}
void inputTeam(Team &team)
{
    printf("\nName of team: ");
    fflush(stdin);
    gets(team.name);
    printf("\nAmount of player in team: ");
    scanf("%d", &team.amount);
    printf("\nScore: ");
    scanf("%f", &team.mark);
}
void inputNTeam(Team a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nInformation of team %d: ", i + 1);
        inputTeam(a[i]);
    }
}
void outputTeam(Team team){
    printf("\nName of team: %s", team.name);
    printf("\tAmount of player in team: %d", team.amount);
    printf("\tScore: %.2f", team.mark);
}
void outputNTeam(Team a[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("\nInformation of team %d: ", i + 1);
        outputTeam(a[i]);
    }
}
void threeTeamsHaveHighestScore(Team a[], int n){
    //3 đội có số điểm cao nhất
    Team temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i].mark<a[j].mark){
                temp.mark=a[i].mark;
                a[i].mark=a[j].mark;
                a[j].mark=temp.mark;
            }
        }
    }
}
void output3Team(Team a[]){
    for (int i = 0; i < 3; i++)
    {
        printf("\nInformation of team %d: ", i + 1);
        outputTeam(a[i]);
    }
}