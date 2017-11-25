#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>
#include <sstream>

enum class  DataType{
  integer = 0,
  floating,
  chr
};

class Node
{
public:
  class NodeData
  {
    union{
      int _idata;
      double _fdata;
      const char *_cdata = nullptr;
    };
    DataType _type = DataType::integer;

  public:
     NodeData(int idata = 0 );
     NodeData(float fdata );
     NodeData(const char *cdata );

    friend std::ostream& operator<<(std::ostream& out, const NodeData& data);

    int idata() const;
    float fdata() const;
    const char *cdata() const;
    DataType type() const;
  };
private:
  NodeData _data;
  std::vector<Node*> _children;

public:
  Node( NodeData data );/*
  Node( int idata );
  Node(float fdata );
  Node( char *idata );*/

  Node *addChild(Node *node);

  void print(int deep = 0);
  std::string jsonify();
};

std::ostream& operator<<(std::ostream& out, const Node::NodeData& data);

#endif // NODE_H
