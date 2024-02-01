#include<stdio.h>
#include<stdbool.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 100

bool e_closure[MAX_STATES][MAX_STATES];
bool visited[MAX_STATES];
int num_states, num_symbols;

void findEClosure(int state) {
    visited[state] = true;
    for (int i = 0; i < num_states; i++) {
        if (e_closure[state][i] && !visited[i]) {
            findEClosure(i);
        }
    }
}

int main() {
    printf("Enter the number of states in the NFA: ");
    scanf("%d", &num_states);
    printf("Enter the number of symbols in the NFA: ");
    scanf("%d", &num_symbols);

    printf("Enter the transition matrix for the ε-moves in the NFA:\n");
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_states; j++) {
            scanf("%d", &e_closure[i][j]);
        }
    }

    printf("The ε-closure for each state in the NFA:\n");
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_states; j++) {
            visited[j] = false;
        }
        findEClosure(i);
        printf("ε-closure of state %d: {", i);
        for (int j = 0; j < num_states; j++) {
            if (visited[j]) {
                printf("%d, ", j);
            }
        }
        printf("}\n");
    }
    return 0;
}
