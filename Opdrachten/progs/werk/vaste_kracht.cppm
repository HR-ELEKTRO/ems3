export module vaste_kracht;
import werknemer;

export class Vaste_kracht: public Werknemer {
public:
    Vaste_kracht(int n, double s);
    double geef_salaris() const override;
private:
    double maandsalaris;
};
