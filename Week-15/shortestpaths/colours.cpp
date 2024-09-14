#include <stdexcept>
#include "colours.h"

std::string data::to_string(data::colour c) {
    switch (c) {
        case colour::black:
            return "black";
        case colour::white:
            return "white";
        case colour::red:
            return "red";
        case colour::blue:
            return "blue";
        case colour::green:
            return "green";
        case colour::darksalmon:
            return "darksalmon";
        case colour::gold:
            return "gold";
        case colour::limegreen:
            return "limegreen";
        case colour::turquoise:
            return "turquoise";
        case colour::violet:
            return "violet";
        case colour::yellow:
            return "yellow";
        default:
            throw std::invalid_argument("Invalid colour");
    }
}
