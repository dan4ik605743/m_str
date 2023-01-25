#include <algorithm>
#include <boost/test/unit_test.hpp>
#include <cstring>
#include <exception>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(erase_test)

BOOST_AUTO_TEST_CASE(erase_test) {
    // short_str
    m_str::m_str str("test");

    try {
        str.erase(5, 1);
    } catch (const std::exception& ex) {
        BOOST_TEST(true);
    }

    str.erase(0, 1);
    BOOST_TEST(str.size() == 3);
    BOOST_TEST(str.at(0) == 'e');
    BOOST_TEST(str.compare("est"));

    str.erase(std::find(str.begin(), str.end(), 'e'));
    BOOST_TEST(str.size() == 2);
    BOOST_TEST(str.at(0) == 's');
    BOOST_TEST(str.compare("st"));

    // long_str
    str.write("testtesttesttest");
    str.erase(0, 1);
    BOOST_TEST(str.size() = 15);
    BOOST_TEST(str.at(0) == 'e');
    BOOST_TEST(str.compare("esttesttesttest"));

    str.erase(std::find(str.begin(), str.end(), 'e'));
    BOOST_TEST(str.size() == 14);
    BOOST_TEST(str.at(0) == 's');
    BOOST_TEST(str.compare("sttesttesttest"));
}

BOOST_AUTO_TEST_SUITE_END()
