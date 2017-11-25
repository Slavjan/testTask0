#include <iostream>
#include "node.h"

using namespace std;


int main()
{
  Node *tree = new Node(8);

  tree->addChild((new Node(12))
                 ->addChild(new Node(15))
                 );
  tree->addChild((new Node(12))
                 ->addChild(new Node(15)));
  tree->addChild(new Node(17));
  tree->addChild(new Node(19));
  tree->addChild(new Node(13));
  tree->addChild(new Node(14));

  tree->print();

  return 0;
}
