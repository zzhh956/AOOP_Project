#include "..\\header_file\\manhattandistance.h"

string ManhattanDistance::solve(string ss)
{
    query.exec("drop database if exists CITYDATABASE");
    query.exec("create database CITYDATABASE");
    query.exec("use CITYDATABASE");

    query.exec("drop table if exists CITYTABLE");
    query.exec("create table CITYTABLE (id int primary key,country varchar(50),city varchar(60),lat double,lon double)");
    query.exec("load data infile'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' into table citytable fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");
    query.exec("SET SQL_SAFE_UPDATES=0;");

    vector<string> v;
    v=stringtoVectorString(ss);
    string s=v[0],t=v[1],v1=v[2],v2=v[3],md,s2;
    s2="select round(abs(min(a.lon)-max(a.lon))+abs(min(b.lat)-max(b.lat)),4) as distance from( select* from citytable where lat<";
    s2+=v1+" order by lat desc limit "+to_string(stoi(s)-1)+","+to_string(stoi(t)-stoi(s)+1)+") as a,";
    s2+="( select* from citytable where lon>"+v2+" order by lon asc limit "+to_string(stoi(s)-1)+","+to_string(stoi(t)-stoi(s)+1)+") as b";
    //---------------------------------------
    query.exec(QString::fromStdString(s2));
    //---------------------------------------
    query.next();
    stringstream token;
    if(query.value(0).isNull())
        token<<"NULL";
    else
        token<<fixed<<setprecision(4)<<query.value(0).toDouble();
    return token.str();




    /*md= query.value(0).toString().toStdString();
    if(md=="0")
        md="0.0000";
    //---------------------------------------蝣箄??臬?摸ULL
    s2="select * from( select* from citytable where lat<";
    s2+=v1+" order by lat desc limit "+to_string(stoi(s)-1)+","+to_string(stoi(t)-stoi(s)+1)+") as a,";
    s2+="( select* from citytable where lon>"+v2+" order by lon asc limit "+to_string(stoi(s)-1)+","+to_string(stoi(t)-stoi(s)+1)+") as b";
    query.exec(QString::fromStdString(s2));
    int flag=0;
    if(query.next()==NULL)
        flag=1;
    if(flag==1)
        md="NULL";
    return md;*/
}
