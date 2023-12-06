//
// Created by 28678 on 2023/12/5.
//

#include <glog/logging.h>
#include <gtest/gtest.h>


#include <numeric>
TEST(std,accumulate){
    std::vector<int> v{1,2,3,4,5};
    int res;
    res = std::accumulate(v.begin(),v.end(),0);
    LOG(INFO) << "计算1累加到5,返回值res: " << res;
    res = std::accumulate(v.begin(),v.end(),10);
    LOG(INFO) << "计算1累加到5,并且初始值为10,res: " << res;

    // 使用 lambda 表达式定义乘法操作
    auto multiplication = [](int x, int y) { return x * y; };
    // 使用 accumulate 进行乘法累积
    res = std::accumulate(v.begin(), v.end(), 1, multiplication);
    LOG(INFO) << "计算1累乘到5,res: " << res;
    res = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    LOG(INFO) << "计算1累乘到5,使用标准库自带的仿函数,res: " << res;
    /**
     * multiplies需要指定模板类型
     * C++17之后可以自动推导
     * 函数模板参数以及类模板参数自动推导
     * */
    //res = std::accumulate(v.begin(), v.end(), 1, std::multiplies());

    res = std::accumulate(v.begin(), v.end(), 2, multiplication);
    LOG(INFO) << "计算1累乘到5,初始值为2,res: " << res;

}