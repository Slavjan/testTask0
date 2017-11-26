#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "node.h"
#include "json.hpp"
using json = nlohmann::json;
#include <iostream>
#include <fstream>

class Serializer
{
private:
  Serializer();
  static Node *fromJson(json &j);
public:
  static bool serialize(Node* tree, const char *path);
  static Node* deserialize( const char* path);
};

#endif // SERIALIZER_H
