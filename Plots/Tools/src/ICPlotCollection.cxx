#include "Plots/Tools/interface/ICPlotCollection.h"

#include "TLegend.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TH2D.h"

#include <iostream>

using namespace std;

/********************************************//**
 * Defaults constructor for this class
 ***********************************************/
template <class PlotIndex,class PlotType>
ICPlotCollection<PlotIndex,PlotType>::ICPlotCollection(){

  m_drawLegend=false;

}

/********************************************//**
 * Constructor that will take a map of files and a path to a plot,
 * open all files and retrive the plot stored at that path. 
 * @param samples minimum value to be visible on this axis 
 * @param path maximum value to be visible on this axis
 ***********************************************/
template <class PlotIndex,class PlotType>
ICPlotCollection<PlotIndex,PlotType>::ICPlotCollection(map<PlotIndex,TFile*> samples,std::string path){
  
  m_drawLegend=false;
  
  for(typename map<PlotIndex,TFile*>::iterator i=samples.begin(); i!=samples.end(); i++){
    (*this)[i->first] = (PlotType*) i->second->Get(path.c_str());
  } 
}

/********************************************//**
 * Set x-axis user defined range (zooms plot to new range) from min to max
 * @param min minimum value to be visible on this axis 
 * @param max maximum value to be visible on this axis 
 ***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::setXaxisRangeUser(double min,double max){

  // Looping over plots
  for(typename map<PlotIndex,PlotType*>::iterator i=this->begin(); i!=this->end(); i++){
    i->second->GetXaxis()->SetRangeUser(min,max);
  }
}

/********************************************//**
 * Set y-axis title (axis caption) for all plots in this container
 * @param title title to be applied to x-axis of all plots
 ***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::setXaxisTitle(std::string title){

  // Looping over plots
  for(typename map<PlotIndex,PlotType*>::iterator i=this->begin(); i!=this->end(); i++){
    i->second->GetXaxis()->SetTitle(title.c_str());
  }
}

/********************************************//**
 * Set y-axis user defined range (zooms plot to new range) from min to max
 * @param min minimum value to be visible on this axis 
 * @param max maximum value to be visible on this axis 
 ***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::setYaxisRangeUser(double min,double max){

  // Looping over plots
  for(typename map<PlotIndex,PlotType*>::iterator i=this->begin(); i!=this->end(); i++){
    i->second->GetYaxis()->SetRangeUser(min,max);
  }
}

/********************************************//**
 * Set y-axis title (axis caption) for all plots in this container
 * @param title title to be applied to y-axis of all plots
 ***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::setYaxisTitle(std::string title){

  // Looping over plots
  for(typename map<PlotIndex,PlotType*>::iterator i=this->begin(); i!=this->end(); i++){
    i->second->GetYaxis()->SetTitle(title.c_str());
  }
}


/********************************************//**
 * Set fill colour for all plots in this container
 * @param attributes map of colours to be applied to each plot 
 ***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::setFillColor  (std::map<PlotIndex,int> attributes){

  for(typename std::map<PlotIndex,int>::iterator i=attributes.begin(); i!=attributes.end(); i++){
    if((*this)[i->first])

    (*this)[i->first]->SetFillColor(i->second);
  }
}

/********************************************//**
* Set fill style for all plots in this container
* @param attributes map of styles to be applied to each plot 
***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::setFillStyle  (std::map<PlotIndex,int> attributes){

  for(typename std::map<PlotIndex,int>::iterator i=attributes.begin(); i!=attributes.end(); i++){
    (*this)[i->first]->SetFillStyle(i->second);
  }
}

/********************************************//**
* Set marker colour for all plots in this container
* @param attributes map of colours to be applied to each plot markers 
***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::setMarkerColor(std::map<PlotIndex,int> attributes){

  for(typename std::map<PlotIndex,int>::iterator i=attributes.begin(); i!=attributes.end(); i++){
    (*this)[i->first]->SetMarkerColor(i->second);
  }
}

/********************************************//**
* Set marker style for all plots in this container
* @param attributes map of styles to be applied to each plot markers 
***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::setMarkerStyle(std::map<PlotIndex,int> attributes){

  for(typename std::map<PlotIndex,int>::iterator i=attributes.begin(); i!=attributes.end(); i++){
    (*this)[i->first]->SetMarkerStyle(i->second);
  }
}

/********************************************//**
 * Set marker size for all plots in this container
 * @param attributes map of sizes to be applied to each plot markers 
 ***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::setMarkerSize(std::map<PlotIndex,int> attributes){
  
  for(typename std::map<PlotIndex,int>::iterator i=attributes.begin(); i!=attributes.end(); i++){
    (*this)[i->first]->SetMarkerSize(i->second);
  }
}

/********************************************//**
 * Passing legend text and option to be draw when calling draw(...)
 * @param legend map of sizes to be applied to each plot markers
 * @param options options of each entry of the legend 
 ***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::setLegend(std::map<PlotIndex,std::string> legend,
                                                     std::map<PlotIndex,std::string> options){

  m_drawLegend    = true;
  m_legendText    = legend;
  m_legendOptions = options;
}

/********************************************//**
 * Call Sumw2() method on all plots
 ***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::sumw2(){

  // Looping over plots
  for(typename map<PlotIndex,PlotType*>::iterator i=this->begin(); i!=this->end(); i++){
    i->second->Sumw2();
  }
}

/********************************************//**
 * Scale all plots by a factor
 * @param factor factor to multiply all plots
 ***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::scale(double factor){

  // Looping over plots
  for(typename map<PlotIndex,PlotType*>::iterator i=this->begin(); i!=this->end(); i++){
    i->second->Scale(factor);
  }
}



/********************************************//**
 * Scale plots according to an input map of factors
 * @param factors maps of factors indexed by keys to indicate to which plot they should be applied
 ***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::scale(map<PlotIndex,double> factors){
  
  // Looping over plots
  for(typename map<PlotIndex,double>::iterator i=factors.begin(); i!=factors.end(); i++){

    // Protection for when factors have elements not present in this map
    if(this->find(i->first) != this->end()){
      (*this)[i->first]->Scale(i->second);
    }
  }  
}

/********************************************//**
 * Scale all contained plots to one by using plots built in Integral() function.
 * 
 * NOTE: The Integral() function does not take into account under and overflow bins.  
 ***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::scaleTo1(){

  // Looping over plots
  for(typename map<PlotIndex,PlotType*>::iterator i=this->begin(); i!=this->end(); i++){
    i->second->Scale(1/i->second->Integral());
  }
}

/********************************************//**
* Rebin all contained plots according to an input map of factors
* @param factor factor to be used to rebin plots
***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::rebin(int factor){
  // Looping over plots
  for(typename map<PlotIndex,PlotType*>::iterator i=this->begin(); i!=this->end(); i++){
    i->second->Rebin(factor);
  }
}

/********************************************//**
* Create and return new plots by adding a set of contained plots
* @param name name for the output plots
* @param selection vector with the identifiers of the plots to be added and returned 
* @return plot resulting from adding all plots found on this contained matching the identifiers on the selection
***********************************************/
template <class PlotIndex,class PlotType>
PlotType* ICPlotCollection<PlotIndex,PlotType>::getMerged(string name, vector<PlotIndex> selection){
  
  PlotType* out = NULL;  
  
  if(selection.size()==0){return out;}
  
  int counter=0;
  
  for(unsigned i=0; i<selection.size(); i++){
    
    // Protection for when asking to merge elements not present on this map 
    if(this->find(selection[i]) != this->end()){
    
      if(counter==0){
        out = (PlotType*) (*this)[selection[i]]->Clone("name");
        counter++;
      }else{
        out->Add((*this)[selection[i]]);
      }
      
    }else{
      cout << "Could not find plots with identifier: " << selection[i] << endl;
    }
  }
  
  return out;
}

/********************************************//**
* Draw a subset of plots in this contained into an input TCanvas.
* 
* This method will take in a TCanvas pointer and draw in it histograms from
* this container following the order and with the attributes present in the
* input variable histograms.
* 
* Vertical axis user range will automatically be set to 125% of the maximum
* value of any selected plot. This is to avoid plots being plotted out of bounds.
* 
* If defined legends will be draw on the top right corner.
* 
* @param canv input TCanvas where plots will be draw
* @param histograms vector of pairs of (index,draw histograms) to be used on drawing.    
* @return plot resulting from adding all plots found on this contained matching the identifiers on the selection
***********************************************/
template <class PlotIndex,class PlotType>
void ICPlotCollection<PlotIndex,PlotType>::draw(TCanvas *canv, std::vector< std::pair<PlotIndex,Option_t*> > histograms){

  double minValue=0;
  double maxValue=0;
  TLegend *l;

  // Loping over all the histograms to be drawn
  for(unsigned i=0; i<histograms.size(); i++){
    PlotType *plot = (*this)[histograms[i].first];

    if(i==0){
      minValue=plot->GetBinContent(plot->GetMinimumBin());
      maxValue=plot->GetBinContent(plot->GetMaximumBin());
    }
    else{
      double tMin = plot->GetBinContent(plot->GetMinimumBin());
      double tMax = plot->GetBinContent(plot->GetMaximumBin());
      if(tMin<minValue){minValue = tMin;}
      if(tMax>maxValue){maxValue = tMax;}
    }
  }

  // Updating the vertical
  setYaxisRangeUser(0,maxValue*1.25);

  // Selecting input canvas for drawing
  canv->cd();

  if(m_drawLegend && m_legendText.size()==m_legendOptions.size()){
   
    l = new TLegend(0.7,0.75,0.9,0.85);
    
    for(unsigned i=0; i<histograms.size(); i++){
      (*this)[histograms[i].first]->Draw(histograms[i].second);
      
      if(m_drawLegend){
        l->AddEntry((*this)[histograms[i].first],m_legendText[histograms[i].first].c_str(),m_legendOptions[histograms[i].first].c_str());
      }
    }
    
    l->Draw();    
  }
}

//The explicit instantiating part
template class ICPlotCollection<int,TH1I>;
template class ICPlotCollection<int,TH1F>;
template class ICPlotCollection<int,TH1D>;
template class ICPlotCollection<int,TH2I>;
template class ICPlotCollection<int,TH2F>;
template class ICPlotCollection<int,TH2D>;

template class ICPlotCollection<string,TH1I>;
template class ICPlotCollection<string,TH1F>;
template class ICPlotCollection<string,TH1D>;
template class ICPlotCollection<string,TH2I>;
template class ICPlotCollection<string,TH2F>;
template class ICPlotCollection<string,TH2D>;