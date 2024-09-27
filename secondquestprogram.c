


#include <stdio.h>
#include <string.h>

typedef struct {
    char accountNumber[5];
    float balance;
} Account;

Account accounts[3] = {
    {"1234", 1000.0},
    {"5678", 2000.0},
    {"9012", 3000.0}
};

char selectedAccount[5] = "";

void displayMenu() {
    printf("\nBanking System Menu:\n");
    printf("1. Select Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%s", selectedAccount);
                break;

            case 2:
                if (strcmp(selectedAccount, "") != 0) {
                    float amount;
                    printf("Enter amount to deposit: ");
                    scanf("%f", &amount);
                    for (int i = 0; i < 3; i++) {
                        if (strcmp(accounts[i].accountNumber, selectedAccount) == 0) {
                            accounts[i].balance += amount;
                            printf("Deposit Successful. New balance: %.2f\n", accounts[i].balance);
                        }
                    }
                } else {
                    printf("Please select an account first.\n");
                }
                break;

            case 3:
                if (strcmp(selectedAccount, "") != 0) {
                    float amount;
                    printf("Enter amount to withdraw: ");
                    scanf("%f", &amount);
                    for (int i = 0; i < 3; i++) {
                        if (strcmp(accounts[i].accountNumber, selectedAccount) == 0) {
                            if (amount > accounts[i].balance) {
                                printf("Insufficient balance.\n");
                            } else {
                                accounts[i].balance -= amount;
                                printf("Withdrawal Successful. New balance: %.2f\n", accounts[i].balance);
                            }
                        }
                    }
                } else {
                    printf("Please select an account first.\n");
                }
                break;

            case 4:
                if (strcmp(selectedAccount, "") != 0) {
                    for (int i = 0; i < 3; i++) {
                        if (strcmp(accounts[i].accountNumber, selectedAccount) == 0) {
                            printf("Current balance: %.2f\n", accounts[i].balance);
                        }
                    }
                } else {
                    printf("Please select an account first.\n");
                }
                break;

            case 5:
                printf("Thank you for using our banking system.\n");
                return 0;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}


