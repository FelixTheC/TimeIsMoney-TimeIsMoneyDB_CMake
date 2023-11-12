//
// Created by felix on 28.10.23.
//

#ifndef TIMEISMONEY_CMAKE_EXTERNALAPI_TABLE_HPP
#define TIMEISMONEY_CMAKE_EXTERNALAPI_TABLE_HPP

#include <QString>

const QString CREATE_EXTERNAL_API_TABLE = "create table if not exists api_base_url"
                                          "("
                                          "    id integer not null constraint api_base_url_pk primary key autoincrement,"
                                          "    base_url varchar(255) not null"
                                          ");";

const QString CREATE_EXTERNAL_API_TOKEN = "create table if not exists api_token"
                                          "("
                                          "    id integer not null constraint api_token_pk primary key autoincrement,"
                                          "    kind  varchar(20)  not null,"
                                          "    token varchar(255) not null,"
                                          "    base_url_pk integer not null unique,"
                                          "    CONSTRAINT base_url_pk FOREIGN KEY (base_url_pk) REFERENCES api_base_url(id)"
                                          ");";

const QString CREATE_EXTERNAL_API_DATA = "create table if not exists api_data"
                                         "("
                                         "    id integer not null constraint api_data_pk primary key autoincrement,"
                                         "    start_api varchar(255) not null,"
                                         "    stop_api  varchar(255) not null,"
                                         "    content_type  text         not null,"
                                         "    req_data  text         not null,"
                                         "    base_url_pk integer not null unique,"
                                         "    CONSTRAINT base_url_pk FOREIGN KEY (base_url_pk) REFERENCES api_base_url(id)"
                                         ");";

const QString EXTERNAL_API_INDEX[] = {"create unique index api_base_url__uindex on api_base_url (base_url);"};

const QString EXTERNAL_API_MIGRATIONS[] = {
        "alter table api_data add column_name text default 'json' not null on conflict ignore;"
};

#endif //TIMEISMONEY_CMAKE_EXTERNALAPI_TABLE_HPP
