#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>

namespace file_utils
{
    using namespace std;

    /**
     *  Create a file if it does not already exist
     *  @param name the name of the file to be created
     * */
    void create(string name)
    {
        ofstream file(name);
        file.close();
    };

    void remove(string name)
    {
        remove(name);
    }

    bool file_exists(string path)
    {
        struct stat buf;
        return (stat(path.c_str(), &buf) == 0);
    };

    vector<string> split(string &s, string delimiter)
    {
        vector<string> result = vector<string>{};
        size_t offset = 0;
        if (delimiter.length() > s.length())
        {
            // you're doing strange things
            result.push_back(s);
            return result;
        }
        while (true)
        {
            if (offset + delimiter.length() > s.length())
            {
                result.push_back(s.substr(offset));
                break;
            }

            size_t pos = s.find(delimiter, offset);

            if (pos == string::npos)
            {
                result.push_back(s.substr(offset));
                break;
            }

            string piece = s.substr(offset, pos);
            result.push_back(piece);
            offset += pos + delimiter.length();
        }
        return result;
    }

    string join(vector<string> words, string delimiter = "")
    {
        string result = "";
        for (string word : words)
        {
            result += word + delimiter;
        }
        return result.substr(0, result.length() - 1);
    }
}
