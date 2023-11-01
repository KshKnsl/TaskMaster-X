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
    char name[50];
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
bool loginIDExists(long loginID) ;
void taskManager(struct Credentials user,int choice);
void seeToDoList(struct Credentials user);
void updateToDoList(struct Credentials user);
void createNewToDoList(struct Credentials user);
void deleteToDoList(struct Credentials user);
void editTasks(struct Credentials user);
bool validateName(char* name);
void addTask(struct Credentials user);

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
    sleep(3);
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
    printf("\n\t\t\t\t\t\t 2. Add tasks to your ToDo List. \n");
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
    sleep(3);
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
    char name[50];
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
    retry1:
    printf("Enter your first name: ");
    scanf("%49s", name);
    if(validateName(name))
    {
         strcpy(newUser.name,name);
         printf("----------Name Validated Successfully----------- \n");
    }
    else
    {     
        printf("\nInvalid Name. Please use only letters and spaces.Retry.....");
        goto retry1;    
    }
    retry2:
    printf("Enter your date of birth (format DDMMYY): ");
    scanf("%d", &dob);

    if(!validate(dob))
    {
        printf("\nWrong Date of birth......Retry.....");
        goto retry2;
    }
    else
    {
        printf("-----------Date Validated Successfully------------ \n");
    }
    long newLoginID;
    while(1) 
    {
        printf("Enter a new Login ID: ");
        scanf("%ld", &newLoginID);
        if(loginIDExists(newLoginID))
            printf("Login ID already exists. Please choose a different one.\n");
        else
        {
            newUser.loginID = newLoginID;
            break;
        }
    }
    printf("Enter a new Password: ");
    scanf("%ld", &newUser.Password);
    newUser.verified = true;
    writeCredentialsToFile(newUser.loginID, newUser.Password);
    printf("\nAccount created successfully!\n");
    printf("Now you will be guided to the login page.\nEnter your credentials there in order to LOGIN\n");
    sleep(3);
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


bool validateName(char* name)
{
    int i;
    if(name[0]=='\0')
        return false;
    for(i=0;name[i]!='\0';i++) 
    {
        char ch=name[i];
        if(!((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||ch==' '))
            return false;
    }
    return true;
}

bool loginIDExists(long loginID) 
{
    FILE *file = fopen("Credentials.txt","r");
    long storedLoginID, storedPassword;
    bool found=false;
    char line[100];   
    while(fgets(line,sizeof(line),file)!=NULL) 
    {
        sscanf(line,"%ld,%ld",&storedLoginID,&storedPassword);    
        if(loginID==storedLoginID) 
        {
            found = true;
            break;
        }
    }
    fclose(file);
    return found;
}

void taskManager(struct Credentials user,int choice)
{
    bool continueTasks = false;
    do
    {
        retry:
        switch(choice) 
        {
            case 1:
                seeToDoList(user);
                break;
            case 2:
                addTask(user);
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
        printf("If you want to continue with the same operation press 1.\n");
        printf("If you want to return to MAIN MENU press 0.");
        scanf("%d", &continueTasks);
    }while(continueTasks);
    taskManager(user,mainMenu());
}

void seeToDoList(struct Credentials user) 
{
    char filename[20];
    sprintf(filename,"%ld.txt",user.loginID); // Generate the file's name based on the user's loginID
    system("cls");
    
    FILE *file = fopen(filename, "r");
    if(file==NULL) 
    {
        printf("Your ToDo List is empty.\n");
    } 
    else 
    {
       printf("Tasks present in the Taskmaster:\n");
       printf("*********************************************************************************************\n");
       printf("*   Task ID   |   Task Name   |   % Complete   |   Priority   |   Due Date   |   Due Time   *\n");
       printf("*********************************************************************************************\n");
    
       char task[1000];
       while(fscanf(file,"%s",task)!=EOF)
       {
        printf("%s\n", task);
       }
        fclose(file);
    }
}

void addTask(struct Credentials user) {
    
    system("cls");
    printf("********************************************************************\n");
    printf("*                      Add New Task                                *\n");
    printf("********************************************************************\n");
    
    char fileName[50];
    sprintf(fileName,"%ld.txt",user.loginID); // Generate the file's name based on the user's loginID
    
    FILE *file = fopen(fileName, "a"); // Open file in append mode
    if (file==NULL) 
    {
        printf("Error opening file.\n");
        return;
    }
    struct Task newTask;
    printf("Enter task name (up to 20 characters): ");
    scanf("%s",newTask.taskname);

    printf("Enter task description (up to 500 characters): ");
    scanf(" %[^\n]",newTask.description);

    printf("Enter task completion percentage: ");
    scanf("%d", &newTask.percent_complete);

    //'completed' should be initially set to false
    newTask.completed = false;

    printf("Enter task priority (1-5): ");
    scanf("%d", &newTask.priority);

    printf("Enter last date to complete the task: ");
    scanf("%d", &newTask.lastDate);

    printf("Enter last time to complete the task: ");
    scanf("%d", &newTask.time);

    printf("Do you have any attachment to be stored ?(yes/no)");
    char ch;
    scanf("%c",&ch);
    scanf("%c",&ch);
    
    if(ch=='Y'||ch=='y')
    {
        printf("Enter any attachment (up to 100 characters): ");
        scanf(" %[^\n]", newTask.attactment);
    }
    else 
    {
        newTask.attactment[0] = '\0'; // Empty string if no attachment
    }

    printf("Enter task category (up to 20 characters): ");
    scanf("%s", newTask.category);

     fprintf(file, "%s_%s_%d_%d_%d_%d_%s_%s\n", newTask.taskname, newTask.description, newTask.percent_complete, newTask.completed,
        newTask.priority, newTask.lastDate, newTask.time, newTask.attactment, newTask.category);

    fclose(file);
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
