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
          login();
          break;
      case 2:
          createAccount();
          break;
      case 3:
          guest();
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
  printf("\nAre you sure you want to exit?(YES/NO)---");
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

void taskMenu()
{
}

void login()
{
    struct Credentials user;
    printf("Login\n");
    printf("Enter your Login ID: ");
    scanf("%ld", &user.loginID);
    printf("Enter your Password: ");
    scanf("%ld", &user.Password);

    FILE *file = fopen("Credentials.txt", "r");
    if(file==NULL)
    {
        printf("Error opening the file.\n");
        return;
    }
    user.verified=false;
    while(fread(&user, sizeof(struct Credentials),1,file)) 
    {
        if(user.loginID==user.loginID&&user.Password==user.Password) 
        {
            user.verified=true;
            break;
        }
    }
    fclose(file);
    if(user.verified) 
    {
        printf("Login successful!\n");
        int choice = mainMenu();
        //Handle the choice based on user's input from main menu
    }
    else 
    {
        printf("Login failed. Please check your credentials or create a new account.\n");
        DEFAULT:
        printf("Options:\n1.Create a new account\n2.Return to Home page\n3.Retry\n4.Exit\n");
        printf("Enter your choice  :  ");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :    createAccount();    break;
            case 2 :    homePage();         break;
            case 3 :    login();            break;
            case 4 :    escape();           break;
            default :   goto DEFAULT;
        }       
    }
}

void createAccount()
{
}

void guest()
{
    
    printf("\nGuest Mode Loading.....\n");
    struct Credentials guestUser;
    guestUser.loginID = 12345;
    guestUser.Password = 12345;
    guestUser.verified = true;
    printf("\nGuest Mode READY.....\n");
    printf("Welcome, Guest!\n");
    int choice = mainMenu();
    // Handle the choice based on user's input from main menu
}