#include <iostream>
using namespace std;

class base{
  public:
  void writeMsg(void){
    cout<<"base class msg1\n";
  }

  virtual void writeMsg2(void){
    cout<<"base class msg2\n";
  }
};

class derived:public base
{
public:
  void writeMsg(void){
    cout<<"derived class msg1\n";
  }

  void writeMsg2(void){
    cout<<"derived class msg2\n";
  }
};

int main(){
  derived derClass;
  base baseClass;
  base *array[] = {&derClass,&baseClass};

  for (uint8_t i = 0; i < (sizeof(array)/sizeof(base*)); i++)
  {
    array[i]->writeMsg();
    array[i]->writeMsg2();
  }
}

