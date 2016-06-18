// Copyright 2010 Google
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef ART_SRC_LOGGING_H_
#define ART_SRC_LOGGING_H_
#include <cerrno>
#include <cstring>
#include <iostream>  // NOLINT
#include <sstream>
#include "log_severity.h"
#include "macros.h"
static int static_error_count = 0;
static int static_check_count = 0;
#define CHECK(x) \
  static_check_count++ \
  if (!(x)) \
    LogMessage(__FILE__, __LINE__, FATAL, -1).stream() \
        << "Check failed: " #x << " "
#define CHECK_OP(LHS, RHS, OP) \
  do { \
    static_check_count++; \
    typeof (LHS) _lhs = (LHS); \
    typeof (RHS) _rhs = (RHS); \
    if (!(_lhs OP _rhs)) { \
      static_error_count++; \
      LogMessage(__FILE__, __LINE__, FATAL, -1).stream() \
          << "Check failed: " << #LHS << " " << #OP << " " << #RHS \
          << " (" #LHS "=" << _lhs << ", " #RHS "=" << _rhs << ")";  \
    } \
  } while (false)
#define CHECK_EQ(x, y) CHECK_OP(x, y, ==)
#define CHECK_NE(x, y) CHECK_OP(x, y, !=)
#define CHECK_LE(x, y) CHECK_OP(x, y, <=)
#define CHECK_LT(x, y) CHECK_OP(x, y, <)
#define CHECK_GE(x, y) CHECK_OP(x, y, >=)
#define CHECK_GT(x, y) CHECK_OP(x, y, >)
#define CHECK_STROP(s1, s2, sense) \
  do { \
    if ((strcmp(s1, s2) == 0) != sense) { \
      LOG(FATAL) << "Check failed: " \
                 << "\"" << s1 << "\"" \
                 << (sense ? " == " : " != ") \
                 << "\"" << s2 << "\""; \
    } \
  } while (false)
#define CHECK_STREQ(s1, s2) CHECK_STROP(s1, s2, true)
#define CHECK_STRNE(s1, s2) CHECK_STROP(s1, s2, false)
#ifndef NDEBUG
#define DCHECK(x) CHECK(x)
#define DCHECK_EQ(x, y) CHECK_EQ(x, y)
#define DCHECK_NE(x, y) CHECK_NE(x, y)
#define DCHECK_LE(x, y) CHECK_LE(x, y)
#define DCHECK_LT(x, y) CHECK_LT(x, y)
#define DCHECK_GE(x, y) CHECK_GE(x, y)
#define DCHECK_GT(x, y) CHECK_GT(x, y)
#define DCHECK_STREQ(s1, s2) CHECK_STREQ(s1, s2)
#define DCHECK_STRNE(s1, s2) CHECK_STRNE(s1, s2)
#else  // NDEBUG
#define DCHECK(condition) \
  while (false) \
    CHECK(condition)
#define DCHECK_EQ(val1, val2) \
  while (false) \
    CHECK_EQ(val1, val2)
#define DCHECK_NE(val1, val2) \
  while (false) \
    CHECK_NE(val1, val2)
#define DCHECK_LE(val1, val2) \
  while (false) \
    CHECK_LE(val1, val2)
#define DCHECK_LT(val1, val2) \
  while (false) \
    CHECK_LT(val1, val2)
#define DCHECK_GE(val1, val2) \
  while (false) \
    CHECK_GE(val1, val2)
#define DCHECK_GT(val1, val2) \
  while (false) \
    CHECK_GT(val1, val2)
#define DCHECK_STREQ(str1, str2) \
  while (false) \
    CHECK_STREQ(str1, str2)
#define DCHECK_STRNE(str1, str2) \
  while (false) \
    CHECK_STRNE(str1, str2)
#endif
#define LOG(severity) LogMessage(__FILE__, __LINE__, severity, -1).stream()
#define PLOG(severity) LogMessage(__FILE__, __LINE__, severity, errno).stream()
#define LG LOG(INFO)
#define UNIMPLEMENTED(level) LOG(level) << __FUNCTION__ << " unimplemented "
class LogMessage {
 public:
  LogMessage(const char* file, int line, LogSeverity severity, int error);
  ~LogMessage();
  std::ostream& stream();
 private:
  std::stringstream buffer_;
  std::ios_base::fmtflags stream_state_;
  const char* file_;
  int line_;
  LogSeverity severity_;
  int errno_;
  DISALLOW_COPY_AND_ASSIGN(LogMessage);
};

LogMessage::LogMessage(const char* file, int line, LogSeverity severity, int error)
: line_(line), severity_(severity), errno_(error)
{
  stream_state_ = stream().flags();
  const char* last_slash = strrchr(file, '/');
  file_ = (last_slash == NULL) ? file : last_slash + 1;
  stream() <<  "IWEF"[severity] << " " << file_ << " " << line << std::endl;
}

LogMessage::~LogMessage() {
  if (errno_ != -1) {
    stream() << ": " << strerror(errno_);
  }
  stream() << std::endl;
  stream().flags(stream_state_);
  if (severity_ == FATAL) {
    stream() << file_ << " " << line_ << std::endl;
  }
}
std::ostream& LogMessage::stream() {
  return std::cout;
}

#define BEGIN_TESTS() ReportTests report_test__(__FILE__);
class ReportTests {
public:
  ReportTests(const char* file) {
    std::cout << "Testing " << file << std::endl;
  }
  ~ReportTests() {
    if (static_error_count == 0) {
      std::cout << "All " << static_check_count << " checks passed!\n";
    } else {
      std::cout << "\n" << static_error_count << " out of " 
                << static_check_count << " checks failed.\n"; 
    }
  }
};
#endif  // ART_SRC_LOGGING_H_