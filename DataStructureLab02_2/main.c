#include <stdio.h>
#include <string.h>

#define SIZE 100
#define INF 999999999

int m[SIZE];		//存放矩阵链的行列信息，m[i-1]和m[i]分别为第i个矩阵的行和列（i = 1、2、3...）
int d[SIZE][SIZE];	//存放矩阵链计算的最优值，d[i][j]为第i个矩阵到第j个矩阵的矩阵链的最优值，i > 0

int Best_DP(int n)
{
    //把d[i][i]置为0，1 <= i < n
    memset(d, 0, sizeof(d));

    int len;
    //递归计算矩阵链的连乘最优值
    //len = 1，代表矩阵链由两个矩阵构成
    for (len = 1; len < n; len++)
    {
        int i, j, k;
        for (i = 1, j = i+len; j < n; i++, j++)
        {
            int min = INF; //无穷大
            for (k = i; k < j; k++)
            {
                printf("i:%d j:%d k:%d\n",i,j,k);
                int count = d[i][k] + d[k+1][j] + m[i-1] * m[k] * m[j];
                printf("c:%d\n",count);
                if (count < min)
                {
                    min = count;
                    printf("m:%d\n",min);
                }
            }
            printf("k:%d\n",k);
            printf("i:%d j:%d\n",i,j);
            d[i][j] = min;
            printf("hhhh\n");
        }
        printf("pppp\n");
    }
    return d[1][n-1];
}

int main()
{
    int n;

    while (1) {
        printf("请输入数组长度:");
        scanf("%d",&n);
        if (n >= 1) {
            int i;
            for (i = 0; i < n; i++) {
                scanf("%d", &m[i]);
            }

            printf("最少乘法次数为：%d\n", Best_DP(n));
            break;
        } else{
            printf("请输入大于0的整数\n");
        }
    }
    return 0;
}