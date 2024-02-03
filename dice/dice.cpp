#include <iostream>
#include <cstdlib>
#include <time.h>
#include <tuple>
#include <vector>
#include <chrono>
#include <ctime>
#include <string>
#include <limits>

using namespace std;

int rand_generator(), max_value(int[6]);
void draw_die(int rand_in);
tuple<int, long long int, float, int> process(vector<char>);

int main(int argc, char *argv []) {
    time_t nowmil = time(nullptr) * 1000;
    srand(nowmil);
    while (true) {
        system("cls");
        int roll_times = 0;
        cout << "<---------------- DICE ---------------->" << endl;
        while (true) {
        cout << "\nRoll how many times? ";
        cin >> roll_times;
            if (roll_times == 0) {
                cout << "Invalid Input --> Integer Required";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            } else {
                break;
            }
        }
        vector<char> dice_values;
        for (int i = 0; i < roll_times; i++) {
            dice_values.push_back(rand_generator());
        }
        auto [fn, sum, average, max] = process(dice_values);
        cout << "\n";
        draw_die(fn);
        cout << "\n\n";
        cout << "Roll Count: " << roll_times << "\nFinal Number: " << fn << "\nAverage Value: " << average << "\nMax Value: " << max << "\nVector Size: " << sizeof(std::vector<char>) + (sizeof(char) * dice_values.size()) << " bytes" << "\nSum of all roll values: " << sum << endl;
        string user_cont = "";
        cout << "\nReset the program? (y/n): ";
        cin >> user_cont;
        if (user_cont == "y") {
            continue;
        } else {
            break;
        }
    }
    return 0;
}

void draw_die(int rand_in) {
    switch (rand_in)
    {
    case 1:
        cout << "-----\n|   |\n| o |\n|   |\n-----";
        break;
    
    case 2:
        cout << "-----\n|  o|\n|   |\n|o  |\n-----";
        break;

    case 3:
        cout << "-----\n|  o|\n| o |\n|o  |\n-----";
        break;

    case 4:
        cout << "-----\n|o o|\n|   |\n|o o|\n-----";
        break;

    case 5:
        cout << "-----\n|o o|\n| o |\n|o o|\n-----";
        break;

    case 6:
        cout << "-----\n|ooo|\n|   |\n|ooo|\n-----";
        break;

    default:
        break;
    }
}

tuple<int, long long int, float, int> process(vector<char> dice_vec) {
    int dice_nums[6] = {0, 0, 0, 0, 0, 0};
    long long int sum = 0;
    int ct = 0;
    for (int i = 0; i < dice_vec.size(); i++) {
        sum += dice_vec[i];
        ct++;
    }
    for (int j = 0; j < dice_vec.size(); j++) {
        dice_nums[dice_vec[j] - 1] += 1;
    }
    float average = (float)sum / (float)ct;
    int final_num = dice_vec[dice_vec.size() - 1];
    return make_tuple(final_num, sum, average, max_value(dice_nums));
}

int max_value(int value_arr[6]) {
    int max = value_arr[0];
    int count = 0;
    for (int i = 0; i < 6; i++) {
        if (max < value_arr[i]) {
            max = value_arr[i];
            count = i + 1;
        }
        if (i == 5 && max == value_arr[0]) {
            count = 1;
        }
    }
    return count;
}

int rand_generator() {
    int random_number = (rand() % (6 - 1 + 1)) + 1;
    return random_number;
}
