#include <string>
#include "splits_emailadres.h"

using namespace std;

gesplitst_emailadres splits_emailadres(string emailadres) {
    string::size_type index_aapje {emailadres.find("@")};
    gesplitst_emailadres resultaat;
    if (index_aapje != string::npos) {
        resultaat.geldig = true;
        resultaat.gebruiker = emailadres.substr(0, index_aapje);
        resultaat.domein = emailadres.substr(index_aapje + 1);
    }
    else {
        resultaat.geldig = false;
    }
    return resultaat;
}