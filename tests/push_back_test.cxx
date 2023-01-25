#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(push_back_test)

BOOST_AUTO_TEST_CASE(push_back_test) {
    m_str::m_str str;

    // short_str
    str.push_back('s');
    BOOST_TEST(str.compare("s"));
    BOOST_TEST(str.size() == 1);
    BOOST_TEST(str.capacity() == 15);

    // long_str
    for (std::size_t i = 0; i != 20; ++i) {
        str.push_back('s');
    }

    BOOST_TEST(str.compare("sssssssssssssssssssss"));
    BOOST_TEST(str.size() == 21);
    BOOST_TEST(str.capacity() == 31);
}

BOOST_AUTO_TEST_SUITE_END()
