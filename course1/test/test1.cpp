//
// Created by fss on 23-5-28.
//
#include <armadillo>
#include <glog/logging.h>
#include <gtest/gtest.h>

TEST(test_arma, add) { /// 加法
  using namespace arma;
  fmat in_matrix1 = "1,2,3;"
                    "4,5,6;"
                    "7,8,9";

  fmat in_matrix2 = "1,2,3;"
                    "4,5,6;"
                    "7,8,9";

  const fmat &out_matrix1 = "2,4,6;"
                            "8,10,12;"
                            "14,16,18";

  const fmat &out_matrix2 = in_matrix1 + in_matrix2;
  ASSERT_EQ(approx_equal(out_matrix1, out_matrix2, "absdiff", 1e-5), true);
}

TEST(test_arma, sub) { /// 减法
  using namespace arma;
  fmat in_matrix1 = "1,2,3;"
                    "4,5,6;"
                    "7,8,9";

  fmat in_matrix2 = "1,2,3;"
                    "4,5,6;"
                    "7,8,9";

  const fmat &out_matrix1 = "0,0,0;"
                            "0,0,0;"
                            "0,0,0;";

  const fmat &out_matrix2 = in_matrix1 - in_matrix2;
  ASSERT_EQ(approx_equal(out_matrix1, out_matrix2, "absdiff", 1e-5), true);
}

TEST(test_arma, matmul) { // 矩阵乘法
  using namespace arma;
  fmat in_matrix1 = "1,2,3;"
                    "4,5,6;"
                    "7,8,9";

  fmat in_matrix2 = "1,2,3;"
                    "4,5,6;"
                    "7,8,9";

  const fmat &out_matrix1 = "30,36,42;"
                            "66,81,96;"
                            "102,126,150;";

  const fmat &out_matrix2 = in_matrix1 * in_matrix2;
  ASSERT_EQ(approx_equal(out_matrix1, out_matrix2, "absdiff", 1e-5), true);
}

TEST(test_arma, pointwise) { ///< 点乘
  using namespace arma;
  fmat in_matrix1 = "1,2,3;"
                    "4,5,6;"
                    "7,8,9";

  fmat in_matrix2 = "1,2,3;"
                    "4,5,6;"
                    "7,8,9";

  const fmat &out_matrix1 = "1,4,9;"
                            "16,25,36;"
                            "49,64,81;";

  const fmat &out_matrix2 = in_matrix1 % in_matrix2;
  ASSERT_EQ(approx_equal(out_matrix1, out_matrix2, "absdiff", 1e-5), true);
}