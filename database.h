#include <string>
#include <vector>

using namespace std;

enum OperationResult
{
    success,
    failure
};

struct ReadOperation
{
    OperationResult result;
    string value;
};

struct WriteOperation
{
    OperationResult result;
};

bool file_exists(string path);
inline vector<string> split(string &s, string delimiter);

class Database
{
public:
    Database(){};
    int size();
    void purge();
    OperationResult get(string key);
    WriteOperation set(string key, string value);

private:
    bool writing;
    bool connected;
};
