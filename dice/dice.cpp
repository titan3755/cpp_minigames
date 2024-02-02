#include <iostream>
#include <cstdlib>
#include <time.h>
#include <tuple>

using namespace std;

int rand_generator();
void draw_die(int rand_in);
tuple<float, float> process();

int main(int argc, char *argv []) {
    while (true) {
        int roll_times = 0;
        cout << "<---------------- DICE ---------------->" << endl;
        while (true) {
        cout << "\nRoll how many times? ";
        cin >> roll_times;
            if (roll_times == 0) {
                cout << "Invalid Input --> Integer Required";
                continue;
            } else {
                break;
            }
        }

    }
    return 0;
}

void draw_die(int rand_in) {

}

tuple<float, float> process() {

}

int rand_generator() {
    srand(time(0));
    int random_number = (rand() % (6 - 1 + 1)) + 1;
    return random_number;
}
