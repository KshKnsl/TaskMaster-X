#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void escape();
void homePage();
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
  printf("||   1.                                                                ||\n");
  printf("||   2.                                                                ||\n");
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
      printf("\n|| ---------- |     |    /\\    |\\    | |  /      \\     / |=====| |    |   ||  ");
      printf("\n||     ||     |     |   /  \\   | \\   | | /        \\   /  |     | |    |   ||  ");
      printf("\n||     ||     |=====|  /====\\  |  \\  | |/          \\=/   |     | |    |   ||  ");
      printf("\n||     ||     |     | /      \\ |   \\ | |\\           |    |     | |    |   ||  ");
      printf("\n||     ||     |     |/        \\|    \\| | \\          |    |=====| |====|   ||  ");
      printf("\n||________________________________________________________________________||  ");
      exit(0);
  }
  else  homePage();
}
