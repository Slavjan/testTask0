#include <iostream>
#include "node.h"

using namespace std;


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

  tree->print();

  return 0;
}
