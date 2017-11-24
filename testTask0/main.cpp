#include <iostream>
#include "node.h"

using namespace std;


int main()
{
  Node *tree = new Node(8);

  tree->addChild((new Node(12))
                 ->addChild(new Node(15))
                 );
  tree->addChild((new Node(17))
                 ->addChild(new Node(19)));
  tree->addChild(new Node(13));
  tree->addChild(new Node(14));

  tree->print();

  return 0;
}
//int main()
//{
//  // To-do console parameters reading

//  Tree tree(new Tree::Variant(9)),
//  tree1(new Tree::Variant(1.2f)),
//  tree2(new Tree::Variant("std")),
//  tree3(new Tree::Variant(12)),
//  tree4(new Tree::Variant(150)),
//  tree5(new Tree::Variant(2.015f));

//  tree.addNode(&tree1);
//  tree.addNode(&tree2);
//  tree.addNode(&tree3);
//  tree.addNode(&tree4);
//  tree.addNode(&tree5);

//  tree.print();

//  cout << "Hello World!" << endl;
//  return 0;
//}
