export module werknemer;

export class Werknemer {
public:
    Werknemer(int n);
    virtual ~Werknemer() = default;
    int geef_nummer() const;
    virtual double geef_salaris() const = 0;
private:
    int nummer;
};
