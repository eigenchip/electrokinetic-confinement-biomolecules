/*
* HPP FILE
* Rectangle-shape groove along the x-axis representing a nanochannel.
* Width is along the y-axis and depth is along the z-axis.
*/

#ifndef SHAPES_CHANNEL_HPP
#define SHAPES_CHANNEL_HPP

#include "Shape.hpp"
#include <utils/Vector.hpp>

namespace Shapes {
/** Channel class inherits from Shape class */
class Chanel : public Shape {
public:
	/** constructor, member variables, member functions */
		    /** initialize the params */
	Channel() : m_width(1.0), m_depth(1.0), {}


	void calculate_dist(const Utils::Vector3d &pos, double &dist, Utils::Vector3d &vec) const override {
		/** center the depth of the channel */
		Utils::Vector3d rel_pos = pos - Utils::Vector3d(0.0, 0.0, m_depth / 2.0);
		double dist_to_y_wall = std::max(0.0, std::abs(rel_pos.y()) - m_width / 2.0);
		double dist_to_z_wall = std::max(0.0, m_depth / 2.0 - rel_pos.z());
		/** dist is the minimum distance from any of the walls of the channel */
		dist = std::min(dist_to_y_wall, dist_to_z_wall);
		vec = rel_pos;
	}


	/** custom functions */
	void set_dimensions(double width, double depth) {
		m_width = width;
		m_depth = depth;
	}
	

	/** accessor functions */
	double width() const { return m_width; }
	double depth() const { return m_depth; }

	
private:
	/** width and depth can be modified via the set_dimensions method */
	double m_width;
	double m_depth;

};


} /* namespace Shapes */


#endif	/* header guard */









