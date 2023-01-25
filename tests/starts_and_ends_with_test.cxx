#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(starts_and_ends_with_test)

BOOST_AUTO_TEST_CASE(starts_and_ends_with_test) {
    m_str::m_str str("testexec");

    // starts_with
    BOOST_TEST(str.starts_with("test"));

    // ends_with
    BOOST_TEST(str.ends_with("exec"));
}

BOOST_AUTO_TEST_SUITE_END()
