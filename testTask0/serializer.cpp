#include "serializer.h"

#include <stack>



Node *Serializer::fromJson(json &j)
{
  Node *node = nullptr;

  if( j.at("value").is_number_integer()){
    node = new Node( j.at("value").get<int>());
  }
  else if( j.at("value").is_number_float()){
    node = new Node( j.at("value").get<double>());
  }
  else if( j.at("value").is_string()){
    node = new Node( j.at("value").get<std::string>());
  }

  for( auto it : j.at("children")){
    node->addChild( fromJson(it) );
  }

  return node;
}

bool Serializer::serialize(Node *tree, const char* path)
{
  std::ofstream stream( path );

  auto j = json::parse( tree->jsonify() );
  stream << j.dump(2);

  return true;
}

Node *Serializer::deserialize(const char *path)
{
  Node *tree = nullptr;

  std::ifstream stream( path );
  if( ! stream.is_open() ){
    return new Node("file is not found!!!!");
  }

  json j;
  stream >> j;

  tree = fromJson( j );

  return tree;
}
