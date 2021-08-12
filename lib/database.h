#include <string>
#include <vector>

namespace database
{
    enum OperationResult
    {
        success,
        failure
    };

    struct ReadOperation
    {
        OperationResult result;
        std::string value;
    };

    struct WriteOperation
    {
        OperationResult result;
    };

    class Database
    {
    public:
        Database();
        int size();
        void purge();
        OperationResult get(std::string key);
        WriteOperation set(std::string key, std::string value);

    private:
        bool writing;
        bool connected;
    };
}
