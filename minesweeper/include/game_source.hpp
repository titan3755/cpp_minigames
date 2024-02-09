#ifndef GAME_SOURCE_HPP
#define GAME_SOURCE_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <time.h>
#include <ctype.h>
#include <cmath>
#include "utils.hpp"

#define ARR_LENGTH 81 // Game grid size --> must be a perfect square or game will glitch out

void intro(), game_mn(), grid_draw(int act_grid[], int act_n, int usr_grid[], int usr_n), score_calc_draw(int score, int tries), end_scrn(bool* loop), array_printer(int arr[], int n);
int rand_generator(int ub, int lb);

#endif