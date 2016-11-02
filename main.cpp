#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tolower(char val);

char oui_non(void);

int main() {
    const signed short max = 100, min = 1;
    signed short nombreMystere, numberChosen;
    short comp = 0;

    srand((unsigned int) time(0));
    nombreMystere = (rand() % (max - min + 1)) + min;
    numberChosen = 0;

    char i;
    do {
        while (numberChosen != nombreMystere) {
            printf("choose a number between 0 and 100 : ");
            comp++;
            fflush(stdin);
            scanf("%hd", &numberChosen);

            if (numberChosen == nombreMystere) {
                printf("that's great , you win! after trying %hd times \n", comp);
            } else if (numberChosen < nombreMystere) {
                printf("choose a higher number");
            } else if (numberChosen > nombreMystere) {
                printf("choose a lower number");
            }
        }
        i = oui_non();
        numberChosen = 0;
        comp = 0;
    } while (i != 'n' && i == 'o');
    return 0;
}

char oui_non(void) {
    char caract;
    char answer;

    do {
        printf("Do you want to play again ? answer with O (Yes) or N(No). \n");
        fflush(stdin);
        scanf("%c", &caract);
    } while (caract != 'o' && caract != 'O' && caract != 'n' && caract != 'N');
    answer = tolower(caract);
    return answer;

}

char tolower(char val) {
    if (val == 'O') {
        val = 'o';
    }

    if(val == 'N'){
        val = 'n';
    }

    return val;
}