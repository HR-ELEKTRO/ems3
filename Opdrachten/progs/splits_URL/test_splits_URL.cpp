#include <gtest/gtest.h>
#include "splits_URL.h"

TEST(split_URL, geldig)
{
    gesplitste_URL res {splits_URL("https://bitbucket.org/HR_ELEKTRO/ems31/wiki/Home.md")};
    EXPECT_EQ(res.geldig, true);
    EXPECT_EQ(res.protocol, "https");
    EXPECT_EQ(res.domein, "bitbucket.org");
    EXPECT_EQ(res.directory, "HR_ELEKTRO/ems31/wiki");
    EXPECT_EQ(res.file, "Home.md");
    res = splits_URL("http://www.stroustrup.com/index.html");
    EXPECT_EQ(res.geldig, true);
    EXPECT_EQ(res.protocol, "http");
    EXPECT_EQ(res.domein, "www.stroustrup.com");
    EXPECT_EQ(res.directory, "");
    EXPECT_EQ(res.file, "index.html");
    res = splits_URL("https://bitbucket.org/HR_ELEKTRO/ems31/src/master/");
    EXPECT_EQ(res.geldig, true);
    EXPECT_EQ(res.protocol, "https");
    EXPECT_EQ(res.domein, "bitbucket.org");
    EXPECT_EQ(res.directory, "HR_ELEKTRO/ems31/src/master");
    EXPECT_EQ(res.file, "");
    res = splits_URL("https://www.hr.nl");
    EXPECT_EQ(res.geldig, true);
    EXPECT_EQ(res.protocol, "https");
    EXPECT_EQ(res.domein, "www.hr.nl");
    EXPECT_EQ(res.directory, "");
    EXPECT_EQ(res.file, "");
}

TEST(split_URL, ongeldig)
{
    gesplitste_URL res {splits_URL("https:/bitbucket.org/HR_ELEKTRO/ems31/wiki/Home.md")};
    EXPECT_EQ(res.geldig, false);
    res = splits_URL("J.Z.M.Broeders@hr.nl");
    EXPECT_EQ(res.geldig, false);
}
