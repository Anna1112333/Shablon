#include <string>
#include <iostream>
#include <algorithm>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};


class Paragraph : public DecoratedText
{
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }

    // >> > <p>Hello world< / p>
};

class Reversed : public DecoratedText
{
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::string reversed_data = data;
       std::reverse(reversed_data.begin(), reversed_data.end() );;       
        text_->render(reversed_data);
    }
    //>> > dlrow olleH
};

class Link : public DecoratedText
{
public:
    explicit Link(Text* text) : DecoratedText(text) {}
   void render(const std::string& data1, const std::string& data2) const {
       
           std::cout << "<a href = ";
           text_->render(data1);
           std::cout << ">";
           text_->render(data2);
           std::cout << "</a>";       
    }    
   // >> > <a href = netology.ru>Hello world< / a>
};


int main() {
    auto text_block = new ItalicText(new BoldText(new Text()));
    text_block->render("Hello world");
    auto text_block1 = new Paragraph(new Text());
    std::cout << std::endl;
    text_block1->render("Hello world");
    std::cout << std::endl;
    auto text_block2 = new Reversed(new Text());
    text_block2->render("Hello world");
    std::cout << std::endl;
    auto text_block3 = new Link(new Text());
    text_block3->render("netology.ru", "Hello world");
    delete text_block;
    delete text_block1;
    delete text_block2;
    delete text_block3;
}