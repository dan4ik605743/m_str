#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(reserve_test)

BOOST_AUTO_TEST_CASE(reserve_test) {
    m_str::m_str str;

    // 1
    str.reserve(1);
    BOOST_TEST(str.capacity() == 15);

    // 16
    str.reserve(16);
    BOOST_TEST(str.capacity() == 15);

    // 17
    str.reserve(17);
    BOOST_TEST(str.capacity() == 16);
}

BOOST_AUTO_TEST_SUITE_END()
