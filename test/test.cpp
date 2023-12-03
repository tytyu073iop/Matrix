#include <gtest/gtest.h>
#include "01.12.2023/Matrix.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>


TEST(Matrix, Basic) { //NOLINT: don't care
    matrix ca(2, 2);
    matrix cb(2, 2);
    std::stringstream sa("2 2 2 2");
    std::stringstream sb("3 3 3 3");
    sa >> ca;
    ASSERT_TRUE(sa.good() || sa.eof()) << sa.rdstate() << " " << sa.eof();
    sb >> cb;
    ASSERT_TRUE(sb.good() || sb.eof()) << sb.rdstate();
    const matrix a(ca);
    const matrix b(cb);
    std::stringstream s;
    s << (a + b);
    EXPECT_EQ(s.str(), "5 5 \n5 5 \n");
    s.str("");
    s << (a - b);
    EXPECT_EQ(s.str(), "-1 -1 \n-1 -1 \n");
    s.str("");
    s << (a * b);
    EXPECT_EQ(s.str(), "12 12 \n12 12 \n");
    s.str("");
    const double c = 2;
    s << (c * a);
    EXPECT_EQ(s.str(), "4 4 \n4 4 \n");
    s.str("");
    s << (a * c);
    EXPECT_EQ(s.str(), "4 4 \n4 4 \n");
    s.str("");
    s << (a / c);
    EXPECT_EQ(s.str(), "1 1 \n1 1 \n");
    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(cb == b);
    matrix t(5, 3);
    t = b;
    EXPECT_TRUE(t == b);
    t -= a;
    s.str("");
    s << t;
    EXPECT_EQ(s.str(), "1 1 \n1 1 \n");
    s.str("");
    t += b;
    s << t;
    EXPECT_EQ(s.str(), "4 4 \n4 4 \n");
    s.str("");
    t *= c;
    s << t;
    EXPECT_EQ(s.str(), "8 8 \n8 8 \n");
    s.str("");
    t /= c;
    s << t;
    EXPECT_EQ(s.str(), "4 4 \n4 4 \n");
    const matrix nc(5, 4);
    EXPECT_THROW(a + nc, matrix::Errors);
    EXPECT_THROW(a - nc, matrix::Errors);
    EXPECT_THROW(a * nc, matrix::Errors);
    EXPECT_THROW(t += nc, matrix::Errors);
    EXPECT_THROW(t -= nc, matrix::Errors);
}

TEST(Matrix, ComplexMulti) {
    matrix ca(3, 2);
    matrix cb(2, 3);
    std::stringstream sa("2 2 2 1 1 1");
    std::stringstream sb("3 1 3 1 3 1");
    sa >> ca;
    ASSERT_TRUE(sa.eof()) << sa.rdstate() << " " << sa.eof();
    sb >> cb;
    ASSERT_TRUE(sb.eof()) << sb.rdstate();
    const matrix a(ca);
    const matrix b(cb);
    std::stringstream s;
    s << a;
    ASSERT_EQ(s.str(), "2 2 2 \n1 1 1 \n");
    s.str("");
    s << b;
    ASSERT_EQ(s.str(), "3 1 \n3 1 \n3 1 \n");
    s.str("");
    s << (a * b);
    EXPECT_EQ(s.str(), "18 6 \n9 3 \n");
   
}

TEST(Matrix, ExceptEqual) {
    matrix a(2, 2);
    std::stringstream as("2 2 2 2");
    as >> a;
    ASSERT_TRUE(as.eof()) << as.rdstate() << " " << as.eof();
    std::stringstream s;
    s.str("");
    s << a;
    ASSERT_EQ(s.str(), "2 2 \n2 2 \n") << "bad input";
    a = a; //NOLINT: Should be
    s.str("");
    s << a;
    EXPECT_EQ(s.str(), "2 2 \n2 2 \n");
}
