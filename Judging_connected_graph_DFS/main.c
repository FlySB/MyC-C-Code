#include <stdio.h>

#define MaxVnum 100
typedef int ArcInfo;
typedef int VexType;

typedef struct ArcNode{
    int Vex;
    struct ArcNode *nextArc;
    //ArcInfo info;
}ArcNode;

typedef struct VexNode{
    VexType data;
    ArcNode *firstarc;
}VexNode;

typedef struct{
    VexNode Vex[MaxVnum];
    int Vexnum, Arcnum;
}ALGraph;

void CreateUDG(ALGraph *G){
    printf("请输入顶点个数：");
    scanf("%d", &G->Vexnum);
    printf("请输入边的个数：");
    scanf("%d", &G->Arcnum);
    for(int i = 0; i < G->Vexnum; i++){
        G->Vex[i].firstarc = NULL;
    }
    for(int j = 0; j < G->Arcnum; j++){
        printf("请输入第%d条边的两个顶点：");
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        ArcNode *p1;
        p1->Vex = v1;
        p1->nextArc = G->Vex[v2].firstarc;
        G->Vex->firstarc = p1;

        ArcNode *p2;
        p2->Vex = v2;
        p2->nextArc = G->Vex[v1].firstarc;
        G->Vex->firstarc = p2;

    }
}

int main() {
    printf("Hello, World!\n");
    return 0;
}