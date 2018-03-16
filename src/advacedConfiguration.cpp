//
// Created by basti on 16.03.2018.
//


#include <advacedConfiguration.h>




void advacedConfiguration::pintLogSrc(bool enable, unsigned int maxLength) {
    maxSrcLength = maxLength;
    printLogSrc = enable;
    filteredLength = 0;

}

void advacedConfiguration::disbaleLogSrcShift(bool disable) {
    disableShift = disable;
    filteredLength = 0;
}
void advacedConfiguration::setCliHighLight(bool enable) {
    highlight_ = enable;

}

bool advacedConfiguration::isPrintLogSrc() const {
    return printLogSrc;
}

int advacedConfiguration::getMaxSrcLength() const {
    return maxSrcLength;
}

int advacedConfiguration::getFilteredLength() const {
    return filteredLength;
}

bool advacedConfiguration::isHighlight() const {
    return highlight_;
}

bool advacedConfiguration::isDisableShift() const {
    return disableShift;
}

string advacedConfiguration::handleSrc(string src) {
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