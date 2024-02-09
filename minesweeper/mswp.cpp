#include "include/game_source.hpp"

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