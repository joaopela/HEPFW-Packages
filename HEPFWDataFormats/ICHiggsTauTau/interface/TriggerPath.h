#ifndef ICHiggsTauTau_TriggerPath
#define ICHiggsTauTau_TriggerPath

#include "Rtypes.h"
#include <string>
#include <vector>
#include <iostream>

namespace ic {

  class TriggerPath {

  public:
    TriggerPath();
    virtual ~TriggerPath();

    inline std::string const& name() const { return name_; }
    inline void set_name(std::string const& name) { name_ = name; }

    inline bool accept() const { return accept_; }
    inline void set_accept(bool const& accept) { accept_ = accept; }

    inline unsigned prescale() const { return prescale_; }
    inline void set_prescale(unsigned const& prescale) { prescale_ = prescale; }

    inline std::size_t id() const { return id_; }
    inline void set_id(std::size_t const& id) { id_ = id; }

    virtual void Print() const;


private:
      std::string   name_;
      bool          accept_;
      unsigned      prescale_;
      unsigned long id_;

  public:
    ClassDef(TriggerPath,1);
};

  typedef std::vector<ic::TriggerPath> TriggerPathCollection;
  typedef std::vector<ic::TriggerPath *> TriggerPathPtrVec;

}
#endif
