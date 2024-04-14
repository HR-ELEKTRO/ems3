#ifndef _HR_BroJZ_Manager_
#define _HR_BroJZ_Manager_

#include <vector>
#include "werknemer.h"

class Manager: public Werknemer {
public:
//  Definieer hier de benodigde memberfuncties
private:
    std::vector<const Werknemer*> ondergeschikten;
};

#endif
