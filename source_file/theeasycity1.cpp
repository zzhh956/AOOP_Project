#include "..\\header_file\\theeasycity1.h"

string TheEasyCity1::solve(string s)
{
    query.exec("drop database if exists CITYDATABASE");
    query.exec("create database CITYDATABASE");
    query.exec("use CITYDATABASE");

    query.exec("drop table if exists CITYTABLE");
    query.exec("create table CITYTABLE (id int primary key,country varchar(50),city varchar(60),lat double,lon double)");
    query.exec("load data infile'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' into table citytable fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");
    query.exec("SET SQL_SAFE_UPDATES=0;");

    vector<string> v;
    v=stringtoVectorString(s);
    string ch=v[0],ev_or_od=v[5],even_or_odd=v[7],asc_or_des=v[8];
    string la=v[1],lo=v[2],p=v[3],q=v[4],m=v[6],n=v[9];
    string dcc,sla,slo,dmm;
    stringstream token;

    //--------------------------------1
    string s2="select count(city)-count(distinct city) from(select * from citytable where city regexp '^[";
    s2+=ch+"]' and lat>"+la+" and lon<"+lo+") as a where city regexp '[^aeiou]$'";
    query.exec(QString::fromStdString(s2));
    query.next();
    dcc= query.value(0).toString().toStdString();
    token<<dcc;
    //--------------------------------2
    if(ev_or_od=="ev")
        s2="update citytable set lat=lat*"+p+" , lon=lon*"+q+" where id%2=0";
    else if(ev_or_od=="od")
        s2="update citytable set lat=lat*"+p+" , lon=lon*"+q+" where id%2=1";
    query.exec(QString::fromStdString(s2));

    //--------------------------------3
    if(even_or_odd=="even"){
        s2="select round(sum(lat),"+n+") as lat_sum,round(sum(lon),"+n+") as lon_sum,(max(length(city))-min(length(city))) as diff from (select * from citytable where id%2=0  order by length(city) ";
        if(asc_or_des=="asc")
            s2+="asc,city desc limit "+m+") as a";
        else if(asc_or_des=="des")
            s2+="desc,city desc limit "+m+") as a";
    }
    else if(even_or_odd=="odd"){
        s2="select round(sum(lat),"+n+") as lat_sum,round(sum(lon),"+n+") as lon_sum,(max(length(city))-min(length(city))) as diff from (select * from citytable where id%2=1  order by length(city) ";
        if(asc_or_des=="asc")
            s2+="asc,city desc limit "+m+") as a";
        else if(asc_or_des=="des")
            s2+="desc,city desc limit "+m+") as a";
    }
    query.exec(QString::fromStdString(s2));
    //--------------------------------answer

    query.next();
    sla= query.value(0).toString().toStdString();
    slo= query.value(1).toString().toStdString();

    dmm= query.value(2).toString().toStdString();
    token<<" "<<fixed<<setprecision(stoi(n))<<query.value(0).toDouble()<<" "<<query.value(1).toDouble()<<" ";
    token<<dmm;

    return token.str();
}
