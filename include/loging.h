/*
 * Logging.h
 *
 *  Created on: Sep 4, 2017
 *      Author: sbalz
 */

#ifndef LOGGING_H_
#define LOGGING_H_

#include <iostream>
#include <string>
using namespace std;

/**
 * Log level.
 */
enum LogLevel {
    None = -1, 	        // Noting  just for tests
    UserInfo = 0,	    // Information for Users
    CriticError = 1,
    Error = 2,
    Message = 3,
    Info = 4,
    Debug = 5,
    DebugL2 = 6,
    DebugL3 = 7
};

class Log {

    /**
     * return a string which contains the name of log level
     */
    static string logLevelToString(LogLevel l);
    static string highLight(LogLevel l);
public:

    /**
     * logging.
     * if something happen in the program call this method and communicate it.
     * By The log level you can define how important you message is
     * @param message message content
     * @param importance of the message
     */

    static void log(string message, LogLevel l);

    /**
     * set the current level.
     * if a message is equal important or more important(lower number) than this message gets printed to the cli
     * @para cli  log level for cli
     * @param file log level for logging to file
     */
    static void setLogLevel(LogLevel cli, LogLevel file);

    /**
     * set the current level.
     * if a message is equal important or more important(lower number) than this message gets printed to the cli
     * @para cli  log level for cli AND file
     */
    static void setLogLevel(LogLevel cliAndFile);


    /**
     * change the logfile name.
     * if a logfile already is in use close the logfile with a corresponding hind and open a new.
     * @param fileName name and location of the new logfile
     */
    static void setLogFileName(string fileName);

    static void setCliHighLight(bool enable);


};

#endif /* LOGGING_H_ */
