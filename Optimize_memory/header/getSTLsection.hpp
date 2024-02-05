#ifndef GETSTLSECTION_HPP
#define GETSTLSECTION_HPP

#include <string>

enum STLSection {
    FACET_NORMAL = 0,
    OUTER_LOOP,
    ENDLOOP,
    UNKNOWN
};

STLSection getSTLsection(const std::string& );

#endif