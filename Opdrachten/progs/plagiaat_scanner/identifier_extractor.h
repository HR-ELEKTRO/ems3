#include <vector>
#include <string>

class Identifier_extractor {
public:
    explicit Identifier_extractor(std::string filename);
    std::vector<std::string> get_identifiers() const;
private:
    std::vector<std::string> identifiers;
    std::vector<char> all_chars;
    std::vector<char>::iterator begin;
    std::vector<char>::iterator end;
    void skip(int number_of_chars_to_skip = 1);
    void skip_line_comment();
    void skip_block_comment();
    void skip_char_string_literal();
    void skip_raw_string_literal();
    void skip_numeric_literal();
    void add_identifier();
};
