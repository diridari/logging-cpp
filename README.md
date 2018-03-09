# Simple Logfile writer

## Goals
This project has the goal to implement a simple logging mechanism where it is possible to change the amount of 
information on runtime.

## Futures
* Set 9 individual and configurable log levels
* print message the the cli and/or to an logfile
* change the location and name of the logfile
* logfile and cli logging can have individual log levels 
* cli highlighting (can be disabled) 


***

## How to use
for future informations see the example.
### Log something
write a log message is very simple:

    Log::log(message,importance);
        
If the configured log level is lower than the importance of this message the the message gets printed to the cli and to 
the logfile (if enabled).

E.g

    Log::log("somthing awful happen :( ",Error);
would result:

    0:21  	:  Error      : somthing awful happen :( 
  
### setLogLevel
with this function you can change the amount of information witch gets printed to the cli or tho the logfile.

This functions is overloaded with:

    setLogLevel(LogLevel cli, LogLevel file) 
    setLogLevel(LogLevel cliAndFile)
This first function sets the logLevel for the logfile and the cli logging individual.
The second function set both log levels equals.

By default writing to an logfile is disabled until the log level != None

### Log Levels
Possible log level with decreasing priority

    None                // Print absolut Noting
    UserInfo            // Information for Users
    CriticError         // bet
    Error 
    Message
    Info
    Debug 
    DebugL2 
    DebugL3
     
### Log File
It is possible to write each Log information to an logfile. 
You can change to log level of the logfile and the log level of the cli individually.

The log file is by default disabled. 

You can  enable it by set its prio higher than None.

####Change the logfile location
you can change the location or the name of the logfile by 

    setLogFileName(new loc/name)
If an logfile is already used the old file gets closed with a hint to the new location.

A new logfile gets opened with the next to its written log message.
### Cli Highlighting 
Because of fun the is a cli highlighting. 
If cause a issue you can disable it by 

    setCliHighLight(bool)
    
### Default configuration
The default configuration is : 

    log cli level = Error;
    log File level = None;
    cli highlight = true;
    log File Name = "log.log";