#include<iostream>
#include<string.h>
#include<exception>
#include <ctime>
#include<iomanip>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
void feedback();
void verification_1();
void feedback();
void verification_2();
char upper_to_lower(char c);
void display_dishes(unordered_set <int> dish_keys);
void floydWarshall(vector<vector<int>>& dist);
int calculate_distance(vector<int> & travel,int destination);


void floydWarshall(vector<vector<int>>& dist)
{
    int V = dist.size();
int i, j, k;
for (k = 0; k < V; k++) {
for (i = 0; i < V; i++) {
for (j = 0; j < V; j++) {
if (dist[i][j] > (dist[i][k] + dist[k][j]))
dist[i][j] = dist[i][k] + dist[k][j];
}
}
}
}

int calculate_distance(vector<int> & travel,int destination)
{
    vector<vector<int>> distance
    {
        {5,6,7,8,9,2},
        {1,2,4,6,3,6},
        {5,1,7,8,1,2},
        {10,6,4,8,5,2},
        {5,6,11,8,3,10}
    };
    floydWarshall(distance);
    travel.push_back(destination);
    int cost=0;
    travel.insert(travel.begin(),0);
    for(int i=0;i<travel.size()-1;i++)
    {
            cost+=distance[travel[i]][i+1];
    }
   
   return cost;
}
class customer_detials
{
    int length_check=0,special_character_check_1=0,special_character_check_2=0,j,k,check_validation_times;
    string customer_name;
  char email_id[25];
public :
    char mobile_number[10];
    void get_personal_details()
    {
        cout<<"Please enter the your personal details  :: " <<endl<<endl;
        check_validation_times=0;
        try
        {
        revalidate_name:
        cout<<"Please enter your name   :   ";
        cin.ignore();
        getline(cin,customer_name);
    length_check = customer_name.length();
    for(int i=0;i<length_check;i++)
    {
        if(!(((customer_name[i] >=  'a') && (customer_name[i] <=  'z')) ||(customer_name[i] ==  ' ') || ((customer_name[i] >=  'A') && (customer_name[i] <=  'Z'))))
        {
            check_validation_times++;
          if (check_validation_times>2)
           {throw 0;}
            else
            {
            cout<<endl<<" !!!            Please input a valid name     !!!"<<endl;
            goto revalidate_name;
            }
            }
        }
    }
    catch(int a)
    {
        cout<<"sorry your chances are over !!   try again later "<<endl<<"thanks for coming ";
        exit(0);
    }
    check_validation_times=0;
   try
{
    revalidate_email :
        cout<<endl<<"Please enter your email id  :  ";
        cin>>email_id;
    for(int i=0;i<=strlen(email_id);i++)
    {
        if(email_id[i] == '@')
        {
            special_character_check_1= i;
        }
         if(email_id[i] =='.')
        {
            special_character_check_2 =i;
        }
    }
    if(!(((special_character_check_1!=0) && (special_character_check_2!=0)) && (special_character_check_1 < special_character_check_2) ))
            {
                check_validation_times++;
                if (check_validation_times>5)
                {
                    throw 2;
                }
                cout<<"    ERROR    !!!        Please give a valid email id         !!!..."<<endl<<endl;
                goto revalidate_email;
            }
}
   catch(int a)
    {
        cout<<"sorry your chances are over !!   try again later "<<endl<<"thanks for coming ";
        exit(0);
    }
    check_validation_times=0;
    try
    {
        revalidate_moblile_number :
        cout<<endl<<"Please enter your 10 digit mobile number  without country code:  ";
        cin>>mobile_number;
    length_check=strlen(mobile_number);
    if(length_check!=10)
    {
        check_validation_times++;
        if (check_validation_times>5)
        {
            throw 2;
        }
       cout<<"    ERROR    !!!        Please give a valid 10 digit phone number         !!!..."<<endl<<endl;
        goto revalidate_moblile_number;
    }
    for(int i=0; i<length_check;i++)
    {
    if(!((mobile_number[i]  >= '0') && (mobile_number[i] <= '9')) )
    {
            check_validation_times++;
            if ( check_validation_times>5)
            {
                throw 0;
            }
            cout<<"    ERROR    !!!        Please give a valid 10 digit phone number         !!!..."<<endl<<endl;
            goto revalidate_moblile_number;
    }
    }
    }
    catch(int a)
    {
        cout<<"sorry your chances are over !!   try again later "<<endl<<"thanks for coming ";
        exit(0);
    }
    }
 };

// void dish_wish (restuarant r-2[]);
    class dish
{
public:
    string dish_name;
    int unique_key;
    int dish_price;
};
class cuisine
{
    public:
    string cuisine_name;
    dish d[5];
};
class restuarant
{
    public:
    string name_of_restaurant;
    cuisine c[4];
};

void initiallize_class (restuarant r[])
{
    r[0].name_of_restaurant="MANCHOW"; r[1].name_of_restaurant="ORCHID HOUSE";
    r[2].name_of_restaurant="RIVER STONE COTTAGE"; r[3].name_of_restaurant="WALK IN WOODS";

    r[0].c[0].cuisine_name= "North Indian"; r[0].c[1].cuisine_name= "South indian";
    r[0].c[2].cuisine_name= "Chinese corner"; r[0].c[3].cuisine_name= "Italian ";
    r[1].c[0].cuisine_name= "North Indian"; r[1].c[1].cuisine_name= "South indian";
    r[1].c[2].cuisine_name= "Chinese corner"; r[1].c[3].cuisine_name= "Italian ";
    r[2].c[0].cuisine_name= "North Indian"; r[2].c[1].cuisine_name= "South indian";
    r[2].c[2].cuisine_name= "Chinese corner"; r[2].c[3].cuisine_name= "Italian ";
    r[3].c[0].cuisine_name= "North Indian"; r[3].c[1].cuisine_name= "South indian";
    r[3].c[2].cuisine_name= "Chinese corner"; r[3].c[3].cuisine_name= "Italian ";
    //
    //
 r[0].c[0].d[0].dish_name = "Veg Rice" ;             r[0].c[0].d[0].dish_price = 150;         r[0].c[0].d[0].unique_key = 101 ;
 r[0].c[0].d[1].dish_name = "Dal Fry" ;              r[0].c[0].d[1].dish_price = 210;         r[0].c[0].d[1].unique_key=102;
 r[0].c[0].d[2].dish_name = "Tanduri Roti" ;         r[0].c[0].d[2].dish_price = 40;          r[0].c[0].d[2].unique_key = 103;
 r[0].c[0].d[3].dish_name = "Crisp Kachori" ;        r[0].c[0].d[3].dish_price = 50;          r[0].c[0].d[3].unique_key = 104;
 r[0].c[0].d[4].dish_name = "Butter nan" ;           r[0].c[0].d[4].dish_price = 30;          r[0].c[0].d[4].unique_key = 105;
//
//
 r[0].c[1].d[0].dish_name = "Veg Chowmien" ;             r[0].c[1].d[0].dish_price = 120;     r[0].c[1].d[0].unique_key = 106;
 r[0].c[1].d[1].dish_name = "Singapuri Chowmien" ;       r[0].c[1].d[1].dish_price = 140;     r[0].c[1].d[1].unique_key = 107;
 r[0].c[1].d[2].dish_name = "Veg Momos" ;                r[0].c[1].d[2].dish_price = 80;      r[0].c[1].d[2].unique_key = 108;
 r[0].c[1].d[3].dish_name = "Spring Roll" ;              r[0].c[1].d[3].dish_price = 90;      r[0].c[1].d[3].unique_key = 109;
 r[0].c[1].d[4].dish_name = "Veg Manchurian" ;           r[0].c[1].d[4].dish_price = 140;     r[0].c[1].d[4].unique_key = 110;
//
 r[0].c[2].d[0].dish_name = "Plain Dosa" ;                r[0].c[2].d[0].dish_price = 50;       r[0].c[2].d[0].unique_key = 111;
 r[0].c[2].d[1].dish_name = "Masala Dosa" ;               r[0].c[2].d[1].dish_price = 90;       r[0].c[2].d[1].unique_key = 112;
 r[0].c[2].d[2].dish_name = "Paneer Dosa" ;               r[0].c[2].d[2].dish_price = 110;      r[0].c[2].d[2].unique_key = 113;
 r[0].c[2].d[3].dish_name = "Idli Sambhar" ;              r[0].c[2].d[3].dish_price = 50;       r[0].c[2].d[3].unique_key = 114;
 r[0].c[2].d[4].dish_name = "Onion Uttappam" ;            r[0].c[2].d[4].dish_price = 130;      r[0].c[2].d[4].unique_key = 115;
//
 r[0].c[3].d[0].dish_name = "Red Sauce Pasta" ;             r[0].c[3].d[0].dish_price = 130;       r[0].c[3].d[0].unique_key = 116;
 r[0].c[3].d[1].dish_name = "White Sauce Pasta" ;           r[0].c[3].d[1].dish_price = 150;       r[0].c[3].d[1].unique_key = 117;
 r[0].c[3].d[2].dish_name = "Lasagna" ;                     r[0].c[3].d[2].dish_price = 310;       r[0].c[3].d[2].unique_key = 118;
 r[0].c[3].d[3].dish_name = "Manchow Special Pizza" ;       r[0].c[3].d[3].dish_price = 310;       r[0].c[3].d[3].unique_key = 119;
 r[0].c[3].d[4].dish_name = "Continental Soup" ;            r[0].c[3].d[4].dish_price = 230;       r[0].c[3].d[4].unique_key = 120;
//
//
 r[1].c[0].d[0].dish_name = "Makkahn Nan" ;             r[1].c[0].d[0].dish_price = 40;             r[1].c[0].d[0].unique_key = 121;
 r[1].c[0].d[1].dish_name = "Aloo Kachori" ;            r[1].c[0].d[1].dish_price = 60;             r[1].c[0].d[1].unique_key = 122;
 r[1].c[0].d[2].dish_name = "Tanduri Roti" ;            r[1].c[0].d[2].dish_price = 70;             r[1].c[0].d[2].unique_key = 123;
 r[1].c[0].d[3].dish_name = "Mix Veg Dal" ;             r[1].c[0].d[3].dish_price = 320;            r[1].c[0].d[3].unique_key = 124;
 r[1].c[0].d[4].dish_name = "Veg Pulao" ;               r[1].c[0].d[4].dish_price = 160;            r[1].c[0].d[4].unique_key = 125;
//
 r[1].c[1].d[0].dish_name = "Mix Veg Manchurian" ;             r[1].c[1].d[0].dish_price = 130;        r[1].c[1].d[0].unique_key = 126;
 r[1].c[1].d[1].dish_name = "Veg Spring Roll" ;                r[1].c[1].d[1].dish_price = 100;        r[1].c[1].d[1].unique_key = 127;
 r[1].c[1].d[2].dish_name = "Veg Paneer Momos" ;               r[1].c[1].d[2].dish_price = 90;         r[1].c[1].d[2].unique_key = 128;
 r[1].c[1].d[3].dish_name = "Hakka Noodles" ;                  r[1].c[1].d[3].dish_price = 150;        r[1].c[1].d[3].unique_key = 129;
 r[1].c[1].d[4].dish_name = "Cheese Chowmien" ;                r[1].c[1].d[4].dish_price = 140;        r[1].c[1].d[4].unique_key = 130;
//
 r[1].c[2].d[0].dish_name = "Onion Masala Uttappam" ;           r[1].c[2].d[0].dish_price = 150;       r[1].c[2].d[0].unique_key = 131;
 r[1].c[2].d[1].dish_name = "Idli Sambhar" ;                    r[1].c[2].d[1].dish_price = 70;        r[1].c[2].d[1].unique_key = 132;
 r[1].c[2].d[2].dish_name = "Paneer Dosa" ;                     r[1].c[2].d[2].dish_price = 150;       r[1].c[2].d[2].unique_key = 133;
 r[1].c[2].d[3].dish_name = "Rawa Dosa" ;                       r[1].c[2].d[3].dish_price = 120;       r[1].c[2].d[3].unique_key = 134;
 r[1].c[2].d[4].dish_name = "Plain Dosa" ;                      r[1].c[2].d[4].dish_price = 70;        r[1].c[2].d[4].unique_key = 135;
//
 r[1].c[3].d[0].dish_name = "Continental Soup" ;                r[1].c[3].d[0].dish_price = 310;                   r[1].c[3].d[0].unique_key = 136;
 r[1].c[3].d[1].dish_name = "Orchid Special Pizza" ;            r[1].c[3].d[1].dish_price = 510;                   r[1].c[3].d[1].unique_key = 137;
 r[1].c[3].d[2].dish_name = "Veg Lasagna" ;                     r[1].c[3].d[2].dish_price = 350;                       r[1].c[3].d[2].unique_key = 138;
 r[1].c[3].d[3].dish_name = "Cheeze Pasta" ;                    r[1].c[3].d[3].dish_price = 180;                       r[1].c[3].d[3].unique_key = 139;
 r[1].c[3].d[4].dish_name = "Veg Soup" ;                        r[1].c[3].d[4].dish_price = 160;                       r[1].c[3].d[4].unique_key = 140;
//
//
 r[2].c[0].d[0].dish_name = "Rumali Roti" ;             r[2].c[0].d[0].dish_price = 40;                       r[2].c[0].d[0].unique_key = 141;
 r[2].c[0].d[1].dish_name = "Veg Tadka Rice" ;                  r[2].c[0].d[1].dish_price = 150;                    r[2].c[0].d[1].unique_key = 142;
 r[2].c[0].d[2].dish_name = "Dal makhani" ;                     r[2].c[0].d[2].dish_price = 210;                    r[2].c[0].d[2].unique_key = 143;
 r[2].c[0].d[3].dish_name = "Tawa roti" ;                r[2].c[0].d[3].dish_price = 30;                   r[2].c[0].d[3].unique_key = 144;
 r[2].c[0].d[4].dish_name = "Shahi Kachori" ;             r[2].c[0].d[4].dish_price = 50;               r[2].c[0].d[4].unique_key = 145;
//
 r[2].c[1].d[0].dish_name = "Fried Momos" ;                     r[2].c[1].d[0].dish_price = 80;                        r[2].c[1].d[0].unique_key = 146;
 r[2].c[1].d[1].dish_name = "Veg Noodles" ;                     r[2].c[1].d[1].dish_price = 120;                       r[2].c[1].d[1].unique_key = 147;
 r[2].c[1].d[2].dish_name = "Singapuri Noodles" ;               r[2].c[1].d[2].dish_price = 140;                   r[2].c[1].d[2].unique_key = 148;
 r[2].c[1].d[3].dish_name = "Special Manchurian" ;              r[2].c[1].d[3].dish_price = 140;                   r[2].c[1].d[3].unique_key = 149;
 r[2].c[1].d[4].dish_name = "Veg Spring Roll" ;                 r[2].c[1].d[4].dish_price = 90;                            r[2].c[1].d[4].unique_key = 150;
//
 r[2].c[2].d[0].dish_name = "Paneer Masala Dosa" ;               r[2].c[2].d[0].dish_price = 110;                  r[2].c[2].d[0].unique_key = 151;
 r[2].c[2].d[1].dish_name = "Plain Dosa" ;                       r[2].c[2].d[1].dish_price = 50;                               r[2].c[2].d[1].unique_key = 152;
 r[2].c[2].d[2].dish_name = "Onion Masala Dosa" ;                r[2].c[2].d[2].dish_price = 90;                           r[2].c[2].d[2].unique_key = 153;
 r[2].c[2].d[3].dish_name = "Veg Onion Uttapaam" ;               r[2].c[2].d[3].dish_price = 130;                      r[2].c[2].d[3].unique_key = 154;
 r[2].c[2].d[4].dish_name = "Idli Sambhar" ;              r[2].c[2].d[4].dish_price = 50;                       r[2].c[2].d[4].unique_key = 155;
//
 r[2].c[3].d[0].dish_name = "Manchurian Soup" ;                   r[2].c[3].d[0].dish_price = 300;                     r[2].c[3].d[0].unique_key = 156;
 r[2].c[3].d[1].dish_name = "Italian Special Pasta" ;             r[2].c[3].d[1].dish_price = 130;                         r[2].c[3].d[1].unique_key = 157;
 r[2].c[3].d[2].dish_name = "White Sauce Pasta" ;                 r[2].c[3].d[2].dish_price = 150;                         r[2].c[3].d[2].unique_key = 158;
 r[2].c[3].d[3].dish_name = "Tomato Soup" ;                       r[2].c[3].d[3].dish_price = 230;                         r[2].c[3].d[3].unique_key = 159;
 r[2].c[3].d[4].dish_name = "Mix Veg Pizza" ;                     r[2].c[3].d[4].dish_price = 310;                              r[2].c[3].d[4].unique_key = 160;
//
//
 r[3].c[0].d[0].dish_name = "Mix Dal" ;                         r[3].c[0].d[0].dish_price = 310;                                      r[3].c[0].d[0].unique_key = 161;
 r[3].c[0].d[1].dish_name = "Tandoori Nan" ;             r[3].c[0].d[1].dish_price = 50;                        r[3].c[0].d[1].unique_key = 162;
 r[3].c[0].d[2].dish_name = "Veg Basmati Rice" ;                 r[3].c[0].d[2].dish_price = 190;                          r[3].c[0].d[2].unique_key = 163;
 r[3].c[0].d[3].dish_name = "Fried Kachori" ;              r[3].c[0].d[3].dish_price = 70;                          r[3].c[0].d[3].unique_key = 164;
 r[3].c[0].d[4].dish_name = "Tawa Roti" ;                 r[3].c[0].d[4].dish_price = 60;                              r[3].c[0].d[4].unique_key = 165;
//
 r[3].c[1].d[0].dish_name = "Mix Veg Noodles" ;                  r[3].c[1].d[0].dish_price = 120;                      r[3].c[1].d[0].unique_key = 166;
 r[3].c[1].d[1].dish_name = "Chinese Special Manchurian" ;       r[3].c[1].d[1].dish_price = 100;                  r[3].c[1].d[1].unique_key = 167;
 r[3].c[1].d[2].dish_name = "Chilly Potato" ;                    r[3].c[1].d[2].dish_price = 110;                              r[3].c[1].d[2].unique_key = 168;
 r[3].c[1].d[3].dish_name = "Fried Spring Roll" ;                r[3].c[1].d[3].dish_price = 120;                           r[3].c[1].d[3].unique_key = 169;
 r[3].c[1].d[4].dish_name = "Veg Kingdom Momos" ;                r[3].c[1].d[4].dish_price = 100;                    r[3].c[1].d[4].unique_key = 170;
//
 r[3].c[2].d[0].dish_name = "Paper Dosa" ;                       r[3].c[2].d[0].dish_price = 180;                              r[3].c[2].d[0].unique_key = 171;
 r[3].c[2].d[1].dish_name = "Veg Uttappaam" ;                    r[3].c[2].d[1].dish_price = 160;                          r[3].c[2].d[1].unique_key = 172;
 r[3].c[2].d[2].dish_name = "Plain Dosa" ;                       r[3].c[2].d[2].dish_price = 50;                                   r[3].c[2].d[2].unique_key = 173;
 r[3].c[2].d[3].dish_name = "Idli Sambhar" ;                     r[3].c[2].d[3].dish_price = 60;                           r[3].c[2].d[3].unique_key = 174;
 r[3].c[2].d[4].dish_name = "Onion Paneer Dosa" ;                r[3].c[2].d[4].dish_price = 150;                          r[3].c[2].d[4].unique_key = 175;
//
 r[3].c[3].d[0].dish_name = "White Sauce Pasta" ;                r[3].c[3].d[0].dish_price = 150;                              r[3].c[3].d[0].unique_key = 176;
 r[3].c[3].d[1].dish_name = "Lnug Fung Soup" ;                   r[3].c[3].d[1].dish_price = 200;                              r[3].c[3].d[1].unique_key = 177;
 r[3].c[3].d[2].dish_name = "Tomato Pasta" ;                     r[3].c[3].d[2].dish_price = 100;                                  r[3].c[3].d[2].unique_key = 178;
 r[3].c[3].d[3].dish_name = "Onion Pizza" ;                      r[3].c[3].d[3].dish_price = 280;                                      r[3].c[3].d[3].unique_key = 179;
 r[3].c[3].d[4].dish_name = "Penne Alfrendo Pasta" ;             r[3].c[3].d[4].dish_price = 220;                              r[3].c[3].d[4].unique_key = 180;
}

unordered_map<int,vector<int>> mapping_unique_keys(restuarant r[])
{
    unordered_map<int,vector<int>> mp;
    int key = 101;
    for(int i=0;i<4;i++)
     {
         for (int j=0;j<4;j++)
         {
             for (int k=0;k<5;k++)
             {
                vector<int> v;
                v.push_back(i);
                v.push_back(j);
                v.push_back(k);
                mp.insert({key,v});
                key++;
             }
         }
    }
return mp;
}


char upper_to_lower(char c)
{
    if (c >= 'a' && c <= 'z')
        return c;
    else
        return c + 32;
}




class node
{
public:
    char data;
    node *children[27];
    vector<int> primary_key;
    bool isterminal;

    node(char d)
    {
        data = d;
        for (int i = 0; i < 27; i++)
        {
            children[i] = NULL;
        }
        isterminal = false;
        primary_key.push_back(-1);
    }
};

class trie
{
public:
    node *root;
    trie()
    {
        root = new node('\0');
    }

    void insert_utility_function(node *root, string word, int key)
    {
        if (word.length() == 0)
        {
            root->isterminal = true;
            root->primary_key.push_back(key);
            return;
        }
        int index;
        if (upper_to_lower(word[0]) >= 'a' && upper_to_lower(word[0]) <= 'z')
        {
            index = upper_to_lower(word[0]) - 'a';
        }
        else
        {
            index = 26;
        }
        node *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new node(word[0]);
            root->children[index] = child;
        }
        insert_utility_function(child, word.substr(1), key);
    }

    void insert_substring_of_strings(string s, int key)
    {
        for (int i = 1; i <= s.length(); i++)
        {
            string st = s.substr(s.length() - i, i);
            insert_utility_function(root, st, key);
        }
    }

    void search_utility_function(node *root, string word, vector<vector<int>> &find_keys)
    {
        // base case
        if (word.length() == 0)
        {
            if (root->isterminal == true)
            {
                find_keys.push_back(root->primary_key);
            }
            return;
        }
        int index;
        if (upper_to_lower(word[0]) >= 'a' && upper_to_lower(word[0]) <= 'z')
        {
            index = upper_to_lower(word[0]) - 'a';
        }
        else
        {
            index = 26;
        }
        node *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            return;
        }
        search_utility_function(child, word.substr(1), find_keys);
    }

    void search_word(string word, vector<vector<int>> &find_keys)
    {
        search_utility_function(root, word, find_keys);
        find_from_prefix(root, word, find_keys);
    }

    bool isLastNode(node *root)
    {
        for (int i = 0; i < 27; i++)
            if (root->children[i])
                return 0;
        return 1;
    }

    void find_from_prefix_utillity(node *root, string prefix, vector<vector<int>> &v)
    {
        if (root->isterminal)
        {
            v.push_back(root->primary_key);
        }
        int i = 0;
        char child;
        for (i = 0; i < 27; i++)
        {

            if (root->children[i] && i < 26)
            {
                child = 'a' + i;
                find_from_prefix_utillity(root->children[i], prefix + child, v);
            }
            if (i == 26 && root->children[i])
            {
                child = ' ';
                find_from_prefix_utillity(root->children[i], prefix + child, v);
            }
        }
    }

    void find_from_prefix(node *root, string text, vector<vector<int>> &v)
    {
        node *temp = root;
        for (char c : text)
        {
            int ind;
            if (upper_to_lower(c) >= 'a' && upper_to_lower(c) <= 'z')
            {
                ind = upper_to_lower(c) - 'a';
            }
            else
            {
                ind = 26;
            }
            // no string in the Trie has this prefix
            if (!temp->children[ind])
                return;
            temp = temp->children[ind];
        }
        // If prefix is present as a word, but there is no subtree below the last matching node.
        if (isLastNode(temp))
        {
            cout << text << endl;
            v.push_back(temp->primary_key);
            return;
        }
        find_from_prefix_utillity(temp, text, v);
        return;
    }

    void insert_dishes(vector<string> s, vector<int> key)
    {
        for (int i = 0; i < s.size(); i++)
        {

            insert_substring_of_strings(s[i], key[i]);
        }
    }
};

unordered_set<int> primary_key_dishes(vector<vector<int>> a)
{
    unordered_set<int> s;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            s.insert(a[i][j]);
        }
    }
    return s;
}
void dish_wish(restuarant r[])
{
    trie *t = new trie();
    vector<string> name;
    vector<int> key;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                name.push_back(r[i].c[j].d[k].dish_name);
                key.push_back(r[i].c[j].d[k].unique_key);
            }
        }
    }
    t->insert_dishes(name, key);
    vector<vector<int>> key_storing;
    cout << "Please enter the dish you want to search" << endl;
    string entered_string;
    cin >> entered_string;
    t->search_word(entered_string, key_storing);
    unordered_set<int> dish_keys = primary_key_dishes(key_storing);
    dish_keys.erase(-1);
    display_dishes(dish_keys);
}

void display_dishes(unordered_set<int> dish_keys)
{
    restuarant r[4];
    initiallize_class(r);
    unordered_map<int, vector<int>> element_key = mapping_unique_keys(r);
    vector<pair<int, pair<string, int>>> p;
    vector<int> price_sort;
    unordered_map<int, int> display_sorted;
    for (auto key : dish_keys)
    {
        auto it = element_key.find(key);
        vector<int> v = it->second;
        price_sort.push_back(r[v[0]].c[v[1]].d[v[2]].dish_price);
        display_sorted.insert({r[v[0]].c[v[1]].d[v[2]].dish_price, r[v[0]].c[v[1]].d[v[2]].unique_key});

        cout << setw(20) << r[v[0]].c[v[1]].d[v[2]].dish_name << " \t ";
        cout << setw(20) << r[v[0]].c[v[1]].d[v[2]].dish_price << "\t";
        cout << setw(20) << r[v[0]].c[v[1]].d[v[2]].unique_key << endl<< endl;
    }
}



void cart(restuarant r[],unordered_map<int,vector<int>> element_key)
{
int track_order_validation_count=0,total_cost=0,yes_add_item,place_or_cancel ,cost;
int entered_unique_key,quant;
   vector <string> outlet_code;
   vector<string> cuisine_code;
    vector <string> dish_name_code;
   vector <int> dish_price_code;
   vector<int> quantity;
try
{
rechoice_unique_key:
cout<<"Enter the unique key of the dish : ";
cin>>entered_unique_key;

if (!((entered_unique_key>=101  && entered_unique_key<=180)))
{  track_order_validation_count++;
if (track_order_validation_count>5)
{
    throw 2;
}
    cout<<("Enter a valid unique key \n");
goto rechoice_unique_key;
}
track_order_validation_count=0;
    auto it = element_key.find(entered_unique_key);
    vector<int>v= it->second;
outlet_code.push_back(r[v[0]].name_of_restaurant);
     cuisine_code.push_back(r[v[0]].c[v[1]].cuisine_name);
    dish_name_code.push_back(r[v[0]].c[v[1]].d[v[2]].dish_name);
    dish_price_code.push_back(r[v[0]].c[v[1]].d[v[2]].dish_price );
    rechoice_quantity :
    cout<<"Please enter its quantity  :    ";
    cin>>quant;
    if (!(quant>0))
    {  track_order_validation_count++;
    if (track_order_validation_count>5)
    {
    throw 2;
    }
    cout<<("Enter a valid quantity\n");
    goto rechoice_quantity;
    }
    quantity.push_back(quant);
cout<<("Do you wish to select any other item \n");
    track_order_validation_count=0;
no_yes:
cout<<("press 1 for next choice and 0 for bill\n");
cin>>yes_add_item;
if (yes_add_item==1)
   {
      goto rechoice_unique_key;
   }
else if(yes_add_item==0)
    {
        cout<<("your orders are : \n");
        int destination ;
        cout<<"enter your destination";
        cin>>destination;
        vector<int> out= { 1,2,3};
        cost=  calculate_distance(out,destination);
    for(int i =0;i<dish_name_code.size();i++)
    {
        cout<<setw(20)<<outlet_code[i]<<"\t";
        cout<<setw(20)<<cuisine_code[i] <<"\t";
        cout<<setw(20)<<dish_name_code[i]<<"\t";
        cout<<setw(20)<<dish_price_code[i]<<"\t";
        cout<<setw(20)<<quantity[i]<<"\t"<<endl;
    total_cost = total_cost +(dish_price_code[i]*quantity[i]);
    }
    }
    else
{
          track_order_validation_count++;
if (track_order_validation_count>5)
    {
    throw 2;
    }
    cout<<"!!!      Please enter a valid choice      !!!"<<endl;
    goto no_yes ;
    }
    cout<<setw(20)<<"\t\t\t  DILEVERY CHARGES = "<<cost<<endl;
  cout<<endl<<"--------------------\t--------------------\t--------------------\t--------------------\t--------------------\t"<<endl;
cout<<"The total amount to be paid :"<<endl;
  cout<<setw(90)<<total_cost<<endl;
cout<<("Press 0 for cancelling your order and 1 for placing your order\n");
cin>>place_or_cancel;
if (place_or_cancel==0)
    {
       feedback();
    exit(0);}
else if (place_or_cancel==1)
{
    cout<<("Please verify yourself before confirming your order\n");
    verification_2();
}
else
{
      track_order_validation_count++;
if (track_order_validation_count>5)
    {
    throw 2;
    }
    cout<<("Please enter a valid choice");
    goto no_yes ;
    }
    }

catch(int a)
    {
        cout<<"sorry !!         unsuccessfull order       " <<endl<<"!!        Please try again later          !!" <<endl;
        exit(0);
    }
}

class payment
{
    int month,year,bank,choice,change_mode;
    char card[100],pin[10], cvv[5],otp[5],upi_id[20];
    public :
         time_t t = time(NULL);
 tm* tPtr = localtime(&t);
        int change_payment_mode;
    int paymentmethod,a=0,i;
    int payment_mode_choice()
    {
       int  check_payment_validation_count=0;
 try
 {
start :
 cout<<"Enter whether you want to pay by card, UPI OR cash:\n";
 cout<<"Enter 1 , 2 OR 3  Respectively\n";
 cin>>paymentmethod;
 if (!((paymentmethod == 1) || (paymentmethod == 2)  || (paymentmethod == 3)))
 {  check_payment_validation_count++;
 if (check_payment_validation_count>5)
 {
     throw 2;
 }
    cout<<"Please enter a valid payment method according to choice \n";
    goto start;
 }
 }
  catch(int a)
    {
        cout<<"sorry !!         wrong choice      " <<endl<<"!!        Please try again later          !!" <<endl;
        exit(0);
    }
    return paymentmethod;
    }
    int payment_mode_1()
    {
        int validation_choice_count_mode_1=0;
        try
        {
 rechoice_bank :
 cout<<"Which bank would like to choose \n";
cout<<"1. STATE BANK OF INDIA \n";
cout<<"2. KOTAK MAHINDRA BANK\n";
cout<<"3. HDFC BANK\n";
cout<<"4. BANK of BARODA\n";
cout<<"5. PUNJAB NATIONAL BANK\n";
 cin>>bank;
 if (!((bank==1) || (bank==2)|| (bank==3) || (bank==4) || (bank==5) ))
 {
        validation_choice_count_mode_1++;
        if (validation_choice_count_mode_1>5)
        {
            throw 2;
        }
     cout<<"Please enter a valid choice according to bank number in the list\n";
     goto rechoice_bank;
 }
 validation_choice_count_mode_1=0;
recard_no:
printf("Enter your 16 digit card number \n");
cin>>card;
if (strlen(card)!=16)
 {
     validation_choice_count_mode_1++;
     if (validation_choice_count_mode_1>2)
        {
            throw 2;
        }
     cout<<"Please enter a valid card number\n";
     goto recard_no;
}
validation_choice_count_mode_1=0;
 remonth:
 cout<<"Enter your card expiry month from (1-12) :\n";
 cin>>month;
 if (!((month ==1) || (month ==2) ||(month ==3) ||(month ==4) ||(month ==5) ||(month ==6) ||(month ==7) ||(month ==8) ||(month ==9) ||(month ==10) ||(month ==11) ||(month ==12)))
      {    validation_choice_count_mode_1++;
        if (validation_choice_count_mode_1>5)
        {
            throw 2;
        }
        cout<<"Please enter a valid month \n";
       goto remonth;
           }
           validation_choice_count_mode_1=0;
reyear:
 cout<<"Enter your card expiry year :\n";
 cin>>year;
          if(((year ==2023)&&( (tPtr->tm_mon)+1>month)))
          {
              validation_choice_count_mode_1++;
              if (validation_choice_count_mode_1>5)
        {
            throw 2;
        }
cout<<"Please enter a valid date\n";
    goto remonth;
          }
          validation_choice_count_mode_1=0;
 if (!((year ==2027) || (year ==2023)|| (year ==2024)|| (year ==2025)|| (year ==2026)))
      {
          if (validation_choice_count_mode_1>5)
        {
            throw 2;
        }
    cout<<"Please enter a valid year\n";
    goto reyear;
        }
        validation_choice_count_mode_1=0;
 new_cvv:
 cout<<"Enter your 3 digit CVV:\n", cvv;
cin>>cvv;
 if (strlen(cvv)!=3)
 {
     validation_choice_count_mode_1++;
               if (validation_choice_count_mode_1>5)
        {
            throw 2;
        }
     cout<<"Please enter a valid CVV\n";
goto new_cvv;}
validation_choice_count_mode_1=0;
 changepin:
 cout<<"Please enter your four digit OTP\n ";
cin>>pin;
 if (strlen(pin)!=4)
 {
     validation_choice_count_mode_1++;
               if (validation_choice_count_mode_1>5)
        {
            throw 2;
        }
        if (validation_choice_count_mode_1==2)
        {
             cout<<"Do you want to change the mode of payment\n";
     cout<<"Enter 0 for choosing another mode or press any key to continue with this mode\n";
     cin>>change_payment_mode;
     if (change_payment_mode==0)
        {
        return 1;
        }
        cout<<"!!           THIS  IS YOUR LAST TRY  !!!         BE CAREFUL              !!!"<<endl;
        }
     cout<<"Please enter a 4 digit OTP\n";
goto changepin;
}
 }
 catch(int a)
    {
        cout<<"sorry !!          unsuccessful payment      " <<endl<<"!!        Please try again later          !!" <<endl;
        exit(0);
    }
return 0;
    }
   int payment_mode_2 ()
    {
        int validation_choice_count_mode_2=0;
        try
        {
 choice_app_for_payment :
 cout<<"Which UPI app you want to use ?\n 1.PAYTM\n 2.PHONEPAY\n 3.GOOGLE PAY\n";
cin>>choice;
 if (!((choice==1)  || (choice==2)  ||  (choice==3)  ))
 {
     validation_choice_count_mode_2++;
     if (validation_choice_count_mode_2 >5)
        {
            throw 2;
        }
     cout<<"Enter a valid choice of app\n";
        goto choice_app_for_payment;
    }
    validation_choice_count_mode_2=0;
 re_upi_id :
 cout<<"Enter your UPI ID:\n";
 cin>>upi_id;
 while(upi_id[i]!='\0')
         {{if (upi_id[i]=='@')
            a++;}
            i++;}
 if ((a!=1) || (!(a<i)))
    {           validation_choice_count_mode_2++;
    if (validation_choice_count_mode_2 >5)
        {
            throw 2;
        }
                cout<<"Please enter a valid UPI ID\n";
 goto re_upi_id;
    }
 validation_choice_count_mode_2=0;
 new_OTP:
 cout<<"Please enter your four digit OTP\n ";
 cin>>otp;
 if (strlen(otp)!=4)
    {
        validation_choice_count_mode_2++;
        if (validation_choice_count_mode_2 >5)
        {
            throw 2;
        }
        if (validation_choice_count_mode_2==2)
        {
             cout<<"Do you want to change the mode of payment\n";
     cout<<"Enter 0 for choosing another mode or press any key to continue with this mode\n";
     cin>>change_payment_mode;
     if (change_payment_mode==0)
        {
        return 1;
        }
        cout<<"!!           THIS  IS YOUR LAST TRY  !!!         BE CAREFUL              !!!"<<endl;
        }
        cout<<"Please enter a 4 digit OTP\n";
goto new_OTP;
}
}
   catch(int a)
    {
        cout<<"sorry !!          unsuccessful payment      " <<endl<<"!!        Please try again later          !!" <<endl;
        exit(0);
    }
        return 0;
        }
 int payment_mode_3()
 {
 int response;
 cout<<"DURING THESE TOUGH TIMES WE RECCOMEND PEOPLE AVOIDING THE USE OF CASH\n";
 cout<<"WOULD YOU STILL LIKE TO PAY BY CASH\n";
 cout<<"PRESS 1. For YES and 2. For NO\n";
 cin>>response;
 if(response==1)
 {
 cout<<"Please pay the amount to the delivery boy  \n";
 return 0;
 }
 if(response==2)
 {
 return 1;
 }
 }
};

void feedback()
{
   system("cls");
   char star[5],verification_validity_count=0;
    cout<<"\nPlease enter your valuable feedback\n";
 try
 {
     re_feedback:
    cout<<"\nEnter the number of stars from 1-5 as per your wishes\n";
    cin>>star;
 for(int i=0;i<strlen(star);i++)
 {
    if((star[i]!='*')||(strlen(star)>5))
    {
        verification_validity_count++;
        if (verification_validity_count>5)
           {
           throw 2;
           }
           cout<<"Please enter the feedback in correct format "<<endl;
           goto re_feedback ;
    }
 }
 }
    catch (int a)
    {
     cout<<"   !!!          Please try again later              !!!"<<endl;
    }
    cout<<("Thank you for visiting our system \t\t\t Please visit again next time ");
    exit(0);
}

 void verification_1()
{
    int first_number,second_number,for_operation,input_answer,actual_answer,check_count_verification_1=0;
    cout<<"Please verify yourself "<<endl<<endl;
    srand(time(0));
    try
    {
    different_values :
    first_number= rand()%25;
    reallocating_number :
    second_number= rand()%25;
    for_operation=rand()%4+1;
    cout<<"Please enter the correct value after the operation between two numbers"<<endl<<endl;
    if (for_operation==1)
    {
        actual_answer=first_number+second_number;
        cout<<first_number<<"  +  " <<second_number<<"  =  ";
    }
  if (for_operation==2)
    {
        actual_answer=first_number-second_number;
        cout<<first_number<<"  -  " <<second_number<<"  =  ";
    }
  if (for_operation==3)
    {
        actual_answer=first_number*second_number;
        cout<<first_number<<"  *  " <<second_number<<"  =  ";
    }
  if (for_operation==4)
    {
        if (second_number==0)
        {
            goto reallocating_number;
        }
        actual_answer=first_number/second_number;
        cout<<first_number<<"  /  " <<second_number<<"  =  ";
        cout<<"Please type the integral value of the result"<<endl;
    }
cin>>input_answer;
if(input_answer!=actual_answer)
{
    check_count_verification_1++;
    if(check_count_verification_1>5)
    {
        throw 2;
    }
    cout<<"ERROR !!!     Please try again  "<<endl<<endl;
    goto  different_values;
}
cout<<" Congratulation you have successfully verified"<<endl<<endl;
    }
    catch(int a)
    {
        cout<<"sorry !!         unsuccessfull verification      " <<endl<<"!!        Please try again later          !!" <<endl;
        exit(0);
    }
    system("cls");
}
void verification_2()
    {
    int i,first_row,second_row,third_row,fourth_row,fifth_row,input_answer,actual_answer,check_count_verification_2=0;
    cout<<"Please verify yourself "<<endl<<endl;
    srand(time(0));
    try
{
    different_values :
    first_row= rand()%4+1;
    second_row = rand()%4+1;
    third_row = rand()%4+1;
    fourth_row = rand()%4+1;
    fifth_row = rand()%4+1;
    actual_answer= first_row+second_row+third_row+fourth_row+fifth_row;
    for(i=0;i< first_row;i++)
        {
            cout<<" * ";
        }
        cout<<endl;
        for(i=0;i< second_row;i++)
        {
            cout<<" * ";
        }
        cout<<endl;
        for(i=0;i< third_row;i++)
        {
            cout<<" * ";
        }
        cout<<endl;
        for(i=0;i< fourth_row;i++)
        {
            cout<<" * ";
        }
        for(i=0;i< fifth_row;i++)
        {
            cout<<" * ";
        }
        cout<<endl<<endl;
        cout<<"Please enter the total number of stars in the displayed pattern  :   ";
        cin>>input_answer;
        if(input_answer!=actual_answer)
{   check_count_verification_2++;
    if(check_count_verification_2>5)
    {
        throw 2;
    }
    cout<<"ERROR !!!     Please try again  "<<endl<<endl;
    goto  different_values;
cout<<endl<<endl<<" Congratulation you have successfully verified"<<endl<<endl;
}
    }
    catch(int a)
    {
        cout<<"sorry !!         unsuccessfull verification      " <<endl<<"!!        Please try again later          !!" <<endl;
        exit(0);
    }
}

int main()
{
    int choice_of_display,cuisine,validation_display_count=0,different_cuisine, choice_another_medium;
    int payment_status;
    string line;
    cout<<" \t\t\t\tWELCOME TO COKOMOCO FOOD DELEVERING SYSTEM"<<endl<<endl;
    cout<<"We provide a wide range of food items at tourist spot dehradun from the most trusted and hygenic outlets" <<endl;
    cout<<" Before we continue forward   ";
    verification_1();
customer_detials c1;
c1.get_personal_details();
restuarant R[4];
    initiallize_class (R);
    unordered_map<int,vector<int>> element_key=mapping_unique_keys(R);
    system("cls");
    rechoice_display_type:
cout<<"Please select how you want to go         (1) outlet_wise \n  \t\t\t\t\t (2) cuisine_wise  \n    \t\t\t\t\t (3) search dish name "  <<endl;
cin>>choice_of_display;
try
{
    if (!((choice_of_display==1)||(choice_of_display==2)||(choice_of_display==3)))
    {
        validation_display_count++;
        if (validation_display_count>5)
        {
            throw 2;
        }
        cout<<"!!!          Please enter a valid choice              !!!"<<endl;
        goto rechoice_display_type;
    }
        else if (choice_of_display==1)
        {
ifstream myfile ("outlet.txt");
if (myfile.is_open()) {
while ( getline (myfile,line) )
    {
cout << line << '\n';
}
myfile.close();
}
else
{
cout << "Unable to open file";
}
}
else if (choice_of_display==2)
        {
            cout<<"Please select your desired cuisine"<<endl;
            cout<<"  1)    North Indian  "<<endl<<"  2)    South Indian  "<<endl<<"  3)    Chinese Corner "<<endl<<"  4)    Italian "<<endl;
            int choice;
            cin>>choice;
            if (!(choice==1 || choice==2 ||choice==3 ||choice==4 ))
            {
        validation_display_count++;
        if (validation_display_count>5)
        {
            throw 2;
        }
        cout<<"!!!          Please enter a valid choice              !!!"<<endl;
        goto rechoice_display_type;
    }
    else
        {
            if (choice==1)
            {
                ifstream myfile ("north_indian.txt");
                    if (myfile.is_open())
                        {
                while ( getline (myfile,line) )
                    {
                    cout << line << '\n';
                    }
            myfile.close();
          }
                else
                {
                cout << "Unable to open file";
        }}
        if (choice==2)
            {
                ifstream myfile ("south_indian.txt");
                    if (myfile.is_open())
                        {
                while ( getline (myfile,line) )
                    {
                    cout << line << '\n';
                    }
            myfile.close();
                    }
                else
                {
                cout << "Unable to open file";
                }
        }
        if (choice==3)
            {
                ifstream myfile ("chinease_corner.txt");
                    if (myfile.is_open())
                        {
                while ( getline (myfile,line) )
                    {
                    cout << line << '\n';
                    }
            myfile.close();
                    }
                else
                {
                cout << "Unable to open file";
        }}
        if (choice==4)
            {
                ifstream myfile ("italian.txt");
                    if (myfile.is_open())
                        {
                while ( getline (myfile,line) )
                    {
                    cout << line << '\n';
                    }
            myfile.close();
                    }
                else
                {
                cout << "Unable to open file";
                }
        }
        }}
else if (choice_of_display==3)
{
    dish_wish(R);
}
    choice_to_select_another_medium:
cout<<"Do you want to search any other way    please enter "<<endl;
cout<<" 1)  to continue to cart "<< " 2)  to select any other medim"<<endl;
cin>>choice_another_medium;
if (!(choice_another_medium == 1 ||  choice_another_medium ==2 ))
{
        validation_display_count++;
        if (validation_display_count>5)
        {
            throw 2;
        }
        cout<<"!!!          Please enter a valid choice              !!!"<<endl;
        goto choice_to_select_another_medium;
    }
    if (choice_another_medium==2)
    {
    goto rechoice_display_type;
    }
}
        catch(int a)
    {
        cout<<"sorry !!          wrong choice        " <<endl<<"!!        Please try again later          !!" <<endl;
        exit(0);
    }
    cart(R,element_key);
    system("cls");
payment p1;
int choice_of_payment=p1.payment_mode_choice();
rechose_payment:
if (choice_of_payment==1)
{
    payment_status=p1.payment_mode_1();
}
if (choice_of_payment==2)
{
    payment_status=p1.payment_mode_2();
}
if (choice_of_payment==3)
{
    payment_status=p1.payment_mode_3();
}
if (payment_status==1)
{
goto rechose_payment;
}
if (payment_status==0)
{
cout<<"!!!           CONGRATULATION  ORDER PLACED SUCCESSFULLY                !!!"<<endl;
cout<<endl<<" ."<<endl;
}
feedback();
   return 0;
}
