#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(compare_test)

BOOST_AUTO_TEST_CASE(compare_test) {
    // null_str
    m_str::m_str str;
    BOOST_TEST(str.compare(""));

    // short_str
    str.write("test");
    BOOST_TEST(str.compare(str.data()));

    // m_str& operator=(m_str&& m_str) short_str
    str.write("testtesttesttest");
    BOOST_TEST(str.compare(str.data()));
}

BOOST_AUTO_TEST_SUITE_END()
