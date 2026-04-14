#include <gtest/gtest.h>
import splits_URL;

TEST(split_URL, geldig)
{
    gesplitste_URL res {splits_URL("https://github.com/HR-ELEKTRO/ems3/wiki/Home")};
    EXPECT_EQ(res.geldig, true);
    EXPECT_EQ(res.protocol, "https");
    EXPECT_EQ(res.domein, "github.com");
    EXPECT_EQ(res.directory, "HR-ELEKTRO/ems3/wiki");
    EXPECT_EQ(res.file, "Home");
    res = splits_URL("http://www.stroustrup.com/index.html");
    EXPECT_EQ(res.geldig, true);
    EXPECT_EQ(res.protocol, "http");
    EXPECT_EQ(res.domein, "www.stroustrup.com");
    EXPECT_EQ(res.directory, "");
    EXPECT_EQ(res.file, "index.html");
    res = splits_URL("https://github.com/HR-ELEKTRO/ems3/tree/master/");
    EXPECT_EQ(res.geldig, true);
    EXPECT_EQ(res.protocol, "https");
    EXPECT_EQ(res.domein, "github.com");
    EXPECT_EQ(res.directory, "HR-ELEKTRO/ems3/tree/master");
    EXPECT_EQ(res.file, "");
    res = splits_URL("https://www.koninklijkhuis.nl/");
    EXPECT_EQ(res.geldig, true);
    EXPECT_EQ(res.protocol, "https");
    EXPECT_EQ(res.domein, "www.koninklijkhuis.nl");
    EXPECT_EQ(res.directory, "");
    EXPECT_EQ(res.file, "");
    res = splits_URL("ftp://sftp.xs4all.nl/WWW/harry.html");
    EXPECT_EQ(res.geldig, true);
    EXPECT_EQ(res.protocol, "ftp");
    EXPECT_EQ(res.domein, "sftp.xs4all.nl");
    EXPECT_EQ(res.directory, "WWW");
    EXPECT_EQ(res.file, "harry.html");
}

TEST(split_URL, ongeldig)
{
    gesplitste_URL res {splits_URL("https:/github.com/HR-ELEKTRO/ems3/wiki/Home")};
    EXPECT_EQ(res.geldig, false);
    res = splits_URL("J.Z.M.Broeders@hr.nl");
    EXPECT_EQ(res.geldig, false);
}
