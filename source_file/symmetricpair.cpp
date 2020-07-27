#include "..\\header_file\\symmetricpair.h"

string SymmetricPair::solve(string s)
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
    string ev_or_od=v[0],m=v[1],n=v[2],k=v[3],s2;
    //-------------------------------------------1
    if(ev_or_od=="ev")
        s2="update citytable set lat = lat + lon, lon = lat - lon, lat = lat - lon where id%2=0";
    else
        s2="update citytable set lat = lat + lon, lon = lat - lon, lat = lat - lon where id%2=1";
    query.exec(QString::fromStdString(s2));
    //-------------------------------------------2
    s2="update citytable set lat=lon where id%10="+m;
    query.exec(QString::fromStdString(s2));
    //-------------------------------------------3
    s2="select x1,y1 from (select x1,y1 from";
    s2+="(select id,round(lat,"+n+") as x1,round(lon,"+n+") as y1 from citytable order by id asc) as a ";
    s2+="inner join ";
    s2+="(select id,round(lat,"+n+") as x2,round(lon,"+n+") as y2 from citytable order by id asc) as b ";
    s2+="on a.id!=b.id and x1=y2 and y1=x2 group by x1,y1 order by x1,y1 ) as c where x1<=y1 limit "+to_string(stoi(k)-1)+",1";

    query.exec(QString::fromStdString(s2));
    query.next();
    stringstream token;
    if(query.value(0).isNull())
        token<<"NULL NULL";
    else
        token<<fixed<<setprecision(stoi(n))<<query.value(0).toDouble()<<" "<<query.value(1).toDouble();

    return token.str();
}
