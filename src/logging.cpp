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
static string logfile = "log.log";
static system_clock::time_point startTime;
static mutex locker;
static advacedConfiguration config =  advacedConfiguration();


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



void Log::log_(string src, string message, LogLevel l) {
    locker.lock();

    src = config.handleSrc(src);

    string log = getTimeStamp() + logLevelToString(l)  + src   + message;


    // write to cli
    if (l <= level){
        string tmp = highlight(l) + log;
        if(highlight){
            tmp += DISABLE_CLI_HIGHLIGHT;
        }
        cout <<  tmp <<"\n";
    }

    locker.unlock();
}

void Log::log_(string message, LogLevel l){
    log_("",message,l);
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

string Log::highlight(LogLevel l) {
    if(config.isHighlight()) {
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




void Log::setLogLevel(int cli, int file) {
    setLogLevel(IntToLogLevel(cli),IntToLogLevel(file));
}

LogLevel Log::IntToLogLevel(int i) {
    switch (i){
        case    -1  : return None;
        case    0   : return UserInfo;
        case    1   : return CriticError;
        case    2   : return Error;
        case    3   : return Message;
        case    4   : return Info;
        case    5   : return Debug;
        case    6   : return DebugL2;
        case    7   : return DebugL3;
        default:
            cerr << "Log :: change Loglevel from int with un undefined value: allowed values ar <-1...7>  set logLevel to Debug"<< endl;
            return Debug;
    }
}

void Log::setLogLevel(int cliAndFile) {
    setLogLevel(IntToLogLevel(cliAndFile));

}



advacedConfiguration * Log::advacedConf() {
    return &config;
}


