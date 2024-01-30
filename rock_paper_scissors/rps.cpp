#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string com_select(), compare(string u_in, string c_in);

int main(int argc, char *argv []) {
    while (true) {
        string user_input = "";
        string com_output = com_select();
        string comparison_result = "";
        cout << "<---------------- ROCK PAPER SCISSORS ---------------->" << endl;
        cout << "\nMake your choice: (type r, p or s): ";
        cin >> user_input;
        comparison_result = compare(user_input, com_output);
        if (comparison_result == "e") {
            cout << "Something went wrong! Error..." << endl;
        } else if (comparison_result == "w") {
            cout << "You Won!!!" << endl;
        } else if (comparison_result == "l") {
            cout << "You lost!!!" << endl;
        } else if (comparison_result == "d") {
            cout << "Game draw!!!" << endl;
        } else {
            cout << "Something went very wrong!" << endl;
        }
        cout << "\nAnother round? (y/n): ";
        string loop_input = "";
        cin >> loop_input;
        if (loop_input == "y") {
            continue;
        } else {
            break;
        }
    }
    return 0;
}

string compare(string u_in, string c_in) {
    if (u_in != "r" && u_in != "p" && u_in != "s") {
        return "e";
    }
    if (u_in == "r" && c_in == "s") {
        return "w";
    } else if (u_in == "p" && c_in == "r") {
        return "w";
    } else if (u_in == "s" && c_in == "p") {
        return "w";
    } else if (u_in == c_in) {
        return "d";
    } else {
        return "l";
    }
}

string com_select() {
    srand(time(0));
    int upper_limit = 2;
    int random = rand() % (upper_limit - 0 + 1);
    string output = "";
    switch (random)
    {
    case 0:
        output = "r";
        break;

    case 1:
        output = "p";
        break;

    case 2:
        output = "s";
        break;
    
    default:
        break;
    }
    return output;
}

