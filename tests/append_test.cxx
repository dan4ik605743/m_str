#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(append_test)

BOOST_AUTO_TEST_CASE(append_test) {
    // null str
    m_str::m_str str;
    m_str::m_str str_;

    str.append(str_);
    BOOST_TEST(str.empty());
    BOOST_TEST(str.size() == 0);
    BOOST_TEST(str.capacity() == 15);

    str.append("");
    BOOST_TEST(str.empty());
    BOOST_TEST(str.size() == 0);
    BOOST_TEST(str.capacity() == 15);

    // short_str
    str_.write("test");

    str.append(str_);
    BOOST_TEST(str.compare(str_.data()));
    BOOST_TEST(str.size() == str_.size());
    BOOST_TEST(str.capacity() == str_.capacity());

    str.write("test");
    str.append(str_);
    BOOST_TEST(str.compare("testtest"));
    BOOST_TEST(str_.size() + str.size() == 12);
    BOOST_TEST(str.capacity() == str_.capacity());

    // long_str
    str_.write("testtestesteststesst");

    str.clear();
    str.append(str_);
    BOOST_TEST(str.compare(str_.data()));
    BOOST_TEST(str.size() == str_.size());
    BOOST_TEST(str.capacity() == str_.capacity());

    str.write("test");
    str.append(str_);
    BOOST_TEST(str.compare("testtesttestesteststesst"));
    BOOST_TEST(str_.size() + str.size() == 44);
    BOOST_TEST(str.capacity() == str_.capacity());

    str.write("testtestesteststesst");
    str.append(str_);
    BOOST_TEST(str.compare("testtestesteststessttesttestesteststesst"));
    BOOST_TEST(str_.size() + str.size() == 60);
    BOOST_TEST(str.capacity() == 63);
}

BOOST_AUTO_TEST_SUITE_END()
