#include<bits/stdc++.h>

using namespace std;

int** findMatrix()



int main()
{
    ifstream file1;


    float no_of_element;

    file1>>no_of_element;



    float node1;
    float node2;
    float node3;
    float node4;

    file1>>node1;
    file1>>node2;
    file1>>node3;
    file1>>node4;


    float G[4][8];

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<8;j++)
        {
            file1>>G[i][j];
        }
    }



    ifstream file2;

    pair< int,pair<int,int> >node_coordinate[10];


    for(int i=0;i<10;i++)
    {
        file2>>node_coordinate[i].first>>node_coordinate[i].second.first>>node_coordinate[i].second.second;
    }

   /* float x1 = node_coordinate[node1].second.first;
    float y1 = node_coordinate[node1].second.second;

    float x2 = node_coordinate[node2].second.first;
    float y2 = node_coordinate[node2].second.second;

    float x3 = node_coordinate[node3].second.first;
    float y3 = node_coordinate[node3].second.second;

    float x4 = node_coordinate[node4].second.first;
    float y4 = node_coordinate[node4].second.second; */

    for(int i=0;i<1-;i++)
    {
        if(node_coordinate[i].first==node1)
        {
             float x1 = node_coordinate[i].second.first;
             float y1 = node_coordinate[i].second.second;
        }

        if(node_coordinate[i].first==node2)
        {
             float x2 = node_coordinate[i].second.first;
             float y2 = node_coordinate[i].second.second;
        }

        if(node_coordinate[i].first==node3)
        {
             float x3 = node_coordinate[i].second.first;
             float y3 = node_coordinate[i].second.second;
        }

        if(node_coordinate[i].first==node4)
        {
             float x4 = node_coordinate[i].second.first;
             float y4 = node_coordinate[i].second.second;
        }
    }


    float p = 1 + 4*(G[0][0]);
    float q = 1 + 4*(G[1][0]);




    float const_multiplierJ=(1/4);

    float J11 = (const_multiplierJ)*(-(1-p)*(x1) + (1-p)*(x2) + (1+p)*(x3) - (1+p)*(x4));
    float J12 = (const_multiplierJ)*(-(1-p)*(y1) + (1-p)*(y2) + (1+p)*(y3) - (1+p)*(y4));
    float J21 = (const_multiplierJ)*(-(1-q)*(x1) - (1+q)*(x2) + (1+q)*(x3) - (1-q)*(x4));
    float J22 = (const_multiplierJ)*(-(1-q)*(y1) - (1+q)*(y2) + (1+q)*(y3) - (1-q)*(y4));

    float J[2][2];

    J[0][0]=J11;
    J[0][1]=J12;
    J[1][0]=J21;
    J[1][1]=J22;


    float detJ=((J11)*(J22))-((J12)*(J21));

    float A[3][4];

    A[0][0] = (J22/detJ);
    A[0][1] = (-1)*(J12/detJ);
    A[0][2] = 0;
    A[0][3] = 0;


    A[1][0] = 0;
    A[1][1] = 0;
    A[1][2] = (-1)*(J21/detJ);
    A[1][3] = (J11/detJ);

    A[2][0] = (-1)*(J21/detJ);
    A[2][1] = (J11/detJ);
    A[2][2] = (J22/detJ);
    A[2][3] = (-1)*(J12/detJ);

    float B[3][8]={0};

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<8;j++)
        {
            for(int k=0;k<4;k++)
            {
                B[i][j]= B[i][j]+A[i][k]*G[k][j];
            }
        }
    }



    float transB[8][3];

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            transB[i][j]=B[j][i];
        }
    }


    float D[3][3];

    float const_multiplierD = E/((1+v)*(1-2*v));

    D[0][0] = (const_multiplierD)*(1-v);
    D[0][1] = (const_multiplierD)*(v);
    D[0][2] = (const_multiplierD)*(0);

    D[1][0] = (const_multiplierD)*(v);
    D[1][1] = (const_multiplierD)*(1-v);
    D[1][2] = (const_multiplierD)*(0);

    D[2][0] = (const_multiplierD)*(0);
    D[2][1] = (const_multiplierD)*(0);
    D[2][2] = (const_multiplierD)*(1-2*v);




    float BtD[8][3]={0};

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                BtD[i][j] = BtD[i][j] + transB[i][k]*D[k][j];
            }
        }
    }

    float BtDB[8][8];

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            for(int k=0;k<3;k++)
            {
                BtDB[i][j] = BtDB[i][j] + BtD[i][k]*B[k][j];
            }
        }
    }

    float matrix[8][8];

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            matrix[i][j] = BtDB[i][j]*(detJ);
        }
    }



    return 0;
}
