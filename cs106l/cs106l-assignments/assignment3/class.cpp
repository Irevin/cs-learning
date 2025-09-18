#include "class.h"
#include <string>

Store::Store(){}
Store::Store(std::string book, std::string candy, int inputPrice){
    this->book = book;
    this->candy = candy;
    this->inputPrice = inputPrice;
}
Store::~Store(){}
const int& Store::getInputPrice() const{
    return this->inputPrice;
}
std::string Store::getBook() const{ 
    return this->book;
}
std::string Store::getCandy() const{
    return this->candy;
}
void Store::setBook(std::string book){
    this->book = book;
}
void Store::setCandy(std::string candy){
    this->candy = candy;
}