# Simple Logfile Writer

## Goals
This project has the goal to implement a simple logging mechanism where it is possible to adjust the amount of 
information on runtime.

## Features
* Set 9 individual and configurable log levels
* Print message to cli and/or to an logfile
* Change the location and name of the logfile
* Logfile and cli logging can have individual log levels 
* Cli highlighting (can be disabled) 
* Define up to 32 point of interest(filters messages) 


***

## Example output 

	0:11  	:      Debug  : magicFunction	 : got param : abc and 42
    0:11  	:      info   : heavyCalculation	 : start heavy calc
    0:11  	:      Debug  : heavyCalculation	 : calculation does need 2777us
    0:14  	:    Message  : heavyCalculation	 : calculation done
    0:14  	:    Message  : magicFunction	 : magically result : abc42
    0:14  	:CriticError  : magicFunction	 : not allowed parameter : -1
    				 from :	 /xxx/SimpleLogging/example/example1.cpp:33
        
## How to use
For further  information's see the example.
### Log something
Write a log message is very simple:

    Log::log(message,importance);
or

    Log::log(message,importance,point_of_interest);
        
If the configured log level is lower than the importance of this message the the message gets printed to the cli and to 
the logfile (if enabled).

E.g

    Log::log("something awful happen :( ",Error);
would result:

    0:21  	:  Error      : something awful happen :(

  
### setLogLevel
With this function you can change the amount of information witch gets printed to the cli or tho the logfile.

This functions is overloaded with:

    setLogLevel(LogLevel cli, LogLevel file) 
    setLogLevel(LogLevel cliAndFile)

This first function sets the logLevel for the logfile and the cli logging individual.
The second function set both log levels equals.

alternative you can use setLogLevel() with int values

    setLogLevel(3,-1); // cli = Message file = none

or with Strings

     setLogLevel("Error")

By default writing to an logfile is disabled until the logfile level != None



### Log Levels
Possible log level with decreasing priority

    None                // int value <-1>   Print absolute Noting
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

You can  enable it by set its priority higher than None.

#### Change the logfile location
you can change the location or the name of the logfile by 

    setLogFileName(new loc/name)
If an logfile is already used the old file gets closed with a hint to the new location.
A new logfile gets opened with the next to its written log message.
### Cli Highlighting 
Because of fun the is a cli highlighting. 
If this cause a issue you can disable it by 

    setCliHighLight(bool)

### Point of interest
The point of interest is a runtime filter function which discard log messages where the current point is not given.
Each point shall have its own flag-bit. By setting all flag-bits which you like to have in you logfile you can adjust the filter.

e.g.
    you are searching a bug in in an IO-drive then you are not interested in log messages from on complete other module.
    If each logical module has its own flag you can adjust the filter to all modules you like the see in the logfile.

Of course a log message can have several point of interest.

    #define interest1 1<<3
    #define Interest2 1<<4
    #define Interest3 1<<5

    Log::setPointOfInterest(interest1 | Interest2); // just messages with the point_of_interest 1 or 2
    Log::log("not printed",Message,Interest3);
    Log::log("printed",Message,Interest3 | interest1);
    Log::log("printed",Message, interest1);
    Log::log("always printed",Message, 0); // or -1

 To enable all point_of_interest you can set the point to -1 or 0.

 A Log Message with the point_of_interest = 0 gets printed no matter what the current configured point_of_interest is.
    
### Default configuration
The default configuration is : 

    log cli level = Error;
    log File level = None;
    cli highlight = true;
    log File Name = "log.log";
    point_of_interest = 0; // no point
    
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
    include_directories(${SOURCE_DIR}/include) # include simpleLog/include
    LINK_DIRECTORIES(${BINARY_DIR}) ## link git build lib
    add_subdirectory(${SOURCE_DIR})
	...
    target_link_libraries(youTarget SimpleLoggingLib)
    ADD_DEPENDENCIES(youTarget simpleLogging)
