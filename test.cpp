#include <string>

#include "database.cpp"

using namespace std;

class TestCase
{
public:
    string name;
    bool run()
    {
        return false;
    }
    void setup() {}
    void teardown() {}
};

class DBTestCase : public TestCase
{
public:
    DBTestCase()
    {
        db = Database();
    }
    Database db;

private:
};

class BasicReadWrite : public DBTestCase
{
public:
    BasicReadWrite() : DBTestCase() {}
    string name = "basic read write";
    bool run()
    {
        db.set("key", "value");
        OperationResult result = db.get("key");
        return result.status == OperationResultStatus::success;
    }
};

int main()
{
    vector<TestCase> tests = vector<TestCase>{BasicReadWrite()};
    bool allTestsPassed = true;
    for (auto test : tests)
    {
        if (!test.run())
        {
            allTestsPassed = false;
            cout << test.name + " failed";
        }
    };

    if (allTestsPassed)
    {
        cout << "all tests passed";
    }
}
