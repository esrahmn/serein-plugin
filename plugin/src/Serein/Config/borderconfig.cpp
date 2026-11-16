#include "borderconfig.hpp"

#include <algorithm>

namespace serein::config {

int BorderConfig::minThickness() {
    return 2;
}

int BorderConfig::clampedThickness() const {
    return std::max(minThickness(), m_thickness);
}

} // namespace serein::config
