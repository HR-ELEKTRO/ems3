export module splits_URL;
import std;
using namespace std;

export struct gesplitste_URL
{
    string protocol;
    string domein;
    string directory;
    string file;
    bool geldig;
};

export gesplitste_URL splits_URL(string URL);
