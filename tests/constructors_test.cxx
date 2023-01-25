#include <boost/test/unit_test.hpp>

#include "lib.hh"

BOOST_AUTO_TEST_SUITE(constructors_test)

BOOST_AUTO_TEST_CASE(constructors_test) {
    // m_str(m_str&& m_str) null_str
    m_str::m_str str;
    m_str::m_str str_(std::move(str));
    BOOST_TEST(str_.size() == 0);
    BOOST_TEST(str_.empty());
    BOOST_TEST(str_.capacity() = 15);

    // m_str(m_str&& m_str) short_str
    m_str::m_str strm_("test");
    m_str::m_str str___(std::move(strm_));
    BOOST_TEST(str___.size() == 4);
    BOOST_TEST(!str___.empty());
    BOOST_TEST(str___.compare(str___.data()));
    BOOST_TEST(str___.capacity() = 15);

    // m_str(m_str&& m_str) long_str
    m_str::m_str strm__("testtesttesttest");
    m_str::m_str str__(std::move(strm__));
    BOOST_TEST(str__.size() == 16);
    BOOST_TEST(!str__.empty());
    BOOST_TEST(str__.compare(str__.data()));
    BOOST_TEST(str__.capacity() == 31);

    // m_str(const m_str& m_str) null_str
    str.clear();
    m_str::m_str str_copy___(str);
    BOOST_TEST(str.empty());
    BOOST_TEST(str.size() == 0);
    BOOST_TEST(str_copy___.empty());
    BOOST_TEST(str_copy___.size() == 0);
    BOOST_TEST(str_copy___.compare(str_copy___.data()));
    BOOST_TEST(str_copy___.compare(str.data()));

    // m_str(const m_str& m_str) short_str
    str.write("test");
    m_str::m_str str_copy(str);
    BOOST_TEST(!str.empty());
    BOOST_TEST(str.size() == 4);
    BOOST_TEST(str.compare(str.data()));
    BOOST_TEST(!str_copy.empty());
    BOOST_TEST(str_copy.size() == 4);
    BOOST_TEST(str_copy.compare(str_copy.data()));
    BOOST_TEST(str_copy.compare(str.data()));

    // m_str(const m_str& m_str) long_str
    str.write("testtesttesttest");
    m_str::m_str str_copy_(str);
    BOOST_TEST(!str.empty());
    BOOST_TEST(str.size() == 16);
    BOOST_TEST(str.compare(str.data()));
    BOOST_TEST(!str_copy_.empty());
    BOOST_TEST(str_copy_.size() == 16);
    BOOST_TEST(str_copy_.compare(str_copy_.data()));
    BOOST_TEST(str_copy_.compare(str.data()));

    // m_str& opreator=(const m_str& m_str) null_str
    str.clear();
    str_copy_ = str;
    BOOST_TEST(str.empty());
    BOOST_TEST(str.size() == 0);
    BOOST_TEST(str_copy_.empty());
    BOOST_TEST(str_copy_.size() == 0);
    BOOST_TEST(str_copy_.compare(str_copy_.data()));
    BOOST_TEST(str_copy_.compare(str.data()));

    // m_str& opreator=(const m_str& m_str) short_str
    str.write("test");
    str_copy_ = str;
    BOOST_TEST(!str.empty());
    BOOST_TEST(str.size() == 4);
    BOOST_TEST(str.compare(str.data()));
    BOOST_TEST(!str_copy_.empty());
    BOOST_TEST(str_copy_.size() == 4);
    BOOST_TEST(str_copy_.compare(str_copy_.data()));
    BOOST_TEST(str_copy_.compare(str.data()));

    // m_str& opreator=(const m_str& m_str) long_str
    str.write("testtesttesttest");
    str_copy_ = str;
    BOOST_TEST(!str.empty());
    BOOST_TEST(str.size() == 16);
    BOOST_TEST(str.compare(str.data()));
    BOOST_TEST(!str_copy_.empty());
    BOOST_TEST(str_copy_.size() == 16);
    BOOST_TEST(str_copy_.compare(str_copy_.data()));
    BOOST_TEST(str_copy_.compare(str.data()));
}

BOOST_AUTO_TEST_SUITE_END()
