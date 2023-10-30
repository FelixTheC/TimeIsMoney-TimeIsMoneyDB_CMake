//
// Created by felix on 28.10.23.
//

#ifndef TIMEISMONEY_CMAKE_INVOICE_TABLE_HPP
#define TIMEISMONEY_CMAKE_INVOICE_TABLE_HPP

#include <QString>

const QString CREATE_INVOICE_TABLE = "create table invoice_settings\
            (\
                id integer not null\
                    constraint invoice_settings_pk\
                        primary key autoincrement,\
                tax double,\
                user_currency varchar(10),\
                client_currency varchar(10),\
                exchange_rate double,\
                header text,\
                footer text\
                   );";

const QString INVOICE_INDEX[] = {"create unique index invoice_settings_id_uindex on invoice_settings (id);"};

#endif //TIMEISMONEY_CMAKE_INVOICE_TABLE_HPP
