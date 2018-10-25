//
// Created by Sebastian Balz on 16.03.2018.
//


#include <advancedConfiguration.h>




void advancedConfiguration::pintLogSrc(bool enable, unsigned int maxLength) {
    maxSrcLength = maxLength;
    printLogSrc = enable;
    filteredLength = 0;

}

void advancedConfiguration::setSrcShift(bool enable) {
    disableShift = !enable;
    filteredLength = 0;
}
void advancedConfiguration::setCliHighLight(bool enable) {
    highlight_ = enable;

}

bool loggerPrivateConfig::isPrintLogSrc() const {
    return printLogSrc;
}

int loggerPrivateConfig::getMaxSrcLength() const {
    return maxSrcLength;
}

int loggerPrivateConfig::getFilteredLength() const {
    return filteredLength;
}

bool loggerPrivateConfig::isHighlight() const {
    return highlight_;
}

bool loggerPrivateConfig::isDisableShift() const {
    return disableShift;
}

string loggerPrivateConfig::handleSrc(string src) {
    bool addSrc = !src.empty();
    if(addSrc && printLogSrc){
        src +="\t";

        if(maxSrcLength == 0 || src.length() < maxSrcLength) {
            if(!disableShift) {
                if (src.length() < filteredLength)
                    filteredLength -= filteredLength/3;
                else
                    filteredLength = src.length();
                while (src.length() < filteredLength)
                    src += " ";
            }
        }
        else{
            src = src.substr(0,maxSrcLength);
            src += "..";
        }
        if(addSrc)
            src += " : ";
    } else
        src = "";

    return src;
}