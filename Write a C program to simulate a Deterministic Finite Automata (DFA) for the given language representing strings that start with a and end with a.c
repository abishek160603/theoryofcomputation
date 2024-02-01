#include <stdio.h>
#include <string.h>

// DFA transition function
int transition(int state, char input) {
    if (state == 0 && input == 'a')
        return 1;
    else if (state == 1 && input != 'a')
        return 2;
    else if (state == 2 && input == 'a')
        return 3;
    else
        return 2; // Dead state
}

// DFA simulation
int main() {
    char input[100];
    int state = 0;
    int i;

    printf("Enter a string: ");
    scanf("%s", input);

    for (i = 0; i < strlen(input); i++) {
        state = transition(state, input[i]);
    }

    if (state == 3)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}
