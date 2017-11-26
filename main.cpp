#include <string>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "node.h"
#include "serializer.h"

int main(int argc, char **argv)
{
  Node *tree = nullptr;

  const char *opts = "i:o:";

  int opt;
  while((opt = getopt(argc, argv, opts)) != -1) {
    switch(opt){
    case 'i':
      tree = Serializer::deserialize( optarg );
      break;

    case 'o':
      if( !tree ){
        std::cerr << " nothing to serialize! " << std::endl;
        return 2;
      }
      Serializer::serialize( tree, optarg );
      break;

    default:
      std::cerr << " unexpected argument " << std::endl;
      return 1;
    }
  }

  tree->print();
  return 0;
}
