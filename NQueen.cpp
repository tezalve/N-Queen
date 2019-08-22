#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <cstdlib>

using namespace std;

int main()
{
    int i,j,count,y;
    int max=0;
    int maxK=0;
    int maxL=0;
    cout << "Board Size(N):";
    cin >> y;
    i=y;
    j=y;
    int a[i][j];

    for(int k=0; k<i; k++) //Nested loop for first queen
    {
        for(int l=0; l<j; l++)
        {
            if (count!=i) //to see if the max number of queens is found (for x/x board, x should be max number)
            {
                count=0;

                for(int k=0; k<i; k++) //initialize the 2D array
                {
                    for(int l=0; l<j; l++)
                        a[k][l] = 2;
                }
                //first queens index using the nested loop
                int firstQueenR = k;
                int firstQueenC = l;
                int left=firstQueenR-firstQueenC; //constant number for left diagonal
                int right=firstQueenR+firstQueenC; //constant number for right diagonal

                for(int p=0; p<i; p++) //eliminate rows
                {
                    a[firstQueenR][p]=0;
                }

                for(int p=0; p<j; p++) //eliminate columns
                {
                    a[p][firstQueenC]=0;
                }

                for(int p=0; p<i; ++p) //eliminate diagonals
                {
                    for(int q=0; q<j; ++q)
                    {
                        if (p-q == left)
                            a[p][q]=0;
                        else if(p+q == right)
                            a[p][q]=0;
                    }
                }
                //assign first queen
                a[firstQueenR][firstQueenC]=1;
                count++; //count queen number

                for(int k=0; k<i; k++) //nested loop to put queens on viable indexes
                {
                    for(int l=0; l<j; l++)
                    {
                        if(a[k][l]==2) //check if the index is viable to put a queen
                        {
                            int tempLeft=k-l; //constant number for left diagonal
                            int tempRight=k+l; //constant number for right diagonal

                            for(int p=0; p<i; p++) //eliminate rows
                            {
                                a[k][p]=0;
                            }

                            for(int p=0; p<j; p++) //eliminate columns
                            {
                                a[p][l]=0;
                            }

                            for(int p=0; p<i; ++p) //eliminate diagonals
                            {
                                for(int q=0; q<j; ++q)
                                {
                                    if (p-q == tempLeft)
                                        a[p][q]=0;
                                    else if(p+q == tempRight)
                                        a[p][q]=0;
                                }
                            }
                            a[k][l]=1; //assign queen
                            count++; //count queen number
                        }
                    }
                }
                if (max<=count) //save the max number of queens found using this algorithm
                    {
                        max=count;
                        //save the index of the first queen(by which max number of queens is found)
                        maxK=k;
                        maxL=l;
                    }
            }
        }
    }
    //running the same algorithm again but this time using the saved index that gave the max no of queens(no nested loop for first queen)
    count=0;
    for(int k=0; k<i; k++)
        {
            for(int l=0; l<j; l++)
                a[k][l] = 2;
        }
    //assign the max index for first queen
    int firstQueenR = maxK;
    int firstQueenC = maxL;
    cout << "First Queen On:" << firstQueenR << "," << firstQueenC << "\n";
    int left=firstQueenR-firstQueenC; //constant number for left diagonal
    int right=firstQueenR+firstQueenC; //constant number for right diagonal

    for(int p=0; p<i; p++) //eliminate rows
    {
        a[firstQueenR][p]=0;
    }

    for(int p=0; p<j; p++) //eliminate columns
    {
        a[p][firstQueenC]=0;
    }

    for(int p=0; p<i; ++p) //eliminate diagonals
    {
        for(int q=0; q<j; ++q)
        {
            if (p-q == left)
                a[p][q]=0;
            else if(p+q == right)
                    a[p][q]=0;
        }
    }

    a[firstQueenR][firstQueenC]=1; //assign queen
    count++;

    for(int k=0; k<i; k++) //nested loop to put queens on viable indexes
    {
        for(int l=0; l<j; l++)
        {
            if(a[k][l]==2) //check if the index is viable to put a queen
            {
                int tempLeft=k-l; //constant number for left diagonal
                int tempRight=k+l; //constant number for right diagonal

                for(int p=0; p<i; p++) //eliminate rows
                {
                    a[k][p]=0;
                }

                for(int p=0; p<j; p++) //eliminate columns
                {
                    a[p][l]=0;
                }

                for(int p=0; p<i; ++p) //eliminate diagonals
                {
                    for(int q=0; q<j; ++q)
                    {
                        if (p-q == tempLeft)
                            a[p][q]=0;
                        else if(p+q == tempRight)
                            a[p][q]=0;

                    }
                }
                a[k][l]=1; //assign queen;
                count++;
            }
        }
    }


    for(int k=0; k<i; k++) //print indexes i.e. the board
    {
        for(int l=0; l<j; l++)
        {
            cout << a[k][l] << " ";
        }
        cout << "\n";
    }
    cout << "No of Max Queens:" << count;
    cout << "\n";
    system("pause");
}
