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
#include "advancedConfiguration.h"

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
#define log(...) GET_MACRO(__VA_ARGS__,logWithitIntresed , logWithoutSrc)(__VA_ARGS__)
#define logWithoutSrc(mes,lev) Log::log_(__FUNCTION__,mes,lev,__FILE__,__LINE__);
#define logWithitIntresed(mes,lev,intr) Log::log_(__FUNCTION__,mes,lev,__FILE__,__LINE__,intr);
/**
 * Log level.
 */
typedef enum LogLevel {
    None = -1, 	        // Noting  just for tests
    UserInfo = 0,	    // Information for Users
    CriticError = 1,
    Error = 2,
    Message = 3,
    Info = 4,
    Debug = 5,
    DebugL2 = 6,
    DebugL3 = 7
}LogLevel;


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

    static LogLevel stringToLogLevel(string toConvert);

    static bool isInPointOfIntressed(unsigned int toCheck);

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

    static void log_(string src ,string message, LogLevel l,string name, int line, int intresed = 0);

    /**
     * set the current level.
     * if a message is equal important or more important(lower number) than this message gets printed to the cli
     * @para cli  log level for cli
     * @param file log level for logging to file
     * @return set success
     */
    static void setLogLevel(LogLevel cli, LogLevel file);
    /**
     * set the current level.
     * if a message is equal important or more important(lower number) than this message gets printed to the cli
     * @para cli  log level for cli
     * @param file log level for logging to file
     * @return set success
     */
    static void setLogLevel(string cli, string file);

    /**
     * set the current level.
     * if a message is equal important or more important(lower number) than this message gets printed to the cli
     * @para cli  log level for cli
     * @param file log level for logging to file
     * @return set success
     */
    static void setLogLevel(int cli, int file);

    /**
     * set the current level.
     * if a message is equal important or more important(lower number) than this message gets printed to the cli
     * @para cli  log level for cli AND file
     */
    static void setLogLevel(LogLevel cliAndFile);

    /**
     * set the current level.
     * if a message is equal important or more important(lower number) than this message gets printed to the cli
     * @para cli  log level for cli AND file
     */
    static void setLogLevel(int cliAndFile);
    /**
     * set the current level.
     * if a message is equal important or more important(lower number) than this message gets printed to the cli
     * @para cli  log level for cli AND file
     */
    static void setLogLevel(string cliAndFile);


    /**
     * change the logfile name.
     * if a logfile already is in use close the logfile with a corresponding hind and open a new.
     * @param fileName name and location of the new logfile
     */
    static void setLogFileName(string fileName);


    /**
     * advanced configuration.
     * allows the set some additional  configurations
     * @return advanced Configuration object
     */
    static advancedConfiguration  *advancedConf();

    /**
     * Filter Logmesages by the point of you interested.
     * Each logmessage where the flag (and the loglevel) match with the configured flag gets printed.
     * Each logmessage where the flag do not match get discared
     * This can be used to reduce the amount of log infmations.
     * print all messages use -1 or 0
     *
     * e.g pointOfInterested = 0b1010
     * log("",Error,0b0); // gets printed because of point = 0
     * log("",Error,0b1); // gets not printed
     * log("",Error,0b10); // gets printed
     *
     * @param points falg to check
     */
    static void setPointOfIntressed(unsigned int points = 0);


    /**
     * print the src line informatione if the level of the message is <= the given value
     * @param l
     */
    static void printSrcLine(LogLevel l);

};


#endif /* LOGGING_H_ */
