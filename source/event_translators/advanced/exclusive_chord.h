#pragma once
#include "../event_change.h"
#include "simple_chord.h"

class exclusive_chord : public simple_chord {
public:

  exclusive_chord(std::vector<std::string> event_names, event_translator* trans) : simple_chord(event_names, trans) {};

  volatile std::thread* thread = nullptr;
  std::vector<int> chord_hits;

  virtual void init(input_source* source);
  virtual bool claim_event(int id, mg_ev event);
  virtual advanced_event_translator* clone() {
    return new exclusive_chord(event_names, out_trans->clone());
  }

  void thread_func();
  volatile bool thread_active;

  static const MGType fields[];
  exclusive_chord(std::vector<std::string> event_names, std::vector<MGField>& fields);
  virtual void fill_def(MGTransDef& def);
};
