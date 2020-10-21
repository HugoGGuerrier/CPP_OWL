#include "lexer/Token.h"
#include "Lexenv.h"

// ----- Constructors -----

Token::Token(int id) {
    this->id = id;
    this->line = -1;
    this->startPos = -1;
    this->endPos = -1;
    this->value = nullptr;
}

// ----- Getters -----

int Token::getId() const {
    return this->id;
}

unsigned int Token::getLine() const {
    return this->line;
}

unsigned int Token::getStartPos() const {
    return this->startPos;
}

unsigned int Token::getEndPos() const {
    return this->endPos;
}

const char *Token::getValue() const {
    return this->value;
}

const char *Token::getName() const {
    if(this->id != -1) {
        return Lexenv::nameArray[this->id];
    }
    return nullptr;
}

// ----- Setters -----

void Token::setId(int newId) {
    this->id = newId;
}

void Token::setLine(unsigned int ln) {
    this->line = ln;
}

void Token::setStartPos(unsigned int sp) {
    this->startPos = sp;
}

void Token::setEndPos(unsigned int ep) {
    this->endPos = ep;
}

void Token::setValue(const char *v) {
    this->value = v;
}