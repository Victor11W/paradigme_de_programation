//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "../../include/basic.h"
#include "../../include/video.h"
#include "../../include/film.h"
#include "../../include/photo.h"
#include "../../include/groupe.h"
#include "../../include/createandmodify.h"


const int PORT = 3333;

CreateAndModify Storage = CreateAndModify();



int main(int argc, char* argv[])
{
  // cree le TCPServer
auto* server = new TCPServer([&](std::string const& request, std::string& response) {
    Storage.createVideo("video1", "../../image+video/SpeedrundragTGC.mp4", 10);
    Storage.createFilm("film1", "../../image+video/SpeedrundragTGC.mp4", 10, 3, new int[3]{1, 2, 3});
    Storage.createPhoto("photo1", "../../image+video/image.png", 10, 10);
    Storage.createGroupe("Groupe1", std::list<std::string>{"video1", "film1", "photo1"});
    std::cout << "Requête reçue : " << request << std::endl;

    // Analyser la requête
    std::istringstream iss(request);
    std::string type, name, action;
    iss >> type >> name >> action;

    if (type == "photo" || type == "film" || type == "video") {
      if (Storage.isInMultimediatable(name)) {
        if (action == "play") {
            Storage.playObject(name);
        } else {
            std::ostringstream test;
            Storage.displayObject(name, test,false);
            response = test.str();
        }
    } else {
        response = "Element not found";}
    }else if (type == "groupe") {
      if (Storage.isInGroupeTable(name)) {
        std::ostringstream test;
        Storage.displayObject(name, test,true);
        response = test.str();
    } else {
        response = "Group not found";}
    
    }else {
        // Type inconnu
        response = "type inconnu : voici la liste des types : photo video film groupe si jamais vous avez bien le bon type n'ouvliez pas le format de la requète : type Name";
    }
    return true;
});



  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  return 0;
}

