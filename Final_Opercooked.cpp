//kode final untuk program Opercooked
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//data structures
struct AddOrder {
    char name[255];
    int price;
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

struct histdessert {
    char name[255];
    char topping[255];
    double callories;
    int price;
    int year, month, date, hour, min, sec;
    char form[3];
};

struct histdrink {
    char name[255];
    char size[2];
    char flavor[255];
    int price;
    int year, month, date, hour, min, sec;
    char form[3];
};

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
void pushOrder(Menu* curr); //Push tail order
Menu* findMenu(int id); //Untuk find menu setelah input di order
AddOrder* createNewOrder(char* name, int price, char* topping, double callories, char* flavor, char size); //Linked list OrderMenu
Menu *addDessert(char *menuName, char *topping, double calories, int menuPrice, int dessertTime); //LinkedList addDessert
void pushTailDessert(char *menuName, char *topping, double calories, int menuPrice, int dessertTime); //pushTail untuk addDessert

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
            // viewCooking();
        }
        if (input == 3)
        {
            printf("\e[1;1H\e[2J");
            // viewOrder();
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
            // addDrink();
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

// void addDrink()
// {
//     strcpy(orderDrink[currentMenu].typeMenu, "Drink");
//     char namaMenu[255], flavor[255];
//     int price;
//     char size[2];

//     getchar();
//     //input nama drink
//     do
//     {
//         printf("Input the name [at least 5 characters]: ");
//         scanf("%[^\n]", namaMenu);
//         getchar();
//     } while (strlen(namaMenu) < 5);

//     strcpy(orderDrink[currentMenu].menuName, namaMenu);

//     //input harga
//     do
//     {
//         printf("Input the price [10 - 500]: $ ");
//         scanf("%d", &price);
//         getchar();
//     } while (price < 10 || price > 500);

//     orderDrink[currentMenu].menuPrice = price;

//     //input flavor
//     int flag = 0;
//     do
//     {
//         printf("Input the flavor ['Mint' | 'Mix Berry' | 'Cheese'](Case Sensitive): ");
//         scanf("%s", flavor);
//         getchar();
//         if (strcmp("Mint", flavor) == 0 || strcmp("Mix Berry", flavor) == 0 || strcmp("Cheese", flavor) == 0)
//         {
//             flag = 1;
//         }
//     } while (flag == 0);
//     strcpy(orderDrink[currentMenu].menuFlavor, flavor);

//     //input size
//     flag = 0;
//     do
//     {
//         printf("Insert the size [S | M | L](Case Sensitive): ");
//         scanf("%s", size);
//         getchar();
//         if (strcmp("S", size) == 0 || strcmp("M", size) == 0 || strcmp("L", size) == 0)
//         {
//             flag = 1;
//         }
//     } while (flag == 0);

//     strcpy(orderDrink[currentMenu].menuSize, size);

//     orderDrink[currentMenu].drinkTime = (rand() % 41) + 10;
//     if (strcmp(flavor, "Mint") == 0)
//     {
//         orderDrink[currentMenu].drinkTime += 10;
//     }
//     else if (strcmp(flavor, "Mix Berry") == 0)
//     {
//         orderDrink[currentMenu].drinkTime += 20;
//     }
//     else if (strcmp(flavor, "Cheese") == 0)
//     {
//         orderDrink[currentMenu].drinkTime += 30;
//     }

//     printf("Successfully added a new menu!");
//     getchar();
//     currentMenu++;
// }

// void viewCooking()
// {
//     printf("| No  | Type     | Name   | Price  | Time Left |\n--------------------------------------------------------------\n");
//     int list = 1;
//     ///////////////////////////////////////////////////////////////////
//     for (int i = 1; i <= totalDessert; ++i)
//     {
//         if (orderDessert[i].dessertTime <= 0)
//             continue;
//         orderDessert[i].dessertTime -= 10;
//         if (orderDessert[i].dessertTime <= 0)
//         {
//             //Pindahin data ke struct history
//             strcpy(historyDessert[totalHDessert].name, orderDessert[i].menuName);
//             strcpy(historyDessert[totalHDessert].topping, orderDessert[i].topping);
//             historyDessert[totalHDessert].callories = orderDessert[i].calories;
//             historyDessert[totalHDessert].price = orderDessert[i].menuPrice;
//             profit += orderDessert[i].menuPrice;
//             //Tambahin order time tapi belum ada
//         }
//     }

//     for (int i = 1; i <= totalDrink; ++i)
//     {
//         if (orderDrink[i].drinkTime <= 0)
//             continue;
//         orderDrink[i].drinkTime -= 10;
//         if (orderDrink[i].drinkTime <= 0)
//         {
//             //Pindahin data ke struct history
//             strcpy(historyDrink[totalHDrink].name, orderDrink[i].menuName);
//             strcpy(historyDrink[totalHDrink].size, orderDrink[i].menuSize);
//             strcpy(historyDrink[totalHDrink].flavor, orderDrink[i].menuFlavor);
//             historyDrink[totalHDrink].price = orderDrink[i].menuPrice;
//             profit += orderDrink[i].menuPrice;
//             //Tambahin order time tapi belum ada
//         }
//     }
//     ///////////////////////////////////////////////////////////////////
//     printf("\t\tDISPLAY MENU\n\n");
//     int idx = 1;
//     //print data dessert
//     while (idx <= totalDessert)
//     {
//         if (orderDessert->dessertTime > 0)
//         {
//             printf(" %-4d| %-9s| %-21s| %-7d| %-10d\n", list, "Dessert", orderDessert[idx].menuName, orderDessert->menuPrice, orderDessert->dessertTime);
//             list++;
//         }
//     }
//     idx = 1;
//     //print data drink
//     while (idx <= totalDrink)
//     {
//         if (orderDrink->drinkTime > 0)
//         {
//             printf(" %-4d| %-9s| %-21s| %-7d| %-10d\n", list, "Drink", orderDrink[idx].menuName, orderDrink->menuPrice, orderDrink->drinkTime);
//             list++;
//         }
//     }
//     printf("Press Enter to return main menu");
//     getchar();
//     //input function mainmenu nya
// }

// void viewOrder()
// {
//     if (totalHDessert || totalHDrink)
//     {
//         puts("| No  | Name                  | Price  | Topping    | Callories  | Flavor     | size  | Order Time              |");
//         puts("-----------------------------------------------------------------------------------------------------------------");
//         for (int i = 0; i < totalHDessert; i++)
//         {
//             printf("| %-3d | %-21s | %-6d | %-10s | %-10.2lf | %-10s | %-5c | %d/%02d/%02d %02d:%02d:%02d %s |\n", i + 1,
//                    historyDessert[i].name, historyDessert[i].price, historyDessert[i].topping, historyDessert[i].callories, "-", "-",
//                    orderDessert[i].orderTime.year, orderDessert[i].orderTime.month, orderDessert[i].date,
//                    orderDessert[i].orderTime.hour, orderDessert[i].orderTime.min, orderDessert[i].orderTime.sec, orderDessert[i].orderTime.form);
//         }
//         for (int i = 0; i < totalHDrink; i++)
//         {
//             printf("| %-3d | %-21s | %-6d | %-10s | %-10.2lf | %-10s | %-5c | %d/%02d/%02d %02d:%02d:%02d %s |\n", i + totalHDessert + 1,
//                    historyDrink[i].name, historyDrink[i].price, "-", "-", historyDrink[i].flavor, historyDrink[i].size,
//                    orderDrink[i].orderTime.year, orderDrink[i].orderTime.month, orderDrink[i].date,
//                    orderDrink[i].orderTime.hour, orderDrink[i].orderTime.min, orderDrink[i].orderTime.sec, orderDrink[i].orderTime.form);
//         }
//     }
//     else
//     {
//         puts("There is no order history!");
//         puts("");
//         puts("Press enter to continue");
//     }
//     getchar();
// }

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
    AddOrder* newOrder = createNewOrder(curr->name, curr->price, curr->topping, curr->calories, curr->flavor, curr->size, curr->time);
    if (!orderHead)
        orderHead = orderTail = newOrder;
    else
    {
        orderTail->next = newOrder;
        orderTail = newOrder;
    }
}

AddOrder* createNewOrder(char* name, int price, char* topping, double callories, char* flavor, char size, int timeLeft) {
    AddOrder* newOrder = (AddOrder*)malloc(sizeof(AddOrder));
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    strcpy(newOrder->name, name);
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