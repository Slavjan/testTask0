#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>

enum class DataType{
  integer = 0,
  floating,
  str
};

union DataVariant{
  int _idata = 0;
  float _fdata;
  char *_cdata;

  DataVariant( int idata ){
    _idata = idata;
  }
  DataVariant(float fdata ){
    _fdata = fdata;
  }
  DataVariant(char *cdata ){
    _cdata =  cdata;
  }
};

class Node
{
public:
  class NodeData
  {
    DataVariant _data;
    DataType _type ;

  public:
    NodeData( DataVariant *data, DataType dataType = DataType::integer);
    NodeData(const int idata = 0 );
    NodeData(const float data );
    NodeData(const char *cdata );

    friend std::ostream& operator<<(std::ostream& out, const NodeData& data);
  };
private:
  NodeData _data;
  std::vector<Node*> _children;

public:
  Node(NodeData data);

  Node *addChild(Node *node);

  void print(int deep = 0);
};

std::ostream& operator<<(std::ostream& out, const Node::NodeData& data);

#endif // NODE_H