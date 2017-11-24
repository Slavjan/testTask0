#include "tree.h"

#include <iostream>

size_t Tree::getChildrenCount()
{
  return _children->size();
}

size_t Tree::getSiblingsCount()
{
  return _siblings->size();
}

Tree *Tree::getNodeById(int id)
{
  if( _id == id )
    return this;
  else{
    for( auto son : *_children ){
      return son->getNodeById( id );
    }
  }
  return nullptr;
}

Tree *Tree::getNodeByData(const Tree::Variant *data)
{
  if( _data == data )
    return this;
  else{
    for( auto son : *_children ){
      return son->getNodeByData( data );
    }
  }
  return nullptr;
}

Tree::Tree(Tree::Variant *data,
           std::vector<Tree *> *siblings,
           std::vector<Tree *> *children)
{
  if(_data){
    *_data = *data;
  }else{
    _data = new Variant( *data );
  }

  _siblings = siblings;
  _children = children;
}

Tree::~Tree()
{
  for( auto son : *_children){
    delete son;
  }
}

void Tree::addNode(Variant *value)
{
  if( !value ){
    _children->push_back(new Tree(new Variant(0)));
  } else {
    Tree* newTree = new Tree( value );
    for( auto brother : *_siblings ){
      newTree->addNode( brother );
    }
    _children->push_back( newTree );
  }
}

void Tree::addNode(Tree *node)
{
  if( !node ){
    _children->push_back( new Tree(new Variant(0)) );
  }else{
    _children->push_back( node );
  }

  delete _data;
}

void Tree::print()
{
  std::cout << "id: " << _id << "value: ";
  if( _data->_dataType == DataType::floating ){
   std::cout << _data->_data->_fdata << std::endl;
  }else if (_data->_dataType == DataType::integer){
   std::cout << _data->_data->_idata << std::endl;
  }else{
   std::cout << _data->_data->_sdata << std::endl;
  }
  std::cout << "\t";
  for( auto son : *_children ){
    son->print();
  }

}

Tree::Variant::Variant(DataVariant *data, DataType dataType){
  if( !_data ){
    if(dataType == DataType::floating)
      _data = new DataVariant( data->_fdata);
    else if(dataType == DataType::integer)
      _data = new DataVariant( data->_idata);
    else if(dataType == DataType::str)
      _data = new DataVariant( *data->_sdata);

  }else{
    if(dataType == DataType::floating)
      _data->_fdata =  data->_fdata;
    else if(dataType == DataType::integer)
      _data->_idata = data->_idata;
    else if(dataType == DataType::str)
      _data->_sdata =  data->_sdata;

    _dataType = dataType;
  }
}

Tree::Variant::Variant(const int data){
  Variant( new DataVariant(data), DataType::integer );
}

Tree::Variant::Variant(const float data){
  Variant( new DataVariant(data), DataType::floating );
}

Tree::Variant::Variant(const std::string data){
  Variant( new DataVariant(data), DataType::str );
}
