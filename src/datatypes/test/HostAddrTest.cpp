/* Copyright (c) 2018 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#include "base/Base.h"
#include <gtest/gtest.h>
#include "datatypes/HostAddr.h"

namespace nebula {

TEST(HostAddr, HashTest) {
    HostAddr addr1(1234567, 0xFFEEDDCC);
    HostAddr addr2(1234567, 0xFFEEDDCC);
    EXPECT_EQ(std::hash<HostAddr>()(addr1), std::hash<HostAddr>()(addr2));

    HostAddr addr3(1234567, 0x00000001);
    HostAddr addr4(1234567, 0x00000002);
    EXPECT_NE(std::hash<HostAddr>()(addr3), std::hash<HostAddr>()(addr4));

    HostAddr addr5(1234567, 0x00000001);
    HostAddr addr6(1234567, 0x00000001);
    EXPECT_EQ(std::hash<HostAddr>()(addr5), std::hash<HostAddr>()(addr6));

    HostAddr addr7(1234567, 0x10000000);
    HostAddr addr8(1234567, 0x20000000);
    EXPECT_NE(std::hash<HostAddr>()(addr7), std::hash<HostAddr>()(addr8));

    HostAddr addr9(1234567, 0x10000000);
    HostAddr addr10(1234567, 0x10000000);
    EXPECT_EQ(std::hash<HostAddr>()(addr9), std::hash<HostAddr>()(addr10));
}

}  // namespace nebula


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    folly::init(&argc, &argv, true);
    google::SetStderrLogging(google::INFO);

    return RUN_ALL_TESTS();
}