#include <boost/test/unit_test.hpp>
#include <cstring>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(capacity_test)

BOOST_AUTO_TEST_CASE(capacity_test) {
    m_str::m_str str;

    // null_str
    BOOST_TEST(str.capacity() == 15);

    // short_str
    str.write("test");
    BOOST_TEST(str.capacity() == 15);

    // long_str
    str.write("testtestesteststesst");
    BOOST_TEST(str.capacity() == 31);
}

BOOST_AUTO_TEST_SUITE_END()
