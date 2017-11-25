#include "serializer.h"

using json = nlohmann::json;

bool Serializer::serialize(Node *tree, const char* path)
{
  std::ofstream stream( path );


  auto j = json::parse( tree->jsonify() );
  stream << j.dump(2);

  return true;
}

//Node *Serializer::deserialize(const char *path)
//{
//  Node *tree;

//  std::ifstream stream( path );
//  if( ! stream.is_open() ){
//    return new Node("file is not found!!!!");
//  }

//  json j;
//  stream >> j;

//  return tree;
//}
