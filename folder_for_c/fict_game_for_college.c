#include <stdio.h>
#include <stdlib.h>

//Project 100% finished!!!

struct Player { //Struct for commencing player manipulation of statistics.
    int win;
    int lose;
    int rang;
    int ID;
};

struct Games { //Saved games stored in respective arrays.
    int game_casual_winner[5];
    int game_casual_loser[5];
    int game_ranked_winner[5];
    int game_ranked_loser[5];
};

int input_handling_n(int *index1, int *index2, struct Player players[5], struct Games *games, int *win_input, int *lose_input, char *rank_or_casual) { //Function handling inputs.
    int is_successful = 0; //True/False value (0 = false, 1 = true)
    char identical[30] = "Winner and loser identical!"; //Explicitly declared due to CodeRunner issues.
    printf("\nEnter winner ID (1-5): ");
    scanf("%d", win_input);
    getchar();
    printf("\nEnter loser ID (1-5): ");
    scanf("%d", lose_input);
    getchar();
    if (*win_input == *lose_input) { //Immediately return false for same both inputs.
        printf("\n%s", identical);
        return 1;
    }
    if ((*win_input > 5 || *win_input < 0) ^ (*lose_input > 5 || *lose_input < 0)) { //One of these conditions must be wrong (XOR).
        return 1; //Abruptly ends the program if only one of any input exceeds 5 or descends 0.
    } else {
        switch(*rank_or_casual) {
            case 'c':
            if (*index1 < 5) { //5 entries max.
                games->game_casual_winner[*index1] = *win_input; //Sorts all win inputs into winner elements.
                games->game_casual_loser[*index1] = *lose_input; //Sorts all loss inputs into loser elements.
                players[*win_input - 1].win += 1; //Increment 1 win each time a player number is typed in from win_input.
                players[*lose_input - 1].lose += 1; //Increment 1 loss each time a player number is typed in from lose_input.
                (*index1)++; //Increment index1 for next casual inputs. Pointer, since index changes after each successful input!
            }  
            break;
            case 'r':
            if (*index2 < 5) { //5 entries max.
                games->game_ranked_winner[*index2] = *win_input; // Same as above, though only applicable to ranked.
                games->game_ranked_loser[*index2] = *lose_input; // ...
                players[*win_input - 1].win += 1; //...
                players[*lose_input - 1].lose += 1; //...
                (*index2)++; //Increment index2 for next ranked inputs. 
            }  
            break;
        } 
    } 
        is_successful = 1; //Make value true 
        if (is_successful) { //If true, then declare this block.
            printf("\nNew game added"); //Print for every successful game added.
        } else { //Else false, return 1.
            return 1;
    }
    return 0;
}
int ranked_score(int *index1, int *index2, struct Player players[5], struct Games *games, int *win_input, int *lose_input) { //Evaluates ranks based on wins or losses (ranked mode)
    if (players[*win_input - 1].win) {
        players[*win_input - 1].rang += 50; //Add 50 points for win.
    }
    if (players[*lose_input - 1].lose) {
        if (players[*lose_input - 1].rang == 0) { 
            return 1; //If points reach 0, do nothing.
        } else if (players[*lose_input - 1].rang >= 50) { 
            players[*lose_input - 1].rang -= 50; //Else, subtract 50.
        }
    } 
    return 0;
}
int game_mode (int *index1, int *index2, struct Player players[5], struct Games *games, int *win_input, int *lose_input, char *rank_or_casual) { //Checks for casual or ranked mode.
    printf("\nEnter game type (c,r): ");
    scanf("%c", rank_or_casual); //Evaluate c or r.
    getchar(); //Remove any trailing characters.
    switch(*rank_or_casual) {
        case 'c':
            input_handling_n(index1, index2, players, games, win_input, lose_input, rank_or_casual); //Prior function declared for case c.
            break;
        case 'r':
            input_handling_n(index1, index2, players, games, win_input, lose_input, rank_or_casual); //Prior function declared for case r.
            ranked_score(index1, index2, players, games, win_input, lose_input); //Since ranked, ranked_score function is declared.
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
    }; //Every player with same stats, but different IDs.
    struct Games games = {0}; //Game stats are all at 0.
    int index1 = 0, index2 = 0; //Index starting with 0 (commonplace).
    int selectPlayer;
    char input_g;
    char rank_or_casual;
    int winner_input, loser_input;
    while(1) {
        printf("\nEnter n, r, p, g or x: ");
        scanf("%c", &input);
        getchar(); //Optional: Remove any leftover newlines/characters.
        switch(input) {
            case 'n': //n nitiates the input process.
                game_mode(&index1, &index2, players, &games, &winner_input, &loser_input, &rank_or_casual); //Key 'n' initiates input_handling inside game_mode function.
                continue;
            case 'r': //r lists all players with respective ranks (highest points = TOP)
                printf("\nPlayer ranks");
                int top_rang = players[0].rang; //Serves as a placeholder.
                for (int i = 1; i < 5; i++) {
                    if (players[i].rang > top_rang) { 
                        top_rang = players[i].rang; // As soon as any other rang greater than 100, make that one top rank.
                    }
                }
                for (int i = 0; i < 5; i++) {
                    if (players[i].rang == top_rang) { //If more than one the same rang size, add TOP afterwards.
                        printf("\nPlayer %d - Rank %d - TOP", players[i].ID, players[i].rang);
                    } else { //Otherwise, list just IDs and rangs.
                        printf("\nPlayer %d - Rank %d", players[i].ID, players[i].rang);
                    }
                }
                continue;  
            case 'p': //p evaluates selected player and their wins/losses/winrate.
                printf("\nSelect player (1-5): ");
                scanf("%d", &selectPlayer);
                getchar();
                if ((players[selectPlayer - 1].win == 0) && (players[selectPlayer - 1].lose) == 0) { //Makes sure that division by 0 is avoided, and no winrate displayed.
                    printf("\nPlayer %d - Rank %d", players[selectPlayer - 1].ID, players[selectPlayer - 1].rang);
                    printf("\nWins/Losses/Winrate: %.0lf/%.0lf/%.2lf %%", (double)(players[selectPlayer - 1].win), (double)(players[selectPlayer - 1].lose), 0.00);
                }
                else if ((players[selectPlayer - 1].lose) == 0) { //No losses entail 100% winrate.
                    printf("\nPlayer %d - Rank %d", players[selectPlayer - 1].ID, players[selectPlayer - 1].rang);
                    printf("\nWins/Losses/Winrate: %.0lf/%.0lf/%.2lf %%", (double)(players[selectPlayer - 1].win), (double)(players[selectPlayer - 1].lose), 100.00);
                } else { //Otherwise, adjust winrate based on the formula win/(win+loss)*100.
                    printf("\nPlayer %d - Rank %d", players[selectPlayer - 1].ID, players[selectPlayer - 1].rang);
                    printf("\nWins/Losses/Winrate: %.0lf/%.0lf/%.2lf %%", (double)(players[selectPlayer - 1].win), (double)(players[selectPlayer - 1].lose), (double)(players[selectPlayer - 1].win) / (double)((players[selectPlayer - 1].win) + (double)(players[selectPlayer - 1].lose)) * 100);
                }
                break;
            case 'g': //g opens up ranked or casual winners and losers respectively.
                printf("\nRanked or casual? (r,c):");
                scanf("%c", &input_g);
                getchar();
                switch(input_g) { //Case r checks all ranked games, c casual games.
                    case 'r': //r checks all ranked winners and losers
                    if ((games.game_ranked_winner[0] != 0) || (games.game_ranked_loser[0] != 0)) { //If first player's values other than 0, display all winners and losers inputted.
                        for (int i = 0; i < index2; i++) {
                            printf("\nWinner: %d - Loser: %d", games.game_ranked_winner[i], games.game_ranked_loser[i]);
                        }
                    } else { //Otherwise, no games started, hence commence print statement.
                        printf("\nThere are no games yet.");
                    }
                    continue;
                    case 'c': //Same what r does, but for casual games.
                    if ((games.game_casual_winner[0] != 0) || (games.game_casual_loser[0] != 0)) { //Same as predecessor.
                        for (int i = 0; i < index1; i++) {
                            printf("\nWinner: %d - Loser: %d", games.game_casual_winner[i], games.game_casual_loser[i]); //Same as predecessor.
                        } 
                    } else {
                        printf("\nThere are no games yet.");
                    }   
                    continue;
            }
            case 'x': //Quits the programm
                exit(EXIT_SUCCESS);
        }
    }
    return 0;
}
