#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/stat.h>
#include <numeric>
#include "database.h"
#include "file.h"

namespace database
{
    using namespace std;

    /**
     * The database should define an interface which can be used to store and retrieve data
     * 
     * We will need to make use of the filesystem to persist the data
     **/

    Database::Database() {}
    // return the number of entries
    int Database::size()
    {
        return 0;
    }
    // remove all entries
    void Database::purge()
    {
    }
    // get entry
    OperationResult Database::get(string key)
    {
        OperationResult result;
        return result;
    }
    // set entry
    WriteOperation Database::set(string key, string value)
    {
        WriteOperation operation;
        if (!file_utils::file_exists("disk"))
        {
            ofstream file("disk");
            file.close();
        }

        fstream disk;

        disk.open("disk", ios::in | ios::out);

        try
        {
            string line;
            disk.seekg(0);
            while (disk)
            {
                getline(disk, line);
                auto pair = file_utils::split(line, "=");
                if (pair.size() < 2)
                {
                    //should delete invalid lines
                    continue;
                }
                if (pair[0] == key)
                {
                    operation.result = success;
                    pair[1] = value;
                    string new_value = file_utils::join(pair);
                    disk.write(new_value.c_str(), new_value.length());
                }
            }
            if (operation.result != success)
            {
                // value doesn't exist yet, clear the eof flag and write it
                disk.clear();
                string new_value = (key + "=" + value + "\n");
                disk.write(new_value.c_str(), new_value.length());
                operation.result = success;
            }

            disk.close();
        }
        catch (int e)
        {
            operation.result = failure;
        }

        return operation;
    }
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