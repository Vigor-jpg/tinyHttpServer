#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <map>

#define DEMAND_DIR "/data/demand.csv"
#define QOS_DIR "/data/qos.csv"
#define SITE_BANDWIDTH_DIR "/data/site_bandwidth.csv"
#define OUTPUT_DIR "/output/solution.txt"
#define CONFIG_DIR "/data/config.ini"

//暂时先这样用这个限制
int QOS_CONSTRAINS;

using namespace std;

struct base
{
    // virtual void readfile() = 0;
};

struct site;
struct client : public base
{
    string name;
    int demand;              //带宽需求
    static unsigned int num; // client 数量

    client() {}
    client(string _name, int _demand) : name(_name), demand(_demand) {}

    // virtual void readfile() override;

    vector<shared_ptr<site>> v_ptr2site; //分配的site
};

struct site : public base
{
    string name;
    bool full = false;
    int max_bandwidth;
    int bandwidth_left;

    site() {}
    site(string _name, int _max_bandwidth) : name(_name), max_bandwidth(_max_bandwidth) ,bandwidth_left(_max_bandwidth){}

    vector<shared_ptr<client>> v_ptr2client; //边缘端列表
};

struct demand //客户c向边缘s申请的带宽demand
{
    int width_demand = 0;
    int qos;
    bool exist = true;     // if  qos < qos_constrains  exist = true;

    demand(int _qos)
        : qos(_qos){}
};

struct brand_allocat{
    bool exist;
    int qos;
    int width_allocat;
    brand_allocat(int _qos) : qos(_qos){
        this->exist = qos < QOS_CONSTRAINS;
    }
};
map<string,site*> sites;                                     /*site_name为key,site为value*/

map<string,client*> clients;                                 /*client_name为key,client为value*/

vector<vector<string>> demand_table;                         /*demand.csv中第一列有需求的client的name*/

map<pair<string,string> ,brand_allocat*> qos_table;          /*qos分配表*/

ifstream demand_stream(DEMAND_DIR,ios::in);

ofstream outpus_stream(OUTPUT_DIR,ios::out);

//读取有需求的client
void demand_table_init(){
    if(!demand_stream){
        cout << "file error !"<<endl;
    }
    string str_line;
    getline(demand_stream,str_line);
    stringstream ss(str_line);
    string str;
    int i = -1;
    vector<string> title;
    while(getline(ss,str,',')){
        i++;
        title.push_back(str);
    }
    demand_table.push_back(title);
    vector<string> content(title.size());
    demand_table.push_back(content);
}

vector<pair<string,long long>> get_weight(string client_name,long long need){
    vector<pair<string,long long>> res;
    long long all = 0;
    for(auto &site : sites){
        brand_allocat *brandAllocat = qos_table[{site.first,client_name}];
        if(brandAllocat->exist){
            long long weight = site.second->bandwidth_left;
            all += weight;
            res.push_back({site.first,weight});
        }
    }
    /*if(all < need){
        perror("error in allocate!");
    }*/
    res.push_back({"total",all});
    return res;
}
void read_demand_content(){
    string str_line;
    getline(demand_stream,str_line);
    stringstream ss(str_line);
    string str;
    int i = -1;
    vector<string> title;
    while(getline(ss,str,',')){
        i++;
        demand_table[1][i] = str;
    }
}
bool demand_data_sort(pair<int,string> p1,pair<int,string> p2){
    return p1.first > p2.first;
}
void allocat_brand(){
    if(!outpus_stream){
        cout << "file err" <<endl;
    }
    vector<pair<int,string>> demand_data;
    for(int i = 1;i < demand_table[0].size();i++){
        demand_data.push_back({atoi(demand_table[1][i].c_str()),demand_table[0][i]});
    }
    sort(demand_data.begin(),demand_data.end(),demand_data_sort);
    for(int i = 0;i < demand_data.size();i++){
        vector<pair<string,long long>> weight = get_weight(demand_data[i].second,demand_data[i].first);
        int n = weight.size();
        int has_allocat = 0;
        outpus_stream << demand_data[i].second << ":";
        for(int j = 0;j < n-1;j++){
            int allcat = 0;
            if(j != n-2){
                allcat = ((double )weight[j].second / weight[n-1].second)*demand_data[i].first;
            }else{
                allcat = demand_data[i].first - has_allocat;
            }
            has_allocat += allcat;
            sites[weight[j].first]->bandwidth_left -= allcat;
            /*if(sites[weight[j].first]->bandwidth_left <= 0){
                sites[weight[j].first]->full = true;
            }*/
            qos_table[{weight[j].first,demand_data[i].second}]->width_allocat = allcat;
            outpus_stream << "<" << weight[j].first << "," << allcat << ">";
        }
        outpus_stream << endl;
    }
}

void read_site_bandwidth() // site 的 readfile
{
    ifstream is(SITE_BANDWIDTH_DIR, ios::in);
    if (!is)
        cout << "read file error " << endl;
    string lineStr;
    vector<vector<string>> strArray;
    int count;
    while (getline(is, lineStr))
    {
        // cout << lineStr << endl;
        stringstream ss(lineStr);
        string str;
        vector<string> lineArray;
        //按逗号分隔
        while (getline(ss, str, ','))
            lineArray.push_back(str);
        // cout<<lineArray[0]<<endl;
        strArray.push_back(lineArray);
    }
    for (int i = 1; i < strArray.size(); ++i)
    {
        site *_s = new site(strArray[i][0], atoi(strArray[i][1].c_str()));
        sites[strArray[i][0]] = _s;
    }
}

//读取qos 
void readqos()
{
    ifstream is(QOS_DIR, ios::in);
    if (!is)
        cout << "read file error " << endl;
    string lineStr;
    vector<vector<string>> strArray;
    int count;
    while (getline(is, lineStr))
    {
        // cout << lineStr << endl;
        stringstream ss(lineStr);
        string str;
        vector<string> lineArray;
        //按逗号分隔
        while (getline(ss, str, ','))
            lineArray.push_back(str);
        // cout<<lineArray[0]<<endl;
        strArray.push_back(lineArray);
    }
    for(int i = 1;i < strArray.size();i++){
        for(int j = 1;j < strArray[0].size();j++){
            qos_table[{strArray[i][0],strArray[0][j]}] = new brand_allocat(atoi(strArray[i][j].c_str()));
        }
    }
}
void clear(){
    for(auto &site : sites){
        site.second->bandwidth_left = site.second->max_bandwidth;
        site.second->full = false;
    }
    for(auto &allocat : qos_table){
        allocat.second->width_allocat = 0;
    }
}
void readConfig(){
    ifstream is(CONFIG_DIR,ios::in);
    if(!is){
        perror("file error");
    }
    string line_str;
    getline(is,line_str);
    getline(is,line_str);
    stringstream ss(line_str);
    string string1;
    getline(ss,string1,'=');
    getline(ss,string1,'=');
    QOS_CONSTRAINS = atoi(string1.c_str());
}
int main()
{
    readConfig();

    readqos();

    read_site_bandwidth();

    demand_table_init();

    while(!demand_stream.eof()){
        clear();
        read_demand_content();
        allocat_brand();
        //break;
    }
    return 0;
}
