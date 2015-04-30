#include "DataFormats/ICHiggsTauTau/interface/Track.h"

namespace ic {
  //Constructors/Destructors
  Track::Track() : momentum_(ThreeVector()), ref_point_(Point()), id_(0), charge_(0) {
  }

  Track::~Track() {
  }

  void Track::Print() const {
    std::cout << momentum_ << std::endl;
    std::cout << ref_point_ << std::endl;
  }
}
