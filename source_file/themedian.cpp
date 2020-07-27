#include "..\\header_file\\themedian.h"

string TheMedian::solve(string s)
{
    query.exec("DROP DATABASE IF EXISTS CITYDATABASE;");
    query.exec("CREATE DATABASE CITYDATABASE;");
    query.exec("USE CITYDATABASE;");
    query.exec("DROP TABLE IF EXISTS CITYTABLE;");
    query.exec("CREATE TABLE CITYTABLE(ID INT,COUNTRY VARCHAR(50),CITY VARCHAR(60),LAT DOUBLE,LON DOUBLE,PRIMARY KEY(ID));");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' INTO TABLE CITYTABLE FIELDS ENCLOSED BY '\"' TERMINATED BY ',' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS;");

    int a,b,m;
    string lat_lon,asc_desc,command1;
    stringstream ss,so;
    ss<<s;
    ss>>a>>b>>lat_lon>>m>>asc_desc;
    command1="SELECT ROUND(AVG(";
    if(lat_lon=="lat")
        command1+="LAT),4) FROM (SELECT @X:=@X+1 AS N,LAT FROM (SELECT * FROM CITYTABLE WHERE ID%10=";
    else
        command1+="LON),4) FROM (SELECT @X:=@X+1 AS N,LON FROM (SELECT * FROM CITYTABLE WHERE ID%10=";
    command1+=to_string(m)+" ORDER BY ";
    if(lat_lon=="lat"){
        if(asc_desc=="asc")
            command1+="LAT ASC LIMIT ";
        else
            command1+="LAT DESC LIMIT ";
    }
    else{
        if(asc_desc=="asc")
            command1+="LON ASC LIMIT ";
        else
            command1+="LON DESC LIMIT ";
    }
    command1+=to_string(b-a+1)+" OFFSET "+to_string(a-1);
    command1+=") AS PP,(SELECT @X:=-1) AS X) AS P WHERE N=FLOOR(@X/2) OR N=CEIL(@X/2);";
    query.exec(command1.c_str());

    query.next();
    if(query.value(0).isNull())
        so<<"NULL";
    else
        so<<fixed<<setprecision(4)<<query.value(0).toDouble();

    return so.str();
}
