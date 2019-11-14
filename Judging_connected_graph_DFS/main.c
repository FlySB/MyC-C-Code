#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxVnum 100
typedef int ArcInfo;
typedef int VexType;

//边结点
typedef struct ArcNode{
    int Vex;
    struct ArcNode *nextArc;
    //ArcInfo info;
}ArcNode;

//顶点
typedef struct VexNode{
    VexType data;
    ArcNode *firstarc;
}VexNode;

//邻接表
typedef struct{
    VexNode Vex[MaxVnum];
    int Vexnum, Arcnum;
}ALGraph;

//建表
void CreateUDG(ALGraph *G){
    printf("请输入顶点个数：");
    scanf("%d", &G->Vexnum);
    printf("请输入边的个数：");
    scanf("%d", &G->Arcnum);
    for(int i = 0; i < G->Vexnum; i++){
        G->Vex[i].firstarc = NULL;
    }
    for(int j = 0; j < G->Arcnum; j++){
        printf("请输入第%d条边的两个顶点：",j+1);
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        ArcNode *p1;
        p1 =(ArcNode*)malloc(sizeof(ArcNode));
        p1->Vex = v1;
        p1->nextArc = G->Vex[v2].firstarc;
        G->Vex[v2].firstarc = p1;

        ArcNode *p2;
        p2 = (ArcNode*)malloc(sizeof(ArcNode));
        p2->Vex = v2;
        p2->nextArc = G->Vex[v1].firstarc;
        G->Vex[v1].firstarc = p2;

    }

}

//DFS遍历
int JudgeCG(ALGraph *G, int vist[], int v){
    vist[v] = 1;
    ArcNode *p;
    p = G->Vex[v].firstarc;
    while (p != NULL){
        int w = p->Vex;
        if(vist[w] == 0) JudgeCG(G,vist,w);
        p = p->nextArc;
    }
}

//邻接表输出
void OutUDG(ALGraph *G){
    ArcNode* p;
    for(int i = 1; i <= G->Vexnum; i++){
        p = G->Vex[i].firstarc;
        printf("%d:",i);
        while (p != NULL){
            printf("%d\t",p->Vex);
            p = p->nextArc;
        }
        printf("\n");
    }
}

//通过DFS遍历节点标注vist判断无向图是否连通
void Judge(ALGraph *G, int vist[]){
    for(int i=1; i <= G->Vexnum; i++){
        if(vist[i] == 0){
            printf("不连通\n");
            return;
        }
    }
    printf("连通\n");
}


int main() {
    ALGraph *G;
    G = (ALGraph*)malloc(sizeof(ALGraph));
    CreateUDG(G);

    printf("\n------------------------------\n");
    printf("邻接表：\n");
    OutUDG(G);
    int vist[G->Vexnum+1];
    memset(vist, 0, sizeof(vist));
    JudgeCG(G,vist,1);
    printf("\n------------------------------\n");
    printf("连接状态：");
    Judge(G,vist);
    return 0;
}