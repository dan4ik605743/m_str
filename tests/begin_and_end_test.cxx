#include <boost/test/unit_test.hpp>
#include <cstring>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(begin_and_end_test)

BOOST_AUTO_TEST_CASE(begin_and_end_test) {
    m_str::m_str str;

    // null_str
    BOOST_TEST(str.empty());
    BOOST_TEST(str.begin() == str.end());

    // short_str
    str.write("test");
    BOOST_TEST(!str.empty());
    BOOST_TEST(str.begin() == str.data());

    // long_str
    str.write("testtestesteststesst");
    BOOST_TEST(!str.empty());
    BOOST_TEST(str.begin() == str.data());
}

BOOST_AUTO_TEST_SUITE_END()
