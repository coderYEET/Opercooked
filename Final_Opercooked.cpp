//kode final untuk program Opercooked
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//data structures
struct AddOrder {
    char name[255];
    int price;
    char type[15];
    char topping[10];
    double callories;
    char flavor[15];
    char size;
    int year, month, date, hour, min, sec;
    char form[3];
    int timeLeft;
    AddOrder *next;
}*orderHead, *orderTail;

struct Menu {
    int id;
    char type[10];
    char name[255] = {};
    int price;
    char topping[10] = {};
    double calories;
    char flavor[15] = {};
    char size;
    int time;
    Menu *next;
} * headMenu, *tailMenu;

struct History{
    char name[255];
    char topping[255];
    char size;
    char flavor[255];
    double callories;
    int price;
    int year, month, date, hour, min, sec;
    char form[3];
    History* next;
}*headHistory = NULL, *tailHistory = NULL;

//global variables or structures
int currentMenu = 1, profit = 0;

//functions
void mainMenu();
void addMenu();
void viewCooking();
void viewOrder();
void order();
void addDessert();
void addDrink();
Menu* findMenu(int id); //Untuk find menu setelah input di order
AddOrder* createNewOrder(char* name, int price, char* topping, double callories, char* flavor, char size, int timeLeft); //Linked list OrderMenu
Menu *addDessert(char *menuName, char *topping, double calories, int menuPrice, int dessertTime); //LinkedList addDessert
Menu* createNewDrink(char *menuName, char *flavor, char size, int menuPrice, int time);//LinkedList addDrink 
History* newHistDrink(char* name, char size, char* flavor, int price, int year, int month, int date, int hour, int min, int sec, char form[3]);
History* newHistDessert(char* name, char* topping, double callories, int price, int year,int month,int date,int hour,int min,int sec, char form[3]);
void pushOrder(Menu* curr); //Push tail order
void pushTailDessert(char *menuName, char *topping, double calories, int menuPrice, int dessertTime); //pushTail untuk addDessert
void pushTailAddDrink(char *menuName, char *flavor, char size, int menuPrice, int time);//pushTail addDrink
void pushHistDrink(char* name, char size, char* flavor, int price, int year, int month, int date, int hour, int min, int sec, char form[3]);
void pushHistDessert(char* name, char* topping, double callories, int price, int year,int month,int date,int hour,int min,int sec, char form[3]);
void popAddOrder();

int main()
{

    mainMenu();

    return 0;
}

void mainMenu()
{
    int input;
    do
    {
        printf("\e[1;1H\e[2J");
        puts("Welcome to Opercooked");
        printf("Today's Profit: $ %d\n", profit);
        puts("===========================");
        puts("1. Add Dessert or Beverage");
        puts("2. View Cooking Process");
        puts("3. View Order History");
        puts("4. Order Dessert or Beverage");
        puts("5. Exit");
        printf(">> ");
      
        scanf("%d", &input); getchar();
        if (input == 1)
        {
            printf("\e[1;1H\e[2J");
            addMenu();
        }
        if (input == 2)
        {
            printf("\e[1;1H\e[2J");
            viewCooking();
        }
        if (input == 3)
        {
            printf("\e[1;1H\e[2J");
            viewOrder();
        }
        if (input == 4)
        {
            printf("\e[1;1H\e[2J");
            order();
        }
        if (input == 5)
        {
            printf("\e[1;1H\e[2J");
            break;
        }
    } while (input != 5);
}

void addMenu()
{
    int input;
    do
    {
        printf("\e[1;1H\e[2J");
        puts("What do you want to add?");
        puts("1. Dessert");
        puts("2. Drink");
        printf("Choose: ");
        scanf("%d", &input); getchar();
        if (input == 1)
        {
            printf("\e[1;1H\e[2J");
            addDessert();
        }
        if (input == 2)
        {
            printf("\e[1;1H\e[2J");
            addDrink();
        }
    } while (input < 1 || input > 2);
}

void addDessert()
{
    char namaMenu[255], toppingMenu[10];
    int price;
    double calories;

    //input nama dessert
    do
    {
        printf("Input the name [at least 5 characters]: ");
        scanf("%[^\n]", namaMenu);
        getchar();
    } while (strlen(namaMenu) < 5);

    //input harga
    do
    {
        printf("Input the price [10 - 500]: $ ");
        scanf("%d", &price);
        getchar();
    } while (price < 10 || price > 500);

    //input topping
    int flag = 0;
    do
    {
        printf("Input the topping ['Caramel' | 'Honey' | 'Syrup'](Case Insensitive): ");
        scanf("%s", toppingMenu);
        getchar();
        if (toppingMenu[0] > 'Z')
            toppingMenu[0] -= 32;
        if (strcmp("Caramel", toppingMenu) == 0 || strcmp("Honey", toppingMenu) == 0 || strcmp("Syrup", toppingMenu) == 0)
        {
            flag = 1;
        }
    } while (flag == 0);

    //input kalori
    do
    {
        printf("Insert calories [1.00 - 99.00]: ");
        scanf("%lf", &calories);
        getchar();
    } while (calories < 1.00 || calories > 99.00);

    //Mencari dessertTime
    //random waktu pembuatan dessert
    srand(time(NULL));
    int totaltime = (rand() % 41) + 50;

    if (strcmp(toppingMenu, "Caramel") == 0)
    {
        totaltime += 10;
    }
    else if (strcmp(toppingMenu, "Honey") == 0)
    {
        totaltime += 15;
    }
    else if (strcmp(toppingMenu, "Syrup") == 0)
    {
        totaltime += 20;
    }

    //create data dari inputan
    pushTailDessert(namaMenu, toppingMenu, calories, price, totaltime);
    printf("\nSuccessfully added a new menu!");
    getchar();
    currentMenu++;
}

void addDrink()
{
    system("cls");
    char namaMenu[255], flavor[255];
    int price;
    char size;

    //input nama drink
    do
    {
        printf("Input the name [at least 5 characters]: ");
        scanf("%[^\n]", namaMenu);
        getchar();
    } while (strlen(namaMenu) < 5);

    //input harga
    do
    {
        printf("Input the price [10 - 500]: $ ");
        scanf("%d", &price);
        getchar();
    } while (price < 10 || price > 500);

    //input flavor
    int flag = 0;
    do
    {
        printf("Input the flavor ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
        scanf("%[^\n]", flavor);
        getchar();
        if (strcmp("Mint", flavor) == 0 || strcmp("Mix Berry", flavor) == 0 || strcmp("Cheese", flavor) == 0)
        {
            flag = 1;
        }
    } while (flag == 0);

    //input size 
    flag = 0;
    do
    {
        printf("Insert the size [S | M | L](Case Sensitive): ");
        scanf("%c", &size);
        getchar();
        if (size == 'S' || size == 'M' || size == 'L')
        {
            flag = 1;
        }
    } while (flag == 0);
    
    // time
    srand(time(0));
    int time = (rand() % 41) + 10;
    if (strcmp(flavor, "Mint") == 0){
        time += 10;
    }
    else if(strcmp(flavor, "Mix Berry") == 0){
        time += 20;
    }
    else if(strcmp(flavor, "Cheese") == 0){
        time += 30;
    }

    printf("Successfully added a new menu!");
    getchar();
    pushTailAddDrink(namaMenu, flavor, size, price, time);
    currentMenu++;
}

void viewCooking()
{
    if (!orderHead){
        printf("There is no cooking process recently!\n");
        printf("Press Enter co continue");
        getchar();
        return;
    }
    printf("| No  | Type     | Name   | Price  | Time Left |\n");
    printf("------------------------------------------------\n");
    int list=1;
    AddOrder* currOrder = orderHead;
    while (currOrder)
    {
        currOrder->timeLeft -= 10;
        if (currOrder->timeLeft <= 0) 
        {
            if (strcmp(currOrder->type, "Dessert") == 0) pushHistDessert (currOrder->name, currOrder->topping, currOrder->callories, currOrder->price, currOrder->year, currOrder->month, currOrder->date, currOrder->hour, currOrder->min, currOrder->sec, currOrder->form);
            else if (strcmp(currOrder->type, "Drink") == 0) pushHistDrink (currOrder->name, currOrder->size, currOrder->flavor, currOrder->price, currOrder->year, currOrder->month, currOrder->date, currOrder->hour, currOrder->min, currOrder->sec, currOrder->form);
            profit += currOrder->price;
            currOrder = currOrder->next;
            popAddOrder(); //popnya langsung cari yang timeLeft <= 0 jadi tidak perlu diberi parameter
        }
        else
        {
            printf("| %-4d| %-9s| %-21s| %-7d| %-8ds |\n", list, currOrder->type,currOrder->name, currOrder->price, currOrder->timeLeft);
            currOrder = currOrder->next;
            list++;
        }
    }
    printf("\nPress Enter to return main menu");
    getchar();
}

void viewOrder()
{
    if (totalHDessert || totalHDrink)
    {
        puts("| No  | Name                  | Price  | Topping    | Callories  | Flavor     | size  | Order Time              |");
        puts("-----------------------------------------------------------------------------------------------------------------");
        for (int i = 0; i < totalHDessert; i++)
        {
            printf("| %-3d | %-21s | %-6d | %-10s | %-10.2lf | %-10s | %-5c | %d/%02d/%02d %02d:%02d:%02d %s |\n", i + 1,
                   historyDessert[i].name, historyDessert[i].price, historyDessert[i].topping, historyDessert[i].callories, "-", "-",
                   orderDessert[i].orderTime.year, orderDessert[i].orderTime.month, orderDessert[i].date,
                   orderDessert[i].orderTime.hour, orderDessert[i].orderTime.min, orderDessert[i].orderTime.sec, orderDessert[i].orderTime.form);
        }
        for (int i = 0; i < totalHDrink; i++)
        {
            printf("| %-3d | %-21s | %-6d | %-10s | %-10.2lf | %-10s | %-5c | %d/%02d/%02d %02d:%02d:%02d %s |\n", i + totalHDessert + 1,
                   historyDrink[i].name, historyDrink[i].price, "-", "-", historyDrink[i].flavor, historyDrink[i].size,
                   orderDrink[i].orderTime.year, orderDrink[i].orderTime.month, orderDrink[i].date,
                   orderDrink[i].orderTime.hour, orderDrink[i].orderTime.min, orderDrink[i].orderTime.sec, orderDrink[i].orderTime.form);
        }
    }
    else
    {
        puts("There is no order history!");
        puts("");
        puts("Press enter to continue");
    }
    getchar();
}

void order() {
    system("cls");
    if (!headMenu)
    {
        puts("There is no Dessert or Drink on the list!");
        printf ("\nPress Enter to continue..."); getchar();
    }
    else
    {
        Menu* curr = headMenu;
        printf ("| %-5s| %-20s| %-7s| %-12s| %-11s| %-11s| %-6s|\n","No", "Name", "Price", "Topping", "Callories", "Flavor", "size");
        puts ("---------------------------------------------------------------------------------------");
        while(curr)
        {
            printf ("| %-5d", curr->id);
            printf ("| %-20s", curr->name);
            printf ("| %-7d", curr->price);
            
            if (strcmp(curr->type, "Drink") == 0) // kalau dia drink
                printf ("| %-12s| %-11s| %-11s| %-6c|\n", "-", "-", curr->flavor, curr->size);
                //   ex: |  -   |   -  | Mint |  S  |

            else //kalau dia dessert
                printf ("| %-12s| %-11.2lf| %-11s| %-6s|\n", curr->topping, curr->calories, "-", "-");
                //   ex: | Honey|  12.50  |   -  |  -  |
            
            curr = curr->next;
        }
        while(1)
        {
            printf ("Choose a menu to order [1 - %d]: ", currentMenu - 1);
            int input;
            scanf ("%d", &input); getchar();
            Menu* found = findMenu(input);
            if (!found)
            {
                puts("Menu not found!");
                printf ("Press enter to continue..."); getchar();
                break;
            }
            else
            {
                puts("Successfully added menu!");
                printf ("Press enter to continue..."); getchar();
                pushOrder(found);
                break;
            }
        }
    } 
}

Menu* findMenu(int id) {
    if (!headMenu)
        return NULL;
    else
    {
        Menu* curr = headMenu;
        while(curr && curr->id != id)
            curr = curr->next;
        return curr;
    }   
}
void pushOrder(Menu* curr) {
    AddOrder* newOrder = createNewOrder(curr->name, curr->price, curr->topping, curr->calories, curr->flavor, curr->size, curr->time, curr->type);
    if (!orderHead)
        orderHead = orderTail = newOrder;
    else
    {
        orderTail->next = newOrder;
        orderTail = newOrder;
    }
}

AddOrder* createNewOrder(char* name, int price, char* topping, double callories, char* flavor, char size, int timeLeft, char* type) {
    AddOrder* newOrder = (AddOrder*)malloc(sizeof(AddOrder));
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    strcpy(newOrder->name, name);
    strcpy(newOrder->type, type);
    newOrder->price = price;
    strcpy(newOrder->topping, topping);
    newOrder->callories = callories;
    strcpy(newOrder->flavor, flavor);
    newOrder->size = size;
    newOrder->year = tm.tm_year + 1900;
    newOrder->month = tm.tm_mon + 1;
    newOrder->date = tm.tm_mday;
    newOrder->hour = tm.tm_hour;
    newOrder->min = tm.tm_min;
    newOrder->sec = tm.tm_sec;
    if (newOrder->hour > 12)
    {
        strcpy(newOrder->form, "PM");
        newOrder->hour -= 12;
    }
    else
        strcpy(newOrder->form, "AM");
    newOrder->timeLeft = timeLeft;
    newOrder->next = NULL;
}

Menu *addDessert(char *menuName, char *topping, double calories, int menuPrice, int dessertTime)
{
    Menu *newDessert = (Menu *)malloc(sizeof(Menu));

    newDessert->id = currentMenu;
    strcpy(newDessert->type, "Dessert");
    strcpy(newDessert->name, menuName);
    strcpy(newDessert->topping, topping);
    newDessert->calories = calories;
    newDessert->price = menuPrice;
    newDessert->time = dessertTime;
    newDessert->next = NULL;

    return newDessert;
}

void pushTailDessert(char *menuName, char *topping, double calories, int menuPrice, int dessertTime)
{
    Menu *temp = addDessert(menuName, topping, calories, menuPrice, dessertTime);
    if (!headMenu)
    {
        headMenu = tailMenu = temp;
    }
    else
    {
        tailMenu->next = temp;
        tailMenu = temp;
    }
}

//LinkedList addDrink
Menu* createNewDrink(char *menuName, char *flavor, char size, int menuPrice, int time)
{
    Menu* newDrink = (Menu*)malloc(sizeof(Menu));

    newDrink->id = currentMenu;
    strcpy(newDrink->type, "Drink");
    strcpy(newDrink->name, menuName);
    strcpy(newDrink->flavor, flavor);
    newDrink->size = size;
    newDrink->price = menuPrice;
    newDrink->time = time;
    newDrink->next = NULL;

    return newDrink;
}

//pushTail addDrink
void pushTailAddDrink(char *menuName, char *flavor, char size, int menuPrice, int time)
{
    Menu* temp = createNewDrink(menuName, flavor, size, menuPrice, time);
    if (!headMenu)
    {
        headMenu = tailMenu = temp;
    }
    else
    {
        tailMenu->next = temp;
        tailMenu = temp;
    }
}

//Functions linked list history
History* newHistDessert(char* name, char* topping, double callories, int price, int year,int month,int date,int hour,int min,int sec, char form[3])
{
    History* node = (History*)malloc(sizeof(History));
    strcpy(node->name, name);
    strcpy(node->topping, topping);
    node->callories = callories;
    node->price = price;
    node->year = year;
    node->month = month;
    node->date = date;
    node->hour = hour;
    node->min = min;
    node->sec = sec;
    strcpy(node->form, form);
    node->next = NULL;
    return node;
};

void pushHistDessert(char* name, char* topping, double callories, int price, int year,int month,int date,int hour,int min,int sec, char form[3]){
    History* node = newHistDessert(name, topping, callories, price, year, month, date, hour, min, sec, form);
    if (tailHistory == NULL){
        headHistory = tailHistory = node;
    }
    else{
        tailHistory->next = node;
        tailHistory = node;
    }
}

History* newHistDrink(char* name, char size, char* flavor, int price, int year, int month, int date, int hour, int min, int sec, char form[3]){
    History* node = (History*)malloc(sizeof(History));
    strcpy(node->name, name);
    node->size = size;
    strcpy(node->flavor, flavor);
    node->price = price;
    node->year = year;
    node->month = month;
    node->date = date;
    node->hour = hour;
    node->min = min;
    node->sec = sec;
    strcpy(node->form, form);
    node->next = NULL;
    return node;
};

void pushHistDrink(char* name, char size, char* flavor, int price, int year, int month, int date, int hour, int min, int sec, char form[3]){
    History* node = newHistDrink(name, size, flavor, price, year, month, date, hour, min, sec, form);
    if (tailHistory == NULL){
        headHistory = tailHistory = node;
    }
    else{
        tailHistory->next = node;
        tailHistory = node;
    }
}

void popAddOrder() {

    AddOrder* curr = orderHead;
    if (curr->timeLeft <= 0)
    {
        orderHead = curr->next;
        free(curr);
        curr = NULL;
    }
    else
    {
        while(curr->next && curr->next->timeLeft >= 0)
            curr = curr->next;
        if (!curr->next)
            return;
        else if (curr->next == orderTail)
        {
            orderTail = curr;
            free(orderTail);
            orderTail = curr;
        }
        else
        {
            AddOrder* temp = curr->next;
            curr->next = temp->next;
            free(temp);
            temp = NULL;
        }   
    }
}
