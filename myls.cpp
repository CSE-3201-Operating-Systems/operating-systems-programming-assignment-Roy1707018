#include <dirent.h>
#include <cstring>
#include<iomanip>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include<fstream>
#include<algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

int ls_l(const char *open) 
{
 
 string com,command,com2,output;
 const char *com_cc;
 fstream file;
 struct dirent *a;
 DIR *dp;
 // getting total
     com = "ls -s ";
     com2 = " > /home/chuti/command/folder/total";
     command = com + com2;
     com_cc = command.c_str();
     system(com_cc);
     file.open("/home/chuti/command/folder/total",ios::in);
     getline(file,output);
     cout<<output<<'\n';
     file.close();  
     
 dp = opendir(open);
  

  while((a = readdir(dp))!=NULL)
  {
     
     
     if(a->d_name[0] != '.')
     {
     string name = a->d_name;
     
     
        
        //getting the permission
     com = "stat -c %A ";
     com2 = " > /home/chuti/command/folder/xyz";
     command = com + name + com2;
     com_cc = command.c_str();
     system(com_cc);
     file.open("/home/chuti/command/folder/xyz",ios::in);
     while(getline(file,output))
        cout << output << " ";
     file.close();  
     
     //getting the link
      
     com = "stat -c %h ";
     com2 = " > /home/chuti/command/folder/xyz";
     command = com + name + com2;
     com_cc = command.c_str();
     system(com_cc);
     file.open("/home/chuti/command/folder/xyz",ios::in);
     while(getline(file,output))
        cout << output << " ";
     file.close();  
     
     // getting gid
     com = "stat -c %G ";
     com2 = " > /home/chuti/command/folder/xyz";
     command = com + name + com2;
     com_cc = command.c_str();
     system(com_cc);
     file.open("/home/chuti/command/folder/xyz",ios::in);
     while(getline(file,output))
        cout << output << " ";
     file.close(); 
     
      
     // getting uid
     com = "stat -c %U ";
     com2 = " > /home/chuti/command/folder/xyz";
     command = com + name + com2;
     com_cc = command.c_str();
     system(com_cc);
     file.open("/home/chuti/command/folder/xyz",ios::in);
     while(getline(file,output))
        cout << output << " ";
     file.close();  
     
     //getting the size
     com = "stat -c %s ";
     com2 = " > /home/chuti/command/folder/xyz";
     command = com + name + com2;
     com_cc = command.c_str();
     system(com_cc);
     file.open("/home/chuti/command/folder/xyz",ios::in);
     while(getline(file,output))
        cout << output << " ";
     file.close(); 
     
     
     
     //getting the date
     com = "stat -c %y ";
     com2 = " > /home/chuti/command/folder/xyz";
     command = com + name + com2;
     com_cc = command.c_str();
     system(com_cc);
     file.open("/home/chuti/command/folder/xyz",ios::in);
     while(getline(file,output))
        {
            string dt = output;
            if(output[6] == '3') {output = "March ";}
            else if(output[6] == '4') {output = "April ";}
            else if(output[6] == '5') {output = "May ";}
            else if(output[6] == '6') {output = "June ";}
            else if(output[6] == '7') {output = "July ";}
            else if(output[6] == '8') {output = "August ";}
            else if(output[6] == '9') {output = "September ";}
            else if(output[6] == '0') {output = "October ";}
            else if(output[6] == '2' && output[5] == '0') {output = "February ";}
            else if(output[6] == '2' && output[5] == '1') {output = "December ";}
            else if(output[6] == '1' && output[5] == '0') {output = "January ";}
            else if(output[6] == '1' && output[5] == '1') {output = "November ";}
            for (int i = 8;i<16;i++)
             output += dt[i];
             
            cout<<output<<" "; 
        }
       
     file.close(); 
     
     //getting the filename
     com = "stat -c %n ";
     com2 = " > /home/chuti/command/folder/xyz";
     command = com + name + com2;
     com_cc = command.c_str();
     system(com_cc);
     file.open("/home/chuti/command/folder/xyz",ios::in);
     while(getline(file,output))
        cout << output << " ";
     file.close(); 
     cout<<endl;
     }
  }
  closedir(dp);
  return 0;
}
struct abc{
int y,mn,d;
double s;
string fname;

};


int ls_t(const char *open)
{
string com,command,com2,output;
 const char *com_cc;
 fstream file;
struct dirent *a;
 DIR *dp;
dp = opendir(open);
vector<abc> test;
int n=0,i=0,j;
//get the file dates
  while((a = readdir(dp))!=NULL)
  {
  if(a->d_name[0] != '.')
  { 
  n++;
    string name = a->d_name;
    com = "stat -c %y ";
     com2 = " > xyz";
     command = com + name + com2;
     com_cc = command.c_str();
     system(com_cc);
     file.open("xyz",ios::in);
     string yr,mn,dt,hr,min,sec;
     int k,l,m,n,o;
     double p;
     double second;
     
     while(getline(file,output))
     {
           yr[0]= output[0];
           yr[1]= output[1];
           yr[2]= output[2];
           yr[3]= output[3];
           mn[0]=output[5];
           mn[1]=output[6];
           dt[0]=output[8];
           dt[1]=output[9];
           hr[0]=output[11];
           hr[1]=output[12];
           min[0]=output[14];
           min[1]=output[15];
           sec[0]=output[17];
           sec[1]=output[18];
           sec[2]=output[19];
           sec[3]=output[20];
           sec[4]=output[21];
           sec[5]=output[22];
           sec[6]=output[23];
           sec[7]=output[24];
           sec[8]=output[25];
           sec[9]=output[26];
           k= stoi(yr);
           l=stoi(mn);
           m=stoi(dt);
           n=stoi(hr);
           o=stoi(min);
           p=stof(sec);
           second=(n*3600)+(o*60)+p;// converting hr and min in second
           
           
           test.push_back({k,l,m,second,name});
           
     }
      i++;
     file.close();
    
  }
  }
  
 // descending order of second
 for(i=1;i<n;i++)
 {
 for(j=0;j<=n-i;j++)
      {
      if(test[j].s< test[j+1].s)
     { swap(test[j].s,test[j+1].s);
      swap(test[j].mn,test[j+1].mn);
      swap(test[j].d,test[j+1].d);
      swap(test[j].y,test[j+1].y);
     // swap(test[j].n,test[j+1].n);
     test[j].fname.swap(test[j+1].fname);
     }
      }
 }
 
 
// descending order of day
for(i=1;i<n;i++)
 {
 for(j=0;j<=n-i;j++)
      {
      if(test[j].d< test[j+1].d)
     { swap(test[j].d,test[j+1].d);
      swap(test[j].mn,test[j+1].mn);
      swap(test[j].s,test[j+1].s);
      swap(test[j].y,test[j+1].y);
     // swap(test[j].n,test[j+1].n);
     test[j].fname.swap(test[j+1].fname);
     }
      }
 }

 
// descending order of month
for(i=1;i<n;i++)
{
 for(j=0;j<=n-i;j++)
      {
      if(test[j].mn< test[j+1].mn)
     { swap(test[j].mn,test[j+1].mn);
      swap(test[j].d,test[j+1].d);
      swap(test[j].s,test[j+1].s);
      swap(test[j].y,test[j+1].y);
     // swap(test[j].n,test[j+1].n);
     test[j].fname.swap(test[j+1].fname);
     }
      }
 }
 
// descending order of year
for(i=1;i<n;i++)
 {
 for(j=0;j<=n-i;j++)
      {
      if(test[j].y< test[j+1].y)
     { swap(test[j].y,test[j+1].y);
      swap(test[j].mn,test[j+1].mn);
      swap(test[j].s,test[j+1].s);
      swap(test[j].d,test[j+1].d);
     // swap(test[j].n,test[j+1].n);
     test[j].fname.swap(test[j+1].fname);
     }
      }
 }

 // print the files
 for(i=0;i<n;i++)
  {
  cout<< test[i].fname<<endl;
  }
 
return 0;
}


int ls_a(const char *open) 
{
 struct dirent *a;
 DIR *dp;
dp = opendir(open);
string s;
vector<string>st,stt;
int i,j;
  

  while((a = readdir(dp))!=NULL)
  {
    
    s=a->d_name;
  
 
   st.push_back(s);
  
    
  
  if(s[0]=='.'&& s[1]>='a' && s[1]<='z')
  {
   s.erase(s.begin()+0);
   stt.push_back(s);
  }
  else
  stt.push_back(s);
     
  
  }
 sort(stt.begin(),stt.end());
 
 
 for(i=0;i<stt.size();i++)
  {
   
   for(j=0;j<stt.size();j++)
   {
    if(st[j]==stt[i])
    {
     cout<<stt[i]<<endl;
   }
   else if(st[j][0]=='.'&& st[j][1]>='a' && st[j][1]<='z')
   {
   s=st[j];
   s.erase(s.begin()+0);
   if(s==stt[i])
   {
   stt[i]='.'+stt[i];
   cout<<stt[i]<<endl;
   }
   }
   
   }
  
  }
  

  closedir(dp);
  return 0;
}

int main(int argc,char **argv) 
{
 
 if(!(strcmp(argv[1],"-l"))) 
   ls_l(".");
   if(!(strcmp(argv[1],"-a"))) 
   ls_a(".");
   if(!(strcmp(argv[1],"-t"))) 
   ls_t(".");
    
//if(!(strcmp(argv[1],"-l"))) 
    //ls_l(".");
  

  return 0;
  
}

//export PATH="$PATH:/home/chuti"


