import std;
import splits_URL;
using namespace std;

int main() {
    print("Geef een URL: ");
    string URL;
    cin >> URL;
    gesplitste_URL res {splits_URL(URL)};
    if (res.geldig) {
        println("Protocol: {}", res.protocol);
        println("Domein:   {}", res.domein);
        println("Directory: {}", res.directory);
        println("File:   {}", res.file);
    }
    else {
        println("{} is geen geldige URL!", URL);
    }
}