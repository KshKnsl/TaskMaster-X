#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
#include<string.h>
#include<math.h>
struct Credentials
{
    long loginID;
    long Password;
    bool verified;
};
void escape();
void login();
void createAccount();
void guest();
void homePage();
int mainMenu();
void taskMenu();
int main()
{
  homePage();
  return 0;
}
void homePage()
{
  int choice;
  printf("\n  _____________________________________________________________________\n");
  printf("||                                                                     ||\n");
  printf("||   \\      /\\      / |===== |      |====== /=====\\ |\\    /| |=====    ||\n");
  printf("||    \\    /  \\    /  |_____ |      |       |     | | \\  / | |_____    ||\n");
  printf("||     \\  /    \\  /   |      |      |       |     | |  \\/  | |         ||\n");
  printf("||      \\/      \\/    |===== |_____ |====== \\=====/ |      | |=====    ||\n");
  printf("||                           TO TaskMaster X                           ||\n");
  printf("||     MENU:-                                                          ||\n");
  printf("||   1.Login                                                           ||\n");
  printf("||   2.Create a new account                                            ||\n");
  printf("||   3.Guest Mode                                                      ||\n");
  printf("||   3.CLOSE TASKMASTER X                                              ||\n");
  printf("||_____________________________________________________________________||\n");
  printf("ENTER YOUR CHOICE::");
  scanf("%d",&choice);
  switch(choice)
  {
      case 1:
          break;
      case 2:
          break;
      case 3:
          break;
      case 4:
          escape();
          break;
      default:
          escape();
  }
}
void escape()
{
  printf("\nAre you sure you want to exit?(YES/NO)");
  char ch; 
  scanf("%c", &ch);
  scanf("%c", &ch);
  if(ch=='Y')
  {
      printf("\n  ________________________________________________________________________");
      printf("\n||                                                                        ||");
      printf("\n|| ---------- |     |    /\\    |\\    | |  /      \\     / |=====| |    |   ||");
      printf("\n||     ||     |     |   /  \\   | \\   | | /        \\   /  |     | |    |   ||");
      printf("\n||     ||     |=====|  /====\\  |  \\  | |/          \\=/   |     | |    |   ||");
      printf("\n||     ||     |     | /      \\ |   \\ | |\\           |    |     | |    |   ||");
      printf("\n||     ||     |     |/        \\|    \\| | \\          |    |=====| |====|   ||");
      printf("\n||________________________________________________________________________||\n");
      exit(0);
  }
  else  homePage();
}
int mainMenu()
{
    //This function is used to print the Menu of the Todo list and returns a choice entered by the user.
    int choice;
    system("cls");          //clears the screen.
    printf("\n\nEnter your choice : ");
    printf("\n\t\t\t\t\t\t 1. See your ToDo List. \n");
    printf("\n\t\t\t\t\t\t 2. Update your ToDo List. \n");
    printf("\n\t\t\t\t\t\t 3. Create a new ToDo List. \n");
    printf("\n\t\t\t\t\t\t 4. Delete your ToDo List. \n");
    printf("\n\t\t\t\t\t\t 5. Edit task(s) in your ToDo List. \n");
    printf("\n\t\t\t\t\t\t 6. Exit ");
    printf("\n\n");
    printf("\n\t\t\t\t\t\t Enter your choice \n\t\t\t\t\t\t --> ");
    scanf("%d",&choice);
    return choice;
}
