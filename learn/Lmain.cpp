//
// Created by fss on 23-5-27.
//

#include <gtest/gtest.h>
#include <glog/logging.h>

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  google::InitGoogleLogging("Learn");
  FLAGS_log_dir = "../../learn/log";
  FLAGS_alsologtostderr = true;
  LOG(INFO) << "Start test......\n";
  return RUN_ALL_TESTS();
}