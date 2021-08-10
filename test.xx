#include <string>
#include <iostream>

#include "database.h"

using namespace std;

// class TestCase
// {
// public:
//     string name;
//     bool run()
//     {
//         return false;
//     }
//     void setup() {}
//     void teardown() {}
// };

// class DBTestCase : public TestCase
// {
// public:
//     DBTestCase()
//     {
//         db = Database();
//     }
//     Database db;

// private:
// };

// class BasicReadWrite : public DBTestCase
// {
// public:
//     string name = "basic read write";
//     BasicReadWrite() : DBTestCase() {}
//     bool run()
//     {
//         auto setOp = db.set("key", "value");
//         // auto operation = db.get("key");
//         cout << setOp.result;
//         return setOp.result == OperationResult::success;
//     }
// };

bool basicReadWrite()
{
    auto db = Database{};
    auto setOp = db.set("test", "run");
    return setOp.result == OperationResult::success;
};

int main()
{
    if (basicReadWrite())
    {
        cout << "success";
    }
    else
    {
        cout << "fail";
    }
    // vector tests = vector<TestCase>{};
    // bool allTestsPassed = true;
    // for (auto test : tests)
    // {
    //     cout << test.name + "sdf";
    //     if (!test.run())
    //     {
    //         allTestsPassed = false;
    //         cout << test.name + " failed";
    //     }
    // };

    // if (allTestsPassed)
    // {
    //     cout << "all tests passed";
    // }
}
