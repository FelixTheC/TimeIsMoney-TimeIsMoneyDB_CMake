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
    ~TaskDB();
    QSharedPointer<QSqlDatabase> getDBPtr();

private:
    QSharedPointer<QSqlDatabase> task_db;
};

#endif // TASKDB_HPP
