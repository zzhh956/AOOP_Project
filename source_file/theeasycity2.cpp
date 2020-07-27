#include "..\\header_file\\theeasycity2.h"

string TheEasyCity2::solve(string s)
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
    string n=v[0],lar_or_sma=v[1],chs=v[2],che=v[3],la=v[4],ha=v[5],lo=v[6],ho=v[7],m=v[8];
    string sn,nc,ed,s2;
    //--------------------------------1
    s2="select mid(country,1,3) as first_three_word , number_of_city from (select country,count(city) as number_of_city from citytable group by country order by number_of_city ";
    if(lar_or_sma=="lar")
        s2+="desc";
    else
        s2+="asc";
    s2+=" limit "+to_string(stoi(n)-1)+",1"+") as a2";
    query.exec(QString::fromStdString(s2));
    /*for(int i=0;i<stoi(n);i++)
            query.next();*/
    query.next();
    if(query.value(0).isNull()){
        sn="NULL";
        nc="NULL";
    }
    else{
        sn=query.value(0).toString().toStdString();
        nc=query.value(1).toString().toStdString();
    }
    //--------------------------------2
    s2="delete from citytable where city regexp '["+che+"]$|^[^"+chs+"]' or ("+la+"< lat and lat< "+ha+" and "+lo+"< lon and lon < "+ho+")";
    query.exec(QString::fromStdString(s2));

    //--------------------------------3
    s2="update citytable set lat = lat + lon, lon = lat - lon, lat = lat - lon where id regexp'"+m+"$'";
    query.exec(QString::fromStdString(s2));


    //--------------------------------4
    s2="select round(sqrt(pow(max(lon)-min(lon),2)+pow(max(lat)-min(lat),2)),4) as distance from CITYTABLE";
    query.exec(QString::fromStdString(s2));
    query.next();
    stringstream token;
    token<<sn<<" "<<nc<<" ";
    ed=query.value(0).toString().toStdString();
    if(query.value(0).isNull()){
        ed="NULL";
        token<<ed;
    }
    else{
        token<<fixed<<setprecision(4)<<query.value(0).toDouble();
    }

    return token.str();
}
