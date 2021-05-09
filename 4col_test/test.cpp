#include "gtest/gtest.h"
#include "../src/parser.hpp"

class DFTest : public ::testing::Test {
protected:
	void SetUp() override {
		dft.from_csv("sample.csv");
	}
	DataFrame dft;
	DataFrame df_nofile;
};

TEST(InputTest, FileFound) {
	std::fstream fs;
	fs.open("sample.csv", std::ios::in);
	ASSERT_TRUE(fs.is_open());
}

TEST_F(DFTest, OpenFileError) {
	EXPECT_NO_THROW(df_nofile.from_csv("somefilethatdoesntexist.csv"));
}

TEST_F(DFTest, FinalColumn) {
	EXPECT_EQ(dft.table[509]->email, "88");
}

TEST_F(DFTest, NaNTest) {
	for (size_t i = 500; i < 509; i++) {
		EXPECT_EQ(dft.table[i]->number, "NaN");
		EXPECT_EQ(dft.table[i]->category, "NaN");
		EXPECT_EQ(dft.table[i]->name, "NaN");
		EXPECT_EQ(dft.table[i]->email, "NaN");
	}
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
