#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

string Trim(string& str)
{
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
    return str;
}

int main()
{
    int N=-1,i=0,j=0,t=0;
    int a[10][10];
    string stu[20][100];
    double sum[50][50];
    ifstream fin("/Users/s20171105111/Desktop/text708/text708/File.csv");
    string line;
    while (getline(fin, line))
    {
        istringstream sin(line);
        vector<string> fields;
        string field;
        while (getline(sin, field, ','))
        {
            fields.push_back(field);
        }
        stu[0][i] = Trim(fields[0]);
        stu[1][i] = Trim(fields[1]);
        stu[2][i] = Trim(fields[2]);
        stu[3][i] = Trim(fields[3]);
        stu[4][i] = Trim(fields[4]);
        stu[5][i] = Trim(fields[5]);
        stu[6][i] = Trim(fields[6]);
        stu[7][i] = Trim(fields[7]);
        stu[8][i] = Trim(fields[8]);
        stu[9][i] = Trim(fields[9]);
        stu[10][i] = Trim(fields[10]);
        i++;
        j++;
        N++;
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<5;j++)
        {
            stringstream c;
            c<<stu[j+6][i+1];
            c>>a[i][j];
        }
    }
    for(t=0;t<N;t++)
    {
        for (i=0;i<5-1;i++)
        {
            for (j=0;j<5-i-1;j++)
            {
                if (a[t][j]<a[t][j+1])
                {
                    int temp;
                    temp=a[t][j];
                    a[t][j]=a[t][j+1];
                    a[t][j+1]=temp;
                }
            }
        }
    }
    for(i=0;i<N;i++)
    {
        sum[i][i]=0;
        for(j=1;j<5-1;j++)
        {
            
            sum[i][i]=sum[i][i]+a[i][j];
        }
        sum[i][i]=sum[i][i]/3;
    }
    ofstream ofile;
    ofile.open("/Users/s20171105111/Desktop/text708/text708/Fileout.csv",ios::out | ios::trunc);
    ofile<<"number,name,sex,birthdate,class,phonenumber,judge"<<endl;
    for(i=0;i<=N-1;i++)
    {
        ofile<<stu[0][i+1];
        for(j=1;j<=5;j++)
        {
            ofile<<","<<stu[j][i+1];
        }
        ofile<<","<<sum[i][i];
        ofile<<endl;
    }
    ofile.close();
    return 0;
}
