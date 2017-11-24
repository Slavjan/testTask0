#include "node.h"

Node::Node(NodeData data)
{
  _data = data;
}

Node* Node::addChild(Node *node)
{
  _children.push_back(node);
  return this;
}


void Node::print(int deep)
{
  for(int i = 0; i < deep; i++)
    std::cout << "\t";

  std::cout << "value: " << _data << std::endl;

  for( auto child : _children ){
    child->print(deep+1);
  }
}


Node::NodeData::NodeData(DataVariant *data, DataType dataType)
{
   if(dataType == DataType::floating)
      _data._fdata =  data->_fdata;
    else if(dataType == DataType::integer)
      _data._idata = data->_idata;
    else if(dataType == DataType::str)
      _data._cdata =  data->_cdata;

    _type = dataType;
}

Node::NodeData::NodeData(const int idata)
{
  _idata = idata;
}

Node::NodeData::NodeData(const float data)
{
  _
}



std::ostream &operator<<(std::ostream &out, const Node::NodeData &data)
{
  out << data._idata;
  return out;
}
