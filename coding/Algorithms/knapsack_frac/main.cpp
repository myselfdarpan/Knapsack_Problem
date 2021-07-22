#include <iostream>

using namespace std;

void sort_it(float weight[], float value[], int n)
{
    float p[10];
    for(int i=0;i<n;i++)
    {
        p[i] = value[i]/weight[i];
    }
    int k;
    for(int m=n;m>=0;m--)
    {
        for(int i=0;i>n-1;i++)
        {
            k = i+1;
            if(p[i]>p[k])
            {
                float temp;
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;

                float tem;
                tem=weight[i];
                weight[i]=weight[k];
                weight[k]=tem;

                tem = value[i];
                value[i]=value[k];
                value[k]=tem;


            }
        }
    }
}


double fractionalKnapsack( float W, float weight[], float value[], int n)
{
    float curweight = 0;
    float finalvalue = 0.0;

    for(int i = 0;i<n;i++)
    {
        if(curweight + weight[i] <= W)
        {

            curweight += weight[i];
            finalvalue += value[i];
        }
        else
        {
            float remain = W - curweight;
            finalvalue += value[i] * (remain / weight[i]);
            break;
        }
    }
    return finalvalue;
}

int main()
{
    float W;
    int n;
    float weight[10];
    float value[10];
    cout<<"Enter the number of element: "<<endl;
    cin>>n;
    cout<<"Enter the capacity: "<<endl;
    cin>>W;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the weight and value of "<<i+1<<" element :"<<endl;
        cin>>weight[i]>>value[i];
    }
    cout<<"Items: ";
    for(int i=0;i<n; i++)
    {
        cout<<"\tItem"<<i+1;
    }
    cout<<endl;
    cout<<"Weight: ";
    for(int i=0;i<n; i++)
    {
        cout<<"\t"<<weight[i];
    }
    cout<<endl;
    cout<<"Value: ";
    for(int i=0;i<n; i++)
    {
        cout<<"\t"<<value[i];
    }
    cout<<endl;
    sort_it(weight, value, n);
    //Functoin call
    cout<<"Maximum Value we obtain is: "<<fractionalKnapsack(W, weight, value, n)<<endl;
    //return 0;
}
