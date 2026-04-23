export module manager;
import werknemer;
import std;
using namespace std;

export class Manager: public Werknemer {
public:
//  Definieer hier de benodigde memberfuncties
private:
    vector<const Werknemer*> ondergeschikten;
};
