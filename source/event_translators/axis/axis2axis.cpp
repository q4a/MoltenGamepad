#include "axis2axis.h"
#include "../event_translator_macros.h"

const MGType axis2axis::fields[] = { MG_AXIS, MG_INT, MG_NULL };
axis2axis::axis2axis(std::vector<MGField>& fields) {
  BEGIN_READ_DEF;
  READ_AXIS(out_axis);
  READ_INT(direction);
}
void axis2axis::fill_def(MGTransDef& def) {
  BEGIN_FILL_DEF("axis2axis");
  FILL_DEF_AXIS(out_axis);
  FILL_DEF_INT(direction);
}
