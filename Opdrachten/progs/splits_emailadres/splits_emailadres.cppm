export module splits_emailadres;
import std;

export struct gesplitst_emailadres
{
    std::string gebruiker;
    std::string domein;
    bool geldig;
};

export gesplitst_emailadres splits_emailadres(std::string emailadres);
