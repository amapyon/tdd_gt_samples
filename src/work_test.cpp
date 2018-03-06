/*
 * work_test.cpp
 */
#include <string>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

TEST(BoolTest, BoolTest) {
	bool val = -1;
	ASSERT_TRUE(true == val);
	EXPECT_TRUE(true != val) << "表明が成り立たないがメッセージを出力して継続";
	ASSERT_FALSE(false == val);
}

TEST(EqualTest, EqualTest) {
	signed char val = 129;
	ASSERT_EQ(-127, val);
	int remain = 10 % 3;
	ASSERT_EQ(1, remain) << "10を3で割った余りは1";
	ASSERT_EQ("-127", to_string(val)) << "数値を文字列に変換";
}

TEST(FloadTest, FloatTest) {
	ASSERT_FLOAT_EQ(0, 1e-45);
	ASSERT_DOUBLE_EQ(0, 1e-323);
	ASSERT_NEAR(10, 11, 1);
	ASSERT_NEAR(0.01, 0.015, 0.01);
}

TEST(ExceiptonTest, ExceptionTest) {
	ASSERT_NO_THROW({
		string s(0, 'a');
	}) << "例外が発生しない";

	ASSERT_ANY_THROW({
		string s(-1, 'a');
	}) << "何かしらの例外が発生する";

	ASSERT_THROW({
		string s(-1, 'a');
	}, length_error) << "length_error例外が発生する";
}
