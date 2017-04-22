#include "operator/concat_op.h"

namespace oneflow {

void ConcatOp::Init(const OperatorConf& op_conf) {
  mut_op_name() = op_conf.name();

  CHECK(op_conf.has_concat_conf());
  auto cnf = new ConcatOpConf(op_conf.concat_conf());
  mut_pb_op_conf().reset(cnf);

  for (int i = 0; i < cnf->in_size(); ++i) {
    std::string ibn = "in_" + std::to_string(i);
    EnrollInputBn(ibn);
    CHECK(ibn2lbn_.emplace(ibn, cnf->in(i)).second);
  }
  EnrollOutputBn("out");
}

} // namespace oneflow
