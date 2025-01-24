#ifndef BASIC_H
#define BASIC_H

#include <string>
#include <iostream>

class Basic
{
private:
    std::string name;
    std::string filename;
public:
    Basic();
    Basic(const std::string name, const std::string filename);

    std::string getName() const;
    std::string getFileName() const;

    void setName(const std::string);
    void setFilename(const std::string);

    virtual ~Basic();
    virtual void play() const = 0;  // Méthode virtuelle pure
    virtual void printAttribut(std::ostream& out) const;
};

#endif // BASIC_H
