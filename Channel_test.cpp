/*
 * 
 */

#define BOOST_TEST_MODULE Channel test
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <shapes/Channel.hpp>
#include <utils/Vector.hpp>

BOOST_AUTO_TEST_CASE(dist_function) {
    Shapes::Channel channel;
    channel.set_dimensions(2.0, 2.0); // width == depth == 2.0

    Utils::Vector3d pos;
    Utils::Vector3d vec;
    double dist;

    // inside the channel
    pos = {0.0, 0.0, 0.5};
    channel.calculate_dist(pos, dist, vec);
    BOOST_CHECK_SMALL(dist, 1e-12);
    BOOST_CHECK_SMALL(vec.norm(), 1e-12);

    // outside the channel
    pos = {0.0, 0.0, 3.0};
    channel.calculate_dist(pos, dist, vec);
    BOOST_CHECK_CLOSE(dist, 0.5, 1e-12);
    BOOST_CHECK_CLOSE(vec.norm(), 0.5, 1e-12);

    pos = {0.0, 2.5, 0.5};
    channel.calculate_dist(pos, dist, vec);
    BOOST_CHECK_CLOSE(dist, 0.5, 1e-12);
    BOOST_CHECK_CLOSE(vec.norm(), 0.5, 1e-12);

    pos = {0.0, 2.5, 3.0};
    channel.calculate_dist(pos, dist, vec);
    BOOST_CHECK_CLOSE(dist, std::sqrt(0.5 * 0.5 + 0.5 * 0.5), 1e-12);
    BOOST_CHECK_CLOSE(vec.norm(), std::sqrt(0.5 * 0.5 + 0.5 * 0.5), 1e-12);
}

BOOST_AUTO_TEST_CASE(set_get_dimensions) {
    Shapes::Channel channel;

    BOOST_CHECK_CLOSE(channel.width(), 1.0, 1e-12);
    BOOST_CHECK_CLOSE(channel.depth(), 1.0, 1e-12);

    channel.set_dimensions(3.0, 4.0);
    BOOST_CHECK_CLOSE(channel.width(), 3.0, 1e-12);
    BOOST_CHECK_CLOSE(channel.depth(), 4.0, 1e-12);
}
