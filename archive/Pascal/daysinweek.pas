var d,m,y,i,s:longint;
    //weekdays:array[0..6] of string = ('Thu 7','Chu Nhat', 'Thu 2', 'Thu 3', 'Thu 4', 'Thu 5', 'Thu 6');
    weekdays:array[0..6] of string = ('Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun');
///////////////////////////////////////////////
function daysinyear(y:longint):longint;
begin
    if ((y mod 400=0) or (((y mod 4=0) and (y mod 100<>0)))) then 
        exit(366)
    else
        exit(365);
end;
//////////
function daysinmonth(m:longint):longint;
begin
    if (m in [1,3,5,7,8,10,12]) then
        exit(31)
    else
        if (m in [4,6,9,11]) then
            exit(30)
        else
            if (daysinyear(y)=365) then 
                exit(28)
            else
                exit(29);
end;
//////////////////////////////////////////////
begin
readln(d,m,y);
for i:=1 to y-1 do
    s:=s+daysinyear(i);
for i:=1 to m-1 do
    s:=s+daysinmonth(i);
s:=s+d-1;
writeln(weekdays[s mod 7]);
end.
