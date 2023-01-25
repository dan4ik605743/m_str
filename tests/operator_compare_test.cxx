#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(operator_compare_test)

BOOST_AUTO_TEST_CASE(operator_compare_test) {
    m_str::m_str str;
    m_str::m_str str_;

    // null_str
    BOOST_TEST(!(str < str_));
    BOOST_TEST(!(str > str_));
    BOOST_TEST(str >= str_);
    BOOST_TEST(str <= str_);
    BOOST_TEST(str == str_);
    BOOST_TEST(!(str != str_));

    // short_str
    str.write("test");
    str_.write("test");
    BOOST_TEST(!(str < str_));
    BOOST_TEST(!(str > str_));
    BOOST_TEST(str >= str_);
    BOOST_TEST(str <= str_);
    BOOST_TEST(str == str_);
    BOOST_TEST(!(str != str_));

    // long_str
    str_.write("testtesttesttest");
    BOOST_TEST(str < str_);
    BOOST_TEST(!(str > str_));
    BOOST_TEST(!(str >= str_));
    BOOST_TEST(str <= str_);
    BOOST_TEST(!(str == str_));
    BOOST_TEST(str != str_);
}

BOOST_AUTO_TEST_SUITE_END()
