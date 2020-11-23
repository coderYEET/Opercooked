#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int currentMenu = 1, profit = 0;
struct Menu {
    int id;
    char type[10];
    char name[255] = {};
    int price;
    char topping[10] = {};
    double callories;
    char flavor[15] = {};
    char size;
    Menu *next;
}*menuHead, *menuTail;

void addDrink();

struct AddOrder {
    char type[15];
    char name[255];
    int price;
    char topping[10];
    double callories;
    char flavor[15];
    char size;
    int year, month, date, hour, min, sec;
    char form[3];
    AddOrder *next;
}*orderHead, *orderTail;

AddOrder* createNewOrder(char* name, int price, char* topping, double callories, char* flavor, char size, char* type) {
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
    newOrder->next = NULL;
}

void order();
void pushOrder(Menu* curr);
Menu* findMenu(int id);

int main() {

    while(1)
    {
        system("cls");
        puts("1. add drink");
        puts("2. order");
        int input;
        scanf ("%d", &input); getchar();
        if (input == 1) addDrink();
        else if (input == 2) order();
        else if (input == 3) break;
    }

    return 0;
}

void order() {
    system("cls");
    if (!menuHead)
    {
        puts("There is no Dessert or Drink on the list!");
        printf ("\nPress Enter to continue..."); getchar();
    }
    else
    {
        Menu* curr = menuHead;
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
                printf ("| %-12s| %-11.2lf| %-11s| %-6s|\n", curr->topping, curr->callories, "-", "-");
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
    if (!menuHead)
        return NULL;
    else
    {
        Menu* curr = menuHead;
        while(curr && curr->id != id)
            curr = curr->next;
        
        return curr;
    }
    
}

void pushOrder(Menu* curr) {
    AddOrder* newOrder = createNewOrder(curr->name, curr->price, curr->topping, curr->callories, curr->flavor, curr->size, curr->type);

    if (!orderHead)
        orderHead = orderTail = newOrder;
    else
    {
        orderTail->next = newOrder;
        orderTail = newOrder;
    }
    
}

//LinkedList addDrink
Menu* createNewDrink(char *menuName, char *flavor, char size, int menuPrice)
{
    Menu* newDrink = (Menu*)malloc(sizeof(Menu));

    newDrink->id = currentMenu;
    strcpy(newDrink->type, "Drink");
    strcpy(newDrink->name, menuName);
    strcpy(newDrink->flavor, flavor);
    newDrink->size = size;
    newDrink->price = menuPrice;
    // newDrink->drinkTime = drinkTime;
    newDrink->next = NULL;

    return newDrink;
}

//pushTail addDrink
void pushTailAddDrink(char *menuName, char *flavor, char size, int menuPrice)
{
    Menu* temp = createNewDrink(menuName, flavor, size, menuPrice);
    if (!menuHead)
    {
        menuHead = menuTail = temp;
    }
    else
    {
        menuTail->next = temp;
        menuTail = temp;
    }
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
    
    printf("Successfully added a new menu!");
    getchar();
    pushTailAddDrink(namaMenu, flavor, size, price);
    currentMenu++;
}