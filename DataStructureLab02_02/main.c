#include <stdio.h>
#include <string.h>

#define SIZE 100
#define INF 999999999

int m[SIZE];		//存放矩阵链的行列信息，m[i-1]和m[i]分别为第i个矩阵的行和列（i = 1、2、3...）
int d[SIZE][SIZE];	//存放矩阵链计算的最优值，d[i][j]为第i个矩阵到第j个矩阵的矩阵链的最优值，i > 0
int s[SIZE][SIZE];

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
            s[i][j] = i;
            int min = INF;
            for (k = i; k < j; k++)
            {
                int count = d[i][k] + d[k+1][j] + m[i-1] * m[k] * m[j];
                if (count < min)
                {
                    s[i][j] = k;
                    min = count;
                }
            }
            d[i][j] = min;
        }
    }
    return d[1][n-1];
}

void MatOut(int size,int n[SIZE][SIZE]){

    for(int i = 1; i < size; i++){
        for(int j = 1; j < size; j++){
            printf("%d\t",n[i][j]);
        }
        printf("\n");
    }
}

void FormatOut(int i, int j){
    if(i == j){
        printf("A%d", i);
        return;
    }
    printf("(");
    FormatOut(i,s[i][j]);
    printf(" x ");
    FormatOut(s[i][j] + 1, j);
    printf(")");
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
    MatOut(n,d);
    MatOut(n,s);
    FormatOut(1,n-1);
    return 0;
}