//
// Created by basti on 16.03.2018.
//

#ifndef SIMPLELOGGING_LOGCONFIGURATION_H
#define SIMPLELOGGING_LOGCONFIGURATION_H


#include <string>
using namespace std;
class advacedConfiguration{



    int maxSrcLength;
    int filteredLength;
    bool highlight_;
    bool disableShift;

public:
    advacedConfiguration(){
        maxSrcLength = 0;
        printLogSrc = false;
        filteredLength = 0;
        highlight_ = true;
        disableShift = false;
    }

    string handleSrc(string src);
    /**
     * Enable or disable the src function of of log message
     * you can define a maximum length of the of the function. If the message src is longer than
     * defined is cut short(and marked with <string of src with length maxLength>..)
     * if the length shall not be cut short set length to 0
     * @param enable enable to print the src
     * @param maxLength to disable the short cutting set to 0
     */
    void pintLogSrc(bool enable = true, unsigned int maxLength = 0);

    void disbaleLogSrcShift(bool disable = false);

    /**
     * enable cli highlighting.
     * @param enable
     */
    void setCliHighLight(bool enable);

    bool printLogSrc ;

    bool isPrintLogSrc() const;

    int getMaxSrcLength() const;

    int getFilteredLength() const;

    bool isHighlight() const;

    bool isDisableShift() const;
};


#endif //SIMPLELOGGING_LOGCONFIGURATION_H

