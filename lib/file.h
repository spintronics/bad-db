#ifndef FILE_H
#define FILE_H
#include <string>
#include <vector>

namespace file_utils
{
    bool file_exists(std::string path);
    std::vector<std::string> split(std::string &s, std::string delimiter);
    std::string join(std::vector<std::string> words, std::string delimiter = "");
    void create(std::string filename);
}
#endif