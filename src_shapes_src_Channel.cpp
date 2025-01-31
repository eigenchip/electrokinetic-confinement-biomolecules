/*
 * 
 */

#include <shapes/Channel.hpp>
#include <utils/Vector.hpp>
#include <algorithm>
#include <cmath>

namespace Shapes {

Channel::Channel() : m_width(1.0), m_depth(1.0) {}

void Channel::calculate_dist(const Utils::Vector3d &pos, double &dist, Utils::Vector3d &vec) const {
    // center depth
    Utils::Vector3d rel_pos = pos - Utils::Vector3d(0.0, 0.0, m_depth / 2.0);
    double dist_to_y_wall = std::max(0.0, std::abs(rel_pos.y()) - m_width / 2.0);
    double dist_to_z_wall = std::max(0.0, m_depth / 2.0 - rel_pos.z());
    // min distance from channel
    dist = std::min(dist_to_y_wall, dist_to_z_wall);
    vec = rel_pos;
}

void Channel::set_dimensions(double width, double depth) {
    m_width = width;
    m_depth = depth;
}

double Channel::width() const {
    return m_width;
}

double Channel::depth() const {
    return m_depth;
}

} // namespace Shapes
