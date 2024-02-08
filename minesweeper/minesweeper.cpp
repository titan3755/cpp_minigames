#include "include/utils.hpp"
#include <iostream>
#include <string>

using namespace std;

void intro(), game_mn(), grid_draw(), score_calc_draw(), end_scrn();

int main(int argc, char *argv[]) {
    while (true) {
        intro();
        game_mn();
        end_scrn();
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
        cout << "2. A 7x7 grid will be displayed which will be the game map\n" << endl;
        cout << "3. The grid cells which contain a \"+\" character after user input indicate score loss\n" << endl;
        cout << "4. The grid cells which contain a \"o\" character after user input indicate score gain\n" << endl;
        cout << "5. The grid will remain unrevealed initially and cells filled with empty spaces\n" << endl;
        cout << "6. Win or Loss stat will depend on score\n\n" << endl;
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
    char game_arr[49] = {0};
    char usr_inp_arr[49] = {0};
    while(true) {
        clrscrn();
        cout << "<---------------- MINESWEEPER ---------------->\n\n" << endl;
        score_calc_draw();
        grid_draw();
    }
}

void score_calc_draw() {

}

void grid_draw() {

}

void end_scrn() {

}