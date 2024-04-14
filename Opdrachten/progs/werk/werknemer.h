#ifndef _HR_BroJZ_Werknemer_
#define _HR_BroJZ_Werknemer_

class Werknemer {
public:
    Werknemer(int n);
    virtual ~Werknemer() = default;
    int geef_nummer() const;
    virtual double geef_salaris() const = 0;
private:
    int nummer;
};

#endif
