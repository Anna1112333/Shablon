#pragma once
#include <fstream>

class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string printAsHTML() const = 0;
    virtual std::string printAsText() const = 0;
    virtual std::string printAsJSON() const = 0;
};

class Data : public Printable
{
public:
    enum class Format
    {
        kText,
        kHTML,
        kJSON
    };

    Data(std::string data, Format format); 

    std::string printAsHTML() const override;
    
    std::string printAsText() const override;
    
    std::string printAsJSON() const override;
    

private:
    std::string data_;
    Format format_;
};

void saveTo(std::ofstream& file, const Printable& printable, Data::Format format);
void saveToAsHTML(std::ofstream& file, const Printable& printable); 
void saveToAsJSON(std::ofstream& file, const Printable& printable); 
void saveToAsText(std::ofstream& file, const Printable& printable); 