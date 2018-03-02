
#ifndef OSCILLATOR_HPP
#define OSCILLATOR_HPP

#include "common.hpp"
#include "node.hpp"
#include <functional>

class Oscillator : public Node {
  enum InputSockets {
    frequency, amplitude, offset, param
  };
  enum Properties {
    oscillation_func
  };
  
  // Persistent state
  std::vector<SigT> bundles;
  
  // Runtime intermediary variables
  AudioData::PolyList states;

  typedef std::function<SigT(SigT, SigT)> OscillationFunc;
  typedef std::vector<OscillationFunc> OscillationFuncList;
  const static OscillationFuncList oscillation_funcs;
  public:
  Oscillator();
  void reset_state();
  Universe::Descriptor infer_polyphony_operation(std::vector<Universe::Pointer>);
  void apply_bundle_universe_changes(const Universe&);
  void process(NodeInputWindow&);
};

#endif
