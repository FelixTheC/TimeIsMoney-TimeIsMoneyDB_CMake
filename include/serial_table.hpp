//
// Created by felix on 11.11.23.
//

#ifndef TIMEISMONEY_CMAKE_SERIAL_TABLE_HPP
#define TIMEISMONEY_CMAKE_SERIAL_TABLE_HPP

#include <QString>

const QString CREATE_SERIAL_SETUP_TABLE = "create table serial_setup\
                                          (\
                                              pk        integer      not null primary key autoincrement,\
                                              baudrate  integer      not null,\
                                              port_name varchar(255) not null\
                                          );";

#endif //TIMEISMONEY_CMAKE_SERIAL_TABLE_HPP
