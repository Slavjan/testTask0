#include "node.h"

Node::Node(NodeData *data)
{
  _data = data;
}

Node::Node(int idata)
{
  Node(  new NodeData( idata ) );
}

Node::Node(float fdata)
{
  Node( new NodeData( fdata ) );
}

Node::Node(char *cdata)
{
  Node( new NodeData( cdata ) );
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

DataVariant *Node::NodeData::data() const
{
  return _data;
}

DataType Node::NodeData::type() const
{
  return _type;
}

Node::NodeData::NodeData(DataVariant *data, DataType dataType)
{
   if(dataType == DataType::floating)
      _data = new DataVariant(data->fdata());
    else if(dataType == DataType::integer)
      _data = new DataVariant(data->idata());
    else if(dataType == DataType::chr)
      _data = new DataVariant(data->cdata());

    _type = dataType;
}

Node::NodeData::NodeData(const int idata)
{
  NodeData(new DataVariant( idata ), DataType::integer);
}

Node::NodeData::NodeData(float fdata)
{
  NodeData(new DataVariant( fdata ), DataType::floating);
}

Node::NodeData::NodeData(char *cdata)
{
  NodeData(new DataVariant( cdata ), DataType::chr);
}


std::ostream &operator<<(std::ostream &out, const Node::NodeData *data)
{
  if(data->type() == DataType::floating)
      out << data->data()->fdata();
   else if(data->type() == DataType::integer)
      out << data->data()->idata();
   else if(data->type() == DataType::chr)
      out << data->data()->cdata();

// out << data._data._idata;
  return out;
}







void DataVariant::setFdata(float fdata)
{
  _fdata = fdata;
}

void DataVariant::setCdata(char *cdata)
{
  _cdata = cdata;
}

void DataVariant::setIdata(int idata)
{
  _idata = idata;
}
