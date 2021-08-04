#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * The database should define an interface which can be used to store and retrieve data
 * 
 * We will need to make use of the filesystem to persist the data
 **/

class Database
{
public:
    Database(bool start_immediately) : running{start_immediately} {}
    void evaluate(string *command)
    {
        if (command == nullptr)
        {
            return;
        }
        if (*command == "get")
        {
            cout << "get command\n";
        }

        if (*command == "set")
        {
            cout << "set command\n";
        }
    };

private:
    bool running;
};