#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(empty_test)

BOOST_AUTO_TEST_CASE(empty_test) {
    m_str::m_str str;

    // null_str
    BOOST_TEST(str.empty());

    // short_str
    str.write("test");
    BOOST_TEST(!str.empty());

    // long_str
    str.write("testtestesteststesst");
    BOOST_TEST(!str.empty());
}

BOOST_AUTO_TEST_SUITE_END()
