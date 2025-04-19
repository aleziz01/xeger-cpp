#pragma once
#include<string>
#include<string_view>
#include<unordered_map>
#include <re2/re2.h>
#include <random>
#include <set>
#include <vector>

#ifdef _WIN32
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT
#endif

EXPORT class Xeger {
public:
    // Constructor
    Xeger(int limit = 10, unsigned int seed = 0) 
        : _limit(limit), _random(std::random_device{}()) {
        if (seed != 0) {
            _random.seed(seed);
        }
        _alphabets["printable"] = getPrintable();
        _alphabets["letters"] = getAsciiLetters();
        _alphabets["uppercase"] = getAsciiUppercase();
        _alphabets["lowercase"] = getAsciiLowercase();
        _alphabets["digits"] = getDigits();
        _alphabets["punctuation"] = getPunctuation();
        _alphabets["nondigits"] = getAsciiLetters() + getPunctuation();
        _alphabets["nonletters"] = getDigits() + getPunctuation();
        _alphabets["whitespace"] = getWhitespace();
        _alphabets["nonwhitespace"] = getPrintable().substr(1); // Strip whitespace
        _alphabets["normal"] = getAsciiLetters() + getDigits() + " ";
        _alphabets["word"] = getAsciiLetters() + getDigits() + "_";
        _alphabets["nonword"] = getNonWord();
        _alphabets["postalsafe"] = getAsciiLetters() + getDigits() + " .-#/";
        _alphabets["urlsafe"] = getAsciiLetters() + getDigits() + "-._~";
        _alphabets["domainsafe"] = getAsciiLetters() + getDigits() + "-";

    }

    // Function to get printable characters
    std::string getPrintable() {
        return " 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    }

    // Function to get ASCII letters
    std::string getAsciiLetters() {
        return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }

    // Function to get ASCII uppercase letters
    std::string getAsciiUppercase() {
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }

    // Function to get ASCII lowercase letters
    std::string getAsciiLowercase() {
        return "abcdefghijklmnopqrstuvwxyz";
    }

    // Function to get digits
    std::string getDigits() {
        return "0123456789";
    }

    // Function to get punctuation
    std::string getPunctuation() {
        return "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    }

    // Function to get whitespace
    std::string getWhitespace() {
        return " \t\n\r\f\v"; // Space, tab, newline, carriage return, form feed, vertical tab
    }

    // Function to get non-word characters
    std::string getNonWord() {
        std::string printable = getPrintable();
        std::string letters_digits = getAsciiLetters() + getDigits() + "_";
        std::set<char> nonword_set;

        // Add all printable characters to the set
        for (char c : printable) {
            nonword_set.insert(c);
        }

        // Remove letters, digits, and underscore from the set
        for (char c : letters_digits) {
            nonword_set.erase(c);
        }

        // Convert the set back to a string
        std::string nonword(nonword_set.begin(), nonword_set.end());
        return nonword;
    }
    
    std::string buildString(const std::vector<std::pair<int,std::string>> parsed) {
        std::string newStr;
        for (const auto& state : parsed) {
            newStr += handleState(state);
        }
        return newStr;
    }

    std::string handleState(const std::pair<int, string>& state) {
        int opcode = state.first;
        std::string value = state.second;
        
    }

private:
    int _limit;
    std::unordered_map<std::string, std::string> _cache; // Using string for keys and values as an example
    std::mt19937 _random; // Mersenne Twister random number generator
    std::unordered_map<std::string, std::string> _alphabets;
    std::unordered_map<std::string, std::function<std::string(const std::string&)>> cases;
};