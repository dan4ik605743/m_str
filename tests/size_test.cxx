#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(size_test)

BOOST_AUTO_TEST_CASE(size_test) {
    m_str::m_str str;

    // null_str
    BOOST_TEST(str.size() == 0);

    // short_str
    str.write("test");
    BOOST_TEST(str.size() == 4);

    // long_str
    str.write("testtesttesttest");
    BOOST_TEST(str.size() == 16);
}

BOOST_AUTO_TEST_SUITE_END()
