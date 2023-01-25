#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(containts_test)

BOOST_AUTO_TEST_CASE(containts_test) {
    m_str::m_str str("hello world");

    // 1
    BOOST_TEST(str.containts("hello"));

    // 2
    BOOST_TEST(!str.containts("goodbye"));

    // 3
    BOOST_TEST(str.containts("w"));

    // 4
    BOOST_TEST(!str.containts("x"));
}

BOOST_AUTO_TEST_SUITE_END()
