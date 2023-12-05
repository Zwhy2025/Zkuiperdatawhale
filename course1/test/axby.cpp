//
// Created by fss on 23-5-28.
//
#include <armadillo>
#include <glog/logging.h>
#include <gtest/gtest.h>


void Axby(const arma::fmat &x, const arma::fmat &w, const arma::fmat &b,
          arma::fmat &y) {
    // 把代码写这里 完成y = w * x + b的运算
    y = w * x + b;                          ///<  重载*用于矩阵乘法
    y.print();                          ///<  打印方法
    y.print("pirnt A：");  ///<  可携带文本
}

TEST(test_arma, Axby) {
    using namespace arma;
    fmat w = "1,2,3;"
             "4,5,6;"
             "7,8,9;";

    fmat x = "1,2,3;"
             "4,5,6;"
             "7,8,9;";

    fmat b = "1,1,1;"
             "2,2,2;"
             "3,3,3;";

    fmat answer = "31,37,43;"
                  "68,83,98;"
                  "105,129,153";

    fmat y;
    Axby(x, w, b, y);
    ASSERT_EQ(approx_equal(y, answer, "absdiff", 1e-5f), true);
}

void EPowerMinus(const arma::fmat &x, arma::fmat &y) {
    // 把代码写这里 完成y = e^{-x}的运算
    y = arma::exp(-x);
}

TEST(test_arma, e_power_minus) {
    using namespace arma;

    fmat x(22400, 2240);               ///< 224*224的矩阵
    x.randu();                                            ///< 随机初始化

    fmat y;
    EPowerMinus(x, y);

    /** 构造数组，从x.mem指针开始，复制224*224个数据到x1中 */
    std::vector<float> x1(x.mem, x.mem + 224 * 224);        ///< 其中，mem是armadillo中的一个指针，指向矩阵的第一个元素，内存是连续的
    ASSERT_EQ(y.empty(), false);                                      ///< 判断y是否为空
    for (int i = 0; i < 224 * 224; ++i) {
        /** 判断y中的每个元素是否与exp(-x)相等   */
        /** ASSERT_LE是判断两个数的差值是否小于1e-5 ASSERT_EQ是判断两个数是否相等 */
        ASSERT_LE(std::abs(std::exp(-x1.at(i)) - y.at(i)), 1e-5f);    ///< 其中矩阵是连续访问的，所以可以用at(i)来访问，也可以用mem[i]来访问
    }
}

void Axpy(const arma::fmat &x, arma::fmat &Y, float a, float y) {
    // 编写Y = a * x + y
    Y = a * x + y;  ///<虽然a是浮点数，但是armadillo会自动转换为矩阵
}

TEST(test_arma, axpy) {
    using namespace arma;
    fmat x(224, 224);
    x.randu();

    fmat Y;
    float a = 3.f;
    float y = 4.f;
    Axpy(x, Y, a, y);

    ASSERT_EQ(Y.empty(), false);
    std::vector<float> x1(x.mem, x.mem + 224 * 224);
    for (int i = 0; i < 224 * 224; ++i) {
        ASSERT_LE(std::abs(x.at(i) * a + y - Y.at(i)), 1e-5f);
    }
}