#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(replace_test)

BOOST_AUTO_TEST_CASE(replace_test) {
    m_str::m_str str("The quick brown fox jumps over the lazy dog.");

    // this_substr_size > arg_str.size
    str.replace(10, 5, "red");
    BOOST_TEST(str.compare("The quick red fox jumps over the lazy dog."));

    // this_substr_size < arg_str.size
    str.replace(10, 3, "brown");
    BOOST_TEST(str.compare("The quick brown fox jumps over the lazy dog."));

    // this_substr_size == arg_str.size
    str.replace(10, 5, "Brown");
    BOOST_TEST(str.compare("The quick Brown fox jumps over the lazy dog."));
}

BOOST_AUTO_TEST_SUITE_END()