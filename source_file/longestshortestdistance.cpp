#include "..\\header_file\\longestshortestdistance.h"

string LongestShortestDistance::solve(string s)
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
    string n=v[0],a=v[1],b=v[2],al_or_ra=v[3];
    string ld,sd,s2;
    if(al_or_ra=="al"){
        s2="select max(distance),min(distance) from (";
        s2+="select round(sqrt(pow(a.round_lon-b.round_lon,2)+pow(a.round_lat-b.round_lat,2)),4) as distance from ";
        s2+="(select * from(select id,country,city,round(lat,"+n+") as round_lat,round(lon,"+n+") as round_lon from CITYTABLE group by round_lat,round_lon) as aa ";
        s2+="order by city asc,id asc limit "+to_string(stoi(a)-1)+","+to_string(stoi(b)-stoi(a)+1)+") as a ";
        s2+="inner join ";
        s2+="(select * from(select id,country,city,round(lat,"+n+") as round_lat,round(lon,"+n+") as round_lon from CITYTABLE group by round_lat,round_lon) as bb ";
        s2+="order by city asc,id asc limit "+to_string(stoi(a)-1)+","+to_string(stoi(b)-stoi(a)+1)+") as b ";
        s2+="on a.round_lat!=b.round_lat or a.round_lon!=b.round_lon) as c";
    }
    else if(al_or_ra=="ra"){
        s2="select max(distance),min(distance) from (";
        s2+="select round(sqrt(pow(a.round_lon-b.round_lon,2)+pow(a.round_lat-b.round_lat,2)),4) as distance from ";
        s2+="(select * from(select id,country,city,round(lat,"+n+") as round_lat,round(lon,"+n+") as round_lon from CITYTABLE group by round_lat,round_lon) as aa ";
        s2+="order by city desc,id asc limit "+to_string(stoi(a)-1)+","+to_string(stoi(b)-stoi(a)+1)+") as a ";
        s2+="inner join ";
        s2+="(select * from(select id,country,city,round(lat,"+n+") as round_lat,round(lon,"+n+") as round_lon from CITYTABLE group by round_lat,round_lon) as bb ";
        s2+="order by city desc,id asc limit "+to_string(stoi(a)-1)+","+to_string(stoi(b)-stoi(a)+1)+") as b ";
        s2+="on a.round_lat!=b.round_lat or a.round_lon!=b.round_lon) as c";
    }

    query.exec(QString::fromStdString(s2));
    stringstream token;
    query.next();
    if(query.value(0).isNull())
        token<<"NULL NULL";
    else
        token<<fixed<<setprecision(4)<<query.value(0).toDouble()<<" "<<query.value(1).toDouble();

    return token.str();
}
