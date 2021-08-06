#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/stat.h>

using namespace std;

/**
 * The database should define an interface which can be used to store and retrieve data
 * 
 * We will need to make use of the filesystem to persist the data
 **/

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

inline bool
file_exists(string path)
{
    struct stat buf;
    return (stat(path.c_str(), &buf) == 0);
};

inline vector<string> split(string &s, string delimiter)
{
    vector<string> result = vector<string>{};
    size_t offset = 0;
    while (true)
    {
        if (offset + delimiter.length() > s.length())
        {
            break;
        }

        size_t pos = s.find(delimiter, offset);

        if (pos == string::npos)
        {
            break;
        }

        string piece = s.substr(offset, pos);
        result.push_back(piece);
        offset += pos + delimiter.length();
    }
    return result;
}

class Database
{
public:
    Database() {}
    // bool connect(string name, ios_base::openmode mode)
    // {
    //     if (!file_exists(name))
    //     {
    //         ofstream file(name);
    //         file.close();
    //     }
    //     fstream disk;
    //     disk.open(name, mode = ios::in);
    //     // disk_ostream.open(name, ios::out);
    //     // disk_istream.open(name, ios::in);

    //     this.disk = &disk;

    //     if (!disk.good())
    //     {
    //         return false;
    //     };

    //     return true;
    // }
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
    WriteOperation set(string key, string value)
    {
        WriteOperation operation;
        if (!file_exists("disk"))
        {
            ofstream file("disk");
            file.close();
        }

        fstream disk;

        disk.open("disk", ios::in);

        disk.seekg(0);
        string line;
        while (disk)
        {
            getline(disk, line);
            auto pair = split(line, "=");
            if (pair.size() < 2)
            {
                continue;
            }
            if (pair[0] == key)
            {
                operation.result = OperationResult::success;
            }
        }
        if (!operation.result != OperationResult::success)
        {
            operation.result = OperationResult::failure;
        }
        return operation;
    }

    // destructor
    // ~Database()
    // {
    //     if (connected)
    //     {
    //         disk_istream.close();
    //         disk_ostream.close();
    //     };
    // }

private:
    // a write operation is taking place
    bool writing = false;
    bool connected = false;
    // ifstream disk_istream;
    // ofstream disk_ostream;
};