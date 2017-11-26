#include <string>

#include "node.h"
#include "serializer.h"
#include "parametrparser.h"

int main(int argc, char **argv)
{
  ParametrParser args(argc, argv);
  Node *tree = nullptr;

  args.setShortOption("i", [&](std::string path){
    tree = Serializer::deserialize( path.c_str() );
  });
  args.setShortOption("o", [&](std::string path){

    if(tree == nullptr){
      std::cerr << " nothing to serialize !" << std::endl;
      return 1;
    }
    Serializer::serialize( tree, path.c_str() );
  });

  try{
    args.exec();
  }catch(ParametrParser::UnknownOption e){
    std::cerr << "Unknown option: " << e.optionName << std::endl;
  }

  tree->print();
  return 0;
}
