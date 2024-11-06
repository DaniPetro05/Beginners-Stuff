#include <stdio.h>
#include <stdlib.h>

/*More comments awaiting currently. 
Project not done yet! */

struct Player {
    int win;
    int lose;
    int rang;
    int ID;
};

struct Games {
    int game_casual_winner[5];
    int game_casual_loser[5];
};


int input_handling_n(int *index, struct Player players[5], struct Games *games) { //Function handling inputs.
    int bool = 0; //True/False value (0 = false, 1 = true)
    int win_input;
    int lose_input;
    printf("\nEnter winner ID (1-5): ");
    scanf("%d", &win_input);
    printf("\nEnter loser ID (1-5): \n");
    scanf("%d", &lose_input);
    if (win_input == lose_input) { //Check for identical inputs.
        fprintf(stderr, "Winner and loser identical!");
        return 1;
    } else if ((win_input > 5 || win_input < 0) ^ (lose_input > 5 || lose_input < 0)) { //One of them must be wrong (XOR)!
        return 1;
    } else {
        if (*index < 5) {
            games->game_casual_winner[*index] = win_input;
            games->game_casual_loser[*index] = lose_input;
            players[win_input - 1].win += 1;
            players[lose_input - 1].lose += 1;
        }  
        }
        (*index)++; //Increment index for next inputs. Pointer, since index must be globally changed!
        bool = 1; //Make value true 
        if (bool) { //If true, then declare this block.
            printf("New game added");
        } else { //Else false, return 1.
            return 1;
    }
    return 0;
}

int ranked_score(int *index, struct Player players[5], struct Games *games) { //For ranked type
    for (int j = 0; j < *index; j++) {
        if (players[j].win) {
            players[j].rang += 50;
        } 
        if (players[j].lose) {
            for (int i = 0; i < *index; i++) {
                if (players[i].rang <= 0) { //Checks if there is still 0 points.
                    break; //If so, stay still.
                } else if (players[i].rang >= 50) { //If bigger than 50, subtract.
                    players[i].rang -= 50;
                    break;
                }
            }
        }
    }
    return 0;
}

int game_mode (int *index, struct Player players[5], struct Games *games) { //Checks for casual or ranked mode.
    char rank_or_casual;
    printf("\nEnter game type (c,r): ");
    scanf(" %c", &rank_or_casual);
    switch(rank_or_casual) {
        case 'c':
            input_handling_n(index, players, games); //Prior function declared for case c.
            break;
        case 'r':
            input_handling_n(index, players, games); //Prior function declared for case r.
            ranked_score(index, players, games);
            break;
    }
    return 0;
}
int main() {
    char input;
    struct Player players[5] = {
    {0, 0, 100, 1},
    {0, 0, 100, 2},
    {0, 0, 100, 3},
    {0, 0, 100, 4},
    {0, 0, 100, 5}
    };
    struct Games games = {0};
    int index = 0; //Index starting with 0 (commonplace).
    int selectPlayer;
    char input_g;
    while(1) {
        printf("\nEnter n, r, p, g or x: ");
        scanf(" %c", &input);
        getchar(); //Optional: Clears out newline buffers.
        switch(input) {
            case 'n':
                game_mode(&index, players, &games); //Key 'n' initiates input_handling inside game_mode function.
                continue;
            case 'r':
                printf("\nPlayer ranks");
                for (int i = 0; i < 5; i++) {
                    printf("\nPlayer %d - Rank %d - TOP", players[i].ID, players[i].rang);
                }
                continue;
            case 'p':
                printf("\nSelect player (1-5): ");
                scanf("%d", &selectPlayer);
                if ((players[selectPlayer - 1].win == 0) && (players[selectPlayer - 1].lose) == 0) {
                    printf("\nPlayer %d - Rank %d", players[selectPlayer - 1].ID, players[selectPlayer - 1].rang);
                    printf("\nWins/Losses/Winrate: %.0lf/%.0lf/%.2lf %%", (double)(players[selectPlayer - 1].win), (double)(players[selectPlayer - 1].lose), 0.00);
                }
                else if ((players[selectPlayer - 1].lose) == 0) {
                    printf("\nPlayer %d - Rank %d", players[selectPlayer - 1].ID, players[selectPlayer - 1].rang);
                    printf("\nWins/Losses/Winrate: %.0lf/%.0lf/%.2lf %%", (double)(players[selectPlayer - 1].win), (double)(players[selectPlayer - 1].lose), 100.00);
                } else {
                    printf("\nPlayer %d - Rank %d", players[selectPlayer - 1].ID, players[selectPlayer - 1].rang);
                    printf("\nWins/Losses/Winrate: %.0lf/%.0lf/%.2lf %%", (double)(players[selectPlayer - 1].win), (double)(players[selectPlayer - 1].lose), (double)(players[selectPlayer - 1].win) / (double)((players[selectPlayer - 1].win) + (double)(players[selectPlayer - 1].lose)) * 100);
                }
                break;
            case 'g':
                printf("\nRanked or casual? (r,c):");
                scanf(" %c", &input_g);
                switch(input_g) {
                    case 'r':
                        for (int i = 0; i < index; i++) {
                            printf("\nWinner: %d - Loser: %d", games.game_casual_winner[i], games.game_casual_loser[i]);
                        }
                        continue;
                    case 'c':
                        break;
                }
            case 'x': 
                exit(EXIT_SUCCESS);
                // printf("No games available.\n");
                }
        }
        return 0;
    }
