#include "Parameters/Parser/interface/ParameterSet.h"

#include "TString.h"

using namespace std;

void hepfw::ParameterSet::insertBool    (string key,bool value)              {pBool_    [key]=value;}
void hepfw::ParameterSet::insertInt     (string key,int value)               {pInt_     [key]=value;}
void hepfw::ParameterSet::insertFloat   (string key,float value)             {pFloat_   [key]=value;}
void hepfw::ParameterSet::insertDouble  (string key,double value)            {pDouble_  [key]=value;}
void hepfw::ParameterSet::insertString  (string key,string value)            {pString_  [key]=value;}
void hepfw::ParameterSet::insertVBool   (string key,vector<bool> value)      {pVBool_   [key]=value;}
void hepfw::ParameterSet::insertVInt    (string key,vector<int> value)       {pVInt_    [key]=value;}
void hepfw::ParameterSet::insertVFloat  (string key,vector<float> value)     {pVFloat_  [key]=value;}
void hepfw::ParameterSet::insertVDouble (string key,vector<double> value)    {pVDouble_ [key]=value;}
void hepfw::ParameterSet::insertVString (string key,vector<string> value)    {pVString_ [key]=value;}
void hepfw::ParameterSet::insertMiBool  (string key,map<int,bool> value)     {pMiBool_  [key]=value;}
void hepfw::ParameterSet::insertMiInt   (string key,map<int,int> value)      {pMiInt_   [key]=value;}
void hepfw::ParameterSet::insertMiFloat (string key,map<int,float> value)    {pMiFloat_ [key]=value;}
void hepfw::ParameterSet::insertMiDouble(string key,map<int,double> value)   {pMiDouble_[key]=value;}
void hepfw::ParameterSet::insertMiString(string key,map<int,string> value)   {pMiString_[key]=value;}
void hepfw::ParameterSet::insertMsBool  (string key,map<string,bool> value)  {pMsBool_  [key]=value;}
void hepfw::ParameterSet::insertMsInt   (string key,map<string,int> value)   {pMsInt_   [key]=value;}
void hepfw::ParameterSet::insertMsFloat (string key,map<string,float> value) {pMsFloat_ [key]=value;}
void hepfw::ParameterSet::insertMsDouble(string key,map<string,double> value){pMsDouble_[key]=value;}
void hepfw::ParameterSet::insertMsString(string key,map<string,string> value){pMsString_[key]=value;}

bool hepfw::ParameterSet::getBool(string key){
  map<string,bool>::iterator p = pBool_.find(key);
  if(p!=pBool_.end()){return p->second;}
  else               {return false;} //TODO: need some handling
}

int hepfw::ParameterSet::getInt(string key){
  map<string,int>::iterator p = pInt_.find(key);
  if(p!=pInt_.end()){return p->second;}
  else              {return 0;} //TODO: need some handling
}

float hepfw::ParameterSet::getFloat   (string key){
  map<string,float>::iterator p = pFloat_.find(key);
  if(p!=pFloat_.end()){return p->second;}
  else                {return 0;} //TODO: need some handling
}

double hepfw::ParameterSet::getDouble  (string key){
  map<string,double>::iterator p = pDouble_.find(key);
  if(p!=pDouble_.end()){return p->second;}
  else                 {return 0;} //TODO: need some handling
}

string hepfw::ParameterSet::getString  (string key){
  map<string,string>::iterator p = pString_.find(key);
  if(p!=pString_.end()){return p->second;}
  else                 {return "";} //TODO: need some handling
}

vector<bool> hepfw::ParameterSet::getVBool(string key){
  map<string,vector<bool> >::iterator p = pVBool_.find(key);
  if(p!=pVBool_.end()){return p->second;}
  else                {return vector<bool>();} //TODO: need some handling
}

vector<int> hepfw::ParameterSet::getVInt(string key){
  map<string,vector<int> >::iterator p = pVInt_.find(key);
  if(p!=pVInt_.end()){return p->second;}
  else               {return vector<int>();} //TODO: need some handling
}

vector<float> hepfw::ParameterSet::getVFloat(string key){
  map<string,vector<float> >::iterator p = pVFloat_.find(key);
  if(p!=pVFloat_.end()){return p->second;}
  else                 {return vector<float>();} //TODO: need some handling
}

vector<double> hepfw::ParameterSet::getVDouble(string key){
  map<string,vector<double> >::iterator p = pVDouble_.find(key);
  if(p!=pVDouble_.end()){return p->second;}
  else                  {return vector<double>();} //TODO: need some handling
}

vector<string> hepfw::ParameterSet::getVString(string key){
  map<string,vector<string> >::iterator p = pVString_.find(key);
  if(p!=pVString_.end()){return p->second;}
  else                  {return vector<string>();} //TODO: need some handling
}

map<int,bool> hepfw::ParameterSet::getMiBool  (string key){
  map<string,map<int,bool> >::iterator p = pMiBool_.find(key);
  if(p!=pMiBool_.end()){return p->second;}
  else                 {return map<int,bool>();} //TODO: need some handling
}

map<int,int> hepfw::ParameterSet::getMiInt   (string key){
  map<string,map<int,int> >::iterator p = pMiInt_.find(key);
  if(p!=pMiInt_.end()){return p->second;}
  else                {return map<int,int>();} //TODO: need some handling
}

map<int,float> hepfw::ParameterSet::getMiFloat (string key){
  map<string,map<int,float> >::iterator p = pMiFloat_.find(key);
  if(p!=pMiFloat_.end()){return p->second;}
  else                  {return map<int,float>();} //TODO: need some handling
}

map<int,double> hepfw::ParameterSet::getMiDouble(string key){
  map<string,map<int,double> >::iterator p = pMiDouble_.find(key);
  if(p!=pMiDouble_.end()){return p->second;}
  else                   {return map<int,double>();} //TODO: need some handling
}

map<int,string> hepfw::ParameterSet::getMiString(string key){
  map<string,map<int,string> >::iterator p = pMiString_.find(key);
  if(p!=pMiString_.end()){return p->second;}
  else                   {return map<int,string>();} //TODO: need some handling
}

map<string,bool> hepfw::ParameterSet::getMsBool  (string key){
  map<string,map<string,bool> >::iterator p = pMsBool_.find(key);
  if(p!=pMsBool_.end()){return p->second;}
  else                 {return map<string,bool>();} //TODO: need some handling
}

map<string,int> hepfw::ParameterSet::getMsInt   (string key){
  map<string,map<string,int> >::iterator p = pMsInt_.find(key);
  if(p!=pMsInt_.end()){return p->second;}
  else                {return map<string,int>();} //TODO: need some handling
}

map<string,float> hepfw::ParameterSet::getMsFloat (string key){
  map<string,map<string,float> >::iterator p = pMsFloat_.find(key);
  if(p!=pMsFloat_.end()){return p->second;}
  else                  {return map<string,float>();} //TODO: need some handling
}

map<string,double> hepfw::ParameterSet::getMsDouble(string key){
  map<string,map<string,double> >::iterator p = pMsDouble_.find(key);
  if(p!=pMsDouble_.end()){return p->second;}
  else                   {return map<string,double>();} //TODO: need some handling
}

map<string,string> hepfw::ParameterSet::getMsString(string key){
  map<string,map<string,string> >::iterator p = pMsString_.find(key);
  if(p!=pMsString_.end()){return p->second;}
  else                   {return map<string,string>();} //TODO: need some handling
}

bool hepfw::ParameterSet::isSetBool    (std::string key){
  if(pBool_.find(key)!=pBool_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetInt     (std::string key){
  if(pInt_.find(key)!=pInt_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetFloat   (std::string key){
  if(pFloat_.find(key)!=pFloat_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetDouble  (std::string key){
  if(pDouble_.find(key)!=pDouble_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetString  (std::string key){
  if(pString_.find(key)!=pString_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetVBool   (std::string key){ 
  if(pVBool_.find(key)!=pVBool_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetVInt    (std::string key){
  if(pVInt_.find(key)!=pVInt_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetVFloat  (std::string key){
  if(pVFloat_.find(key)!=pVFloat_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetVDouble (std::string key){
  if(pVDouble_.find(key)!=pVDouble_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetVString (std::string key){  
  if(pVString_.find(key)!=pVString_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetMiBool  (std::string key){  
  if(pMsBool_.find(key)!=pMsBool_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetMiInt   (std::string key){
  if(pMsInt_.find(key)!=pMsInt_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetMiFloat (std::string key){
  if(pMsFloat_.find(key)!=pMsFloat_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetMiDouble(std::string key){  
  if(pMsDouble_.find(key)!=pMsDouble_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetMiString(std::string key){
  if(pMsString_.find(key)!=pMsString_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetMsBool  (std::string key){
  if(pMiBool_.find(key)!=pMiBool_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetMsInt   (std::string key){
  if(pMiInt_.find(key)!=pMiInt_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetMsFloat (std::string key){
  if(pMiFloat_.find(key)!=pMiFloat_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetMsDouble(std::string key){
  if(pMiDouble_.find(key)!=pMiDouble_.end()){return true;}
  else{return false;}
}

bool hepfw::ParameterSet::isSetMsString(std::string key){
  if(pMiString_.find(key)!=pMiString_.end()){return true;}
  else{return false;}
}

string hepfw::ParameterSet::toString(){

  string out = "Parameters List:\n\n";

  if(pBool_.size()){
    out += "##> Type: bool\n";
    for(map<string,bool>::iterator i=pBool_.begin(); i!=pBool_.end(); i++){
      out += Form("%s = %d\n",i->first.c_str(),i->second);
    }
  }

  if(pInt_.size()){
    out += "##> Type: int\n";
    for(map<string,int>::iterator i=pInt_.begin(); i!=pInt_.end(); i++){
      out += Form("%s = %d\n",i->first.c_str(),i->second);
    }
  }

  if(pFloat_.size()){
    out += "##> Type: int\n";
    for(map<string,float>::iterator i=pFloat_.begin(); i!=pFloat_.end(); i++){
      out += Form("%s = %f\n",i->first.c_str(),i->second);
    }
  }

  if(pDouble_.size()){
    out += "##> Type: double\n";
    for(map<string,double>::iterator i=pDouble_.begin(); i!=pDouble_.end(); i++){
      out += Form("%s = %f\n",i->first.c_str(),i->second);
    }
  }

  if(pString_.size()){
    out += "##> Type: string\n";
    for(map<string,string>::iterator i=pString_.begin(); i!=pString_.end(); i++){
      out += Form("%s = %s\n",i->first.c_str(),i->second.c_str());
    }
  }

  // Maps for vectors of basics variables
  if(pVBool_.size()){
    out += "##> Type: vector<bool>\n";
    for(map<string,vector<bool> >::iterator i=pVBool_.begin(); i!=pVBool_.end(); i++){
      out += Form("%s: {",i->first.c_str());
      for(unsigned a=0; a<i->second.size();a++){
        if(a==0){out += (i->second)[0];}
        else    {out += ","; out+=(i->second)[a];}
      }
      out += "}\n";
    }
  }
  if(pVInt_.size()){
    out += "##> Type: vector<int>\n";
    for(map<string,vector<int> >::iterator i=pVInt_.begin(); i!=pVInt_.end(); i++){
      out += Form("%s: {",i->first.c_str());
      for(unsigned a=0; a<i->second.size();a++){
        if(a==0){out += (i->second)[0];}
        else    {out += ","; out+=(i->second)[a];}
      }
      out += "}\n";
    }
  }
  if(pVFloat_.size()){
    out += "##> Type: vector<float>\n";
    for(map<string,vector<float> >::iterator i=pVFloat_.begin(); i!=pVFloat_.end(); i++){
      out += Form("%s: {",i->first.c_str());
      for(unsigned a=0; a<i->second.size();a++){
        if(a==0){out += (i->second)[0];}
        else    {out += ","; out+=(i->second)[a];}
      }
      out += "}\n";
    }
  }
  if(pVDouble_.size()){
    out += "##> Type: vector<double>\n";
    for(map<string,vector<double> >::iterator i=pVDouble_.begin(); i!=pVDouble_.end(); i++){
      out += Form("%s: {",i->first.c_str());
      for(unsigned a=0; a<i->second.size();a++){
        if(a==0){out += (i->second)[0];}
        else    {out += ","; out+=(i->second)[a];}
      }
      out += "}\n";
    }
  }
  if(pVString_.size()){
    out += "##> Type: vector<double>\n";
    for(map<string,vector<string> >::iterator i=pVString_.begin(); i!=pVString_.end(); i++){
      out += Form("%s: {",i->first.c_str());
      for(unsigned a=0; a<i->second.size();a++){
        if(a==0){out += (i->second)[0];}
        else    {out += ","; out+=(i->second)[a];}
      }
      out += "}\n";
    }
  }

  // Maps for maps (key int) of basics variables
  if(pMiBool_.size()){
    out += "##> Type: map<int,bool>\n";
    for(map<string,map<int,bool> >::iterator i=pMiBool_.begin(); i!=pMiBool_.end(); i++){
      out += Form("%s: {\n",i->first.c_str());
      for(map<int,bool>::iterator a=i->second.begin(); a!=i->second.end();a++){
        Form("  %d = %d\n",a->first,a->second);
      }
      out += "}\n";
    }
  }
  if(pMiInt_.size()){
    out += "##> Type: map<int,int>\n";
    for(map<string,map<int,int> >::iterator i=pMiInt_.begin(); i!=pMiInt_.end(); i++){
      out += Form("%s: {\n",i->first.c_str());
      for(map<int,int>::iterator a=i->second.begin(); a!=i->second.end();a++){
        Form("  %d = %d\n",a->first,a->second);
      }
      out += "}\n";
    }
  }
  if(pMiFloat_.size()){
    out += "##> Type: map<int,float>\n";
    for(map<string,map<int,float> >::iterator i=pMiFloat_.begin(); i!=pMiFloat_.end(); i++){
      out += Form("%s: {\n",i->first.c_str());
      for(map<int,float>::iterator a=i->second.begin(); a!=i->second.end();a++){
        Form("  %d = %f\n",a->first,a->second);
      }
      out += "}\n";
    }
  }
  if(pMiDouble_.size()){
    out += "##> Type: map<int,double>\n";
    for(map<string,map<int,double> >::iterator i=pMiDouble_.begin(); i!=pMiDouble_.end(); i++){
      out += Form("%s: {\n",i->first.c_str());
      for(map<int,double>::iterator a=i->second.begin(); a!=i->second.end();a++){
        Form("  %d = %f\n",a->first,a->second);
      }
      out += "}\n";
    }
  }
  if(pMiString_.size()){
    out += "##> Type: map<int,string>\n";
    for(map<string,map<int,string> >::iterator i=pMiString_.begin(); i!=pMiString_.end(); i++){
      out += Form("%s: {\n",i->first.c_str());
      for(map<int,string>::iterator a=i->second.begin(); a!=i->second.end();a++){
        Form("  %d = %s\n",a->first,a->second.c_str());
      }
      out += "}\n";
    }
  }

  // Maps for maps (key string) of basics variables
  if(pMsBool_.size()){
    out += "##> Type: map<string,bool>\n";
    for(map<string,map<string,bool> >::iterator i=pMsBool_.begin(); i!=pMsBool_.end(); i++){
      out += Form("%s: {\n",i->first.c_str());
      for(map<string,bool>::iterator a=i->second.begin(); a!=i->second.end();a++){
        Form("  %s = %d\n",a->first.c_str(),a->second);
      }
      out += "}\n";
    }
  }
  if(pMsInt_.size()){
    out += "##> Type: map<string,int>\n";
    for(map<string,map<string,int> >::iterator i=pMsInt_.begin(); i!=pMsInt_.end(); i++){
      out += Form("%s: {\n",i->first.c_str());
      for(map<string,int>::iterator a=i->second.begin(); a!=i->second.end();a++){
        Form("  %s = %d\n",a->first.c_str(),a->second);
      }
      out += "}\n";
    }
  }
  if(pMsFloat_.size()){
    out += "##> Type: map<int,float>\n";
    for(map<string,map<string,float> >::iterator i=pMsFloat_.begin(); i!=pMsFloat_.end(); i++){
      out += Form("%s: {\n",i->first.c_str());
      for(map<string,float>::iterator a=i->second.begin(); a!=i->second.end();a++){
        Form("  %s = %f\n",a->first.c_str(),a->second);
      }
      out += "}\n";
    }
  }
  if(pMsDouble_.size()){
    out += "##> Type: map<string,double>\n";
    for(map<string,map<string,double> >::iterator i=pMsDouble_.begin(); i!=pMsDouble_.end(); i++){
      out += Form("%s: {\n",i->first.c_str());
      for(map<string,double>::iterator a=i->second.begin(); a!=i->second.end();a++){
        Form("  %s = %f\n",a->first.c_str(),a->second);
      }
      out += "}\n";
    }
  }
  if(pMsString_.size()){
    out += "##> Type: map<string,string>\n";
    for(map<string,map<string,string> >::iterator i=pMsString_.begin(); i!=pMsString_.end(); i++){
      out += Form("%s: {\n",i->first.c_str());
      for(map<string,string>::iterator a=i->second.begin(); a!=i->second.end();a++){
        Form("  %s = %s\n",a->first.c_str(),a->second.c_str());
      }
      out += "}\n";
    }
  }

  return out;
  
}
