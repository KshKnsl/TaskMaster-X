# include<stdio.h>
# include<stdlib.h>
#include<string.h>
void depart();
void homePage();
int main()
{
  homePage();
  return 0; 
}
void homePage()
{       
  printf("|⌈¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯⌉|  ");
  printf("||   \\      /\\      / |===== |      |====== /=====\\ |\\    /| |=====    ||");
  printf("||    \\    /  \\    /  |_____ |      |       |     | | \\  / | |_____    || ");
  printf("||     \\  /    \\  /   |      |      |       |     | |  \\/  | |         || ");
  printf("||      \\/      \\/    |===== |_____ |====== \\=====/ |      | |=====    || ");
  printf("||                           TO TaskScapes                             ||   ");                                                   
  printf("||     MENU:-                                                          ||   ");       
  printf("||   1.                                                                ||   ");
  printf("||   2.                                                                ||   ");
  printf("||   3.CLOSE TASKSCAPES                                                ||   ");               
  printf("|⌊_____________________________________________________________________⌋|   ");
  printf("ENTER YOUR CHOICE::");
  int choice;
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
  printf("Are you sure you want to exit?(YES/NO)");
  char input[3];
  scanf("%s", input);
  if(strcmp(input,"YES")==0)
  {
      printf("|⌈¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯⌉|  ");
      printf("|| ---------- |     |    /\\    |\\    | |  /      \\     / |=====| |    |   ||  ");
      printf("||     ||     |     |   /  \\   | \\   | | /        \\   /  |     | |    |   ||  ");
      printf("||     ||     |=====|  /====\\  |  \\  | |/          \\=/   |     | |    |   ||  ");
      printf("||     ||     |     | /      \\ |   \\ | |\\           |    |     | |    |   ||  ");
      printf("||     ||     |     |/        \\|    \\| | \\          |    |=====| |====|   ||  ");
      printf("|⌊________________________________________________________________________⌋|  ");
      exit(0);
  }
  else  homePage();
}