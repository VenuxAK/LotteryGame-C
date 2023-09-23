#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int age = 0;
int user_id = 001;
int main_balance = 0;
int balance = 0;
int system_generated_number = 0;
int user_guess_number = 0;

int playGame(int system_number, int user_number, int bal);
int addBalance(int bal);
int again();

int main() {
    printf("######### Welcome from Lottery Game! #########\n\n");

    printf("Please enter your age: ");
    scanf("%d", &age);

    if(age > 17) {
        while (age > 17) {
            printf("Please enter your ID: ");
            scanf("%d", &user_id);
            if(user_id == 001) {
                while (user_id == 001) {
                    printf("Please fill your balance first (Note: more than 500KS): ");
                    scanf("%d", &main_balance);
                    if(main_balance > 499) {
                        while (main_balance > 499) {
                            srand(time(NULL));
                            system_generated_number = 1 + (rand() % 10);
                            printf("How much money will you spend (Note: more than 500KS): ");
                            scanf("%d", &balance);
                            if(main_balance >= balance && balance > 499) {
                                printf("Enter guess number between 1 and 10: ");
                                scanf("%d", &user_guess_number);
                                if(user_guess_number > 0 && user_guess_number <= 10) {
                                    playGame(system_generated_number,user_guess_number, balance);
                                } else {
                                    printf("Guess number must between 1 to 10\n");
                                    printf("Enter guess number between 1 and 10: ");
                                    scanf("%d", &user_guess_number);
                                    playGame(system_generated_number,user_guess_number, balance);
                                }
                            } else {
                                printf("Not enough balance!\n");
                                printf("Your main balance is %d\n", main_balance);
                            }
                        }
                    } else {
                        printf("Low balance!\n");
                        printf("Note: your main balance must have 1000KS\n");
                    }
                }
            } else {
                printf("Wrong ID!!!\n");
            }
        }
    } else {
        printf("You are not allowed to play this adult game***");
    }

    return 0;
}

int addBalance(int bal) {
    main_balance += bal;
}

int playGame(int system_number, int user_number, int bal) {
    if(system_number == user_number) {
        printf("Congrats!!!\nYou Win The Game\n");
        printf("System number is %d\n", system_number);
        main_balance += (bal * 1.5);
        printf("Your main balance is %d\n", main_balance);
        again();
    } else {
        main_balance -= bal;
        printf("Try again!!!\n");
        printf("System generated number is %d\n", system_number);
        printf("Your main balance is %d\n", main_balance);
        again();
    }
}

int again() {
    int play_again = 0;
    printf("Wanna play again?\n");
    printf("Press 1 to play again and 0 exit: ");
    scanf("%d", &play_again);
    if(play_again == 1) {
        return 1;
    } else if(play_again == 0) {
        exit(0);
    }
}