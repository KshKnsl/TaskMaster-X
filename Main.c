# include<stdio.h>
# include<stdlib.h>
#include<string.h>
void depart();
void homePage();
int main()
{
    depart();
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
  printf("||                           TO TaskScapes                             ||\n");
  printf("||     MENU:-                                                          ||\n");
  printf("||   1.                                                                ||\n");
  printf("||   2.                                                                ||\n");
  printf("||   3.CLOSE TASKSCAPES                                                ||\n");
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
          depart();
          break;
      default:
          depart();
  }
}
void depart()
{
  printf("\nAre you sure you want to exit?(YES/NO)");
  char input[3];
  scanf("%s", input);
  if(strcmp(input,"YES")==0)
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
