#include <boost/test/unit_test.hpp>
#include <exception>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(copy_test)

BOOST_AUTO_TEST_CASE(copy_test) {
    // short_str
    m_str::m_str str("test");

    try {
        char buff[5];
        str.copy(buff, 3, 5);
    } catch (const std::exception& ex) {
        BOOST_TEST(true);
    }

    BOOST_TEST(str[0] == 't');

    // long_str
    str.write("testtestesteststesst");
    BOOST_TEST(str[0] = 't');

    try {
        str.at(50);
    } catch (const std::exception& ex) {
        BOOST_TEST(true);
    }
}

BOOST_AUTO_TEST_SUITE_END()
