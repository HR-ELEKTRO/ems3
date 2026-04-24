export module identifier_extractor;
import std;
using namespace std;

export class Identifier_extractor {
public:
    explicit Identifier_extractor(string filename);
    vector<string> get_identifiers() const;
private:
    vector<string> identifiers;
    vector<char> all_chars;
    vector<char>::iterator begin;
    vector<char>::iterator end;
    void skip(int number_of_chars_to_skip = 1);
    void skip_line_comment();
    void skip_block_comment();
    void skip_char_string_literal();
    void skip_raw_string_literal();
    void skip_numeric_literal();
    void add_identifier();
};
