//
// Created by felix on 28.10.23.
//

#ifndef TIMEISMONEY_CMAKE_TASKS_TABLE_HPP
#define TIMEISMONEY_CMAKE_TASKS_TABLE_HPP

#include <QString>

const QString CREATE_TASK_TABLE = "create table if not exists tasks"
                                  "("
                                  "id             integer      not null constraint tasks_pk primary key autoincrement,"
                                  "client         varchar(255) not null,"
                                  "task           varchar(255) not null,"
                                  "price_per_hour DOUBLE(5,2),"
                                  "probono        bool,"
                                  "created_at     datetime,"
                                  "closed_at      datetime"
                                  ");";

const QString TASK_INDEX[] = {
        "create index tasks_client_index on tasks (client);",
        "create index tasks_client_task_index on tasks (client, task);",
        "create index tasks_closed_at_index on tasks (closed_at desc);",
        "create index tasks_created_at_index on tasks (created_at);",
        "create unique index tasks_id_uindex on tasks (id);",
        };

#endif //TIMEISMONEY_CMAKE_TASKS_TABLE_HPP
