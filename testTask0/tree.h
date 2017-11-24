#ifndef TREE_H
#define TREE_H

#include <vector>
#include <string>

union DataVariant{
  int _idata = 0;
  float _fdata;
  std::string *_sdata;

  DataVariant( int idata ){
    _idata = idata;
  }
  DataVariant(float fdata ){
    _fdata = fdata;
  }
  DataVariant(std::string sdata ){
    _sdata =  new std::string(sdata);
  }
};

enum DataType{
  integer = 0,
  floating,
  str
};

class Tree
{
public:
  struct Variant{
    DataVariant *_data = nullptr;
    DataType _dataType = DataType::integer;

    Variant( DataVariant *data, DataType dataType = integer);
    Variant(const int data );
    Variant(const float data );
    Variant(const std::string data );

  };
private:
  int _id = 0;
  Variant *_data = nullptr;
  std::vector<Tree*> *_siblings = nullptr;
  std::vector<Tree*> *_children = nullptr;

  size_t getChildrenCount();
  size_t getSiblingsCount();
  Tree* getNodeById( int id );
  Tree* getNodeByData(const Variant *data = nullptr);


public:
  Tree(Variant *data,
       std::vector<Tree*> *siblings = nullptr,
       std::vector<Tree*> *children = nullptr);
  ~Tree();

  void addNode(Variant *value);
  void addNode(Tree *node);
  void addNode(DataVariant *data, DataType dataType = integer);

  int getId();
  Variant getData();
  template<typename T>
  T getValue(){
    if(_data->_dataType == DataType::integer)
      return _data->_data->_idata;
    else if(_data->_dataType == DataType::floating){
      return _data->_data->_fdata;
    }else if(_data->_dataType == DataType::str){
      return _data->_data->_sdata;
    }
    return nullptr;
  }

  Tree getNode(const int id);

  void print();
};

#endif // TREE_H
