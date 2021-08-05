#include <iostream>
#include <string>
#include <vector>
#include "database.cpp"

using namespace std;

// enum CommandType
// {
//     GET,
//     SET
// };

// struct Command
// {
//     string name;
//     CommandType type;
//     vector<string> args;
// };

/**
 * The main input/output loop should happen here
 **/

int main()
{
    cout << "let's do database things\n";
    string command = "";
    Database database = Database();
    while (true)
    {
        cin >> command;
        // database.evaluate(&command);
    }
}