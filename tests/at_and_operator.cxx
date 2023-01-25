#include <boost/test/unit_test.hpp>
#include <cstring>
#include <exception>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(at_and_operator_test)

BOOST_AUTO_TEST_CASE(at_and_operator_test) {
    // short_str
    m_str::m_str str("test");

    try {
        str.at(5);
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
