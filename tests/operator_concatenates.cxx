#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(operator_concatenates_test)

BOOST_AUTO_TEST_CASE(operator_concatenates_test) {
    m_str::m_str str("test");
    m_str::m_str str_("test");

    BOOST_TEST((str + str_) == "testtest");
}

BOOST_AUTO_TEST_SUITE_END()
