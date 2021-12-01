var a:array[1..100] of longint;
    np:array[1..100000000] of ansistring;
    n,d,i,inp:longint;
///////////////////////////////////////
function stri(number:int64):ansistring;
begin
str(number,stri);
end;
////////
function int(strin:ansistring):int64;
var check:longint;
begin
val(strin,int,check);
end;
////////
function join(a:array of longint):ansistring;
var i:longint;
begin
join:='';
for i:=1 to n do
    join:=join+stri(a[i]);
end;
////////
procedure sinhnp(k:longint);
var i:longint;
begin
if k>n then 
    begin
    np[d]:=join(a);
    d:=d+1;
    end
else
    for i:=0 to 1 do
        begin
        a[k]:=i;
        sinhnp(k+1);
        end;
end;
//////////////////////////////////////////
begin
readln(inp);
n:=9;
d:=1;
sinhnp(1);
for i:=1 to d-1 do
    begin
    if (int(np[i]) mod inp=0) and (int(np[i])<>0) then
        begin
        writeln(int(np[i]));
        halt;
        end;
    end;
end.