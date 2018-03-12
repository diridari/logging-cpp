# Simple Logfile Writer

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

## Example output 

    0:0   	:User_info    : main	 : do somthing with default logLevel
    0:9   	:CriticError  : magicFunction	 : not allowed parameter : -1
    0:9   	:User_info    : main	 : do somthing with Message as logLevel
    0:17  	:    Message  : heavyCalucuation	 : calculation done
    0:17  	:    Message  : magicFunction	 : magically result : abc42
    0:17  	:CriticError  : magicFunction	 : not allowed parameter : -1
    0:17  	:User_info    : main	 : do somthing with Debug as logLevel
    0:17  	:      Debug  : magicFunction	 : got param : abc and 42
    0:17  	:      info   : heavyCalucuation	 : start heavy calc
    0:17  	:      Debug  : heavyCalucuation	 : calculation does need 6262us
    0:23  	:    Message  : heavyCalucuation	 : calculation done
    0:23  	:    Message  : magicFunction	 : magically result : abc42
    0:23  	:CriticError  : magicFunction	 : not allowed parameter : -1
        
## How to use
for future informations see the example.
### Log something
write a log message is very simple:

    Log::log(message,importance);
or

    Log::log(src,message,importance);
        
If the configured log level is lower than the importance of this message the the message gets printed to the cli and to 
the logfile (if enabled).

E.g

    Log::log("something awful happen :( ",Error);
    Log::log("src of message",""something awful happen :( ",Error);
would result:

    0:21  	:  Error      : something awful happen :(
    0:21  	:  Error      : src of message  :  something awful happen :(
  
### setLogLevel
with this function you can change the amount of information witch gets printed to the cli or tho the logfile.

This functions is overloaded with:

    setLogLevel(LogLevel cli, LogLevel file) 
    setLogLevel(LogLevel cliAndFile)
This first function sets the logLevel for the logfile and the cli logging individual.
The second function set both log levels equals.

alternative you can use setLogLevel() with int values

    setLogLevel(3,-1); // cli = Message file = none
By default writing to an logfile is disabled until the log level != None

    
### Log Levels
Possible log level with decreasing priority

    None                // int value <-1>   Print absolut Noting
    UserInfo            // int value <0>    Information for Users
    CriticError         // int value <1>     bet .. 
    Error               // ..
    Message
    Info
    Debug 
    DebugL2 
    DebugL3             //int value <7>    
     
### Log File
It is possible to write each Log information to an logfile. 
You can change to log level of the logfile and the log level of the cli individually.

The log file is by default disabled. 

You can  enable it by set its prio higher than None.

#### Change the logfile location
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
    
 ***
 # Build
 cmake build commands:
 
 	cmake CMakeLists.txt
	make 
	
 # Cmake implementation 
 To include this project to you own project you can use following cmake configuration:
 
    include(ExternalProject)
    externalProject_add(
            simpleLogging
            GIT_REPOSITORY https://github.com/diridari/SimpleLogging.git
            CONFIGURE_COMMAND   cmake CMakeLists.txt
            BUILD_IN_SOURCE ON
            INSTALL_COMMAND make SimpleLoggingLib   # make target
    )
    ExternalProject_Get_Property(simpleLogging SOURCE_DIR)
    ExternalProject_Get_Property(simpleLogging BINARY_DIR)
    include_directories(${SOURCE_DIR}/include) # include simpleLog/inlude
    LINK_DIRECTORIES(${BINARY_DIR}) ## link git build lib
    add_subdirectory(${SOURCE_DIR})
	...
    target_link_libraries(youTarget SimpleLoggingLib)
    ADD_DEPENDENCIES(youTarget simpleLogging)
