module identifier_extractor;
import std;
using namespace std;

Identifier_extractor::Identifier_extractor(string filename) {
    ifstream inf {filename};
    if (inf) {
        noskipws(inf);
        istream_iterator<char> istream_begin{inf}, istream_end{};
        copy(istream_begin, istream_end, back_inserter(all_chars));
        begin = all_chars.begin();
        end = all_chars.end();
        while (begin != end) {
            switch (*begin) {
                case '/':  
                    skip_line_comment(); 
                    skip_block_comment();
                    break;
                case '\'':
                case '\"':
                    skip_char_string_literal();
                    break;
                case 'L':
                case 'U':
                    if (begin+1 != end && (*(begin+1) == '\'' || *(begin+1) == '\"')) {
                        skip();
                        skip_char_string_literal();
                    }
                    else if (begin+1 != end && *(begin+1) == 'R' && begin+2 != end && *(begin+2) == '\"') {
                        skip();
                        skip_raw_string_literal();
                    }
                    break;
                case 'u':
                    if (begin+1 != end && (*(begin+1) == '\'' || *(begin+1) == '\"')) {
                        skip();
                        skip_char_string_literal();
                    }
                    else if (begin+1 != end && *(begin+1) == 'R' && begin+2 != end && *(begin+2) == '\"') {
                        skip();
                        skip_raw_string_literal();
                    }
                    else if (begin+1 != end && *(begin+1) == '8' && begin+2 != end && (*(begin+2) == '\'' || *(begin+2) == '\"')) {
                        skip(2);
                        skip_char_string_literal();
                    }
                    else if (begin+1 != end && *(begin+1) == '8' && begin+2 != end && *(begin+2) == 'R' && begin+3 != end && *(begin+3) == '\"') {
                        skip(2);
                        skip_raw_string_literal();
                    }
                    break;
                case 'R':
                    skip_raw_string_literal();
                    break;
            }
            if (isdigit(*begin)) {
                skip_numeric_literal();
            }
            if (isalpha(*begin) || *begin == '_') {
                add_identifier();
            }
            else {
                skip();
            }                
        }
    }
    else {
        cerr << "Error: kan bestand " << filename << " niet openen.\n";
    }
}

void Identifier_extractor::skip(int number_of_chars_to_skip) {
    for (int i {0}; i < number_of_chars_to_skip; ++i) {
        if (begin != end) ++begin;
    }
}

vector<string> Identifier_extractor::get_identifiers() const {
    return identifiers;
}

void Identifier_extractor::skip_line_comment() {
    if (begin+1 != end && *(begin + 1) == '/') {
        while (begin+1 != end && *(begin+1) != '\n') {
            ++begin;
        }
    }
}

void Identifier_extractor::skip_block_comment() {
    if (begin+1 != end && *(begin + 1) == '*') {
        begin+=2;
        while ((begin != end && *begin != '*') || (begin+1 != end && *(begin+1) != '/')) {
            ++begin;
        }
        begin+=2;
    }
}

void Identifier_extractor::skip_char_string_literal() {
    char stop {*begin};
    ++begin;
    while (begin != end && *begin != stop)
    {
        if (*begin == '\\' && begin+1 != end && (*(begin+1) == stop || *(begin+1) == '\\')) {   
            ++begin;
        }
        ++begin;
    }
    skip();
    if (begin != end && stop == '\"' && *begin == 's') {
        ++begin;
    }
}

void Identifier_extractor::skip_raw_string_literal() {
    if (begin+1 != end && *(begin + 1) == '\"') {
        begin+=2;
        string delimiter;
        while (begin != end && *begin != '(') {
            delimiter+=*begin++;
        }
        delimiter+='\"';
        skip();
        bool delimiter_found {false};
        while (!delimiter_found) {
            while (begin != end && *begin != ')') {
                ++begin;
            }
            skip();
            // check delimiter;
            delimiter_found = true;
            for (char c: delimiter) {
                if (begin == end || *begin != c) {
                    delimiter_found = false;
                    break;
                }
                ++begin;
            }
        }
        if (begin != end && *begin == 's') {
            ++begin;
        }
    }
}

void Identifier_extractor::skip_numeric_literal() {
    // assume only valid C++ input
    // '_' is needed for user defined literals
    while (begin != end && (isalnum(*begin) || *begin == '_')) {
        ++begin;
    }
}

void Identifier_extractor::add_identifier() {
    string id;
    while (begin != end && (isalnum(*begin) || *begin == '_')) {
        id+=*begin++;
    }
    identifiers.push_back(id);
}
