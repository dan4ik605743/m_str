#include <boost/test/unit_test.hpp>
#include <exception>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(substr_test)

BOOST_AUTO_TEST_CASE(substr_test) {
    // short_str
    m_str::m_str str("test");

    try {
        str.substr(1, 5);
    } catch (const std::exception& ex) {
        BOOST_TEST(true);
    }
    auto tmp = str.substr(2);
    auto tmp_ = str.substr(2, 1);
    BOOST_TEST(tmp == "te");
    BOOST_TEST(tmp_ == "es");

    // long_str
    str.write("testtesttesttest");

    try {
        str.substr(1, 50);
    } catch (const std::exception& ex) {
        BOOST_TEST(true);
    }

    auto _tmp = str.substr(1);
    auto __tmp = str.substr(2, 1);
    BOOST_TEST(_tmp == "t");
    BOOST_TEST(__tmp == "es");
}

BOOST_AUTO_TEST_SUITE_END()
