#include<iostream>

using namespace std;
struct process{
    int wl, wt,tt;
    process * next;
};
process * readylist= NULL;
int totalprocess;
void Diplaylist( );
void appendProcess(process *temp);
void intalailizdSystem();
void runSystyem();
void DisplayAvg();
int main()
{
  intalailizdSystem();
  runSystyem();
  Diplaylist();
  DisplayAvg();


}
void intalailizdSystem(){
  process *temp1;
  cout<<"enter total number of process"<<endl;
  cin>>totalprocess;
  if(totalprocess == 0 && 'A' ){
    cout<<"please enter from 1 to 100000000";
  }
  for(int i=1; i<=totalprocess; i++){
        temp1 = new process;
    temp1->next = NULL;
    cout<<"Enter the WorkLoad for process "<<i<<"  ";
    cin>>temp1->wl;
    appendProcess(temp1);

}}

void appendProcess(process *temp){
  process *temp2;
  if(readylist == NULL){
     temp->wt=0;
    temp->tt=temp->wl;
     readylist = temp;
  }
  else if (readylist ->next == NULL){
        readylist->next = temp;

     }
     else {
      temp2=  readylist;
      while(temp2->next!= NULL)
        temp2= temp2->next;

      temp2 ->next = temp;


     }
}
void Diplaylist(){
  process *temp;
  if (readylist ==NULL){
    cout<<" empty "<< endl;
  }else if (readylist->next == NULL ){
      for(int j=1; j<=totalprocess; j++){
            cout<<"WL of "<<j<<" is = "<<readylist->wl<<endl;
            cout<<"WT of "<<j<<" is = "<<readylist->wt<<endl;
             cout<<"TT of "<<j<<" is = "<<readylist->tt<<endl;

      }
      cout<<endl;
      //cout<<readylist->wl<<" "<<readylist->wt<<"   " <<readylist->tt;

    }else{
      temp= readylist;
      while(temp!= NULL){
            cout<<endl;
         cout<<temp->wl<<" "<<temp->wt<<"   " <<temp->tt;
         temp = temp->next;
      }
    }
}

void runSystyem(){
 process *temp1 , *temp2;
 if(readylist == NULL){
    cout<<"empty"<<endl;

 }else if (readylist->next == NULL){
    cout<<"allready assinged";
 }else{
  temp1 = readylist;
  temp2 = temp1->next;
  while(temp2!= NULL){
        temp2->wt= temp1->wt + temp1 ->wl-1;

        temp2->tt = temp2->wt+temp2->wl;
  temp1= temp2;
  temp2= temp2->next;


  }
 }

}

void DisplayAvg() {
    process *temp = readylist;
    int total_wt = 0, total_tt = 0;

    while(temp != NULL) {
        total_wt += temp->wt;
        total_tt += temp->tt;
        temp = temp->next;
    }

    float avg_wt = (float)total_wt / totalprocess;
    float avg_tt = (float)total_tt / totalprocess;
    cout<<endl;

    cout << "Average Waiting Time: " << avg_wt << endl;
    cout << "Average Turnaround Time: " << avg_tt << endl;
}



