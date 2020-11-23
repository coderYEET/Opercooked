#include<stdio.h>

histdessert historyDessert[105];
histdrink historyDrink[105];
pesanDessert orderDessert[105];
pesanDrink orderDrink[105];

void viewOrder(){
    if(totalHDessert || totalHDrink){
        puts("| No  | Name                  | Price  | Topping    | Callories  | Flavor     | size  | Order Time              |");
        puts("-----------------------------------------------------------------------------------------------------------------");
        for(int i = 0; i < totalHDessert; i++){
            printf("| %-3d | %-21s | %-6d | %-10s | %-10.2lf | %-10s | %-5c | %d/%02d/%02d %02d:%02d:%02d %s |\n", i + 1, 
            historyDessert[i].name, historyDessert[i].price, historyDessert[i].topping, historyDessert[i].callories, "-", "-", 
            orderDessert[i].orderTime.year, orderDessert[i].orderTime.month, orderDessert[i].date, 
            orderDessert[i].orderTime.hour, orderDessert[i].orderTime.min, orderDessert[i].orderTime.sec, orderDessert[i].orderTime.form);
        }
        for(int i = 0; i < totalHDrink; i++){
            printf("| %-3d | %-21s | %-6d | %-10s | %-10.2lf | %-10s | %-5c | %d/%02d/%02d %02d:%02d:%02d %s |\n", i + totalHDessert + 1, 
            historyDrink[i].name, historyDrink[i].price, "-", "-", historyDrink[i].flavor, historyDrink[i].size, 
            orderDrink[i].orderTime.year, orderDrink[i].orderTime.month, orderDrink[i].date, 
            orderDrink[i].orderTime.hour, orderDrink[i].orderTime.min, orderDrink[i].orderTime.sec, orderDrink[i].orderTime.form);
        }
    }
    else{
        puts("There is no order history!");
        puts("");
        puts("Press enter to continue");
    }
    getchar();
}