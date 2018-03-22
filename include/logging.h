/*
 * Logging.h
 *
 *  Created on: Sep 4, 2017
 *      Author: Sebastian Balz
 */

#ifndef LOGGING_H_
#define LOGGING_H_

#include <iostream>
#include <string>
#include <typeinfo>
#include "advacedConfiguration.h"

using namespace std;

/**
 * Compiler magic.
 */
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
/**
 * Logging.
 * if something happen in the program call this makro and communicate it.
 * By The log level you can define how important you message is
 * if an src is not defined the src is set to the function name.
 * The src of the message gets logged if "setPintLogSrc(true)".
 * You can set the max length of the messageSrc with "setPintLogSrc(true,<maxLength>)" or set it to unlimited with "setPintLogSrc(true,0)"
 */
#define log(...) GET_MACRO(__VA_ARGS__,logWithSrc , logWithoutSrc)(__VA_ARGS__)
#define logWithoutSrc(mes,lev) Log::log_(__FUNCTION__,mes,lev);
#define logWithSrc(src,mes,lev) Log::log_(src,mes,lev);
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


static const char *const DISABLE_CLI_HIGHLIGHT = "\033[0;0m";

class Log {

    /**
     * return a string which contains the name of log level
     */
    static string logLevelToString(LogLevel l);
    /**
     * set the cli highlight coresponding to the  loglevel
     * @param l  loglevel to determ cli collore
     * @return cli command to highlight the following text
     */
    static string highlight(LogLevel l);
    static LogLevel IntToLogLevel(int i);
    static string handleSrc(string src);
public:


    /**
     * logging.
     * if something happen in the program call this method and communicate it.
     * By The log level you can define how important you message is
     * @param message message content
     * @param importance of the message
     */

    static void log_(string message, LogLevel l);

    /**
     * logging.
     * if something happen in the program call this method and communicate it.
     * By The log level you can define how important you message is
     * @param src src of the log message
     * @param message message content
     * @param importance of the message
     */

    static void log_(string src ,string message, LogLevel l);

    /**
     * set the current level.
     * if a message is equal important or more important(lower number) than this message gets printed to the cli
     * @para cli  log level for cli
     * @param file log level for logging to file
     * @return set success
     */
    static void setLogLevel(LogLevel cli, LogLevel file);
    static void setLogLevel(int cli, int file);

    /**
     * set the current level.
     * if a message is equal important or more important(lower number) than this message gets printed to the cli
     * @para cli  log level for cli AND file
     */
    static void setLogLevel(LogLevel cliAndFile);
    static void setLogLevel(int cliAndFile);


    /**
     * change the logfile name.
     * if a logfile already is in use close the logfile with a corresponding hind and open a new.
     * @param fileName name and location of the new logfile
     */
    static void setLogFileName(string fileName);


    /**
     * allows the set some additional  configurations
     * @return
     */
    static advacedConfiguration  *advacedConf();




};


#endif /* LOGGING_H_ */
