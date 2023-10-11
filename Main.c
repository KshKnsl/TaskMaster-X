#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<unistd.h>

struct Credentials
{
    long loginID;
    long Password;
    bool verified;
};

struct Task 
{
    int  taskID;
    char taskname[20];
    char description[500];
    int  percent_complete;
    bool completed;
    int  priority;//set priority on a scale of 1-5    
    int  lastDate;//last date to complete the task
    int  time;//last time to complete the task
    char attactment[100];//askuser if he wants to attach any link or file with his file(like meet,docs,excelsheet,URL address)
    char category[20];
};

void escape();
void login();
void createAccount();
void guest();
void homePage();
int  mainMenu();
bool validate(int dob);
void taskManager(struct Credentials user,int choice);
void seeToDoList(struct Credentials user);
void updateToDoList(struct Credentials user);
void createNewToDoList(struct Credentials user);
void deleteToDoList(struct Credentials user);
void editTasks(struct Credentials user);

int main()
{
  homePage();
  return 0;
}

void homePage()
{
    system("cls");
    system("color 17");
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
    printf("||   4.CLOSE TASKMASTER X                                              ||\n");
    printf("||_____________________________________________________________________||\n");
    printf("ENTER YOUR CHOICE::");
    scanf("%d",&choice);
    printf("\nLoading.....\n");
    sleep(1);
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
  scanf("%c",&ch);
  scanf("%c",&ch);

  if(ch=='Y'||ch=='y')
  {
    printf("\n  ________________________________________________________________________");
    printf("\n||                                                                        ||");
    printf("\n|| ---------- |     |    /\\    |\\    | |  /      \\     / |=====| |    |   ||");
    printf("\n||     ||     |     |   /  \\   | \\   | | /        \\   /  |     | |    |   ||");
    printf("\n||     ||     |=====|  /====\\  |  \\  | |/          \\=/   |     | |    |   ||");
    printf("\n||     ||     |     | /      \\ |   \\ | |\\           |    |     | |    |   ||");
    printf("\n||     ||     |     |/        \\|    \\| | \\          |    |=====| |====|   ||");
    printf("\n||________________________________________________________________________||\n");
    sleep(7);
    system("cls");
    exit(0);
  }
  else
  {
    homePage();
  }
}

int mainMenu()
{
    //This function is used to print the Menu of the Todo list and returns a choice entered by the user.
    int choice;
    
    system("cls");          //clears the screen.
    system("color 4F");
    
    printf("\n");

    printf("\t\t\t\t\t**************************************\n");
    printf("\t\t\t\t\t***                                ***\n");
    printf("\t\t\t\t\t***            MAIN MENU           ***\n");
    printf("\t\t\t\t\t***                                ***\n");
    printf("\t\t\t\t\t**************************************\n");
    
    printf("\nEnter your choice : ");
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

void writeCredentialsToFile(long loginID, long Password)
{
    FILE *file=fopen("Credentials.txt","a");
    if(file==NULL)
    {
        printf("Error opening the file for writing.\n");
        return;
    }
    fprintf(file,"%ld,%ld\n",loginID,Password);
    fflush(file);
    fclose(file);
}


bool readCredentialsFromFile(long loginID, long Password)
{
    FILE *file = fopen("Credentials.txt","r");
    long storedLoginID, storedPassword;
    bool found = false;
    char line[100];
    while(fgets(line,sizeof(line),file)!=NULL)
    {
        sscanf(line,"%ld,%ld",&storedLoginID,&storedPassword);
        if(loginID==storedLoginID&&Password==storedPassword)
        {
            found=true;
            break;
        }
    }
    fclose(file);
    return found;
}

void login()
{
    sleep(5);
    system("cls");
    system("color E1");
    struct Credentials user;
    printf("**************************************\n");
    printf("*                 Login              *\n");
    printf("**************************************\n");
    printf("Enter your Login ID: ");
    scanf("%ld", &user.loginID);
    printf("Enter your Password: ");
    scanf("%ld", &user.Password);
    if(readCredentialsFromFile(user.loginID, user.Password))
    {
        printf("**************************************\n");
        printf("*          Login Successful          *\n");
        printf("**************************************\n");
        printf("\nMAIN MENU Loading.....\n");
        sleep(5);
        int choice = mainMenu();
        taskManager(user,choice);
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
    char name[20];
    int dob = 0;
    struct Credentials newUser;
    sleep(3);
    system("cls");
    system("color 2f");
    struct Credentials user;
    printf("**************************************\n");
    printf("*         CREATE AN ACCOUNT          *\n");
    printf("**************************************\n");
    printf("To Create a New Account\n");
    printf("Enter your first name: ");
    scanf("%19s", name);
    retry:
    printf("Enter your date of birth (format DDMMYY): ");
    scanf("%d", &dob);

    if(!validate(dob))
    {
        printf("\nWrong Date of birth......Retry.....");
        goto retry;
    }
    else
    {
        printf("------Date Validated------- \n");
    }
    printf("\nEnter a new Login ID: ");
    scanf("%ld", &newUser.loginID);
    printf("Enter a new Password: ");
    scanf("%ld", &newUser.Password);
    newUser.verified = true;
    // Write the new user's credentials to the file
    writeCredentialsToFile(newUser.loginID, newUser.Password);
    printf("\nAccount created successfully!\n");
    printf("Now you will be guided to the login page.\nEnter your credentials there to log in\n");
    sleep(3);
    system("cls");
    login();
}

void guest()
{
    system("cls");
    system("color 5a");
    printf("\nGuest Mode Loading.....\n");
    sleep(2);
    struct Credentials guestUser;
    guestUser.loginID = 12345;
    guestUser.Password = 12345;
    guestUser.verified = true;
    printf("\nGuest Mode READY.....\n");
    sleep(2);
        printf("**************************************\n");
        printf("*          WELCOME GUEST             *\n");
        printf("**************************************\n");
    sleep(3);
    printf("Guiding you to Main Menu...");
    sleep(3);
    int choice = mainMenu();
    taskManager(guestUser,choice);
}

bool validate(int dob)
{
    int day=dob/10000;
    int month=(dob/100)%100;
    int year=dob%100;
    if(year<0||year>99||month<1||month>12||day<1||day>31)
    {
         return false;
    }
    if((month==2&&day>29)||((month==4||month==6||month==9||month==11)&&day>30))
    {
        return false;
    }
    return true;
}

void taskManager(struct Credentials user,int choice)
{
    retry:
    switch(choice) 
    {
        case 1:
            seeToDoList(user);
            break;
        case 2:
            updateToDoList(user);
            break;
        case 3:
            createNewToDoList(user);
            break;
        case 4:
            deleteToDoList(user);
            break;
        case 5:
            editTasks(user);
            break;
        case 6:
            escape();
        default:
            printf("Invalid choice. Please choose a valid option.\n");
            sleep(5);
            choice=mainMenu();
            goto retry;
    }
}

void seeToDoList(struct Credentials user)
{
    // Implement code to display the user's ToDo List
    // You can read tasks associated with the loginID.txt from a file and display them.
}

void updateToDoList(struct Credentials user)
{
    // Implement code to update the user's ToDo List with %completion of tasks and the completed tasks
}

void createNewToDoList(struct Credentials user)
{
    // Implement code to create a new ToDo List for the user
}

void deleteToDoList(struct Credentials user)
{
    // Implement code to delete the user's ToDo List
}

void editTasks(struct Credentials user)
{
    // Implement code to edit tasks in the user's ToDo List
}