#include <gtest/gtest.h>
#include <lib/lib.hpp>

// Test Certdsa fixture
class LibTest : public ::testing::Test {
protected:
  const std::string expected = "test";

  void SetUp() override {}
};

TEST_F(LibTest, test_cert_dsa_512b) {
  // Arrange
  const std::string actual = lib::test();

  // Act
  const bool result = (actual == expected);

  // Expect
  EXPECT_TRUE(result);
}
