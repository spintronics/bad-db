#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * The database should define an interface which can be used to store and retrieve data
 * 
 * We will need to make use of the filesystem to persist the data
 **/

enum OperationResultStatus
{
    success,
    failure
};

struct OperationResult
{
    OperationResultStatus status;
    string value;
};

class Database
{
public:
    Database()
    {
        writing = false;
    }
    // return the number of entries
    int size()
    {
        return 0;
    }
    // remove all entries
    void purge()
    {
    }
    // get entry
    OperationResult get(string key)
    {
        OperationResult result;
        return result;
    }
    // set entry
    OperationResult set(string key, string value)
    {
        OperationResult result;
        return result;
    }

    // destructor
    ~Database() {}

    // Database(bool start_immediately) : running{start_immediately} {}
    // void evaluate(string *command)
    // {
    //     if (command == nullptr)
    //     {
    //         return;
    //     }
    //     if (*command == "get")
    //     {
    //         cout << "get command\n";
    //     }

    //     if (*command == "set")
    //     {
    //         cout << "set command\n";
    //     }
    // };

private:
    // a write operation is taking place
    bool writing;
};