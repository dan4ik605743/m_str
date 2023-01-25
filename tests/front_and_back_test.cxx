#include <boost/test/unit_test.hpp>
#include <exception>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(front_and_back_test)

BOOST_AUTO_TEST_CASE(front_and_back_test) {
    m_str::m_str str;

    // null_str
    try {
        str.front();
    } catch (const std::exception& ex) {
        BOOST_TEST(true);
    }

    try {
        str.back();
    } catch (const std::exception& ex) {
        BOOST_TEST(true);
    }

    // short_str
    str.write("tests");
    BOOST_TEST(str.front() == 't');
    BOOST_TEST(str.back() == 's');

    // long_str
    str.write("testtestesteststessts");
    BOOST_TEST(str.front() == 't');
    BOOST_TEST(str.back() == 's');
}

BOOST_AUTO_TEST_SUITE_END()
