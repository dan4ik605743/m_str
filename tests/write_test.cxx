#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(write_test)

BOOST_AUTO_TEST_CASE(write_test) {
    m_str::m_str str;

    // short_str write(const m_str& m_str)
    m_str::m_str str_;
    m_str::m_str str__;
    str_.write(str__);
    BOOST_TEST(str_.capacity() == 15);
    BOOST_TEST(str_.size() == 0);
    BOOST_TEST(str_.empty());

    // short_str write(const m_str& m_str)
    str__.write("test");
    str_.write(str__);
    BOOST_TEST(str_.capacity() == 15);
    BOOST_TEST(str_.size() == 4);
    BOOST_TEST(str_.compare("test"));

    // long_str write(const m_str& m_str)
    str__.write("testtesttesttest");
    str_.write(str__);
    BOOST_TEST(str_.capacity() == 31);
    BOOST_TEST(str_.size() == 16);
    BOOST_TEST(str_.compare("testtesttesttest"));

    // 1
    str.write("s");
    BOOST_TEST(str.capacity() == 15);
    BOOST_TEST(str.size() == 1);
    BOOST_TEST(str.data() == "s");

    // 15
    str.write("sssssssssssssss");
    BOOST_TEST(str.capacity() == 15);
    BOOST_TEST(str.size() == 15);
    BOOST_TEST(str.compare("sssssssssssssss"));

    // 16
    str.write("ssssssssssssssss");
    BOOST_TEST(str.capacity() == 31);
    BOOST_TEST(str.size() == 16);
    BOOST_TEST(str.compare("ssssssssssssssss"));

    // 17
    str.write("sssssssssssssssss");
    BOOST_TEST(str.capacity() == 31);
    BOOST_TEST(str.size() == 17);
    BOOST_TEST(str.compare("sssssssssssssssss"));

    // 32
    str.write("ssssssssssssssssssssssssssssssss");
    BOOST_TEST(str.capacity() == 63);
    BOOST_TEST(str.size() == 32);
    BOOST_TEST(str.compare("ssssssssssssssssssssssssssssssss"));
}

BOOST_AUTO_TEST_SUITE_END()
