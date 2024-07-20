#include <iostream>
#include<unordered_map>
using namespace std;
int main() {
    
    //create
    unordered_map<string, int> m;
    
    //insertion
    pair<string,int> p=make_pair("Scorpio" , 9);
    m.insert(p);
    
    pair<string,int> p2=make_pair("Alto" , 2);
    m.insert(p2);
    
    //another way
    m["fortuner"] = 10;

    //access
    cout<<m.at("Alto") << endl;
    cout<<m.at("Scorpio") << endl;
    //wrong fetch will give error as s is undercase 
    //cout<<m.at("scorpio") <<endl;
    
    //another way to access
    cout<< m["fortuner"] << endl;
    
    //search using count function if returns 1 then present if no then not
    cout<<"Check Scorpio is present or not :"<<m.count("Scorpio")<<endl;
    
    //search using find function
    if(m.find("fortuner") != m.end()){
      cout<< "Fortuner Found" << endl;
    }
    else{
      cout<<"Fortuner Not found" << endl;
    }
    
    //size of map(unordered)
    cout<<"Before size :"<< m.size()<<endl;
    //wrong way to access element
    //if you try to access the element('hummer') with square bracket compiler will first create an entry and with mapping 0 then it will print 0
    cout<<m["hummer"]<<endl;
    //as hummer is not present before but when you typed m['hummer'] this creates an entry of hummer having count 10
    //and now if we check size the size will be greater than 1 before size compared
    cout<<"after wrong accessing of an element size:"<< m.size()<<endl;
    
    //iterating over map
    //while iterating the order is not the same as you inserted
    for(auto i: m) {
        cout<<i.first<<" " << i.second << endl;
    }
    
    
    
    
    return 0;
}
