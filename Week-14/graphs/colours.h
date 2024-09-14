#ifndef GRAPHS_FULL_COLOURS_H
#define GRAPHS_FULL_COLOURS_H

#include <string>

namespace data {
    enum class colour {
        black,
        white,
        red,
        blue,
        green,
        darksalmon,
        gold,
        limegreen,
        turquoise,
        violet,
        yellow
    };

    std::string to_string(colour c);
}

#endif //GRAPHS_FULL_COLOURS_H
