#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "../lib/database.h"

/**
 * The main input/output loop should happen here
 **/

int main()
{
    using namespace std;

    cout << "let's do database things\n";
    string command = "";
    database::Database database = database::Database();

    database::WriteOperation what = database.set("key", "value");
    if (what.result == database::OperationResult::success)
        cout << "success" << endl;
    else
        cout << "failure" << endl;
}