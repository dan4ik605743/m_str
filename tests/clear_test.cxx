#include <boost/test/unit_test.hpp>
#include <cstring>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(clear_test)

BOOST_AUTO_TEST_CASE(clear_test) {
    m_str::m_str str;

    // null_str
    str.clear();
    BOOST_TEST(str.empty());

    // short_str
    str.write("test");
    BOOST_TEST(str.size() == 4);
    str.clear();
    BOOST_TEST(str.size() == 0);
    BOOST_TEST(str.empty());

    // long_str
    str.write("testtesttesttest");
    BOOST_TEST(str.size() == 16);
    str.clear();
    BOOST_TEST(str.size() == 0);
    BOOST_TEST(str.empty());
}

BOOST_AUTO_TEST_SUITE_END()
