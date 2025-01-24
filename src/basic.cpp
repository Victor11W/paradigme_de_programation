#include "../include/basic.h"


Basic::Basic(): name(""), filename("")
{

}

Basic::Basic(const std::string name,const std::string filename):name(name),filename(filename)
{

}

std::string Basic::getName() const{
    return this->name;
}
std::string Basic::getFileName() const{
    return this->filename;
}

void Basic::setName(const std::string name2){
    this->name=name2;
}


void Basic::setFilename(const std::string filename2){
    this->filename=filename2;
}

Basic::~Basic(){}


void Basic::printAttribut(std::ostream& out) const{
}