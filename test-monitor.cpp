#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(checkVitalStatus(99, 102, 70));
  ASSERT_TRUE(checkVitalStatus(98.1, 70, 98));
}
