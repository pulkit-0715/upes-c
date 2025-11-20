/*
start
input array

int maxi=arr[0];
maxiindex=0;
for(int j=1;j<n;j++)
{
    if(arr[j]>maxi){
    maxi=arr[j];
    maxindex=j;
    }
    
}


printf(%d %d""maxi,maxiindex);


end
*/


/*
int max=arr[0],sec=max,third=max;

find only max


int maxi=arr[0];
maxiindex=0;




for(int j=1;j<n;j++)
{
    if(arr[j]>maxi){
    maxi=arr[j];
    maxindex=j;
    }
    
}
for(int i=0;i<n-1;i++)
{
    if(arr[i]!=max)
    {
        sec=arr[i];
        for(int j=0;j<n;j++)
        if(arr[j]<sec)
        {
            third=arr[j];
           break;
        }
           break;
    }
}


for(int j=1;j<n;j++)
{
    if(arr[j]>maxi){
    third=sec;
    sec=max;
    maxi=arr[j];
    }   

    if(arr[j]>sec&&arr[j]<maxi)
    {   
    third=sec;
    sec=arr[j];
    }

    if(arr[j]>third)
    third=arr[j];
}


*/