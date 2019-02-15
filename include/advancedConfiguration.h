//
// Created by Sebastian Balz on 16.03.2018.
//




#ifndef ADVANCEDCONFIG_H
#define ADVANCEDCONFIG_H


#include <string>


using namespace std;

/**
 * Some advanced configurations for the Logger
 */
class advancedConfiguration {


protected:
    int maxSrcLength;
    int filteredLength;
    bool highlight_;
    bool disableShift;
    bool printLogSrc;


public:
    advancedConfiguration() {
        maxSrcLength = 0;
        printLogSrc = false;
        filteredLength = 0;
        highlight_ = true;
        disableShift = true;
    }


    /**
     * Enable or disable the src function of of log message
     * you can define a maximum length of the of the function. If the message src is longer than
     * defined is cut short(and marked with <string of src with length maxLength>..)
     * if the length shall not be cut short set length to 0
     * @param enable enable to print the src
     * @param maxLength to disable the short cutting set to 0
     */
    void pintLogSrc(bool enable = true, unsigned int maxLength = 0);

    /**
     * the src-shift allows an smother view of if the source of the message is added to the Log-Message
     *
     * @param disable
     */
    void setSrcShift(bool disable = true);

    /**
     * enable cli highlighting.
     * @param enable
     */
    void setCliHighLight(bool enable);


};

/**
 * This class is only seen by the Logging class.
 *
 */
class loggerPrivateConfig : public advancedConfiguration {

public:
    string handleSrc(string src);

    bool isPrintLogSrc() const;

    int getMaxSrcLength() const;

    int getFilteredLength() const;

    bool isHighlight() const;

    bool isDisableShift() const;
};

#endif //ADVANCEDCONFIG_H

