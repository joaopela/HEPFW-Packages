#include "DataFormats/ICHiggsTauTau/interface/JPTJet.h"

namespace ic {
  // Constructors/Destructors
  JPTJet::JPTJet() {
  }

  JPTJet::~JPTJet() {
  }

  void JPTJet::Print() const {
    Candidate::Print();
  }

  std::vector<std::size_t> JPTJet::constituent_tracks() const {
    unsigned size = pions_in_vtx_in_calo_.size() +
                    pions_in_vtx_out_calo_.size() +
                    pions_out_vtx_in_calo_.size() +
                    muons_in_vtx_in_calo_.size() +
                    muons_in_vtx_out_calo_.size() +
                    muons_out_vtx_in_calo_.size() +
                    elecs_in_vtx_in_calo_.size() +
                    elecs_in_vtx_out_calo_.size() +
                    elecs_out_vtx_in_calo_.size();
    std::vector<std::size_t> trks;
    trks.reserve(size);
    trks.insert(trks.end(),pions_in_vtx_in_calo_.begin(),pions_in_vtx_in_calo_.end());
    trks.insert(trks.end(),pions_in_vtx_out_calo_.begin(),pions_in_vtx_out_calo_.end());
    trks.insert(trks.end(),pions_out_vtx_in_calo_.begin(),pions_out_vtx_in_calo_.end());
    trks.insert(trks.end(),muons_in_vtx_in_calo_.begin(),muons_in_vtx_in_calo_.end());
    trks.insert(trks.end(),muons_in_vtx_out_calo_.begin(),muons_in_vtx_out_calo_.end());
    trks.insert(trks.end(),muons_out_vtx_in_calo_.begin(),muons_out_vtx_in_calo_.end());
    trks.insert(trks.end(),elecs_in_vtx_in_calo_.begin(),elecs_in_vtx_in_calo_.end());
    trks.insert(trks.end(),elecs_in_vtx_out_calo_.begin(),elecs_in_vtx_out_calo_.end());
    trks.insert(trks.end(),elecs_out_vtx_in_calo_.begin(),elecs_out_vtx_in_calo_.end());
    return trks;
  }

}
