#include<stdio.h>
#include<stdbool.h>

void createAccount();
void writeCredentialsToFile(long loginID, long Password) ;
bool readCredentialsFromFile(long loginID, long Password);
void login() ;

void writeCredentialsToFile(long loginID, long Password) 
{
    FILE *file = fopen("Credentials.txt", "a");
    fprintf(file,"Hello\n");
    fprintf(file, "%ld,%ld\n", loginID, Password);
    fclose(file);
}

bool readCredentialsFromFile(long loginID, long Password) 
{
    FILE *file = fopen("Credentials.txt", "r");
    long storedLoginID, storedPassword;
    bool found = false;
    char line[100];
    while(fgets(line, sizeof(line), file) != NULL) 
    {
        sscanf(line, "%ld,%ld", &storedLoginID, &storedPassword);
        if (loginID == storedLoginID && Password == storedPassword) 
        {
            found = true;
            break;
        }
    }    
    fclose(file);
    return found;
}
void login() 
{
    long id,password;
    printf("Login\n");
    printf("Enter your Login ID: ");
    scanf("%ld", &id);
    printf("Enter your Password: ");
    scanf("%ld", &password);
    
    if (readCredentialsFromFile(id, password)) 
    {
        printf("Login successful!\n");
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
            case 3 :    login();            break;
            default :   goto DEFAULT;
        }       
    }
}

void createAccount() 
{
    long loginid,password;
    id:
    printf("\nEnter a new Login ID: ");
    scanf("%ld", &loginid);
    printf("\nEnter a new Password: ");
    scanf("%ld", &password);
    writeCredentialsToFile(loginid, password);  
    printf("\nAccount created successfully!\n");
    login();
}
 int main()
 {
    createAccount();
    return 0;
 }