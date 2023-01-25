#include <boost/test/unit_test.hpp>
#include <string_view>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(insert_test)

BOOST_AUTO_TEST_CASE(insert_test) {
    m_str::m_str str("xmplr");

    // 1
    str.insert(0, 1, 'E');
    BOOST_TEST(str.compare("Exmplr"));

    // 2
    str.insert(2, 'e');
    BOOST_TEST(str.compare("Exemplr"));

    // 3
    str.insert(6, 'a');
    BOOST_TEST(str.compare("Exemplar"));

    // 4
    str.insert(8, " is an example string.", 0, 14);
    BOOST_TEST(str.compare("Exemplar is an example"));

    // 5
    str.insert(str.find_first_of("n") + 1, ":");
    BOOST_TEST(str.compare("Exemplar is an: example"));

    // 6
    str.insert(str.find_first_of(":") + 1, 2, '=');
    BOOST_TEST(str.compare("Exemplar is an:== example"));

    // 7
    std::string_view seq = " string";
    str.insert(str.find_last_of("e") + 1, seq);
    BOOST_TEST(str.compare("Exemplar is an:== example string"));
}

BOOST_AUTO_TEST_SUITE_END()
