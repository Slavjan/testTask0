#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>

enum class  DataType{
  integer = 0,
  floating,
  chr
};

class DataVariant{
  int _idata = 0;
  float _fdata;
  char *_cdata;
public:
  DataVariant(int idata ){
    _idata = idata;
  }
  DataVariant(float fdata ){
    _fdata = fdata;
  }
  DataVariant(char *cdata ){
    _cdata =  cdata;
  }

  int idata(){
    return _idata;
  }
  float fdata(){
    return _fdata;
  }
  char* cdata(){
    return _cdata;
  }
  void setIdata(int idata);
  void setFdata(float fdata);
  void setCdata(char *cdata);
};


class Node
{
public:
  class NodeData
  {
    DataVariant *_data;
    DataType _type = DataType::integer;

  public:
      NodeData(DataVariant *data, DataType dataType = DataType::integer);
      NodeData(const int idata = 0 );
      NodeData(float fdata = 0 );
      NodeData(char *cdata = nullptr);

    friend std::ostream& operator<<(std::ostream& out, const NodeData& data);
    DataVariant *data() const;
    DataType type() const;
  };
private:
  NodeData *_data;
  std::vector<Node*> _children;

public:
  Node( NodeData *data );
  Node( int idata );
  Node(float fdata );
  Node( char *idata );

  Node *addChild(Node *node);

  void print(int deep = 0);
};

std::ostream& operator<<(std::ostream& out, const Node::NodeData& data);

#endif // NODE_H
