#include <stdio.h>

typedef struct {
    char *name;
    int value;
} ScoreType;

const ScoreType SCORES[] = {
    {"TD + 2pt", 8},
    {"TD + Extra Point", 7},
    {"TD", 6},
    {"Field Goal", 3},
    {"Safety", 2}
};

const int NUM_SCORES = sizeof(SCORES) / sizeof(SCORES[0]);

void find_combinations(int target_score, int start_idx, int current_combination[], int count_idx) {
    if (target_score == 0) {
        printf("Score combination: ");
        for (int i = 0; i < count_idx; i++) {
            int score_idx = current_combination[i];
            printf("%s (%d)", SCORES[score_idx].name, SCORES[score_idx].value);
            if (i < count_idx - 1) {
                printf(" + ");
            }
        }
        printf("\n");
        return;
    }

    if (target_score < 0) {
        return;
    }

    for (int i = start_idx; i < NUM_SCORES; i++) {
        // Store the index of the score choice
        current_combination[count_idx] = i;
        find_combinations(target_score - SCORES[i].value, i, current_combination, count_idx + 1);
    }
}

int main() {
    int score = 0;

    // Loop until user inputs 1 or less to exit
    while (1) {
        printf("Enter 0 or 1 to stop, or enter the total score: ");
        if (scanf("%d", &score) != 1 || score <= 1) {
            break;
        }

        int combination_buffer[score / 2 + 1];
        printf("\nPossible scoring combinations for a total score of %d:\n", score);
        find_combinations(score, 0, combination_buffer, 0);
        printf("\n");
    }

    return 0;
}
