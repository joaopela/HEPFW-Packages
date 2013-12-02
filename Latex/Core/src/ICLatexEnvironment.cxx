#include "Latex/Core/interface/ICLatexEnvironment.h"

using namespace std;

ICLatexEnvironment::ICLatexEnvironment(){
  
  m_name = "";
  m_optionsPosition = "";

}

ICLatexEnvironment::~ICLatexEnvironment(){}
    
string ICLatexEnvironment::toString(){
  
  string out;
  out  = this->toStringEnvBegin();
  out += this->toStringEnvInner();
  out += this->toStringEnvEnd();
  
  return out;
  
}


string ICLatexEnvironment::toStringEnvBegin(){
  
  string out;
  out = "\\begin{"+m_name+"}";
  
  if(m_optionsPosition != ""){
    out += "["+m_optionsPosition+"]";
  }
  
  out += "\n";
  
  return out;
  
}

string ICLatexEnvironment::toStringEnvInner(){

  string out;
  for(unsigned i=0; i<innerObjects.size(); i++){
    out += innerObjects[i]->toString();
  }  
  return out;

}

string ICLatexEnvironment::toStringEnvEnd(){
  
  string out;
  out = "\\end{"+m_name+"}";
  return out;
  
}