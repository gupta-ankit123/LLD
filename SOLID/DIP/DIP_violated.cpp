#include <iostream>
using namespace std;

class MySQLDatabase
{
public:
    void savetoSQL(string data)
    {
        cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
    }
};

class MongoDatabase
{
public:
    void savetoMongo(string data)
    {
        cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
    }
};

// Here the high level module is tightly coupled with the save functions let say in future we want to create a new save functionality
// for another DB then we have to make changes directly in the UserService class which will violate the open close principle.
// In order to avoid that we can create an interface between the high level module and low level module.
class UserService
{
private:
    MySQLDatabase sqlDB;
    MongoDatabase mongoDB;

public:
    void saveUsertoSQL(string user)
    {
        sqlDB.savetoSQL(user);
    }

    void saveUsertoMongo(string user)
    {
        mongoDB.savetoMongo(user);
    }
};

int main()
{
    UserService service;
    service.saveUsertoMongo("Ankit");
    service.saveUsertoSQL("Gupta");
}