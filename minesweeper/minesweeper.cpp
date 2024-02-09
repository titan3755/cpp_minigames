#include "include/utils.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <time.h>
#include <ctype.h>
#include <cmath>

#define ARR_LENGTH 49 // Game grid size --> must be a perfect square or game will glitch out

using namespace std;

void intro(), game_mn(), grid_draw(int act_grid[], int act_n, int usr_grid[], int usr_n), score_calc_draw(int score, int tries), end_scrn(bool* loop), array_printer(int arr[], int n);
int rand_generator(int ub, int lb);

int main(int argc, char *argv[]) {
    time_t nowmil = time(nullptr) * 1000;
    srand(nowmil);
    bool g_loop = true;
    while (g_loop) {
        intro();
        game_mn();
        end_scrn(&g_loop);
    }
    return 0;
}

void intro() {
    clrscrn();
    string usrinpt = "";
    cout << "<---------------- MINESWEEPER ---------------->" << endl;
    cout << "\nWelcome to a command-line clone of the classic game Minesweeper!" << endl;
    cout << "\nJump right in or go to the help screen? (g/h):";
    cin >> usrinpt;
    if (usrinpt == "h") {
        clrscrn();
        string usr_cont = "";
        cout << "<---------------- HELP ---------------->\n\n" << endl;
        cout << "1. There will be a score counter at the top\n" << endl;
        cout << "2. A 7x7 grid will be displayed which will be the game map and all cells initialized with \"?\" symbol\n" << endl;
        cout << "3. The grid cells which contain a \"+\" character after user input indicate score loss\n" << endl;
        cout << "4. The grid cells which contain a \"o\" character after user input indicate score gain\n" << endl;
        cout << "5. The grid will remain unrevealed initially and cells filled with empty spaces\n" << endl;
        cout << "6. If the same row and col no is entered more than once the score will remain unchanged\n" << endl;
        cout << "7. Win or Loss stat will depend on score\n\n" << endl;
        cout << "Start game? (y/n):";
        cin >> usr_cont;
        if (usr_cont == "n") {
            exit(0);
        }
    }
    clrscrn();
    return;
}

void game_mn() {
    int game_arr[ARR_LENGTH] = {0};
    int usr_inp_arr[ARR_LENGTH] = {0};
    int score = 0;
    int tries = 0;
    for (int i = 0; i < sizeof(game_arr)/sizeof(game_arr[0]); i++) {
        int rand_nm = rand_generator(5, 1);
        if (rand_nm == 3 || rand_nm == 5) {
            game_arr[i] = 1;
        }
    }
    while(score < 5 && score > -5) {
        string row_col = "";
        clrscrn();
        cout << "<---------------- MINESWEEPER ---------------->\n" << endl;
        score_calc_draw(score, tries);
        grid_draw(game_arr, ARR_LENGTH, usr_inp_arr, ARR_LENGTH);
        // array_printer(game_arr, ARR_LENGTH); debug
        // array_printer(usr_inp_arr, ARR_LENGTH); debug
        while (true) {
            cout << "\nEnter the row and col number (e.g-> 4x5 for row 4 col 5): ";
            cin >> row_col;
            if (row_col.length() == 3 && isdigit(row_col[0]) && row_col[1] == 'x' && isdigit(row_col[2])) {
                if ((int(row_col[0]) - 48) >= 1 && (int(row_col[0]) - 48) <= (int)sqrt(ARR_LENGTH) && (int(row_col[2]) - 48) >= 1 && (int(row_col[2]) - 48) <= (int)sqrt(ARR_LENGTH)) {
                    break;
                } else {
                    cout << "Row and Col number must be within the interval [1, " << (int)sqrt(ARR_LENGTH) << "] !" << endl;
                    continue;
                }
            } else {
                cout << "Incorrect format! Try again -->" << endl;
                continue;
            }
        }
        int position = ((int)sqrt(ARR_LENGTH) * ((int(row_col[0]) - 48) - 1) + (int(row_col[2]) - 48)) - 1;
        if (usr_inp_arr[position] == 1) {
            tries++;
            continue;
        } else {
            usr_inp_arr[position] = 1;
        }
        if (game_arr[position] == 1) {
            score--;
        } else {
            score++;
        }
        tries++;
    }
    if (score >= 5) {
        cout << "\nYou won the game! Tries: " << tries << endl;
    } else if (score <= -5) {
        cout << "\nYou lost the game! Tries: " << tries << endl;
    }
}

void score_calc_draw(int score, int tries) {
    cout << "Your score ----> " << score << "     Number of tries: " << tries << endl;
}

void grid_draw(int act_grid[], int act_n, int usr_grid[], int usr_n) {
    cout << "\n";
    for (int j = 0; j < (int)sqrt(ARR_LENGTH); j++) {
        if (j == 0) {
            cout << " ";
        }
        cout << " " << (j + 1) << " ";
    }
    cout << "\n";
    for (int k = 0; k < (int)sqrt(ARR_LENGTH); k++) {
        if (k == 0) {
            cout << "  ";
        }
        if (k < ((int)sqrt(ARR_LENGTH) - 1)) {
            cout << "---";
        } else {
            cout << "-";
        }
    }
    cout << " ";
    for (int i = 0; i < usr_n; i++) {
        if (i == 0) {
            cout << "\n" << 1;
        }
        if (i % (int)sqrt(ARR_LENGTH) == 0 && i != 0) {
            cout << "\n" << ((int)(i / (int)sqrt(ARR_LENGTH))) + 1;
        }
        string usr_char = "";
        if (act_grid[i] == 1 && usr_grid[i] == 1) {
            usr_char = "+";
        } else if (usr_grid[i] == 1 && act_grid[i] == 0) {
            usr_char = "o";
        } else {
            usr_char = "?";
        }
        cout << "|" << usr_char << "|";
    }
    cout << "\n  ------------------- ";
    cout << "\n";
}

void end_scrn(bool* loop) {
    string usr_in = "";
    cout << "\n\nReset the game or exit? (r/e):";
    cin >> usr_in;
    if (usr_in == "e") {
        *loop = false;
    }
}

void array_printer(int arr[], int n) {
    cout << "\nArray: ";
    for (int i = 0; i < n; i++) {
        cout << " " << arr[i];
    }
    cout << "\n";
}

int rand_generator(int ub, int lb) {
    int random_number = (rand() % (ub - lb + 1)) + lb;
    return random_number;
}
