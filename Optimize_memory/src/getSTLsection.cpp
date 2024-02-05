#include "../header/getSTLsection.hpp"


STLSection getSTLsection(const std::string& line) {
    if (line.find("facet normal") != std::string::npos) {
        return STLSection::FACET_NORMAL;
    } else if (line.find("outer loop") != std::string::npos) {
        return STLSection::OUTER_LOOP;
    } else if (line.find("endloop") != std::string::npos) {
        return STLSection::ENDLOOP;
    } else {
        return STLSection::UNKNOWN;
    }
}