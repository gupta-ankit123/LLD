#include <iostream>
using namespace std;

class Database
{
public:
    virtual void save(string data) = 0;
};

class MySQLDatabase : public Database
{
public:
    void save(string data) override
    {
        cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
    }
};

class MongoDB : public Database
{
public:
    void save(string data) override
    {
        cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
    }
};

class UserService
{
private:
    Database *db; // Dependency Injection

public:
    UserService(Database *database)
    {
        db = database;
    }
    void storeUser(string user)
    {
        db->save(user);
    }
};

int main()
{
    MySQLDatabase sqlDB;
    MongoDB mdb;

    UserService service1(&sqlDB);
    service1.storeUser("Ankit");

    UserService service2(&mdb);
    service2.storeUser("Gupta");

    return 0;
}