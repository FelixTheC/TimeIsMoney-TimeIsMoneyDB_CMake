#ifndef TASKDB_HPP
#define TASKDB_HPP

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSharedPointer>


class TaskDB
{
public:
    TaskDB();
    explicit TaskDB(const std::string &db_name);
    ~TaskDB() = default;
    
    QSharedPointer<QSqlDatabase> getDBPtr();
    
    void create_table_invoice();
    void create_table_tasks();
    void create_table_external_api();

private:
    std::string database_name {};
    QSharedPointer<QSqlDatabase> db;
    QSharedPointer<QSqlDatabase> connect_db();
    void init_db();
};

#endif // TASKDB_HPP
