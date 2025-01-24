#include <iostream>
#include <memory>  // Pour shared_ptr
#include <list>
#include "../include/film.h"
#include "../include/photo.h"
#include "../include/groupe.h"
#include "../include/createandmodify.h"
#include "../include/readMethod.h"

int main(int argc, const char* argv[]) {
    // test pour readMethod
    std::istringstream in("{\"type\": \"Photo\", \"name\": \"phoro1\", \"filename\": \"../image+video/image.pgn\", \"latitude\": 12, \"longitude\": 13}");
    auto photo = readMethod::readElement(in);


    return 0;
}
