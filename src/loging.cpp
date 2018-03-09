#include "loging.h"
#include <fstream>
#include <mutex>

static LogLevel level = Error;
static LogLevel logFilelevel = None; // creat no log file if not requested
static fstream *logWriter;
static bool loggerisOpen = false;

#include <chrono>

static bool firstTimeStamp = true;
static string *lastLog = new string("");
using namespace std::chrono;

string logfile = "log.log";

system_clock::time_point startTime;
mutex locker;
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
        s += " "; // Append blanks for a better apperance
    s += "\t";
    return s;

}
void openLogWriter(fstream **writer) {
    *writer = new fstream();
    (*writer)->open(logfile, ofstream::trunc | ofstream::out);
    if (level != None) {
        cout << "write logfile to ";
        system("pwd");
        cout << "log.log" << endl;
    }
    loggerisOpen = true;
}

void Log::log(string message, LogLevel l){
    locker.lock();
        string log =  getTimeStamp() + logLeveltoString(l) + message;
        if (l <= level)
            cout << log << endl;

        if (l <= logFilelevel)
        {
            if (!loggerisOpen)
                openLogWriter(&logWriter);
            *logWriter <<   log << endl;
            logWriter->flush();
        }

    locker.unlock();
}


void Log::setLogLevel(LogLevel cli, LogLevel file)
{
    level = cli;
    logFilelevel = file;
}

void Log::setLogLevel(LogLevel cliAndFile)
{
    setLogLevel(cliAndFile, cliAndFile);
}


void Log::setLogFileName(string fileName){
    locker.lock();
    if(loggerisOpen) {
        loggerisOpen = false;
        *logWriter << "change Logfile to " << fileName << endl;
        logWriter->close();
    }
    logfile = fileName;
    locker.unlock();
}
string Log::logLeveltoString(LogLevel l)
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
        default	: return "unkown Level";
    }

}

