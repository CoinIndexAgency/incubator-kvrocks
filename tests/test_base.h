#ifndef KVROCKS_TEST_BASE_H
#define KVROCKS_TEST_BASE_H

#include <gtest/gtest.h>

#include "t_hash.h"

class TestBase : public testing::Test {
protected:
  explicit TestBase() {
    storage_ = new Engine::Storage("testsdb", "testsdb_backup");
    rocksdb::Options opts;
    opts.create_if_missing = true;
    Status s = storage_->Open();
    assert(s.IsOK());
  }
  ~TestBase() override {
    rmdir("testsdb");
    delete storage_;
  }

protected:
  Engine::Storage *storage_;
  Slice key_;
  std::vector<Slice> fields_;
  std::vector<Slice> values_;
};
#endif //KVROCKS_TEST_BASE_H