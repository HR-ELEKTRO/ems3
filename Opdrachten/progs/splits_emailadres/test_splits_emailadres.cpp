#include <gtest/gtest.h>
#include "splits_emailadres.h"

TEST(splits_emailadres, geldig)
{
    gesplitst_emailadres res {splits_emailadres("j.z.m.broeders@hr.nl")};
    EXPECT_EQ(res.geldig, true);
    EXPECT_EQ(res.gebruiker, "j.z.m.broeders");
    EXPECT_EQ(res.domein, "hr.nl");
    res = splits_emailadres("Willem-Alexander@koninklijkhuis.org");
    EXPECT_EQ(res.geldig, true);
    EXPECT_EQ(res.gebruiker, "Willem-Alexander");
    EXPECT_EQ(res.domein, "koninklijkhuis.org");
}

TEST(splits_emailadres, ongeldig)
{
    gesplitst_emailadres res {splits_emailadres("www.hogeschoolrotterdam.nl")};
    EXPECT_EQ(res.geldig, false);
    res = splits_emailadres("Maxima.koninklijkhuis.org");
    EXPECT_EQ(res.geldig, false);
}
