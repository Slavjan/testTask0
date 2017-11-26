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

std::string Node::jsonify()
{
  std::stringstream json;

  json << "{ \"value\": " << _data << ", \"children\":[";

  for( auto child : _children ){
    json << child->jsonify();

    if( child != *(_children.end()-1) ){
      json << ",";
    }
  }

  json << "]}";

  return json.str();
}

//Node::NodeData::NodeData(DataVariant *data, DataType dataType)
//{
//   if(dataType == DataType::floating)
//      _data = data->fdata();
//    else if(dataType == DataType::integer)
//      _data = data->idata();
//    else if(dataType == DataType::chr)
//      _data = data->cdata();

//    _type = dataType;
//}

int Node::NodeData::idata() const
{
  return _idata;
}

double Node::NodeData::fdata() const
{
  return _fdata;
}

std::string Node::NodeData::cdata() const
{
  return _cdata;
}

DataType Node::NodeData::type() const
{
  return _type;
}

Node::NodeData::NodeData(int idata)
{
  _idata = idata;
  _type = DataType::integer;
}

Node::NodeData::NodeData(double fdata)
{
  _fdata = fdata;
  _type = DataType::floating;
}

Node::NodeData::NodeData(std::string cdata)
{
  _cdata = cdata;
  _type = DataType::string;
}

Node::NodeData::NodeData(const char *cdata)
{
  _cdata = cdata;
  _type = DataType::string;
}

std::ostream &operator<<(std::ostream &out, const Node::NodeData &data)
{
  if(data.type() == DataType::floating)
      out << data.fdata();
   else if(data.type() == DataType::integer)
      out << data.idata();
   else if(data.type() == DataType::string)
      out <<"\"" << data.cdata() << "\"";

// out << data._data._idata;
  return out;
}
