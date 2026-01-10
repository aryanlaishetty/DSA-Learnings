#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void itineraryTickets(unordered_map<string, string> tickets) {
    unordered_set<string> to;

    for(pair<string, string> ticket : tickets) {
        to.insert(ticket.second);
    }

    string start = "";
    for(pair<string, string> ticket : tickets) {
        if(to.find(ticket.first) == to.end()) { //starting point - searching 'from' element in 'to'
            start = ticket.first;
        }
    }

    //Sequence print
    cout<<start<<" -> ";
    while(tickets.count(start)) {
        cout<<tickets[start]<<" -> ";
        start = tickets[start];
    }
    cout<<"destination reached"<<endl;
}

int main() {
    unordered_map<string, string> tickets;  //<from, to>
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    itineraryTickets(tickets);

    return 0;
}