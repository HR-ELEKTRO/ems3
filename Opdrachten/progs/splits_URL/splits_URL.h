#ifndef _HR_BroJZ_Split_URL_
#define _HR_BroJZ_Split_URL_

#include <string>

struct gesplitste_URL
{
    std::string protocol;
    std::string domein;
    std::string directory;
    std::string file;
    bool geldig;
};

gesplitste_URL splits_URL(std::string URL);

#endif
