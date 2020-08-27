#include <iostream>
using namespace std;

int main()
{
    double x;
    scanf("%lf", &x); //如果写成scanf("%f", &x)就会报错,因为这时候x就不是浮点数了
    
    double l = -100, r = 100;
    while(r - l > 1e-8) //因为题目要求精确到-6次方,所以这里再减小两位小数
    {
        double mid = (r - l)/2 + l;
        if(mid * mid * mid >= x) r = mid; //说明mid^3 >= x,应该往左找
        else l = mid; //因为是浮点,所以依旧是=mid
    }
    printf("%.6lf",l);
    return 0;
}