#include <iostream>
#include <map>
using namespace std;

map <int,string,greater<int>> list;

void add_player();
void print_list();
void remove_11th();
void print_player();

int main()
{
    bool check = true;
    int choice;

    while(check)
    {
        cout<<"select option fro the following : \n1-Add score\n2-Print the top 10\n3-Search for score by name\n4-Exit : ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                add_player();
                remove_11th();
                break;
            case 2:
                print_list();
                break;
            case 3:
                print_player();
                break;
            case 4:
                cout<<"\nGoodbye <3\n  ";
                check=false;
                break;
            default:
                cout<<"\n***wrong choice***\n*Please enter your choice again*\n\n";
        }
    }

    return 0;

}

void add_player()
{
    string name;
    int score;
    cout <<"Enter the name and the score of the player ";
    cin>>name>>score;
    list.insert({score,name});

}

void print_list()
{
    if (list.empty())
    {
        cout<<"no players have been input yet\n\n";
    }
    else
    {
            for(auto i:list)
        {
            cout<<i.second<<"\t"<<i.first<<endl ;
        }
    }

}

void remove_11th()
{
    if(list.size()>10)
    {
        list.erase(prev(list.end()));
    }
}

void print_player()
{
    int search =0;
    string name;
    cout<<"Enter the name of the player to search\n";
    cin>>name;
    for(auto i:list)
    {
        if(i.second == name)
        {
            cout<<i.second<<"\t"<<i.first<<endl ;
            search++;
        }
    }
    if (search==0)
    {
        cout<<"this player has not been input yet or is not in the top 10 scores\n\n";
    }

}
