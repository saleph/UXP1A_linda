//
// Created by root on 16/12/17.
//

#ifndef UXP1A_LINDA_SCANNER_H
#define UXP1A_LINDA_SCANNER_H


#include <istream>
#include <unordered_map>
#include "../Token.h"

class Scanner
{
public:
    Scanner(std::istream& input)
            : input(input)
    {}

    Scanner(const Scanner&) = delete;
    const Scanner& operator=(const Scanner&) = delete;

    void read_next();
    Token get_token() const;
    int get_current_line() const;

private:
    Token current_token;
    std::istream& input;
    int current_line = 1;

    void skip_whitespaces();
    bool try_punctuation_mark();
    bool try_integer();
    bool try_eof();
    bool try_string_literal();

    std::string read_identifier() const;

    const std::unordered_map<char, PunctuationMark> punctuation_marks_map
            {
                    { '(', PunctuationMark::LeftParenthesis },
                    { ')', PunctuationMark::RightParenthesis },
                    { ',', PunctuationMark::Comma },
            };
};


#endif //UXP1A_LINDA_SCANNER_H
