#ifndef GROUPE_H
#define GROUPE_H

#include <list>
#include <string>
#include "basic.h"
#include <memory>
using BasicPtr= std::shared_ptr<Basic>;
class Groupe : public std::list<Basic*>
{
private:
    std::string Name;
    std::list<BasicPtr> List;
public:
    Groupe();
    Groupe(std::string Name,const std::list<BasicPtr>& List);

    std::string getName()const;
    void setName(std::string Name);

    std::list<BasicPtr> getList()const;
    void setList(std::list<BasicPtr>);

    void AfficheElement(int i, std::ostream& out);

    void Affiche(std::ostream& out);

    ~Groupe();

    void save(std::ostream& out);
};


#endif // GROUPE_H
