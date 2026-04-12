import std;
import splits_emailadres;
using namespace std;

int main() {
    print("Geef je e-mailadres: ");
    string emailadres;
    cin >> emailadres;
    gesplitst_emailadres res {splits_emailadres(emailadres)};
    if (res.geldig) {
        println("Gebruiker: {}", res.gebruiker);
        println("Domein:    {}", res.domein);
    }
    else {
        println("{} is geen geldig e-mailadres!", emailadres);
    }
}