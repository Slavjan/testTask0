#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "node.h"
#include "json.hpp"

#include <iostream>
#include <fstream>

class Serializer
{
private:
  Serializer();
public:
  static bool serialize(Node* tree, const char *path);
  static Node* deserialize( const char* path);

};

#endif // SERIALIZER_H
