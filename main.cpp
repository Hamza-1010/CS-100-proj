

#include<iostream> 
#include<fstream>
#include<iomanip>
#include<Windows.h>//for sleep function
#include<stdlib.h>//for clear screen function
#include"map.cpp"//linking map file 
#include"function_map.cpp"//linking map function file 
#include<string>
#include<ctime>
#include"pixel_map.cpp"

using namespace std;
string result = "";
string names[25]={"parking lot","cricket ground","aquatic centre","M1","M2","M3","M4","M7","tennis court","sports complex","SDSB","M5","M6","Power generators","REDC","Mosque","F1","F2","F3","F4","SSE","PDC","HSS","SAHSOL","Library"};
int size1 = sizeof(names)/sizeof(names[0]);
void AI_animate_1(string str){ // creates a dynamic animation of word
    string cat ="";
    for(int x= 0;x<str.length();x++){
        cat = str.substr(x,1);
        Sleep(15);
        cout<<cat;
    }   
}
void AI_animate_2(string str1){ //creates sliding animation of word
    for(int x =0 ;x<52;x++){
        for(int i=0;i<x;i++){
            cout<<" ";
        }
        cout<<str1;
        Sleep(5);
        system("cls");
    }
    cout<<"******____________________________________________________"<<str1<<"______________________________________________________*******";

}


int minimum_distance(int distance[], bool visited[]) // finding nearest unvisited node 

{    
    const int INF = 1000;
    int minimum=INF;
    int index;
              
    for(int k=0;k<25;k++) 
    {
        if(visited[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            index=k;
        }
    }
    return index;
}



/* parking lot > 2   cricket ground >2    aquatic centre
M1 M2 ^1 M3 M4 >1  ^1 M7 >1 tennis court>2  ^1 sports complex >1  SDSB
M5 ^1 >0.5   M6  >1  ^1 Power generators >2       REDC  >2       ^1 mosque >1 F1>0.5 F2   *** map used to model cost matrix
^1 SSE >2           ^1 PDC  >2                HSS  >2       ^1 Library^1
                                        ^1 SAHSOL      ^1 F3 F4 
*/
void dijkstras(string start,string end,int source,int ending,int vertex[][25]){//finds shortest path between two nodes on the graph
    
    int distance[25];//array containig minimum distance through each node
    string route[25][25];//string array containg the final route
    const int INF = 1000;//edges not connected 
   
    
    bool visited[25];
    for(int x=0;x<25;x++){ //initially all distances are infinity and all nodes are univisted
        distance[x]=INF; 
        visited[x]=false;
    }
    distance[source]=0; // source node as distance 0 as no cost from going to same node 
    
     
     
     for(int x = 0; x<25; x++)                           
    {
        int m=minimum_distance(distance,visited); // unvisited node is index value m 
        visited[m]=true;
        int counter =0;
        

        for(int i = 0; i<25; i++){ //traversing graph and relaxing 

             
            // if the sum of cost and distance to adjacent node is less than current distance to node, then update node
            if(vertex[m][i]!=INF  && distance[m]+vertex[m][i]<distance[i]){ //first condition checks if it is an adjacent node second check if going from m node to ith node is actually a shorter path
                distance[i]=distance[m]+vertex[m][i];
                    route[x][i] = names[i];

                
                
            }
            
    
            }
            cout<<endl;
    }      
                
        
      
    
    
   

    cout<<endl;
    
    
     /*for(int x=0;x<25;x++){
         for(int i =0; i<25; i++){
             cout<<route[x][i];
            
        }
        
        cout<<endl;
       
     }*/



     
    cout<<endl<<endl;
    
    
     
   
    cout<<endl<<endl<<endl;
    AI_animate_1("The min distance (or in this case the number of hops from one node to the other) required to traverse from ");
    cout<<start;
    AI_animate_1(" to ");
    cout<<end<<"";
    AI_animate_1(" is ");
    cout<<distance[ending]<<endl;
    AI_animate_1("You will need to traverse LUMS through following these directions :\n");
   
    

    

for (int a=0;a<25;a++){
    for(int x=0;x<25;x++){
            if(route[a][x]=="SSE")   //outputing pictue of each location to show result and then writing to global variable result
        {
            SSE();
            result =result+ SSE1();
            
        }
        else if ( route[a][x] =="parking lot"){
            parking_lot();
            result = result+ parking_lot1();

        }   
        else if (route[a][x]=="cricket ground"){
            cricket_ground();
            result = result+ cricket_ground1();
        } 
        else if(route[a][x]=="aquatic centre"){
            aquatic_center();
            result = result + aquatic_center1();
           

        }
        else if (route[a][x]=="M1"){
            M1();
            result = result + M11();
            

        }
        else if(route[a][x]=="M2"){
            M2();
            result = result + M21();


        }
        else if(route[a][x]=="M3"){
            M3();
            result = result + M31();

        }
        else if (route[a][x]=="M4"){
            M4();
            result = result + M41();

        }
        else if (route[a][x]=="M7"){
            M7();
            result = result + M71();

        }
        else if(route[a][x]=="tennis court"){
            tennis_court();
            result = result + tennis_court1();

        }
        else if (route[a][x]=="sports complex "){
            sports_complex();
            result = result + sports_complex1();

        }
        else if (route[a][x]=="SDSB"){
            SDSB();
            result = result + SDSB1();

        }
        else if (route[a][x]=="M5"){
            M5();
            result = result + M51();

        }
        else if (route[a][x]== "M6"){
            M6();
            result = result + M61();

        }
        else if(route[a][x]=="Power generatos")  {
            power_generators();
            result = result + power_generators1();

        }  
        else if(route[a][x]=="REDC") {
            REDC();
            result = result + REDC1();

        }  
        else if (route[a][x]=="Mosque") {
            mosque();
            result = result + mosque1();

        }   
        else if(route[a][x]=="F1"){
            F1();
            result = result + F11();

        }
        else if(route[a][x]=="F2"){
            F2();
            result = result + F21();
        }  
        else if(route[a][x]=="F3"){
            F3();
            result = result + F31();
        } 
        else if (route[a][x]=="F4") {
            F3();
            result = result + F31();
        }
        else if(route[a][x]=="PDC"){
            PDC();
            result = result + PDC1();
        }
        else if (route[a][x]=="HSS"){
            HSS();
            result = result + HSS1();
        }
        else if(route[a][x]=="SAHSOL"){
            SAHSOL();
            result = result + SAHSOL1();
        }
        else if(route [a][x]=="Library"){
            library();
            result = result + library1();

        }
        else if(route[a][x]==end){
            break;
        }}

                

        
        }
        
}

            
        


void save(){//saves output of code in a text file with user specified name given user wants to store result and also states time of journey 
     cout<<"Enter the name of the file ";
     time_t tm = time(0);
     char * date_time = ctime(&tm);
     string name_of_file;
     cin>>name_of_file;
     string final_name =name_of_file+".txt";
     ofstream File(final_name);
     string text = "The time at which you recorded the journey was ";
     File<<text;
     File<<date_time;
     File<<result;
     File.close();

}


int main (){
    
    AI_animate_2("LUMS Directions");
    cout<<endl<<endl;
    cout<<endl;
    AI_animate_1("Hey, if you are feeling a bit lost at LUMS, don't worry, this  program is here to help !\n");
    cout<<endl<<endl;
    AI_animate_1("Map generation in progress....................\n ");
    cout<<endl;
    generate_map();
    cout<<"\n";
    AI_animate_1("All the significant places at LUMS are listed for you so you can input your location. PLease consult the pixel map for exact location \n\n\n");
    
    for(int x =0;x<size1;x++){
        AI_animate_1(names[x]);
        cout<<"\n";
        
    }
    cout<<"\n\n\n";

    AI_animate_1("Please enter your current location in LUMS \n");
    string current_location;
    getline(cin,current_location);
    AI_animate_1("Please enter the location you want to go to \n");
    string final_location;
    getline(cin,final_location);
    bool found1=false,found2 =false ;
    string names[25]={"parking lot","cricket ground","aquatic centre","M1","M2","M3","M4","M7","tennis court","sports complex","SDSB","M5","M6","Power generators","REDC","Mosque","F1","F2","F3","F4","SSE","PDC","HSS","SAHSOL","Library"};
    for(int i=0;i<25;i++){
        if(names[i]==current_location){
            found1= true;
        }
        if(names[i]==final_location){
            found2=true;
        }
    }
    while(found1==false||found2==false){
        AI_animate_1("It appears that the location that you have entered is not correct,please re-enter your locations\n");
        cin.clear();
        AI_animate_1("Please enter your current location in LUMS \n");
        getline(cin,current_location);
        AI_animate_1("Please enter the location you want to go to \n");
        getline(cin,final_location);
        for(int i=0;i<25;i++){
        if(names[i]==current_location){
            found1= true;
        }
        if(names[i]==final_location){
            found2=true;
        }
    }

    }
    
    
    
    
    
    while (final_location==current_location){
        AI_animate_1("current location cannot be the same as final location\n");
        cin.clear();
        AI_animate_1("Please enter your current location in LUMS \n");
        getline(cin,current_location);
        AI_animate_1("Please enter the location you want to go to \n");
        getline(cin,final_location);
        
        
    }

    int num_start;
    int num_end;
    for(int q=0;q<25;q++){
        if(names[q]==current_location){
            num_start = q;
        }
        if(names[q]==final_location){
            num_end =q;
        }
    }
    const int INF = 1000;
    int vertex [25][25]={
    {0,2,5,1,1,1,1,1,3,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
    {2,0,1,2,1,2,2,1,1,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
    {5,1,0,INF,INF,INF,INF,INF,1,1,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
    {1,1,INF,0,1,1,1,2,INF,INF,INF,1,1,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
    {1,INF,INF,1,0,1,1,2,INF,INF,INF,1,1,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
    {1,INF,INF,1,1,0,1,2,INF,INF,INF,2,1,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
    {1,INF,INF,1,1,1,0,2,INF,INF,INF,1,1,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
    {1,1,INF,1,1,1,1,0,1,2,INF,INF,INF,1,1,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
    {INF,1,1,INF,INF,INF,INF,1,0,1,INF,INF,INF,INF,1,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
    {INF,INF,2,1,INF,INF,INF,INF,INF,INF,0,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
    {INF,INF,INF,INF,INF,INF,INF,INF,INF,1,0,INF,INF,INF,INF,1,INF,INF,INF,INF,INF,INF,INF,INF,INF},
    {INF,INF,INF,5,1,INF,INF,INF,0,INF,1,INF,INF,INF,INF,INF,INF,INF,1,INF,INF,INF,INF,INF,INF},
    {INF,INF,INF,5,1,INF,INF,INF,INF,0,1,INF,INF,INF,INF,INF,INF,1,INF,INF,INF,INF,INF,INF,INF},
    {INF,INF,INF,INF,INF,INF,INF,1,INF,INF,INF,1,1,0,1,INF,INF,INF,INF,INF,INF,1,INF,INF,INF},
    {INF,INF,INF,INF,INF,INF,INF,INF,1,1,INF,INF,INF,1,0,1,INF,INF,INF,INF,INF,INF,1,INF,INF},
    {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,1,INF,INF,INF,1,0,INF,INF,INF,INF,INF,INF,INF,INF,1},
    {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,0,1,1,1,INF,INF,INF,INF,1},
    {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,1,0,1,1,INF,INF,INF,INF,1},
    {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,1,1,0,1,INF,INF,INF,INF,1},
    {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,1,1,1,0,INF,INF,INF,INF,1},
    {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,1,1,INF,INF,INF,INF,INF,INF,INF,0,1,INF,INF,INF},
    {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,1,INF,INF,INF,INF,INF,INF,1,0,1,INF,INF},
    {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,1,INF,INF,INF,INF,INF,INF,1,0,1,1},
    {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,1,0,1},
    {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,1,1,1,1,1,INF,INF,1,1,0}};//adjacency/cost matrix to store values of edges to each node
    
    
    dijkstras(current_location,final_location,num_start,num_end,vertex);
    //AI_animate_1("For your convenience, we have highlighted the places you need to visit on the map !!! ");
    cout<<endl;
    AI_animate_1("Do you want to store the result of this jounrey in a text file ? If yes enter yes, else enter no \n");
    cout<<endl;
    string decision;
    cin>>decision;
    if (decision =="yes" || decision =="Yes"){
        save();
        cout<<"Thanks for using the program !!!\n";
        cout<<"Your text file is saved in the same folder as the cpp file  ";
    }
    else{
        cout<<"Thanks for using the program !!! ";
    }
    return 0;
    

}
