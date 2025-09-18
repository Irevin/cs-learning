#include <string>

class Store{
private:
    std::string book;
    std::string candy;
    int inputPrice;
    const int& getInputPrice() const;
public:
    Store();
    Store(std::string book, std::string candy, int inputPrice);
    ~Store();
    std::string getBook() const;
    std::string getCandy() const;
    void setBook(std::string book);
    void setCandy(std::string candy);
};