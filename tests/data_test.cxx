#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(data_test)

BOOST_AUTO_TEST_CASE(data_test) {
    m_str::m_str str;

    // null_str
    BOOST_TEST(str.data() == str.end());

    // short_str
    str.write("test");
    BOOST_TEST(str.data() == str.begin());

    // long_str
    str.write("testtestesteststesst");
    BOOST_TEST(str.data() == str.begin());
}

BOOST_AUTO_TEST_SUITE_END()
