#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(length_test)

BOOST_AUTO_TEST_CASE(length_test) {
    m_str::m_str str;

    // null_str
    BOOST_TEST(str.length() == str.size());

    // short_str
    str.write("test");
    BOOST_TEST(str.length() == str.size());

    // long_str
    str.write("testtestesteststesst");
    BOOST_TEST(str.length() == str.size());
}

BOOST_AUTO_TEST_SUITE_END()
