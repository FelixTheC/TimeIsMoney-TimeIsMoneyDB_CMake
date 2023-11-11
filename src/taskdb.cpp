#include <iostream>
#include "../include/taskdb.hpp"
#include "../include/tasks_table.hpp"
#include "../include/invoice_table.hpp"
#include "../include/externalapi_table.hpp"
#include "../include/serial_table.hpp"


TaskDB::TaskDB()
{
    database_name = "taskdata";
    init_db();
}

TaskDB::TaskDB(const std::string &db_name)
{
    database_name = db_name;
    init_db();
}

void TaskDB::init_db()
{
    auto task_db = connect_db();
    
    if (!task_db->open())
    {
        qWarning("Connection error: No connection to DB.");
    }
    else
    {
        QSqlQuery query;
        
        query.exec(CREATE_TASK_TABLE);
        for (const auto &val: TASK_INDEX)
        {
            query.exec(val);
        }
        
        query.exec(CREATE_INVOICE_TABLE);
        for (const auto &val: INVOICE_INDEX)
        {
            query.exec(val);
        }
        
        query.exec(CREATE_EXTERNAL_API_TABLE);
        query.exec(CREATE_EXTERNAL_API_TOKEN);
        query.exec(CREATE_EXTERNAL_API_DATA);
        query.exec(CREATE_SERIAL_SETUP_TABLE);
        
        for (const auto &val: EXTERNAL_API_INDEX)
        {
            query.exec(val);
        }
    }
    
    task_db->close();
}

QSharedPointer<QSqlDatabase>
TaskDB::getDBPtr()
{
    if (db)
    {
        return db;
    }
    else
    {
        auto db_ = QSqlDatabase::addDatabase("QSQLITE");
        db_.setDatabaseName(QString::fromStdString(database_name + ".db3"));
        return QSharedPointer<QSqlDatabase>(new QSqlDatabase(db_));
    }
}

QSharedPointer<QSqlDatabase> TaskDB::connect_db()
{
    if (db)
    {
        db->close();
        db->open();
        return db;
    }
    else
    {
        auto sqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
        sqlDatabase.setDatabaseName(QString::fromStdString(database_name + ".db3"));
        db = QSharedPointer<QSqlDatabase>(new QSqlDatabase(sqlDatabase));
        
        if (!db->open())
        {
            qWarning("Connection error: No connection to DB.");
            
            return nullptr;
        }
        
        return db;
    }
}

void TaskDB::create_table_invoice()
{
    auto sql_db = connect_db();
    
    QSqlQuery query {};
    
    query.exec(CREATE_INVOICE_TABLE);
    for (const auto &val: INVOICE_INDEX)
    {
        query.exec(val);
    }
}

void TaskDB::create_table_tasks()
{
    auto sql_db = connect_db();
    QSqlQuery query {};
    
    query.exec(CREATE_TASK_TABLE);
    for (const auto &val: TASK_INDEX)
    {
        query.exec(val);
    }
}

void TaskDB::create_table_external_api()
{
    auto sql_db = connect_db();
    QSqlQuery query {};
    
    query.exec(CREATE_EXTERNAL_API_TABLE);
    query.exec(CREATE_EXTERNAL_API_TOKEN);
    query.exec(CREATE_EXTERNAL_API_DATA);
    
    for (const auto &val: EXTERNAL_API_INDEX)
    {
        query.exec(val);
    }
}
