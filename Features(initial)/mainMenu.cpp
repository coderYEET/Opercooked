#include <stdio.h>

void mainMenu();
void addMenu();

int profit = 0;

int main() {

	mainMenu();

	return 0;
}

void mainMenu() {
	int input;
	do {
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
		scanf("%d", &input);
		if(input == 1) {
			printf("\e[1;1H\e[2J");
			addMenu();
			getchar();
			getchar();
		}
		if(input == 2) {
			printf("\e[1;1H\e[2J");
			// viewCooking();
			getchar();
			getchar();
		}
		if(input == 3) {
			printf("\e[1;1H\e[2J");
			// viewOrder();
			getchar();
			getchar();
		}
		if(input == 4) {
			printf("\e[1;1H\e[2J");
			// order();
			getchar();
			getchar();
		}
		if(input == 5) {
			printf("\e[1;1H\e[2J");
			break;
		}
	} while(input != 5);
}

void addMenu() {
	int input;
	do {
		printf("\e[1;1H\e[2J");
		puts("What do you want to add?");
		puts("1. Dessert");
		puts("2. Drink");
		printf("Choose: ");
		scanf("%d", &input);
		if(input == 1) {
			printf("\e[1;1H\e[2J");
			//dessert();
			getchar();
		}
		if(input == 2) {
			printf("\e[1;1H\e[2J");
			//drink();
			getchar();
		}
	} while(input < 1 || input > 2);
}
