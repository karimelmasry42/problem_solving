#include <stdio.h>
int main() {
  int user_choice;
  float balance, withdraw, deposit;

  printf("Enter current balance: $");
  scanf("%f", &balance);

  do {
    // get choice
    printf("\n");
    printf("Enter \n");
    printf("1 - Show balance \n");
    printf("2 - Withdraw \n");
    printf("3 - Deposit \n");
    printf("4 - Exit \n");
    scanf("%d", &user_choice);
    printf("\n");

    switch (user_choice) {
    case 1:
      // show balance
      printf("Current balance: $%.2f", balance);
      break;

    case 2:
      // withdraw
      printf("Enter withdrawal ammount: $");
      scanf("%f", &withdraw);
      if (withdraw <= 0) {
        printf("Withdrawal amount must be greater than 0");
        break;
      } else if (withdraw > balance) {
        printf("Withdrawal amount cannot be greater than balance");
        break;
      }
      balance -= withdraw;
      printf("$%.2f withdrawn\n", withdraw);
      printf("Current balance: $%.2f", balance);
      break;

    case 3:
      // deposit
      printf("Enter deposit ammount: $");
      scanf("%f", &deposit);
      if (deposit <= 0) {
        printf("Deposit amount must be greater than 0");
        break;
      }
      balance += deposit;
      printf("$%.2f deposited\n", deposit);
      printf("Current balance: $%.2f", balance);
      break;

    case 4:
      // exit
      printf("Goodbye");
      break;

    default:
      // invalid input
      printf("Invalid input");
    }
    printf("\n");
  } while (user_choice != 4);
  return 0;
}