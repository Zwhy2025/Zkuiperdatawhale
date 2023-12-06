//
// Created by fss on 23-6-4.
//
#include "data/tensor.hpp"
#include <glog/logging.h>
#include <gtest/gtest.h>


TEST(test_fill_reshape, reshape1) {
    using namespace kuiper_infer;
    LOG(INFO) << "-------------------Reshape-------------------";
    Tensor<float> f1(2, 3, 4);
    std::vector<float> values(2 * 3 * 4);
    // 将1到12填充到values中
    for (int i = 0; i < 24; ++i) {
        values.at(i) = float(i + 1);
    }
    f1.Show();
    f1.Fill(values, false);
    /// 将大小调整为(4, 3, 2)
    f1.Reshape({4, 3, 2},false);
    LOG(INFO) << "-------------------After Reshape-------------------";
    f1.Show();
}





TEST(test_fill_reshape, fill1) {
    using namespace kuiper_infer;
    Tensor<float> f1(2, 3, 4);
    std::vector<float> values(2 * 3 * 4);
    // 将1到12填充到values中
    for (int i = 0; i < 24; ++i) {
        values.at(i) = float(i + 1);
    }
    f1.Fill(values);
    LOG(INFO) << "------------------- after Fill-------------------";
    f1.Show();

    LOG(INFO) << "-------------------before Fill-------------------";
    arma::cube notous;
    notous.set_size(3, 4, 2);
    std::copy(values.begin(), values.end(), notous.memptr());
    notous.print("notous");
    /**  有一说一这个库是真的奇怪 */
}

