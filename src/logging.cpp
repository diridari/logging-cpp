/*
 * Logging.cpp
 *
 *  Created on: Sep 4, 2017
 *      Author: Sebastian Balz
 */

#include "logging.h"
#include <fstream>
#include <mutex>

using namespace std::chrono;

static LogLevel level = Error;
static LogLevel logFileLevel = None; // create no log file if not requested
static fstream *logWriter;
static bool loggerIsOpen = false;

static bool firstTimeStamp = true;
static bool highlight = true;
static string logfile = "log.log";
static system_clock::time_point startTime;
static mutex locker;

static string getTimeStamp()
{
    if (firstTimeStamp)
    {
        firstTimeStamp = false;
        startTime = chrono::high_resolution_clock::now();
    }

    auto current_time = std::chrono::high_resolution_clock::now();
    string s = to_string(std::chrono::duration_cast<std::chrono::seconds>(current_time - startTime).count()) + ":";
    s += to_string(std::chrono::duration_cast<std::chrono::milliseconds>(current_time - startTime).count() % 1000);
    while (s.length() < 6)
        s += " "; // Append blanks for a better appearance
    s += "\t";
    return s;

}
void openLogWriter(fstream **writer) {
    *writer = new fstream();
    (*writer)->open(logfile, ofstream::trunc | ofstream::out);
    if (level != None) {
        cout << "write logfile to " << logfile<< endl;
    }
    loggerIsOpen = true;
}

void Log::log(string message, LogLevel l){
    locker.lock();

    string log = getTimeStamp() + logLevelToString(l) + message;
    // write to cli
    if (l <= level){
        string tmp = highLight(l) + log;
        if(highlight){
            tmp +=  "\033[0;0m";
        }
        cout <<  tmp <<endl; ;
    }
    // write to logfile
    if (l <= logFileLevel)
    {
        if (!loggerIsOpen)
            openLogWriter(&logWriter);
        *logWriter <<   log << endl;
        logWriter->flush();
    }
    locker.unlock();
}


void Log::setLogLevel(LogLevel cli, LogLevel file)
{
    level = cli;
    logFileLevel = file;
}

void Log::setLogLevel(LogLevel cliAndFile)
{
    setLogLevel(cliAndFile, cliAndFile);
}


void Log::setLogFileName(string fileName){
    locker.lock();
    if(loggerIsOpen) {
        loggerIsOpen = false;
        if (level != None) {
            *logWriter << "change Logfile to " << fileName << endl;
        }
        logWriter->close();
    }
    logfile = fileName;
    locker.unlock();
}
string Log::logLevelToString(LogLevel l)
{
    switch (l)
    {
        case CriticError:
            return ":CriticError  : ";
        case Error:
            return ":  Error      : ";
        case Info:
            return ":      info   : ";
        case Message:
            return ":    Message  : ";
        case UserInfo:
            return ":User_info    : ";
        case None:
            return "";
        case Debug:
            return ":      Debug  : ";
        case DebugL2:
            return ":    Debug L2 : ";
        case DebugL3:
            return ":     Debug L3: ";
        default	: return "unknown Level";
    }

}

string Log::highLight(LogLevel l) {
    if(highlight) {
        switch (l) {
            case None:
                return "";
            case UserInfo:
                return "";
            case CriticError:
                return "\033[1;31m";
            case Error:
                return "\033[1;32m";
            case Message:
                return "\033[0;33m";
            case Info:
                return "\033[0;34m";
            case Debug:
                return "\033[0;37m";
            case DebugL2:
                return "\033[0;37m";
            case DebugL3:
                return "\033[2;37m";
        }
    }
    return "";

}

void Log::setCliHighLight(bool enable) {
    highlight = enable;

}

