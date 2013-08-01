#ifndef CPLUSPLUSFS_CPLUSPLUSFS_STATUS_H_
#define CPLUSPLUSFS_CPLUSPLUSFS_STATUS_H_

#include <cstdint>

#include <string>
#include <vector>

namespace cplusplusfs {

class Status {
public:
  Status(bool succeed, uint32_t error = 0) : bit_field_(static_cast<uint32_t>(succeed) << (32 - 1)  | error) {}

  Status(const Status&) = default;
  Status(Status&&) = default;


  operator bool() const { return static_cast<bool>(bit_field_ >> (32 - 1)); };

  uint32_t   ErrorNumber() const { return bit_field_ << 1 >> 1; }
  const std::string &ErrorMessage() const {
    return Status::error_messages[index_undefined_error_ +
                                  (ErrorNumber() < error_messages.size()) *
                                  (ErrorNumber() - index_undefined_error_)]; }

private:
  const uint32_t bit_field_;

  static const std::vector<std::string> error_messages;
  static constexpr uint32_t index_undefined_error_ = 1;
};

}

#endif  // CPLUSPLUSFS_CPLUSPLUSFS_STATUS_H_
