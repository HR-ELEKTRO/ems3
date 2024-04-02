#ifndef _HR_BroJZ_splits_Emailadres_
#define _HR_BroJZ_splits_Emailadres_

#include <string>

struct gesplitst_emailadres
{
    std::string gebruiker;
    std::string domein;
    bool geldig;
};

gesplitst_emailadres splits_emailadres(std::string emailadres);

#endif

