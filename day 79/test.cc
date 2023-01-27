

// 衡量人体胖瘦程度
// 链接：https://www.nowcoder.com/questionTerminal/4d604603fae94a26b59b7bc18f363bc0
// 来源：牛客网

// 在计算BMI（BodyMassIndex ，身体质量指数）的案例基础上，判断人体胖瘦程度。BMI中国标准如下表所示。




// 输入描述:

// 多组输入，每一行包括两个整数，用空格隔开，分别为体重（公斤）和身高（厘米）。



// 输出描述:

// 针对每行输入，输出为一行，人体胖瘦程度，即分类。

// 示例1
// 输入

// 80 170
// 60 170
// 90 160
// 50 185

// 输出

// Overweight
// Normal
// Obese
// Underweight


#include<stdio.h>

int main()
{
    int weight = 0;
    float high = 0;
    
    float BMI = 0;
    
    while((scanf("%d %f",&weight,&high)) != EOF)
    {
        BMI = weight/(high/100 * high/100);
        
        if(BMI < 18.5)
            printf("Underweight\n");
        else if(BMI > 27.9)
            printf("Obese\n");
        else if(BMI > 23.9 && BMI <= 27.9)
            printf("Overweight\n");
        else
            printf("Normal\n");
    }
    
    
    
    
    
    return 0;
}