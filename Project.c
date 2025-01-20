#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

void adminlogin();
void admin();
void employee();
void customer();
void adminservices();
void employeeservices();
void phnnumber();

void searchbyid();
void searchbyrole();
void employee_details();
void entrytime();
void exittime();

void displaymenuadminlogin();
void displaymenucustomer();

void display_The_bengali_menu();
void display_The_american_menu();
void display_The_english_menu();
void display_The_indian_menu();
void display_The_middle_eastern_menu();

void insertMenu();
void insert_The_bengali_menu();
void insert_The_american_menu();
void insert_The_english_menu();
void insert_The_indian_menu();
void insert_The_middle_eastern_menu();

void deleteItem();
void delete_The_bengali_menu();
void delete_The_american_menu();
void delete_The_english_menu();
void delete_The_indian_menu();
void delete_The_middle_eastern_menu();

void updateprice();
void update_The_bengali_menu();
void update_The_american_menu();
void update_The_english_menu();
void update_The_indian_menu();
void update_The_middle_eastern_menu();

void orderfood();
void selectitem(char menu);
void viewcart();

void cash_or_card();
void process_cash();
void process_card();

void customerpurchasehistory();
void alltimehistory();
void specificdatehistory();

void searchbyword();
void moveCursorRelative(int dx, int dy);

void setColor(int color);
void reset();


char store[200];
char buffer[256];
char buffer2[256];
int id;
int employeeid;
char employeeposition[50];
int i = 0;
char Customername[100];
double total = 0;
int j = 0;
int track = 0;
char phone_number[15];
char mobile_number[20];
char menu;
int count = 0;
int productonfile = 0;
int id;
int load = 0;
char employeefile1[] = "C:\\Project\\EmployeeTime\\";


FILE *employeefile;
FILE *bengalimenu;
FILE *americanmenu;
FILE *englishmenu;
FILE *indianmenu;
FILE *middleeasternmenu;
FILE *customerfile;
FILE *appear;
FILE *check;
FILE *con;

struct Product
{
    long productId;
    char productName[100];
    int productQuantity;
    float productPrice;
};
struct Product product[100];

struct Admin
{
    int id;
    char password[50];
};

struct cartitem
{
    int num;
    char productName[50];
    int quantity;
    float price;
};
struct cartitem cartproducts[100];

struct Searchproduct
{
    int p_id;
    char p_name[50];
    float p_price;
};
struct Searchproduct search[100];

/*
Color	    Code
Black	     0
Dark Blue	 1
Dark Green	 2
Dark Cyan	 3
Dark Red	 4
Dark Magenta 5
Dark Yellow	 6
Light Gray	 7
Gray	     8
Blue	     9
Green	     10
Cyan	     11
Red	         12
Magenta	     13
Yellow	     14
White	     15
*/

int main()
{
    setColor(14);
    printf("                     _______                    \n");
    printf("                    //    ||   ||   ||   ||          \n");
    printf("                   //     ||   ||   ||   ||          \n");
    printf("                  //      ||   ||   ||   ||          \n");
    printf("                 //       ||   ||   ||   ||          \n");
    printf("                ((        ||   ||   ||   ||          \n");
    printf("                \\\\        ||   ||   ||   ||          \n");
    printf("                 \\\\       ||   ||   ||   ||          \n");
    printf("                  \\\\______||   \\\\ __/\\__ //          \n");
    printf("                     ||   ||     ||    ||        \n");
    printf("                     ||   ||     ||    ||        \n");
    printf("                     ||   ||     ||    ||        \n");
    printf("                     ||   ||     ||    ||        \n");
    printf("                     ||   ||     ||    ||        \n");
    printf("                     ||   ||     ||    ||        \n");
    printf("                     ||   ||     ||    ||        \n");
    printf("                     ||___||     ||____||        \n\n\n");

    printf("---------------------------------------------------------------\n");
    printf("|                                                             |\n");
    printf("---------------------------------------------------------------\n");
    setColor(12);
    char wel[] = "Welcome to Our Restaurant 'SPOONS'\n\n";
    moveCursorRelative(12, -2);
    for (int i = 0; i < sizeof(wel) / sizeof(wel[i]); i++)
    {
        printf("%c", wel[i]);
        fflush(stdout);
        usleep(50000);
    }
    reset();
    homepage();
    getch();
}

void reset()
{
    setColor(14);
}
void moveCursorRelative(int dx, int dy)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(hConsole, &info);
    COORD coord = {info.dwCursorPosition.X + dx, info.dwCursorPosition.Y + dy};
    SetConsoleCursorPosition(hConsole, coord);
}

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void homepage()
{
    while (1)
    {
        setColor(6);
        printf("\n---------------------------------------------------------------\n");
        printf("|                         Home Page                           |\n");
        printf("---------------------------------------------------------------\n");
        setColor(14);
        char ch;
        printf("1.Admin\n2.Employee\n3.Customer\n4.Exit\n");
        ch = _getch();
        switch (ch)
        {
        case '1':
            admin();
            break;
        case '2':
            employeeservices();
            break;
        case '3':
            customer();
            break;
        case '4':
            exit(0);
        default:
            setColor(12);
            printf("\n\t\t\tInvalid Choice\n\t\t\t  Try Again...");
            break;
        }
    }
    return;
    reset();
}

void admin()
{
    while (1)
    {
        setColor(3);
        printf("---------------------------------------------------------------\n");
        printf("|                       Admin Services                        |\n");
        printf("---------------------------------------------------------------\n");
        setColor(11);
        char ch;
        printf("1.Login\n2.Change Password\n3.Back\n\n");
        ch = _getch();
        switch (ch)
        {
        case '1':
            adminlogin();
            break;
        case '2':
            updatepass();
            break;
        case '3':
            homepage();
            exit(0);
        default:
            setColor(12);
            printf("\n\t\t\tInvalid Choice\n\t\t\t  Try Again...");
            break;
        }
    }
    reset();
    return;
}


void adminlogin()
{
    setColor(3);
    printf("---------------------------------------------------------------\n");
    printf("|                        Admin Login                          |\n");
    printf("---------------------------------------------------------------\n");
    setColor(11);
    struct Admin store[3];
    FILE *ptr;
    int p = 1;
    while (p)
    {
        ptr = fopen("C:\\Project\\Panels\\adminpanel.txt", "r");
        if (ptr == NULL)
        {
            printf("File doesn't Exist\n\n");
        }
        else
        {
            int id, i = 0;
            char pass[50];
            char ch;
            printf("Enter ID: ");
            scanf("%d", &id);
            fflush(stdin);
            printf("Enter Password: ");
            while (1)
            {
                ch = _getch();
                if (ch == 13)
                {
                    pass[i] = '\0';
                    printf("\n");
                    break;
                }
                else if (ch == '\b')
                {
                    if (i > 0)
                    {
                        i--;
                        printf("\b \b");
                    }
                }
                else if (ch != 32 && i < sizeof(pass) - 1)
                {
                    pass[i] = ch;
                    printf("*");
                    i++;
                }
            }
            i = 0;
            int count = 0;
            while ((fscanf(ptr, "%d,%s", &store[i].id, store[i].password)) == 2)
            {
                if (store[i].id == id && strcmp(pass, store[i].password) == 0)
                {
                    setColor(10);
                    printf("\n\t\t\tLogin Successful\n\n");
                    reset();
                    count++;
                    p = 0;
                    fclose(ptr);
                    adminservices();
                    break;
                }
            }
            if (count == 0)
            {
                setColor(12);
                printf("\n\t\t\tInvalid Choice\n\t\t\t  Try Again...\n");
                setColor(11);
                fclose(ptr);
            }
        }
    }

     reset();
}
void adminservices()
{
    while (1)
    {
        setColor(9);
        printf("\n---------------------------------------------------------------\n");
        printf("|                          Options                            |\n");
        printf("---------------------------------------------------------------\n");
        setColor(11);
        printf("1.Display Menu\n2.Insert Item\n3.Update Price\n4.Delete Item\n5.Employee Details\n6.Customer Details\n7.Logout\n\n");
        char sc;
        sc = _getch();
        switch (sc)
        {
        case '1':

            displaymenuadminlogin();
            break;
        case '2':

            insertMenu();
            break;
        case '3':

            updateprice();
            break;
        case '4':

            deleteItem();
            break;
        case '5':

            employee();
            break;
        case '6':

            customerpurchasehistory();
            break;
        case '7':

            homepage();
            return;
        default:
            setColor(12);
            printf("\n\t\t\tInvalid Choice\n\t\t\t  Try Again...");
        }
    }
    reset();
}

void updatepass()
{
    setColor(3);
    printf("\n\n---------------------------------------------------------------\n");
    printf("|                       Update Password                       |\n");
    printf("---------------------------------------------------------------\n");
    setColor(11);
    FILE *passoldfile, *passnewfile;
    passoldfile = fopen("C:\\Project\\Panels\\adminpanel.txt", "r");
    passnewfile = fopen("C:\\Project\\Panels\\temp_adminpanel.txt", "w");

    if (passoldfile == NULL || passnewfile == NULL)
    {
        perror("Error opening file");
        return;
    }

    char buffer[250];
    int id, preferedid, changed = 0;
    char oldpass[20], newpass1[20], newpass2[20], prefferedpass[20];
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter Old Password: ");
    int i = 0;
    while (1)
    {
        char ch = _getch();
        if (ch == 13)
        {
            oldpass[i] = '\0';
            printf("\n");
            break;
        }
        else if (ch == '\b')
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (ch != 32 && i < sizeof(oldpass) - 1)
        {
            oldpass[i] = ch;
            printf("*");
            i++;
        }
    }
    while (fgets(buffer, sizeof(buffer), passoldfile) != NULL)
    {
        if (sscanf(buffer, "%d,%[^\n]", &preferedid, prefferedpass) == 2)
        {
            if (id == preferedid && strcmp(oldpass, prefferedpass) == 0)
            {
                printf("\nEnter New Password: ");
                int i = 0;
                while (1)
                {
                    char ch = _getch();
                    if (ch == 13)
                    {
                        newpass1[i] = '\0';
                        printf("\n");
                        break;
                    }
                    else if (ch == '\b')
                    {
                        if (i > 0)
                        {
                            i--;
                            printf("\b \b");
                        }
                    }
                    else if (ch != 32 && i < sizeof(newpass1) - 1)
                    {
                        newpass1[i] = ch;
                        printf("*");
                        i++;
                    }
                }
                printf("Re-Enter New Password: ");
                i = 0;
                while (1)
                {
                    char ch = _getch();
                    if (ch == 13)
                    {
                        newpass2[i] = '\0';
                        printf("\n");
                        break;
                    }
                    else if (ch == '\b')
                    {
                        if (i > 0)
                        {
                            i--;
                            printf("\b \b");
                        }
                    }
                    else if (ch != 32 && i < sizeof(newpass2) - 1)
                    {
                        newpass2[i] = ch;
                        printf("*");
                        i++;
                    }
                }
                if (strcmp(newpass1, newpass2) == 0)
                {
                    changed++;
                    fprintf(passnewfile, "%d,%s\n", preferedid, newpass1);
                }
                else{
                    fprintf(passnewfile, "%d,%s\n", preferedid, prefferedpass);
                }
            }
            else
            {
                fprintf(passnewfile, "%d,%s\n", preferedid, prefferedpass);
            }
        }
    }

    if (changed > 0)
    {
        setColor(10);
        printf("\n\t\t Password Updated Successfully\n\n");
        setColor(11);
    }
    else
    {
        setColor(12);
        printf("\n\tWrong ID or Password......Try Again\n\n");
        setColor(11);
        fclose(passoldfile);
        fclose(passnewfile);
        remove("C:\\Project\\Panels\\temp_adminpanel.txt");
        updatepass();
        return;
    }

    fclose(passoldfile);
    fclose(passnewfile);
    remove("C:\\Project\\Panels\\adminpanel.txt");
    rename("C:\\Project\\Panels\\temp_adminpanel.txt", "C:\\Project\\Panels\\adminpanel.txt");
    return;

    reset();
}

void displaymenuadminlogin()
{

    while (1)
    {
        setColor(9);
        printf("\n---------------------------------------------------------------\n");
        printf("|                         Menu List                           |\n");
        printf("---------------------------------------------------------------\n");
        reset();
        printf("1.Bengali Menu\n2.Indian Menu\n3.Middle-Eastern Menu\n4.English Menu\n5.American Menu\n6.Back\n7.Exit\n\n");
        char choice;
        choice = _getch();
        switch (choice)
        {
        case '1':

            display_The_bengali_menu();
            break;
        case '2':

            display_The_indian_menu();
            break;
        case '3':

            display_The_middle_eastern_menu();
            break;
        case '4':

            display_The_english_menu();
            break;
        case '5':

            display_The_american_menu();
            break;
        case '6':

            adminservices();
            return;
        case '7':
            exit(0);
        default:
            setColor(12);
            printf("\n\t\t\tInvalid Choice\n\t\t\t  Try Again...");
        }
    }
    reset();
}


void display_The_bengali_menu()
{
    setColor(6);
    printf("\n---------------------------------------------------------------\n");
    printf("|                      Bengali Food                           |\n");
    printf("---------------------------------------------------------------\n");
    productonfile = 0;
    bengalimenu = fopen("C:\\Project\\Menu\\The_bengali_menu.txt", "r");
    if (bengalimenu == NULL)
    {
        printf("Unable to open file The_bengali_menu.txt\n");
    }
    else
    {
        printf("|  ID  |              Item Name             |       Price     |\n");
        printf("---------------------------------------------------------------\n");
        reset();
        i = 0;
        while ((fscanf(bengalimenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
        {
            productonfile++;
            printf("|  %02d  |  %-34s|      %-11.2f|\n", product[i].productId, product[i].productName, product[i].productPrice);
            i++;
            setColor(6);
            printf("---------------------------------------------------------------\n");
            reset();

        }
        if (productonfile == 0)
        {
            printf("|                     No Item Available                       |\n");
            printf("---------------------------------------------------------------\n");
        }
    }
    fclose(bengalimenu);
    reset();
}

void display_The_indian_menu()
{
    setColor(4);
    printf("\n---------------------------------------------------------------\n");
    printf("|                       Indian Food                           |\n");
    printf("---------------------------------------------------------------\n");
    productonfile = 0;
    indianmenu = fopen("C:\\Project\\Menu\\The_indian_menu.txt", "r");
    if (indianmenu == NULL)
    {
        printf("Unable to open file The_indian_menu.txt\n");
    }
    else
    {
        printf("|  ID  |              Item Name             |       Price     |\n");
        printf("---------------------------------------------------------------\n");
        reset();
        i = 0;
        while ((fscanf(indianmenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
        {
            productonfile++;
            printf("|  %02d  |  %-34s|      %-11.2f|\n", product[i].productId, product[i].productName, product[i].productPrice);
            i++;
            setColor(4);
            printf("---------------------------------------------------------------\n");
            reset();
        }
        if (productonfile == 0)
        {
            printf("|                     No Item Available                       |\n");
            printf("---------------------------------------------------------------\n");
        }
    }
    fclose(indianmenu);
    reset();
}

void display_The_middle_eastern_menu()
{
    setColor(2);
    productonfile = 0;
    printf("\n---------------------------------------------------------------\n");
    printf("|                  Middle-Eastern Food                        |\n");
    printf("---------------------------------------------------------------\n");
    middleeasternmenu = fopen("C:\\Project\\Menu\\The_middle_eastern_menu.txt", "r");
    if (middleeasternmenu == NULL)
    {
        printf("Unable to open file The_middle_eastern_menu.txt\n");
    }
    else
    {
        printf("|  ID  |              Item Name             |       Price     |\n");
        printf("---------------------------------------------------------------\n");
        reset();
        i = 0;
        while ((fscanf(middleeasternmenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
        {
            productonfile++;
            printf("|  %02d  |  %-34s|      %-11.2f|\n", product[i].productId, product[i].productName, product[i].productPrice);
            i++;
            setColor(2);
            printf("---------------------------------------------------------------\n");
            reset();
        }
        if (productonfile == 0)
        {
            printf("|                     No Item Available                       |\n");
            printf("---------------------------------------------------------------\n");
        }
    }
    fclose(middleeasternmenu);
    reset();
}

void display_The_english_menu()
{
    setColor(5);
    productonfile = 0;
    printf("\n---------------------------------------------------------------\n");
    printf("|                      English Food                           |\n");
    printf("---------------------------------------------------------------\n");

    englishmenu = fopen("C:\\Project\\Menu\\The_english_menu.txt", "r");
    if (englishmenu == NULL)
    {
        printf("Unable to open file The_english_menu.txt\n");
    }
    else
    {
        printf("|  ID  |              Item Name             |       Price     |\n");
        printf("---------------------------------------------------------------\n");
        reset();
        i = 0;
        while ((fscanf(englishmenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
        {
            productonfile++;
            printf("|  %02d  |  %-34s|      %-11.2f|\n", product[i].productId, product[i].productName, product[i].productPrice);
            i++;
            setColor(5);
            printf("---------------------------------------------------------------\n");
            reset();
        }
        if (productonfile == 0)
        {
            printf("|                   No Item Available                      |\n");
            printf("---------------------------------------------------------------\n");
        }
    }
    fclose(englishmenu);
    reset();
}

void display_The_american_menu()
{
    setColor(13);
    productonfile = 0;
    printf("\n---------------------------------------------------------------\n");
    printf("|                      American Food                          |\n");
    printf("---------------------------------------------------------------\n");
    americanmenu = fopen("C:\\Project\\Menu\\The_american_menu.txt", "r");
    if (americanmenu == NULL)
    {
        printf("Unable to open file The_american_menu.txt\n");
    }
    else
    {

        printf("|  ID  |              Item Name             |       Price     |\n");
        printf("---------------------------------------------------------------\n");
        reset();
        i = 0;
        while ((fscanf(americanmenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
        {
            productonfile++;
            printf("|  %02d  |  %-34s|      %-11.2f|\n", product[i].productId, product[i].productName, product[i].productPrice);
            i++;
            setColor(13);
            printf("---------------------------------------------------------------\n");
            reset();
        }
        if (productonfile == 0)
        {
            printf("|                   No Product Available                      |\n");
            printf("---------------------------------------------------------------\n");
        }
    }
    fclose(americanmenu);
    reset();
}
void insertMenu()
{
    while (1)
    {
        setColor(10);
        printf("\n---------------------------------------------------------------\n");
        printf("|                       Insert Item                           |\n");
        printf("---------------------------------------------------------------\n");
        reset();
        printf("1.Bengali Menu\n2.Indian Menu\n3.Middle-Eastern Menu\n4.English Menu\n5.American Menu\n6.Back\n7.Exit\n\n");
        char choice;
        choice = _getch();
        switch (choice)
        {
        case '1':

            insert_The_bengali_menu();
            break;
        case '2':

            insert_The_indian_menu();
            break;
        case '3':

            insert_The_middle_eastern_menu();
            break;
        case '4':

            insert_The_english_menu();
            break;
        case '5':

            insert_The_american_menu();
            break;
        case '6':

            adminservices();
            return;
        case '7':
            exit(0);
        default:
            setColor(12);
            printf("\n\t\t Invalid Choice\nTry Again...");
        }
    }
}

void insert_The_bengali_menu()
{
    i = 0;
    display_The_bengali_menu();
    bengalimenu = fopen("C:\\Project\\Menu\\The_bengali_menu.txt", "a");
    fflush(stdin);
    char Productname[100];
    printf("\nEnter Product Name: ");
    scanf("%[^\n]", Productname);
    printf("Enter Price: ");
    double price;
    scanf("%lf", &price);
    fprintf(bengalimenu, "%d,%s,%.2lf\n", i + 1, Productname, price);
    fclose(bengalimenu);
}

void insert_The_indian_menu()
{
    i = 0;
    display_The_indian_menu();
    indianmenu = fopen("C:\\Project\\Menu\\The_indian_menu.txt", "a");
    fflush(stdin);
    char Productname[100];
    printf("\nEnter Product Name: ");
    scanf("%[^\n]", Productname);
    printf("Enter Price: ");
    double price;
    scanf("%lf", &price);
    fprintf(indianmenu, "%d,%s,%.2lf\n", i + 1, Productname, price);
    fclose(indianmenu);
}

void insert_The_middle_eastern_menu()
{
    i = 0;
    display_The_middle_eastern_menu();
    middleeasternmenu = fopen("C:\\Project\\Menu\\The_middle_eastern_menu.txt", "a");
    fflush(stdin);
    char Productname[100];
    printf("\nEnter Product Name: ");
    scanf("%[^\n]", Productname);
    printf("Enter Price: ");
    double price;
    scanf("%lf", &price);
    fprintf(middleeasternmenu, "%d,%s,%.2lf\n", i + 1, Productname, price);
    fclose(middleeasternmenu);
}

void insert_The_english_menu()
{
    i = 0;
    display_The_english_menu();
    englishmenu = fopen("C:\\Project\\Menu\\The_english_menu.txt", "a");
    fflush(stdin);
    char Productname[100];
    printf("\nEnter Product Name: ");
    scanf("%[^\n]", Productname);
    printf("Enter Price: ");
    double price;
    scanf("%lf", &price);
    fprintf(englishmenu, "%d,%s,%.2lf\n", i + 1, Productname, price);
    fclose(englishmenu);
}

void insert_The_american_menu()
{
    i = 0;
    display_The_american_menu();
    americanmenu = fopen("C:\\Project\\Menu\\The_american_menu.txt", "a");
    fflush(stdin);
    char Productname[100];
    printf("\nEnter Product Name: ");
    scanf("%[^\n]", Productname);
    printf("Enter Price: ");
    double price;
    scanf("%lf", &price);
    fprintf(americanmenu, "%d,%s,%.2lf\n", i + 1, Productname, price);
    fclose(americanmenu);
}
void deleteItem()
{
    while (1)
    {
        setColor(12);
        printf("\n---------------------------------------------------------------\n");
        printf("|                       Delete Item                           |\n");
        printf("---------------------------------------------------------------\n");
        reset();
        printf("1.Bengali Menu\n2.Indian Menu\n3.Middle-Eastern Menu\n4.English Menu\n5.American Menu\n6.Back\n7.Exit\n\n");
        char choice;
        choice = _getch();
        switch (choice)
        {
        case '1':

            delete_The_bengali_menu();
            break;
        case '2':

            delete_The_indian_menu();
            break;
        case '3':

            delete_The_middle_eastern_menu();
            break;
        case '4':

            delete_The_english_menu();
            break;
        case '5':

            delete_The_american_menu();
            break;
        case '6':

            adminservices();
            return;
        case '7':
            exit(0);
        default:
            setColor(12);
            printf("\n\t\tThis Menu doesn't exist\n");
        }
    }
    reset();
}

void delete_The_bengali_menu()
{
    display_The_bengali_menu();
    FILE *newfile;
    newfile = fopen("C:\\Project\\Menu\\temp_The_bengali_menu.txt", "w");
    bengalimenu = fopen("C:\\Project\\Menu\\The_bengali_menu.txt", "r");
    printf("\nEnter Product ID: ");
    int id;
    scanf("%d", &id);
    i = 0;
    int j = 0, count = 0;
    while ((fscanf(bengalimenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
    {

        if (id == product[i].productId)
        {
            printf("\nProduct Name: %s\nPrice: %.2lf\n", product[i].productName, product[i].productPrice);
            count++;
        }
        else
        {
            j++;
            fprintf(newfile, "%d,%s,%.2lf\n", j, product[i].productName, product[i].productPrice);
        }
        i++;
    }
    if (count == 0)
    {
        printf("Item Not found to delete\n");
    }
    fclose(bengalimenu);
    fclose(newfile);
    remove("C:\\Project\\Menu\\The_bengali_menu.txt");
    rename("C:\\Project\\Menu\\temp_The_bengali_menu.txt", "C:\\Project\\Menu\\The_bengali_menu.txt");
}

void delete_The_indian_menu()
{
    display_The_indian_menu();
    FILE *newfile;
    newfile = fopen("C:\\Project\\Menu\\temp_The_indian_menu.txt", "w");
    indianmenu = fopen("C:\\Project\\Menu\\The_indian_menu.txt", "r");
    printf("\nEnter Product ID: ");
    int id;
    scanf("%d", &id);
    i = 0;
    int j = 0, count = 0;
    while ((fscanf(indianmenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
    {

        if (id == product[i].productId)
        {
            printf("\nProduct Name: %s\nPrice: %.2lf\n", product[i].productName, product[i].productPrice);
            count++;
        }
        else
        {
            j++;
            fprintf(newfile, "%d,%s,%.2lf\n", j, product[i].productName, product[i].productPrice);
        }
        i++;
    }
    if (count == 0)
    {
        printf("Item Not found to delete\n");
    }
    fclose(indianmenu);
    fclose(newfile);
    remove("C:\\Project\\Menu\\The_indian_menu.txt");
    rename("C:\\Project\\Menu\\temp_The_indian_menu.txt", "C:\\Project\\Menu\\The_indian_menu.txt");
}

void delete_The_middle_eastern_menu()
{
    display_The_middle_eastern_menu();
    FILE *newfile;
    newfile = fopen("C:\\Project\\Menu\\temp_The_middle_eastern_menu.txt", "w");
    middleeasternmenu = fopen("C:\\Project\\Menu\\The_middle_eastern_menu.txt", "r");
    printf("\nEnter Product ID: ");
    int id;
    scanf("%d", &id);
    i = 0;
    int j = 0, count = 0;
    while ((fscanf(middleeasternmenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
    {

        if (id == product[i].productId)
        {
            printf("\nProduct Name: %s\nPrice: %.2lf\n", product[i].productName, product[i].productPrice);
            count++;
        }
        else
        {
            j++;
            fprintf(newfile, "%d,%s,%.2lf\n", j, product[i].productName, product[i].productPrice);
        }
        i++;
    }
    if (count == 0)
    {
        printf("Item Not found to delete\n");
    }
    fclose(middleeasternmenu);
    fclose(newfile);
    remove("C:\\Project\\Menu\\The_middle_eastern_menu.txt");
    rename("C:\\Project\\Menu\\temp_The_middle_eastern_menu.txt", "C:\\Project\\Menu\\The_middle_eastern_menu.txt");
}

void delete_The_english_menu()
{
    display_The_english_menu();
    FILE *newfile;
    newfile = fopen("C:\\Project\\Menu\\temp_The_english_menu.txt", "w");
    englishmenu = fopen("C:\\Project\\Menu\\The_english_menu.txt", "r");
    printf("\nEnter Product ID: ");
    int id;
    scanf("%d", &id);
    i = 0;
    int j = 0, count = 0;
    while ((fscanf(englishmenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
    {

        if (id == product[i].productId)
        {
            printf("\nProduct Name: %s\nPrice: %.2lf\n", product[i].productName, product[i].productPrice);
            count++;
        }
        else
        {
            j++;
            fprintf(newfile, "%d,%s,%.2lf\n", j, product[i].productName, product[i].productPrice);
        }
        i++;
    }
    if (count == 0)
    {
        printf("Item Not found to delete\n");
    }
    fclose(englishmenu);
    fclose(newfile);
    remove("C:\\Project\\Menu\\The_english_menu.txt");
    rename("C:\\Project\\Menu\\temp_The_english_menu.txt", "C:\\Project\\Menu\\The_english_menu.txt");
}

void delete_The_american_menu()
{
    display_The_american_menu();
    FILE *newfile;
    newfile = fopen("C:\\Project\\Menu\\temp_The_american_menu.txt", "w");
    americanmenu = fopen("C:\\Project\\Menu\\The_american_menu.txt", "r");
    printf("\nEnter Product ID: ");
    int id;
    scanf("%d", &id);
    i = 0;
    int j = 0, count = 0;
    while ((fscanf(americanmenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
    {

        if (id == product[i].productId)
        {
            printf("\nProduct Name: %s\nPrice: %.2lf\n", product[i].productName, product[i].productPrice);
            printf("\nEnter New Price: ");
            count++;
        }
        else
        {
            j++;
            fprintf(newfile, "%d,%s,%.2lf\n", j, product[i].productName, product[i].productPrice);
        }
        i++;
    }
    if (count == 0)
    {
        printf("Item Not found to delete\n");
    }
    fclose(americanmenu);
    fclose(newfile);
    remove("C:\\Project\\Menu\\The_american_menu.txt");
    rename("C:\\Project\\Menu\\temp_The_american_menu.txt", "C:\\Project\\Menu\\The_american_menu.txt");
}

void updateprice()
{
    setColor(14);
    while (1)
    {
        printf("\n---------------------------------------------------------------\n");
        printf("|                       Update Item                           |\n");
        printf("---------------------------------------------------------------\n");
        printf("1.Bengali Menu\n2.Indian Menu\n3.Middle-Eastern Menu\n4.English Menu\n5.American Menu\n6.Back\n7.Exit\n\n");
        char choice;
        choice = _getch();
        switch (choice)
        {
        case '1':

            update_The_bengali_menu();
            break;
        case '2':

            update_The_indian_menu();
            break;
        case '3':

            update_The_middle_eastern_menu();
            break;
        case '4':

            update_The_english_menu();
            break;
        case '5':

            update_The_american_menu();
            break;
        case '6':

            adminservices();
            return;
        case '7':
            exit(0);
        default:
            setColor(12);
            printf("\n\t\tInvalid Choice\n\t\t  Try Again...");
        }
    }
    reset();
}

void update_The_bengali_menu()
{
    display_The_bengali_menu();
    FILE *newfile;
    printf("\nEnter product ID: ");
    int id;
    scanf("%d", &id);
    newfile = fopen("C:\\Project\\Menu\\temp_The_bengali_menu.txt", "w");
    bengalimenu = fopen("C:\\Project\\Menu\\The_bengali_menu.txt", "r");
    i = 0;
    int count = 0;
    while ((fscanf(bengalimenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
    {
        if (id == product[i].productId)
        {
            count++;
            printf("\nProduct Name: %s\nOld Price: %.2lf\n", product[i].productName, product[i].productPrice);
            printf("\nEnter New Price: ");
            scanf("%f", &product[i].productPrice);
        }
        fprintf(newfile, "%d,%s,%.2lf\n", product[i].productId, product[i].productName, product[i].productPrice);
        i++;
    }
    if (count == 0)
    {
        printf("Item Not Found\nCan't be Updated\n");
    }
    fclose(bengalimenu);
    fclose(newfile);
    remove("C:\\Project\\Menu\\The_bengali_menu.txt");
    rename("C:\\Project\\Menu\\temp_The_bengali_menu.txt", "C:\\Project\\Menu\\The_bengali_menu.txt");
}

void update_The_indian_menu()
{
    display_The_indian_menu();
    FILE *newfile;
    printf("\nEnter product ID: ");
    int id;
    scanf("%d", &id);
    newfile = fopen("C:\\Project\\Menu\\temp_The_indian_menu.txt", "w");
    indianmenu = fopen("C:\\Project\\Menu\\The_indian_menu.txt", "r");
    i = 0;
    int count = 0;
    while ((fscanf(indianmenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
    {
        if (id == product[i].productId)
        {
            count++;
            printf("\nProduct Name: %s\nOld Price: %.2lf\n", product[i].productName, product[i].productPrice);
            printf("\nEnter New Price: ");
            scanf("%f", &product[i].productPrice);
        }
        fprintf(newfile, "%d,%s,%.2lf\n", product[i].productId, product[i].productName, product[i].productPrice);
        i++;
    }
    if (count == 0)
    {
        printf("Item Not Found\nCan't be Updated\n");
    }
    fclose(indianmenu);
    fclose(newfile);
    remove("C:\\Project\\Menu\\The_indian_menu.txt");
    rename("C:\\Project\\Menu\\temp_The_indian_menu.txt", "C:\\Project\\Menu\\The_indian_menu.txt");
}

void update_The_middle_eastern_menu()
{
    display_The_middle_eastern_menu();
    FILE *newfile;
    printf("\nEnter product ID: ");
    int id;
    scanf("%d", &id);
    newfile = fopen("C:\\Project\\Menu\\temp_The_middle_eastern_menu.txt", "w");
    middleeasternmenu = fopen("C:\\Project\\Menu\\The_middle_eastern_menu.txt", "r");
    i = 0;
    int count = 0;
    while ((fscanf(middleeasternmenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
    {
        if (id == product[i].productId)
        {
            count++;
            printf("\nProduct Name: %s\nOld Price: %.2lf\n", product[i].productName, product[i].productPrice);
            printf("\nEnter New Price: ");
            scanf("%f", &product[i].productPrice);
        }
        fprintf(newfile, "%d,%s,%.2lf\n", product[i].productId, product[i].productName, product[i].productPrice);
        i++;
    }
    if (count == 0)
    {
        printf("Item Not Found\nCan't be Updated\n");
    }
    fclose(middleeasternmenu);
    fclose(newfile);
    remove("C:\\Project\\Menu\\The_middle_eastern_menu.txt");
    rename("C:\\Project\\Menu\\temp_The_middle_eastern_menu.txt", "C:\\Project\\Menu\\The_middle_eastern_menu.txt");
}

void update_The_english_menu()
{
    display_The_english_menu();
    FILE *newfile;
    printf("\nEnter product ID: ");
    int id;
    scanf("%d", &id);
    newfile = fopen("C:\\Project\\Menu\\temp_The_english_menu.txt", "w");
    englishmenu = fopen("C:\\Project\\Menu\\The_english_menu.txt", "r");
    i = 0;
    int count = 0;
    while ((fscanf(englishmenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
    {
        if (id == product[i].productId)
        {
            count++;
            printf("\nProduct Name: %s\nOld Price: %.2lf\n", product[i].productName, product[i].productPrice);
            printf("\nEnter New Price: ");
            scanf("%f", &product[i].productPrice);
        }
        fprintf(newfile, "%d,%s,%.2lf\n", product[i].productId, product[i].productName, product[i].productPrice);
        i++;
    }
    if (count == 0)
    {
        printf("Item Not Found\nCan't be Updated\n");
    }
    fclose(englishmenu);
    fclose(newfile);
    remove("C:\\Project\\Menu\\The_english_menu.txt");
    rename("C:\\Project\\Menu\\temp_The_english_menu.txt", "The_english_menu.txt");
}

void update_The_american_menu()
{
    display_The_american_menu();
    FILE *newfile;
    printf("\nEnter product ID: ");
    int id;
    scanf("%d", &id);
    newfile = fopen("C:\\Project\\Menu\\temp_The_american_menu.txt", "w");
    americanmenu = fopen("C:\\Project\\Menu\\The_american_menu.txt", "r");
    i = 0;
    int count = 0;
    while ((fscanf(americanmenu, "%ld,%100[^,],%f", &product[i].productId, product[i].productName, &product[i].productPrice)) == 3)
    {
        if (id == product[i].productId)
        {
            count++;
            printf("\nProduct Name: %s\nOld Price: %.2lf\n", product[i].productName, product[i].productPrice);
            printf("\nEnter New Price: ");
            scanf("%f", &product[i].productPrice);
        }
        fprintf(newfile, "%d,%s,%.2lf\n", product[i].productId, product[i].productName, product[i].productPrice);
        i++;
    }
    if (count == 0)
    {
        printf("Item Not Found\nCan't be Updated\n");
    }
    fclose(americanmenu);
    fclose(newfile);
    remove("C:\\Project\\Menu\\The_american_menu.txt");
    rename("C:\\Project\\Menu\\temp_The_american_menu.txt", "The_american_menu.txt");
}

void employee()
{
    while (1)
    {
        setColor(9);
        printf("---------------------------------------------------------------\n");
        printf("|                       Employee Details                      |\n");
        printf("---------------------------------------------------------------\n");
        setColor(3);
        printf("1.Search By ID\n2.Search By Position\n3.Employee Entry\\Exit Info (Specific Date)\n4.Back\n\n");
        char ch = _getch();
        switch (ch)
        {
        case '1':
            searchbyid();
            break;
        case '2':
            searchbyrole();
            break;
        case '3':
            employee_details();
            break;
        case '4':
            adminservices();
            return;
        default:
            printf("Wrong Input\n");
        }
    }
    reset();
}

void searchbyid()
{
    setColor(11);
    employeefile = fopen("C:\\Project\\Panels\\employee.txt", "r");
    fflush(stdin);
    printf("\nEnter Employee ID: ");
    scanf("%d", &employeeid);
    char position[50];
    char task[50];
    int num;
    int count = 0;
    if (employeefile == NULL)
    {
        printf("File can't be opened\n\n");
    }
    else
    {
        while (fgets(buffer, sizeof(buffer), employeefile) != NULL)
        {

            if ((sscanf(buffer, "ID : %d, %[^\n]", &id, position)) == 2)
            {
                if (id == employeeid)
                {

                    printf("\n\n---------------------------------------------------------------\n");
                    printf("| Employee ID : %-4d | Position : %-27s |\n", id, position);
                    printf("---------------------------------------------------------------\n");
                    count++;
                    break;
                }
            }
        }
        if (count == 0)
        {
            setColor(12);
            printf("\n\t\tThis ID is not Found\n\n");
        }
        else
        {
            printf("\n");
        }
        fclose(employeefile);
    }
    reset();
}

void searchbyrole()
{
    setColor(13);
    employeefile = fopen("C:\\Project\\Panels\\employee.txt", "r");
    step7:
    printf("\nEnter Position: ");
    fflush(stdin);
    scanf("%[^\n]", employeeposition);
    int alphabet = 0;
    for(int j = 0; j<strlen(employeeposition);j++)
    {
        if(isalpha(employeeposition[j]))
        {
            alphabet++;
        }
    }
    if(alphabet!=strlen(employeeposition))
    {
        printf("Not a Valid Postion\n\n");
        goto step7;
    }
    printf("\n");
    char position[50];
    char position2[50];
    strcpy(position2, employeeposition);
    strlwr(position2);
    char task[50];
    int len = strlen(employeeposition);
    int num;
    int count = 0;
    if (employeefile == NULL)
    {
        printf("\nFile can't be opened\n\n");
    }
    else
    {
        while (fgets(buffer, sizeof(buffer), employeefile) != NULL)
        {
            strcpy(buffer2, buffer);
            strlwr(buffer2);
            if (strstr(buffer2, position2) != NULL)
            {

                if ((sscanf(buffer, "ID : %d, %[^\n]", &id, position)) == 2)
                {

                    printf("---------------------------------------------------------------\n");
                    setColor(14);
                    printf("| Employee ID : %-4d | Position : %-27s |\n", id, position);
                    setColor(13);
                    printf("---------------------------------------------------------------\n");
                    count++;
                }
            }
        }
        if (count == 0)
        {
            setColor(12);
            printf("This Position is not Found\n\n");
            reset();
        }
        else
        {
            printf("\n");
        }
        fclose(employeefile);
    }
    reset();
}

void employee_details()
{
    setColor(9);
    printf("---------------------------------------------------------------\n");
    printf("|                    Specific Day Details                     |\n");
    printf("---------------------------------------------------------------\n");
    setColor(14);

    char filename[150];
    int day, month, year;

    step5:printf("Enter Date (DD-MM-YYYY): ");
    fflush(stdin);
    if (scanf("%d-%d-%d", &day, &month, &year) != 3 || day < 1 || day > 31 || month < 1 || month > 12 || year < 1900)
    {
        printf("Invalid date format. Please enter a valid date (DD-MM-YYYY).\n\n");
        goto step5;
    }

    sprintf(filename, "C:\\Project\\EmployeeTime\\%02d-%02d-%d.txt", day, month, year);

    con = fopen(filename, "r");
    if (con == NULL)
    {
        setColor(12);
        printf("No records found for the date: %02d-%02d-%d\n\n", day, month, year);
        reset();
        return;
    }

    setColor(3);

    printf("\n\n---------------------------------------------------------------\n");
    printf("|                Employee Details for %02d-%02d-%d              |\n", day, month, year);
    printf("---------------------------------------------------------------\n");

    setColor(14);

    char line[200];
    while (fgets(line, sizeof(line), con) != NULL)
    {

        if (strlen(line) == 0 || strspn(line, " \t\r\n") == strlen(line))
        {
            continue;
        }

        strtok(line, "\n");
        if (strstr(line, "Departure Time:") != NULL)
        {
            setColor(14);
            printf("| %-57s   |\n", line);
            setColor(3);
            printf("---------------------------------------------------------------\n");
        }
        else if (strstr(line, "Entry Time:") != NULL)
        {
            setColor(14);
            printf("| %-57s   |\n", line);
            setColor(3);
            printf("---------------------------------------------------------------\n");
        }
        else
        {
            setColor(14);
            printf("| %-57s   |\n", line);
        }
    }

    fclose(con);
    reset();
}

void customerpurchasehistory()
{
    char ch;
    while (1)
    {
        setColor(1);
        printf("\n\n---------------------------------------------------------------\n");
        printf("|                      Purchase History                       |\n");
        printf("---------------------------------------------------------------\n");
        setColor(7);
        printf("1.All-Time History\n2.Search By Specific Date\n3.Back\n\n");
        ch = _getch();
        switch (ch)
        {
        case '1':

            alltimehistory();
            break;
        case '2':

            fflush(stdin);
            specificdatehistory();
            break;
        case '3':

            adminservices();
            return;
            break;
        default:
            printf("\nWrong input\n\n");
        }
    }
    reset();
}

void alltimehistory()
{
    char location[] = "C:\\Project\\Customers\\";
    FILE *file;
    setColor(1);
    printf("\n---------------------------------------------------------------\n");
    printf("|                All-Time Purchase History                    |\n");
    printf("---------------------------------------------------------------\n");
    setColor(7);
    phnnumber();
    strcat(location, phone_number);
    strcat(location, ".txt");
    file = fopen(location, "r");
    if (file == NULL)
    {
        setColor(12);
        printf("Haven't Purchase Here Yet.\n");
        return;
    }
    char menu;
    char buffer[150];
    int day, month, year;
    int hour, min;
    char gmt[10];
    int found_date = 0;
    int i = 0;
    char name[29];
    float total = 0;
    int flag = 0;
    fflush(stdin);
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        fflush(stdin);
        if (sscanf(buffer, "%d-%d-%d , %d:%d %s", &day, &month, &year, &hour, &min, gmt) == 6)
        {
            printf("\nDate: %d-%d-%d   Time: %02d:%02d %s\n\n", day, month, year, hour, min, gmt);
            fflush(stdin);
            while (fgets(buffer, sizeof(buffer), file) != NULL)
            {
                fflush(stdin);
                if ((sscanf(buffer, "Customer Name: %[^,]", name)) == 1)
                {
                    printf("Customer Name: %s\n", name);
                    printf("---------------------------------------------------------------\n");
                    printf("|  ID  |             Item Name         |  Quantity |   Price  |\n");
                    printf("---------------------------------------------------------------\n");
                }
                else if ((sscanf(buffer, "%c-%ld,%[^,],%d,%f", &menu, &product[i].productId, product[i].productName, &product[i].productQuantity, &product[i].productPrice) == 5))
                {
                    printf("| %c-%02ld | %-30s|     %-3d   |  %-7.2f |\n", menu, product[i].productId, product[i].productName, product[i].productQuantity, product[i].productPrice);
                    i++;
                    printf("---------------------------------------------------------------\n");
                }
                else if ((sscanf(buffer, "Total (After Tax + Discount) - %f", &total)) == 1)
                {
                    printf("|                      Total (After Tax + Discount) - %-7.2f |\n", total);
                    printf("---------------------------------------------------------------\n\n");
                }
                else if ((sscanf(buffer, "%d-%d-%d , %d:%d %s", &day, &month, &year, &hour, &min, gmt)) == 6)
                {
                    printf("\nDate: %d-%d-%d   Time: %02d:%02d %s\n\n", day, month, year, hour, min, gmt);
                    continue;
                }
            }
        }
    }
    fclose(file);
    return;
}

void specificdatehistory()
{
    char location[] = "C:\\Project\\Customers\\";
    FILE *file;
    setColor(1);
    printf("\n---------------------------------------------------------------\n");
    printf("|                Date-Wise Purchase History                   |\n");
    printf("---------------------------------------------------------------\n");
    setColor(7);
    phnnumber();
    strcat(location, phone_number);
    strcat(location, ".txt");
    file = fopen(location, "r");
    if (file == NULL)
    {
        setColor(12);
        printf("Haven't Purchase Here Yet.\n");
        return;
    }
    int target_day, target_month, target_year;
    step4: printf("\nEnter Date (DD-MM-YYYY): ");
    fflush(stdin);
    if (scanf("%d-%d-%d", &target_day, &target_month, &target_year) != 3 || target_day < 1 || target_day > 31 || target_month < 1 || target_month > 12 || target_year < 1900)
    {
        printf("Invalid date format. Please enter a valid date (DD-MM-YYYY).\n\n");
        goto step4;
    }
    char menu;
    char buffer[150];
    int day, month, year;
    int hour, min;
    char gmt[10];
    int found_date = 0;
    int i = 0;
    int counting = 0;
    char name[50];
    int flag = 1;
    float total = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        if (sscanf(buffer, "%d-%d-%d , %d:%d %s", &day, &month, &year, &hour, &min, gmt) == 6)
        {
            if (day == target_day && month == target_month && year == target_year)
            {
                counting++;
                printf("\nTime: %02d:%02d %s\n\n", hour, min, gmt);
                while (fgets(buffer, sizeof(buffer), file) != NULL)
                {
                    if ((sscanf(buffer, "Customer Name: %[^,]", name)) == 1)
                    {
                        printf("Customer Name: %s\n", name);
                        printf("---------------------------------------------------------------\n");
                        printf("|  ID  |             Item Name         |  Quantity |   Price  |\n");
                        printf("---------------------------------------------------------------\n");
                    }
                    else if ((sscanf(buffer, "%c-%ld,%[^,],%d,%f", &menu, &product[i].productId, product[i].productName, &product[i].productQuantity, &product[i].productPrice) == 5))
                    {
                        printf("| %c-%02ld | %-30s|     %-3d   |  %-7.2f |\n", menu, product[i].productId, product[i].productName, product[i].productQuantity, product[i].productPrice);
                        i++;
                        printf("---------------------------------------------------------------\n");
                    }
                    else if ((sscanf(buffer, "Total (After Tax + Discount) - %f", &total)) == 1)
                    {
                        printf("|                      Total (After Tax + Discount) - %-7.2f |\n", total);
                        printf("---------------------------------------------------------------\n\n");
                    }
                    else if ((sscanf(buffer, "%d-%d-%d , %d:%d %s", &day, &month, &year, &hour, &min, gmt)) == 6)
                    {
                        if (day == target_day && month == target_month && year == target_year)
                        {
                            printf("Time: %02d:%02d %s\n\n", hour, min, gmt);
                            continue;
                        }
                        else
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    if (counting == 0)
    {
        setColor(12);
        printf("\nNothing Purchased in This Specific Date.\n\n");
    }
    fclose(file);
    return;
}

void employeeservices()
{
    setColor(3);
    int day, month, year, hour, min;
    char gmt[3];
    char buffer[200];
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    strftime(buffer, sizeof(buffer), "Entry Time: %d-%m-%Y , %I:%M %p\n", localTime);
    if (sscanf(buffer, "Entry Time: %d-%d-%d , %d:%d %s", &day, &month, &year, &hour, &min, gmt))
    {
        sprintf(store, "C:\\Project\\EmployeeTime\\%d-%d-%d.txt", day, month, year);
    }
    check = fopen(store, "a");
    fclose(check);
    while (1)
    {
        printf("\n\n---------------------------------------------------------------\n");
        printf("|                      Employee Services                      |\n");
        printf("---------------------------------------------------------------\n");
        printf("1.Entry\n2.Departure\n3.Back\n4.Exit\n\n");
        char ch = _getch();
        switch (ch)
        {
        case '1':

            entrytime();
            break;
        case '2':

            exittime();
            break;
        case '3':

            homepage();
            exit(0);
        case '4':
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
    reset();
}

void entrytime()
{
    setColor(10);
    printf("---------------------------------------------------------------\n");
    printf("|                      Employee Entry                         |\n");
    printf("---------------------------------------------------------------\n");
    FILE *mainfile, *newfile;
    check = fopen(store, "a+");
    if (check == NULL)
    {
        printf("Error opening today's log file.\n");
        return;
    }
    printf("Enter ID: ");
    scanf("%d", &id);
    char line[200];
    int id_found = 0;
    while (fgets(line, sizeof(line), check) != NULL)
    {
        int logged_id;
        if (sscanf(line, "Employee ID : %d", &logged_id) == 1)
        {
            if (logged_id == id)
            {
                id_found = 1;
                break;
            }
        }
    }
    if (id_found)
    {
        printf("This ID has already been logged today.\n\n");
        fclose(check);
        return;
    }
    mainfile = fopen("C:\\Project\\Panels\\employee.txt", "r");
    if (mainfile == NULL)
    {
        printf("Error opening employee database.\n");
        fclose(check);
        return;
    }
    char newbuffer[200];
    int anotherid;
    int valid_id = 0;
    while (fgets(newbuffer, sizeof(newbuffer), mainfile) != NULL)
    {
        if (sscanf(newbuffer, "ID : %d", &anotherid) == 1)
        {
            if (id == anotherid)
            {
                valid_id = 1;
                break;
            }
        }
    }
    fclose(mainfile);
    if (valid_id == 0)
    {
        printf("This ID doesn't exist in the employee database. Please Try again\n\n");
        fclose(check);
        entrytime();
        return;
    }
    fprintf(check, "Employee ID : %d\n", id);
    char buffer[200];
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    strftime(buffer, sizeof(buffer), "Entry Time: %I:%M %p", localTime);
    fprintf(check, "%s\n\n", buffer);
    printf("Entry Successful\n\n");
    fclose(check);
    reset();
}

void exittime()
{
    setColor(12);
    printf("---------------------------------------------------------------\n");
    printf("|                     Employee Departure                      |\n");
    printf("---------------------------------------------------------------\n");
    int id;
    char newfile[100] = "temp_";
    strcat(newfile, "employee.txt");
    strcat(employeefile1, newfile);
    printf("Enter ID: ");
    scanf("%d", &id);
    FILE *new = fopen(store, "r");
    if (new == NULL)
    {
        printf("Could not open the original file.\n");
        return;
    }
    FILE *update = fopen(employeefile1, "w");
    if (update == NULL)
    {
        printf("Could not create the update file.\n");
        fclose(new);
        return;
    }
    char buffer[200];
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    strftime(buffer, sizeof(buffer), " %I:%M %p", localTime);
    char st[200];
    int fileid;
    int entry_found = 0;
    int departure_logged = 0;
    while (fgets(st, sizeof(st), new) != NULL)
    {
        if (sscanf(st, "Employee ID : %d", &fileid) == 1)
        {
            fprintf(update, "%s", st);
            if (id == fileid)
            {
                entry_found = 1;

                while (fgets(st, sizeof(st), new) != NULL)
                {

                    if (strncmp(st, "Entry Time:", 11) == 0)
                    {
                        if (strstr(st, "Departure Time:") != NULL)
                        {
                            departure_logged = 1;
                            fprintf(update, "%s", st);
                        }
                        else
                        {
                            strtok(st, "\n");
                            fprintf(update, "%s | Departure Time:%s\n", st, buffer);
                        }
                        break;
                    }
                    fprintf(update, "%s", st);
                }
            }
        }
        else
        {
            fprintf(update, "%s", st);
        }
    }
    fclose(new);
    fclose(update);
    if (entry_found)
    {
        if (departure_logged)
        {
            printf("Departure time for this ID has already been logged.\n\n");
            remove(employeefile1);
        }
        else
        {
            remove(store);
            rename(employeefile1, store);
            printf("Departure time updated successfully.\n\n");
        }
    }
    else
    {
        remove(employeefile1);
        setColor(12);
        printf("Employee ID hasn't entered today.\n\n");
    }
    reset();
}


void customer()
{
    while (1)
    {
        setColor(9);
        printf("\n\n---------------------------------------------------------------\n");
        printf("|                      Customer Services                      |\n");
        printf("---------------------------------------------------------------\n");
        setColor(11);
        printf("1.Display Menu\n2.Order food\n3.Search By Item name\n4.Back\n5.Exit\n\n");

        char choice;
        choice = _getch();
        switch (choice)
        {
        case '1':

            displaymenucustomer();
            break;
        case '2':

            orderfood();
            return;
        case '3':

            searchbyword();
            break;
        case '4':

            homepage();
            exit(0);
        case '5':
            exit(0);
        default:
            setColor(12);
            printf("\n\t\tInvalid Choice\n\t\t Try Again...");
        }
    }
    reset();
}

void displaymenucustomer()
{
    while (1)
    {
        setColor(6);
        printf("\n---------------------------------------------------------------\n");
        printf("|                         Menu List                           |\n");
        printf("---------------------------------------------------------------\n");
        setColor(14);
        printf("\n1.Bengali Menu\n2.Indian Menu\n3.Middle-Eastern Menu\n4.English Menu\n5.American Menu\n6.Back\n7.Exit\n\n");
        char choice;
        choice = _getch();
        switch (choice)
        {
        case '1':

            display_The_bengali_menu();
            break;
        case '2':

            display_The_indian_menu();
            break;
        case '3':

            display_The_middle_eastern_menu();
            break;
        case '4':

            display_The_english_menu();
            break;
        case '5':

            display_The_american_menu();
            break;
        case '6':

            customer();
            return;
        case '7':
            exit(0);
        default:
            setColor(12);
            printf("\n\t\tInvalid Choice\n\t\t Try Again...");
        }
    }
    reset();
}


void orderfood()
{
    char location[] = "C:\\Project\\Customers\\";
    count = 0;
    setColor(9);
    printf("---------------------------------------------------------------\n");
    printf("|                        Order Food                           |\n");
    printf("---------------------------------------------------------------\n");
    setColor(11);
    fflush(stdin);
    printf("Enter Name: ");
    scanf("%[^\n]s", Customername);
    phnnumber();
    fflush(stdin);
    strcat(location, phone_number);
    strcat(location, ".txt");
    appear = fopen(location, "r");
    if (appear != NULL)
    {
        char buffer[200];
        char store_name[30];
        while (fgets(buffer, sizeof(buffer), appear) != NULL)
        {
            fflush(stdin);
            if (sscanf(buffer, "Customer Name: %27[^,],Appear : %d", store_name, &count) == 2)
            {
                continue;
            }
        }
        fclose(appear);
    }
    customerfile = fopen(location, "a");
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    strftime(buffer, sizeof(buffer), "%d-%m-%Y , %I:%M %p", localTime);
    fprintf(customerfile, "%s\n\n", buffer);
    count++;
    fprintf(customerfile, "Customer Name: %-26s ,Appear : %d\n\n", Customername, count);

    while (1)
    {
    step1:
        setColor(3);
        printf("\n---------------------------------------------------------------\n");
        printf("|                         Menu List                           |\n");
        printf("---------------------------------------------------------------\n");
        setColor(11);
        printf("1.Bengali Menu\n2.Indian Menu\n3.Middle-Eastern Menu\n4.English Menu\n5.American Menu\n6.Done\n\n");
        char choice;
        choice = _getch();
        switch (choice)
        {
        case '1':

            display_The_bengali_menu();
            menu = 'B';
            break;
        case '2':

            display_The_indian_menu();
            menu = 'I';
            break;
        case '3':

            display_The_middle_eastern_menu();
            menu = 'M';
            break;
        case '4':

            display_The_english_menu();
            menu = 'E';
            break;
        case '5':

            display_The_american_menu();
            menu = 'A';
            break;
        case '6':
            if (load != 0)
            {

                viewcart();
                return;
            }
            else
            {
                setColor(12);
                printf("\n\t\tDidn't Select Any Product....\n\t\t  Please Select Product\n\n");
                goto step1;
            }

        default:
            setColor(12);
            printf("\n\t\tInvalid Choice\n\t\t Try Again...");
            goto step1;
        }

        selectitem(menu);
    }
    reset();
    return;
}

void phnnumber()
{
    setColor(11);
    char ch;
    int i = 0;
    printf("Phone(+88): ");

    while (1)
    {
        ch = _getch();

        if (ch == 13)
        {
            phone_number[i] = '\0';
            break;
        }

        if (ch == '\b')
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }

        else if (isdigit(ch) && i < sizeof(phone_number) - 1 && ch != 32)
        {
            phone_number[i] = ch;
            setColor(3);
            printf("%c", ch);
            i++;
        }
        else
        {
            setColor(12);
            printf("\nInvalid input... Please enter digits only.\n");
            setColor(11);
            i = 0;
            printf("Phone(+88): ");
        }
    }

    int length = strlen(phone_number);
    if (length == 11)
    {
        setColor(10);
        printf("\n\n\t\t Phone Number Accepted\n");
        strcpy(mobile_number, phone_number);
        return;
    }
    else
    {
        setColor(12);
        printf("\nWrong Format...Please Try Again\n");
        phnnumber();
    }
}


void selectitem(char menu)
{
    setColor(11);
    printf("\n\n\t\t1.Continue\t|\t0.Stop\n");
    setColor(9);
    printf("\n---------------------------------------------------------------\n");
    setColor(3);
    printf("|                       Add to List                           |\n");
    setColor(9);
    printf("---------------------------------------------------------------\n");
    setColor(3);
    printf("| ID |             Item Name          | Quantity |    Price   |\n");
    setColor(9);
    printf("---------------------------------------------------------------\n");
    setColor(11);
    char check;
    while (1)
    {
        setColor(11);
        check = _getch();
        if (check == '1')
        {
            setColor(11);
            int number;
            printf("| ");
            scanf("%d", &number);
            moveCursorRelative(5, -1);

            if (number > i || number <= 0)
            {
                printf("|\t\t      ");
                setColor(12);
                printf("Wrong product ID\t\t\t");
                setColor(11);
                printf("      |\n");
                printf("---------------------------------------------------------------\n");
            }
            else
            {
                setColor(11);

                printf("|  %-29s |     ", product[number - 1].productName);
            step2:
                scanf("%d", &product[i].productQuantity);
                if (product[i].productQuantity <= 0)
                {
                    moveCursorRelative(43, -1);
                    printf("\b      \b");
                    moveCursorRelative(-3, 0);
                    goto step2;
                }
                load++;
                moveCursorRelative(49, -1);
                printf("|  %-10.2f|\n", product[i].productQuantity * product[number - 1].productPrice);
                printf("---------------------------------------------------------------\n");
                fprintf(customerfile, "%c-%d,%s,%d,%.2f\n", menu, number, product[number - 1].productName, product[i].productQuantity, product[i].productQuantity * product[number - 1].productPrice);
                total = total + product[i].productQuantity * product[number - 1].productPrice;
                cartproducts[j].num = j + 1;
                cartproducts[j].quantity = product[i].productQuantity;
                cartproducts[j].price = product[i].productQuantity * product[number - 1].productPrice;
                strcpy(cartproducts[j].productName, product[number - 1].productName);
                j++;
                track++;
            }
        }
        else if (check == '0')
        {
            break;
        }
    }

    return;
}

void viewcart()
{
    setColor(3);
    printf("\t\t\tCustomer Details\n\n");
    setColor(11);
    printf("Customer Name: %-26s Phone No: %s\n", Customername, mobile_number);
    setColor(3);
    printf("\n---------------------------------------------------------------\n");
    printf("|                        View Cart                            |\n");
    printf("---------------------------------------------------------------\n");
    setColor(11);
    printf("| ID |             Item Name          | Quantity |    Price   |\n");
    setColor(3);
    printf("---------------------------------------------------------------\n");

    for (j = 0; j < track; j++)
    {
        setColor(11);
        printf("| %02d | %-30s |     %-3d  |  %-8.2f  |\n", cartproducts[j].num, cartproducts[j].productName, cartproducts[j].quantity, cartproducts[j].price);
        setColor(3);
        printf("---------------------------------------------------------------\n");
    }
    setColor(11);
    double tax = (double)round(total * 0.03);
    printf("|                                      Base Total = %-9.2lf |\n", total);
    printf("|                                          Tax(+) = %-9.2lf |\n", tax);
    if (count > 4 && total>=200)
    {
        double discount;
        if (count > 3 && count <= 5)
        {
            discount = (double)round(total * 0.05);
            printf("|                                     Discount(-) = %-9.2lf |\n", discount);
        }
        else if (count > 5 && count <= 10)
        {
            discount = (double)round(total * 0.07);
            printf("|                                     Discount(-) = %-9.2lf |\n", discount);
        }
        else if (count > 10 && count <= 13)
        {
            discount = (double)round(total * 0.1);
            printf("|                                     Discount(-) = %-9.2lf |\n", discount);
        }
        else if (count > 13)
        {
            discount = (double)round(total * 0.13);
            printf("|                                     Discount(-) = %-9.2lf |\n", discount);
        }
        total -= discount;
    }
    total += tax;
    total = (double)round(total);
    printf("|                                           Total = %-9.2lf |\n", total);
    setColor(3);
    printf("---------------------------------------------------------------\n");
    fprintf(customerfile, "Total (After Tax + Discount) - %.2lf\n\n\n", total);
    fclose(customerfile);
    cash_or_card();
    reset();
}

void cash_or_card()
{
    setColor(9);
    float amount;
    printf("\n\n---------------------------------------------------------------\n");
    printf("|                     Payment Options                         |\n");
    printf("---------------------------------------------------------------\n");
    setColor(11);
    printf("1.Cash\n");
    printf("2.Card\n");
    char choice;
    choice = _getch();
    switch (choice)
    {
    case '1':
    {
        process_cash();
        sleep(60);
        exit(1);
    }
    case '2':
    {
        process_card();
        sleep(60);
        exit(1);
    }
    default:
    {
        setColor(12);
        printf("\n\t\tInvalid Choice\n\t\t Try Again...");
        cash_or_card();
    }
    }
}

void process_cash()
{
    setColor(3);
    printf("\n---------------------------------------------------------------\n");
    printf("|                          Cash                               |\n");
    printf("---------------------------------------------------------------\n");
    setColor(11);
    float cash_given, change;
    printf("\nEnter the amount of cash given: ");
    scanf("%f", &cash_given);
    if (cash_given >= total)
    {
        change = cash_given - total;
        printf("Change: %.2f\n", change);
        setColor(10);
        printf("\n\t\t  Transaction successful!\n");
        setColor(14);
        char thanks[200] = "\n\tThanks for your purchase.....Come back soon.\n";
    for (int i = 0; i < sizeof(thanks) / sizeof(thanks[i]); i++)
    {
        printf("%c", thanks[i]);
        fflush(stdout);
        usleep(50000);
    }
    }
    else
    {
        setColor(12);
        printf("\n\t\t  Insufficient cash provided.\n\t\t\tTransaction failed.\n\t\t\t Try Again..\n");
        cash_or_card();
        return;
    }
}

void process_card()
{
    setColor(3);
    printf("\n---------------------------------------------------------------\n");
    printf("|                          Card                               |\n");
    printf("---------------------------------------------------------------\n");
    setColor(11);
    char card_number[20];
    int i = 0;
    char pin[5];
    int j = 0;
    char cn, p;
    printf("\nEnter Card Number: ");

    while (1)
    {
        cn = _getch();
        if (cn == 13)
        {
            card_number[i] = '\0';
            break;
        }
        else if (cn == '\b')
        {
            if (i > 0)
            {
                if (card_number[i - 1] == ' ')
                {
                    i--;
                    printf("\b \b");
                }
                i--;
                printf("\b \b");
            }
        }
        else if (cn >= '0' && cn <= '9' && i < sizeof(card_number) - 1)
        {
            card_number[i] = cn;
            printf("%c", cn);
            i++;
            if (i == 4 || i == 9 || i == 14)
            {
                card_number[i] = ' ';
                printf(" ");
                i++;
            }
        }
    }

    printf("\nEnter PIN: ");

    while (1)
    {
        p = _getch();

        if (p == 13)
        {
            pin[j] = '\0';
            break;
        }
        else if (p == '\b')
        {
            if (j > 0)
            {
                j--;
                printf("\b \b");
            }
        }
        else if (p >= '0' && p <= '9' && j < sizeof(pin) - 1)
        {
            pin[j] = p;
            printf("*");
            j++;
        }
    }
    setColor(10);
    printf("\n\t\t  Transaction successful!\n");
    setColor(14);
    char thanks[200] = "\n\tThanks for your purchase.....Come back soon.\n";
    for (int i = 0; i < sizeof(thanks) / sizeof(thanks[i]); i++)
    {
        printf("%c", thanks[i]);
        fflush(stdout);
        usleep(50000);
    }
}


void searchbyword()
{

    bengalimenu = fopen("C:\\Project\\Menu\\The_bengali_menu.txt", "r");
    indianmenu = fopen("C:\\Project\\Menu\\The_indian_menu.txt", "r");
    middleeasternmenu = fopen("C:\\Project\\Menu\\The_middle_eastern_menu.txt", "r");
    englishmenu = fopen("C:\\Project\\Menu\\The_english_menu.txt", "r");
    americanmenu = fopen("C:\\Project\\Menu\\The_american_menu.txt", "r");
    int i = 0;
    char productname[20];
    char name[50];
    char filename[50];
    fflush(stdin);
    setColor(6);
    printf("---------------------------------------------------------------\n");
    printf("|                       Search Food                           |\n");
    printf("---------------------------------------------------------------\n");
    setColor(14);
    step6:
    fflush(stdin);
    printf("Enter Product Name: ");
    scanf("%[^\n]", productname);
    int len = strlen(productname);
    int alphabet = 0;
    for(int j = 0; j<len; j++)
    {
        if(isalpha(productname[j]))
        {
            alphabet++;
        }
    }
    if(alphabet != len)
    {
        printf("Not A valid Name\n\n");
        goto step6;
    }
    printf("\n");
    strcpy(name, productname);
    strlwr(name);
    char buffer[1000];
    char buffer2[1000];

    printf("---------------------------------------------------------------\n");
    while (fgets(buffer, sizeof(buffer), bengalimenu) != NULL)
    {
        strcpy(buffer2, buffer);
        strlwr(buffer2);
        if (strstr(buffer2, name) != NULL)
        {
            if (sscanf(buffer, "%d, %[^,], %f", &search[i].p_id, search[i].p_name, &search[i].p_price) == 3)
            {
                printf("| B-%02d  | %-40s  | %-8.2f|\n", search[i].p_id, search[i].p_name, search[i].p_price);
                printf("---------------------------------------------------------------\n");
                i++;
            }
        }
    }
    while (fgets(buffer, sizeof(buffer), indianmenu) != NULL)
    {
        strcpy(buffer2, buffer);
        strlwr(buffer2);
        if (strstr(buffer2, name) != NULL)
        {
            if (sscanf(buffer, "%d, %[^,], %f", &search[i].p_id, search[i].p_name, &search[i].p_price) == 3)
            {
                printf("| I-%02d  | %-40s  | %-8.2f|\n", search[i].p_id, search[i].p_name, search[i].p_price);
                printf("---------------------------------------------------------------\n");
                i++;
            }
        }
    }
    while (fgets(buffer, sizeof(buffer), middleeasternmenu) != NULL)
    {
        strcpy(buffer2, buffer);
        strlwr(buffer2);
        if (strstr(buffer2, name) != NULL)
        {
            if (sscanf(buffer, "%d, %[^,], %f", &search[i].p_id, search[i].p_name, &search[i].p_price) == 3)
            {
                printf("| M-%02d  | %-40s  | %-8.2f|\n", search[i].p_id, search[i].p_name, search[i].p_price);
                i++;
                printf("---------------------------------------------------------------\n");
            }
        }
    }
    while (fgets(buffer, sizeof(buffer), englishmenu) != NULL)
    {
        strcpy(buffer2, buffer);
        strlwr(buffer2);
        if (strstr(buffer2, name) != NULL)
        {
            if (sscanf(buffer, "%d, %[^,], %f", &search[i].p_id, search[i].p_name, &search[i].p_price) == 3)
            {
                printf("| M-%02d  | %-40s  | %-8.2f|\n", search[i].p_id, search[i].p_name, search[i].p_price);
                i++;
                printf("---------------------------------------------------------------\n");
            }
        }
    }
    while (fgets(buffer, sizeof(buffer), americanmenu) != NULL)
    {
        strcpy(buffer2, buffer);
        strlwr(buffer2);
        if (strstr(buffer2, name) != NULL)
        {
            if (sscanf(buffer, "%d, %[^,], %f", &search[i].p_id, search[i].p_name, &search[i].p_price) == 3)
            {
                printf("| A-%02d  | %-40s  | %-8.2f|\n", search[i].p_id, search[i].p_name, search[i].p_price);
                i++;
                printf("---------------------------------------------------------------\n");
            }
        }
    }
    if (i == 0)
    {
        setColor(12);
        printf("|                  Not found in the Menu                      |\n", productname);
        setColor(6);
        printf("---------------------------------------------------------------\n\n");
    }
    fclose(bengalimenu);
    fclose(indianmenu);
    fclose(middleeasternmenu);
    fclose(englishmenu);
    fclose(americanmenu);
    return;
}

