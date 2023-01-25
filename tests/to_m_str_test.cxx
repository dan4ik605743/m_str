#include <boost/test/unit_test.hpp>
#include <exception>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(to_m_str_test)

BOOST_AUTO_TEST_CASE(to_m_str_test) {
    // short_str
    auto short_str = m_str::to_m_str(1234);
    BOOST_TEST(short_str.compare("1234"));

    // long_str
    auto long_str = m_str::to_m_str(1234567891011121314);
    BOOST_TEST(long_str.compare("1234567891011121314"));
}

BOOST_AUTO_TEST_SUITE_END()
