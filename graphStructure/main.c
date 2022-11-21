#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[20];
    struct edge *right;
    struct node *down;
};

struct edge
{
    char name[20];
    int weight;
    struct edge *next;
};




struct node *first = NULL;
struct node *nodeTemp = NULL;
struct node *temp = NULL;


//struct edge *first_edge = NULL;

struct edge *edgeTemp = NULL;
struct edge *iter = NULL;

int weightSum = 0;

struct node *createRoot(char nodeName[20])
{

    struct node *addroot = malloc(sizeof(struct node));
    strcpy(addroot->name,nodeName);
    addroot->right = NULL;
    addroot->down = NULL;
    return addroot;

}
struct edge *createEdge(char edgeName[20],int weight)
{

    struct edge *addedge = malloc(sizeof(struct edge));
    strcpy(addedge->name, edgeName);
    addedge->weight = weight;
    addedge->next = NULL;

    return addedge;
}

int addNode(char nodeName[20],char edgeName[20],int weight)
{
    if(!strcmp(nodeName,edgeName))   // self pathi engelleme kontrolü
    {
        return -1;
    }
    if(first == NULL)
    {
        first = createRoot(nodeName);
        first->right = createEdge(edgeName,weight);
        first->down = createRoot(edgeName);
        first->down->right = createEdge(nodeName,weight);
        return 1;
    }
    else
    {
        temp = first;

        while(temp->down != NULL)  // a b 20 - b a 20 ayný yollarýn bir daha girilmesini engelliyor
        {
            if(!strcmp(temp->name,nodeName) || !strcmp(temp->name,edgeName))
            {
                iter = temp->right;

                while(iter != NULL)
                {
                    if(!strcmp(iter->name,nodeName) || !strcmp(iter->name,edgeName))
                    {
                        return -1;
                    }
                    iter = iter->next;
                }
            }
            temp  = temp->down;
        }

        nodeTemp = first;
        while(nodeTemp!= NULL)
        {
            if(!strcmp(nodeTemp->name,nodeName))
            {
                edgeTemp = nodeTemp->right;
                while(edgeTemp->next != NULL)
                {
                    if(!strcmp(edgeTemp->name,edgeName))
                    {
                        return -1;
                    }
                    else
                    {
                        edgeTemp = edgeTemp->next;
                    }
                }

                edgeTemp->next = createEdge(edgeName,weight);
                temp = nodeTemp;

                while(temp->down != NULL)  // tersini ekleme yeri  (a b 20) = (b a 20) için
                {
                    if(!strcmp(temp->name,edgeName))
                    {
                        temp->down = createRoot(edgeName);
                        iter = temp->right;
                        while(iter->next != NULL)
                        {
                            iter = iter->next;
                        }
                        iter->next = createEdge(nodeName,weight);
                        return 1;
                    }
                    else
                    {
                        temp = temp->down;
                    }
                }

                nodeTemp = first;
                while(nodeTemp->down != NULL)
                {
                    if(!strcmp(nodeTemp->name,edgeName))
                    {
                        edgeTemp=nodeTemp->right;
                        while(edgeTemp->next != NULL)
                        {
                            edgeTemp = edgeTemp->next;
                        }
                        edgeTemp->next = createEdge(nodeName,weight);
                        return 1;
                    }
                    nodeTemp = nodeTemp->down;
                }
                temp->down = createRoot(edgeName);
                temp->down->right = createEdge(nodeName,weight);
                return 1;
            }
            nodeTemp = nodeTemp->down;
        }



        nodeTemp = first;
        while(nodeTemp->down != NULL)  // kod buraya kadar geldiyse öyle bir yol yok demektir hiç olmayan yolu burda ekliyor
        {
            nodeTemp = nodeTemp->down;
        }
        nodeTemp->down = createRoot(nodeName);
        nodeTemp->down->right = createEdge(edgeName,weight);
        nodeTemp->down->down = createRoot(edgeName);
        nodeTemp->down->down->right = createEdge(nodeName,weight);
        nodeTemp =first;

        while(nodeTemp->down != NULL)
        {
            if(!strcmp(nodeTemp->name,edgeName))
            {
                edgeTemp = nodeTemp->right;
                while(edgeTemp->next != NULL)
                {
                    edgeTemp = edgeTemp->next;
                }
                edgeTemp->next = createEdge(nodeName,weight);
                return 1;
            }
            nodeTemp = nodeTemp->down;
        }
    }
};

int isFullGraph()
{
    temp = first;
    int nodeCounter = -1;
    int edgeCounter = 0;
    int graphCounter = 1;

    while(temp!= NULL)
    {
        nodeCounter++;
        temp = temp->down;
    }
    temp = first;
    while(temp != NULL)
    {
        iter = temp->right;
        while(iter != NULL)
        {
            edgeCounter++;
            iter = iter->next;
        }

        if(edgeCounter != nodeCounter)
        {
            graphCounter = 0;
        }
        edgeCounter = 0;
        temp = temp->down;
    }

    if(graphCounter)
    {
        NodeList();
        printf("\nKomple Graphtir\n");
        return 1;
    }
    NodeList();
    printf("\nKomple Graph Degildir\n");
}

void NodeList()
{
    nodeTemp = first;
    while(nodeTemp != NULL)
    {
        edgeTemp = nodeTemp;
        printf("%s",nodeTemp->name);
        while(edgeTemp->next != NULL)
        {
            printf(" -> %s (%d)",edgeTemp->next->name,edgeTemp->next->weight);
            edgeTemp = edgeTemp->next;
        }
        printf("\n");
        nodeTemp = nodeTemp->down;
    }
}

int findPath(char start[20],char target[20],struct node *root,struct edge *edge)
{
    if(root == NULL && edge->next == NULL)
    {
        return 0;
    }
    else
    {

        if(edge->next == NULL)
        {
            printf("%s\n",edge->name);
            findPath(start,target,root->down,root->down->right);
        }
        else
        {
            findPath(start,target,root,edge->next);
        }
         printf("%s\n",edge->name);




    }

}
int main()
{
    FILE *file = fopen("graph.txt","r");
    char nodeName[20],edgeName[20];
    int weight;
    while(!feof(file))
    {
        fscanf(file,"%s",&nodeName);
        fscanf(file,"%s",&edgeName);
        fscanf(file,"%d",&weight);
        addNode(nodeName,edgeName,weight);
    }
    isFullGraph();
    printf("\n");
    printf("\n");




    return 0;
}
