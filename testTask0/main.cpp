#include <iostream>
#include <fstream>
#include "node.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{
  Node *tree = new Node(8);
  tree->addChild((new Node("ffsdfsd"))
                 ->addChild(new Node(15))
                 );
  tree->addChild( (new Node(17.9f))
                  ->addChild(new Node(19.2f)) );
  tree->addChild(new Node("rtrt"));
  tree->addChild(new Node(1.4f));

//  tree->print();

  auto j = json::parse( tree->jsonify() );

  std::cout << j.dump(2) << std::endl;


  return 0;
}
