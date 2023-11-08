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
    char taskname[20];
    char description[500];
    int  percent_complete;
    bool completed;
    int  priority;//set priority on a scale of 1-5
    int  lastDate;//last date to complete the task
    int  time;//last time to complete the task
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

int  seeToDoList(struct Credentials user);
void updateToDoList(struct Credentials user);
void filterToDoList(struct Credentials user);
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
    system("cls");
    system("color 3E");
    printf("\n\t\t\t\t\t\t  ________________________________________________________________________");
    printf("\n\t\t\t\t\t\t||                                                                        ||");
    printf("\n\t\t\t\t\t\t|| ---------- |     |    /\\    |\\    | |  /      \\     / |=====| |    |   ||");
    printf("\n\t\t\t\t\t\t||     ||     |     |   /  \\   | \\   | | /        \\   /  |     | |    |   ||");
    printf("\n\t\t\t\t\t\t||     ||     |=====|  /====\\  |  \\  | |/          \\=/   |     | |    |   ||");
    printf("\n\t\t\t\t\t\t||     ||     |     | /      \\ |   \\ | |\\           |    |     | |    |   ||");
    printf("\n\t\t\t\t\t\t||     ||     |     |/        \\|    \\| | \\          |    |=====| |====|   ||");
    printf("\n\t\t\t\t\t\t||________________________________________________________________________||\n");
    sleep(2);
    system("cls");
    printf("\n\n");

    system("color 2E");
    int choice=1;
    printf("Would you like to provide feedback? (1: Yes, 2: No): ");
    fflush(stdin);
    scanf("%d",&choice);

    if(choice == 1)
    {
        // Feedback form
        char feedback[1000];
        printf("\nPlease provide your feedback (up to 999 characters):\n");
        fflush(stdin);
        fgets(feedback, sizeof(feedback), stdin);

        // Save the feedback to a file
        size_t feedback_length = strlen(feedback);
        if(feedback_length > 0 && feedback[feedback_length - 1] == '\n')
        {
            feedback[feedback_length - 1] = '\0';
        }

        FILE *feedbackFile = fopen("feedback.txt", "a");
        if(feedbackFile == NULL)
        {
            printf("Error saving feedback. Please try again later.\n");
        }
        else
        {
            fprintf(feedbackFile,"%s\n",feedback);
            fclose(feedbackFile);
            printf("Thank you for your feedback! It has been saved in feedback.txt.\n");
        }
    }

    printf("\nGoodbye! Have a great day!\n");
    sleep(1);
    system("cls");
    exit(0);
  }

  else
  {
    homePage();
  }
  return;
}

int mainMenu()
{
    //This function is used to print the Menu of the Todo list and returns a choice entered by the user.
    int choice;

    system("cls");
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
    printf("\n\t\t\t\t\t\t 3. Update Completion status of the task in ToDo List. \n");
    printf("\n\t\t\t\t\t\t 4. Filter tasks in ToDo List \n");
    printf("\n\t\t\t\t\t\t 5. Delete a task in ToDo List. \n");
    printf("\n\t\t\t\t\t\t 6. Edit task(s) in your ToDo List. \n");
    printf("\n\t\t\t\t\t\t 7. Exit ");
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
    sleep(2);
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
    sleep(2);
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
    sleep(2);
    login();
}

void guest()
{
    system("cls");
    system("color 5a");
    printf("\nGuest Mode Loading.....\n");
    sleep(1);
    struct Credentials guestUser;
    guestUser.loginID = 12345;
    guestUser.Password = 12345;
    guestUser.verified = true;
    printf("\nGuest Mode READY.....\n");
    sleep(1);
        printf("**************************************\n");
        printf("*          WELCOME GUEST             *\n");
        printf("**************************************\n");
    sleep(1);
    printf("Guiding you to Main Menu...");
    sleep(2);
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
                updateToDoList(user);
                break;
            case 4:
                filterToDoList(user);
                break;
            case 5:
                deleteToDoList(user);
                break;
            case 6:
                editTasks(user);
                break;
            case 7:
                escape();
            default:
                printf("Invalid choice. Please choose a valid option.\n");
                sleep(5);
                choice=mainMenu();
                goto retry;
        }

        printf("\n");
        printf("\tPlease choose an option:\n");
        printf("\t1. Continue with the same operation\n");
        printf("\t0. Return to MAIN MENU\n");
        printf("\tEnter your choice: ");
        scanf("%d", &continueTasks);

    }while(continueTasks);

    taskManager(user,mainMenu());
}

int seeToDoList(struct Credentials user)
{
    int serial=0;
    char filename[20];
    sprintf(filename, "%ld.txt", user.loginID); // Generate the file's name based on the user's loginID
    system("cls");

    FILE *file =fopen(filename,"r");
    if(file==NULL)
    {
        printf("Your ToDo List is empty.\n");
    }
    else
    {
        serial = 1;

        printf("**********************************************************************************************************************************************\n");
        printf("*   Serial No |   Task Name                  |   %% Complete  |   Completed  |   Priority   |   Due Date  |  Due Time  |    Category          *\n");
        printf("**********************************************************************************************************************************************\n");

        struct Task task;
        char line[1000];

        while(fgets(line, sizeof(line), file) != NULL)
        {
            if(sscanf(line, "Task Name: %19s", task.taskname) == 1)
            {
                // Successfully read the task name, now process the rest of the data
                fgets(line, sizeof(line), file); // Read the description line
                sscanf(line, "Description: %499[^\n]", task.description); // Read the description

                fgets(line, sizeof(line), file); // Read the next line
                sscanf(line, "Completion Percentage: %d", &task.percent_complete);

                fgets(line, sizeof(line), file);
                sscanf(line, "Completed: %d", &task.completed);

                fgets(line, sizeof(line), file);
                sscanf(line, "Priority: %d", &task.priority);

                fgets(line, sizeof(line), file);
                sscanf(line, "Last Date: %d", &task.lastDate);

                fgets(line, sizeof(line), file);
                sscanf(line, "Last Time: %d", &task.time);

                fgets(line, sizeof(line), file);
                sscanf(line, "Category: %19s", task.category);

                printf("* %10d  | %-28s | %11d%%  | %-11s  | %11d  | %10d  | %9d  | %-20s *\n",
                       serial, task.taskname, task.percent_complete, task.completed ? "Yes" : "No",
                       task.priority, task.lastDate, task.time, task.category);
                printf("**********************************************************************************************************************************************\n");

                serial++; // Increment the serial number
            }
        }

        fclose(file);
        return serial;
    }
}

void addTask(struct Credentials user)
{
    system("cls");
    printf("********************************************************************\n");
    printf("*                      Add New Task                                *\n");
    printf("********************************************************************\n");

    char fileName[50];
    sprintf(fileName, "%ld.txt", user.loginID); // Generate the file's name based on the user's loginID

    FILE *file = fopen(fileName, "a"); // Open file in append mode
    if(file==NULL)
    {
        printf("Error opening file.\n");
        return;
    }




    struct Task newTask;
    printf("Enter task name (up to 19 characters): ");
    scanf("%19s", newTask.taskname);

    printf("Enter task description (up to 499 characters): ");
    scanf(" %[^\n]", newTask.description);

    printf("Enter task completion percentage: ");
    scanf("%d", &newTask.percent_complete);

    newTask.completed = false; // Initialize to false

    printf("Enter task priority (1-5): ");
    scanf("%d", &newTask.priority);

    printf("Enter last date to complete the task: ");
    scanf("%d", &newTask.lastDate);

    printf("Enter last time to complete the task: ");
    scanf("%d", &newTask.time);

    printf("Enter task category (up to 19 characters): ");
    scanf("%19s", newTask.category);

    fprintf(file, "Task Name: %s\n", newTask.taskname);
    fprintf(file, "Description: %s\n", newTask.description);
    fprintf(file, "Completion Percentage: %d\n", newTask.percent_complete);
    fprintf(file, "Completed: %d\n", newTask.completed);
    fprintf(file, "Priority: %d\n", newTask.priority);
    fprintf(file, "Last Date: %d\n", newTask.lastDate);
    fprintf(file, "Last Time: %d\n", newTask.time);
    fprintf(file, "Category: %s\n", newTask.category);
    fprintf(file, "\n");
    fclose(file);
    printf("Task added successfully.\n");
    sleep(2);
}

void updateToDoList(struct Credentials user)
{
    system("cls");

    printf("********************************************************************\n");
    printf("*                      Update To-Do List                           *\n");
    printf("********************************************************************\n");

    char filename[20];
    sprintf(filename, "%ld.txt", user.loginID);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    int taskNumber = seeToDoList(user);
    int taskChoice;

    printf("Enter the task number you want to update (0 to exit): ");
    scanf("%d", &taskChoice);

    if(taskChoice<=0||taskChoice>taskNumber)
    {
        printf("No task selected or invalid task number.\n");
        fclose(file);
        return;
    }

    char line[1000];
    int serial = 1;

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        printf("Error creating the temporary file.\n");
        fclose(file);
        return;
    }

    while(fgets(line, sizeof(line), file) != NULL)
    {
        int percent;
        bool completed;
        if(strstr(line, "Completion Percentage")!=NULL)
        {
            int percent;
            if(serial==taskChoice)
            {
                printf("Enter updated completion percentage: ");
                scanf("%d", &percent);
                fprintf(tempFile, "Completion Percentage: %d\n",percent);
                printf("To-Do List updated successfully.\n");
                if(percent==100)
                {
                    completed=true;
                    fgets(line, sizeof(line), file);
                    fprintf(tempFile, "Completed: %d\n", completed);
                }

            }
            else            fprintf(tempFile, "%s", line);
            serial++;
        }
        else            fprintf(tempFile, "%s", line);
    }

    // Close the files
    fclose(file);
    fclose(tempFile);

    //Reopen the file
    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    tempFile = fopen("temp.txt", "r");

    if (tempFile == NULL)
    {
        printf("Error creating the temporary file.\n");
        fclose(file);
        return;
    }

    while(fgets(line, sizeof(line), tempFile) != NULL)
    {
        fprintf(file, "%s", line);
    }

    //closing the file
    fclose(file);
    fclose(tempFile);
    sleep(2);
}

void deleteToDoList(struct Credentials user)
{
    system("cls");
    printf("********************************************************************\n");
    printf("*                   Delete To-Do List                               *\n");
    printf("********************************************************************\n");
    
    char filename[20];
    sprintf(filename, "%ld.txt", user.loginID);

    FILE *inputFile, *tempFile;
    int taskNumber, found = 0;
    char task[100];

    // Open the input file in read mode
    inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Error opening file!\n");
        return ;
    }
    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening file!\n");
        fclose(inputFile);
        return ;
    }
    printf("Enter task number to delete: ");
    scanf("%d", &taskNumber);
    while (fscanf(inputFile, "%d %[^\n]s", &found, task) != EOF) {
        if (found != taskNumber) {
            fprintf(tempFile, "%d %s\n", found, task);
        }
    }
    fclose(inputFile);
    fclose(tempFile);
    remove("filename.txt");
    rename("temp.txt", "filename.txt");

    printf("Task deleted successfully.\n");
    // Implement code to delete the user's To-Do List
    printf("To-Do List deleted successfully.\n");
    sleep(2);
}
void editTasks(struct Credentials user)
{
    system("cls");
    printf("********************************************************************\n");
    printf("*                      Edit Tasks                                  *\n");
    printf("********************************************************************\n");

    char filename[20];
    char response;
    sprintf(filename, "%ld.txt", user.loginID);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    FILE *edit = fopen("edit.txt", "a");
    if (edit == NULL) {
        printf("Error creating the editable file.\n");
        fclose(file);
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        fputc(ch, edit);
    }

    fclose(file);
    fclose(edit);

    printf("File contents copied successfully to edit.txt.\n");

    printf("Do you want to edit the file? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        edit = fopen("edit.txt", "r+");

        if (edit == NULL) {
            printf("Error opening the destination file for editing.\n");
            return;
        }

        int taskNumber = seeToDoList(user);
        int taskChoice;

        printf("Enter the task number you want to edit (0 to exit): ");
        scanf("%d", &taskChoice);

        if (taskChoice <= 0 || taskChoice > taskNumber) {
            printf("No task selected or invalid task number.\n");
            fclose(edit);
            return;
        }

        FILE *tempEdit = fopen("temp_edit.txt", "w");

        if (tempEdit == NULL) {
            printf("Error creating a temporary file for editing.\n");
            fclose(edit);
            return;
        }

        char line[100]; // Assuming each line can have up to 100 characters
        int currentTask = 0;

        while (fgets(line, sizeof(line), edit) != NULL) {
            currentTask++;
            if (currentTask == taskChoice) {
                printf("Enter the new editable task : \n");
                char editedTask[100];
                getchar(); // Clearing the input buffer
                fgets(editedTask, sizeof(editedTask), stdin);
                fprintf(tempEdit, "%s", editedTask);
            } else {
                fprintf(tempEdit, "%s", line);
            }
        }

        fclose(tempEdit);
        fclose(edit);

        remove("edit.txt");
        rename("temp_edit.txt", "edit.txt");

        printf("Tasks edited successfully.\n");

        // Copy the edited content from edit.txt back to filename
        file = fopen(filename, "w");
        edit = fopen("edit.txt", "r");

        if (file == NULL || edit == NULL) {
            printf("Error opening files for copying.\n");
            return;
        }

        while ((ch = fgetc(edit)) != EOF) {
            fputc(ch, file);
        }

        fclose(file);
        fclose(edit);
    }
    sleep(2);
}


void filterToDoList(struct Credentials user)
{


}
