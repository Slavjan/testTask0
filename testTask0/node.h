#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>
#include <sstream>

enum class  DataType{
  integer = 0,
  floating,
  string
};

class Node
{
public:
  class NodeData
  {
    int _idata;
    double _fdata;
    std::string _cdata;

    DataType _type = DataType::integer;

  public:
     NodeData(int idata = 0 );
     NodeData(double fdata );
     NodeData(std::string cdata );
     NodeData(const char* cdata );

    friend std::ostream& operator<<(std::ostream& out, const NodeData& data);

    int idata() const;
    double fdata() const;
    std::string cdata() const;
    DataType type() const;
  };
private:
  NodeData _data;
  std::vector<Node*> _children;

public:
  Node( NodeData data );

  Node *addChild(Node *node);

  void print(int deep = 0);
  std::string jsonify();
};

std::ostream& operator<<(std::ostream& out, const Node::NodeData& data);

#endif // NODE_H
